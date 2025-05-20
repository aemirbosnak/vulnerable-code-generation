//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

float expenses(float income);
float savings(float income, float exp);

int main()
{
	float income, exp, sav;
	printf("Enter your monthly income: $");
	scanf("%f", &income);

	exp = expenses(income);
	sav = savings(income, exp);

	printf("\n---Monthly Finance Planner---\n");
	printf("Monthly Income: $%.2f\n", income);
	printf("Monthly Expenses: $%.2f\n", exp);
	printf("Monthly Savings: $%.2f\n", sav);

	return 0;
}

float expenses(float income)
{
	float housing, food, transport, utilities, others, total;

	printf("\nEnter your monthly housing expenses: $");
	scanf("%f", &housing);

	printf("Enter your monthly food expenses: $");
	scanf("%f", &food);

	printf("Enter your monthly transportation expenses: $");
	scanf("%f", &transport);

	printf("Enter your monthly utilities expenses: $");
	scanf("%f", &utilities);

	printf("Enter your other monthly expenses: $");
	scanf("%f", &others);

	total = housing + food + transport + utilities + others;

	if (total > income) {
		printf("\nWARNING: Your monthly expenses are greater than your income. Please review your expenses.\n");
	}

	return total;
}

float savings(float income, float exp)
{
	float savings;

	savings = income - exp;

	return savings;
}