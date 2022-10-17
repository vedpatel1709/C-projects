/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   :Patel Ved Rajendrakumar
	ID     :149409203
	Email  :vrpatel33@myseneca.ca
	Section:IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_NETINCOME  500.00
#define MAX_NETINCOME  400000.00
#define MAX 10
#define MIN 1
#include<stdio.h>
int main(void) {
	double netincome = 0.0, sum = 0.0;
	int nitems ;
	int i = 0 ;
	const double mincost = 100.00;
	const int min_priority = 1 ;
	const int max_priority = 3 ;

	double cost[MAX];
	int priority[MAX];
	char choice[MAX];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
        printf("\n");
	do {
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netincome);
		if (netincome > MAX_NETINCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
		if (netincome < MIN_NETINCOME) 
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		printf("\n");
	} while (netincome > MAX_NETINCOME || netincome < MIN_NETINCOME);
	 
	do {
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &nitems);
		if (nitems>MAX || nitems<MIN) {
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		printf("\n");

	} while (nitems > MAX || nitems < MIN);
	
	
	for (i = 0; i < nitems; i++) {
		printf("Item-%d Details:\n", i+1);

		do {
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < mincost)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (cost[i] < mincost); 
		
		do {
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i]>max_priority || priority[i]<min_priority)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (priority[i]>max_priority || priority[i]<min_priority); ;

		do {
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%*c%c", &choice[i]);
			if ((choice[i] != 'y') && (choice[i] != 'n'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		 } while ((choice[i]!='y') && (choice[i]!='n'));
		   sum += cost[i];
		   printf("\n");
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < nitems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], choice[i], cost[i]); 
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n",sum);
        printf("\n");
	printf("Best of luck in all your future endeavours!\n");
return 0;
}