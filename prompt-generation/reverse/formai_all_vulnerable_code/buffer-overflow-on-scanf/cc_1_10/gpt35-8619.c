//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>

// Function prototypes
void calculateSavings(double salary, double expenses);
double calculateTotalExpenses(double rent, double groceries, double utilities, double transportation, double entertainment);

int main() {
   // Declare variables
   double salary, rent, groceries, utilities, transportation, entertainment;

   // Prompt user for input
   printf("Enter your monthly salary: ");
   scanf("%lf", &salary);
   printf("Enter your monthly rent: ");
   scanf("%lf", &rent);
   printf("Enter your monthly grocery expenses: ");
   scanf("%lf", &groceries);
   printf("Enter your monthly utilities expenses: ");
   scanf("%lf", &utilities);
   printf("Enter your monthly transportation expenses: ");
   scanf("%lf", &transportation);
   printf("Enter your monthly entertainment expenses: ");
   scanf("%lf", &entertainment);

   // Calculate total expenses
   double totalExpenses = calculateTotalExpenses(rent, groceries, utilities, transportation, entertainment);

   // Print total expenses
   printf("\nTotal monthly expenses: $%.2f\n", totalExpenses);

   // Calculate and print savings
   calculateSavings(salary, totalExpenses);

   return 0;
}

// Function to calculate total expenses
double calculateTotalExpenses(double rent, double groceries, double utilities, double transportation, double entertainment) {
   return rent + groceries + utilities + transportation + entertainment;
}

// Function to calculate and print savings
void calculateSavings(double salary, double expenses) {
   double savings = salary - expenses;
   
   if (savings > 0) {
      printf("You have $%.2f left for savings and investments.\n", savings);
   } else if (savings == 0) {
      printf("You have no money left for savings and investments.\n");
   } else {
      printf("You are in debt. Your expenses exceed your income by $%.2f.\n", -savings);
   }
}