//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

struct Expense {
   char description[50];
   float amount;
   char category[20];
   char date[11];
};

int numExpenses = 0;
struct Expense expenses[MAX_EXPENSES];

void addExpense() {
   struct Expense newExpense;
   printf("Enter description: ");
   fgets(newExpense.description, 50, stdin);
   printf("Enter amount: ");
   scanf("%f", &newExpense.amount);
   getchar(); // absorb newline character from scanf
   printf("Enter category: ");
   fgets(newExpense.category, 20, stdin);
   printf("Enter date (MM/DD/YYYY): ");
   fgets(newExpense.date, 11, stdin);
   expenses[numExpenses] = newExpense;
   numExpenses++;
   printf("Expense added successfully!\n");
}

void viewExpenses() {
   if (numExpenses == 0) {
      printf("No expenses currently recorded.\n");
      return;
   }
   printf("%-20s %-10s %-20s %-10s\n", "Description", "Amount", "Category", "Date");
   printf("--------------------------------------------------------\n");
   for (int i = 0; i < numExpenses; i++) {
      printf("%-20s $%-9.2f %-20s %-10s\n", expenses[i].description, expenses[i].amount,
            expenses[i].category, expenses[i].date);
   }
}

void summarizeExpenses() {
   if (numExpenses == 0) {
      printf("No expenses currently recorded.\n");
      return;
   }
   float total = 0;
   char* categories[MAX_EXPENSES];
   int numCategories = 0;
   for (int i = 0; i < numExpenses; i++) {
      total += expenses[i].amount;
      int categoryExists = 0;
      for (int j = 0; j < numCategories; j++) {
         if (strcmp(categories[j], expenses[i].category) == 0) {
            categoryExists = 1;
            break;
         }
      }
      if (!categoryExists) {
         categories[numCategories] = expenses[i].category;
         numCategories++;
      }
   }
   printf("Total expenses: $%.2f\n", total);
   printf("Categories:\n");
   for (int i = 0; i < numCategories; i++) {
      float categoryTotal = 0;
      for (int j = 0; j < numExpenses; j++) {
         if (strcmp(categories[i], expenses[j].category) == 0) {
            categoryTotal += expenses[j].amount;
         }
      }
      printf("%s: $%.2f\n", categories[i], categoryTotal);
   }
}

int main() {
   while (1) {
      printf("\n");
      printf("Select an option:\n");
      printf("1. Add expense\n");
      printf("2. View expenses\n");
      printf("3. Summarize expenses\n");
      printf("4. Quit\n");
      int choice;
      scanf("%d", &choice);
      getchar(); // absorb newline character from scanf
      printf("\n");
      switch (choice) {
         case 1:
            addExpense();
            break;
         case 2:
            viewExpenses();
            break;
         case 3:
            summarizeExpenses();
            break;
         case 4:
            printf("Goodbye!\n");
            return 0;
         default:
            printf("Invalid choice.\n");
            break;
      }
   }
   return 0;
}