//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

int main() {
   float income, rent, groceries, transportation, utilities, entertainment, savings, totalExpenses, netIncome;
   int months;

   printf("Welcome to your Personal Finance Planner!\n\n");
   
   printf("Please enter your monthly income: ");
   scanf("%f", &income);

   printf("Please enter your monthly rent/mortgage: ");
   scanf("%f", &rent);

   printf("Please enter your monthly groceries: ");
   scanf("%f", &groceries);

   printf("Please enter your monthly transportation: ");
   scanf("%f", &transportation);

   printf("Please enter your monthly utilities: ");
   scanf("%f", &utilities);

   printf("Please enter your monthly entertainment: ");
   scanf("%f", &entertainment);

   printf("Please enter your monthly savings: ");
   scanf("%f", &savings);

   printf("How many months would you like to plan for? ");
   scanf("%d", &months);

   totalExpenses = rent + groceries + transportation + utilities + entertainment;

   printf("\n\n ----- Monthly Expenses ----- \n");
   printf("Rent: $%.2f\n", rent);
   printf("Groceries: $%.2f\n", groceries);
   printf("Transportation: $%.2f\n", transportation);
   printf("Utilities: $%.2f\n", utilities);
   printf("Entertainment: $%.2f\n", entertainment);
   printf("Total Expenses: $%.2f\n\n", totalExpenses);

   printf("----- Monthly Income ----- \n");
   printf("Income: $%.2f\n", income);
   printf("Savings: $%.2f\n\n", savings);

   netIncome = income - totalExpenses - savings;

   printf("----- Net Income ----- \n");
   printf("Net Income: $%.2f\n\n", netIncome);

   printf("----- Total Plan ----- \n");
   printf("Total Income: $%.2f\n", income * months);
   printf("Total Expenses: $%.2f\n", totalExpenses * months);
   printf("Total Savings: $%.2f\n", savings * months);
   printf("Net Income: $%.2f\n", netIncome * months);

   return 0;
}