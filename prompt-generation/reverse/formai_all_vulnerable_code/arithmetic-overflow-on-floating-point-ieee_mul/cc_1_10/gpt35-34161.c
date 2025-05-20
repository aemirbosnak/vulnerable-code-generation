//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>

int main() {
   float monthlyIncome, housingCosts, foodCosts, transportationCosts, otherExpenses, savings;
   float totalExpenses, disposableIncome, housingPercent, foodPercent, transportationPercent, otherPercent;

   // Initializing variables
   monthlyIncome = 0.0;
   housingCosts = 0.0;
   foodCosts = 0.0;
   transportationCosts = 0.0;
   otherExpenses = 0.0;
   savings = 0.0;

   // Reading inputs from user
   printf("Enter your monthly income: ");
   scanf("%f", &monthlyIncome);

   printf("Enter your cost of housing: ");
   scanf("%f", &housingCosts);

   printf("Enter your cost of food: ");
   scanf("%f", &foodCosts);

   printf("Enter your cost of transportation: ");
   scanf("%f", &transportationCosts);

   printf("Enter your other monthly expenses: ");
   scanf("%f", &otherExpenses);

   // Calculating expenses
   totalExpenses = housingCosts + foodCosts + transportationCosts + otherExpenses;
   disposableIncome = monthlyIncome - totalExpenses;

   // Calculating percentages
   housingPercent = (housingCosts / monthlyIncome) * 100;
   foodPercent = (foodCosts / monthlyIncome) * 100;
   transportationPercent = (transportationCosts / monthlyIncome) * 100;
   otherPercent = (otherExpenses / monthlyIncome) * 100;

   // Calculating savings
   savings = monthlyIncome - totalExpenses;

   // Displaying results
   printf("\n\nRESULTS:\n\n");
   printf("Monthly Income: $%.2f\n", monthlyIncome);
   printf("Housing Costs: $%.2f (%.2f%% of income)\n", housingCosts, housingPercent);
   printf("Food Costs: $%.2f (%.2f%% of income)\n", foodCosts, foodPercent);
   printf("Transportation Costs: $%.2f (%.2f%% of income)\n", transportationCosts, transportationPercent);
   printf("Other Expenses: $%.2f (%.2f%% of income)\n", otherExpenses, otherPercent);
   printf("Total Monthly Expenses: $%.2f\n", totalExpenses);
   printf("Disposable Income: $%.2f\n", disposableIncome);
   printf("Savings: $%.2f\n", savings);

   return 0;
}