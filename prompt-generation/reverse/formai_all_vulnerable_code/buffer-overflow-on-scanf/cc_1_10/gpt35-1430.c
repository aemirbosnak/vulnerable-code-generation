//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
   char category[20];
   float amount;
   char date[15];
};

int main() {
   struct expense expenses[100];
   int count = 0;

   while(1) {
      printf("\n\nExpense Tracker\n");
      printf("1. Add Expense\n");
      printf("2. View Expenses\n");
      printf("3. Exit\n");
      printf("Enter your choice: ");
      int choice;
      scanf("%d", &choice);

      switch(choice) {
         case 1: {
            struct expense new_expense;
            printf("\nEnter Category: ");
            scanf("%s", new_expense.category);
            printf("Enter Amount: ");
            scanf("%f", &new_expense.amount);
            printf("Enter Date: ");
            scanf("%s", new_expense.date);
            expenses[count] = new_expense;
            count += 1;

            printf("\nExpense Added Successfully.");
            break;
         }
         case 2: {
            printf("\nExpenses:\n");
            printf("Category\tAmount\tDate\n");
            for(int i=0; i<count; i++) {
               printf("%s\t\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
            }
            break;
         }
         case 3: {
            printf("\nExiting Expense Tracker.");
            exit(0);
         }
         default: {
            printf("\nInvalid Choice.");
            break;
         }
      }
   }

   return 0;
}