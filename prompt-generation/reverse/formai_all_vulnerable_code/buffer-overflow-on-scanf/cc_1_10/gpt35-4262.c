//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
   char name[50];
   double amount;
   char category[20];
};

void addExpense(struct Expense expenses[], int *numExpenses);
void displayExpenses(struct Expense expenses[], int numExpenses);
void displayCategory(struct Expense expenses[], int numExpenses);
void displayTotal(struct Expense expenses[], int numExpenses);

int main() {
   int numExpenses = 0;
   struct Expense expenses[100];

   int choice = 1;
   while (choice != 0) {
      printf("\n");
      printf("1. Add Expense\n");
      printf("2. Display Expenses\n");
      printf("3. Display Expenses by Category\n");
      printf("4. Display Total Expense\n");
      printf("0. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            addExpense(expenses, &numExpenses);
            break;
         case 2:
            displayExpenses(expenses, numExpenses);
            break;
         case 3:
            displayCategory(expenses, numExpenses);
            break;
         case 4:
            displayTotal(expenses, numExpenses);
            break;
         case 0:
            printf("Exiting...\n");
            exit(0);
         default:
            printf("Invalid Choice\n");
            break;
      }
   }

   return 0;
}

void addExpense(struct Expense expenses[], int *numExpenses) {
   char name[50];
   double amount;
   char category[20];

   printf("Enter Name: ");
   scanf("%s", name);
   printf("Enter Amount: ");
   scanf("%lf", &amount);
   printf("Enter Category: ");
   scanf("%s", category);

   strcpy(expenses[*numExpenses].name, name);
   expenses[*numExpenses].amount = amount;
   strcpy(expenses[*numExpenses].category, category);

   (*numExpenses)++;
}

void displayExpenses(struct Expense expenses[], int numExpenses) {
   printf("\n");
   printf("Expenses:\n");

   for (int i = 0; i < numExpenses; i++) {
      printf("%s\t%.2lf\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
   }
}

void displayCategory(struct Expense expenses[], int numExpenses) {
   char category[20];

   printf("\n");
   printf("Enter Category to Display: ");
   scanf("%s", category);

   printf("\n");
   printf("Expenses in %s Category:\n", category);

   for (int i = 0; i < numExpenses; i++) {
      if (strcmp(expenses[i].category, category) == 0) {
         printf("%s\t%.2lf\n", expenses[i].name, expenses[i].amount);
      }
   }
}

void displayTotal(struct Expense expenses[], int numExpenses) {
   double total = 0;

   for (int i = 0; i < numExpenses; i++) {
      total += expenses[i].amount;
   }

   printf("\n");
   printf("Total Expense: %.2lf\n", total);
}