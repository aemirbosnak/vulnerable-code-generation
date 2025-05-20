//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold expense data
struct expense {
   char name[30];
   float amount;
   char date[15];
};

void addExpense(struct expense *e, int *n) {
   printf("Enter expense name: ");
   scanf("%s", e[*n].name);
   printf("Enter expense amount: ");
   scanf("%f", &e[*n].amount);
   printf("Enter date (dd/mm/yyyy): ");
   scanf("%s", e[*n].date);
   *n += 1;
}

void displayExpenses(struct expense *e, int n) {
   printf("%-30s%-10s%s\n", "Expense Name", "Amount", "Date");
   for(int i=0; i<n; i++) {
      printf("%-30s%-10.2f%s\n", e[i].name, e[i].amount, e[i].date);
   }
}

int main() {
   int choice, n = 0;
   struct expense expenses[50];
  
   do {
      printf("\nExpense Tracker\n");
      printf("1. Add Expense\n");
      printf("2. Display Expenses\n");
      printf("3. Exit\n");
      printf("Enter choice (1-3): ");
      scanf("%d", &choice);

      switch(choice) {
         case 1: 
            addExpense(expenses, &n);
            break;
         case 2:
            displayExpenses(expenses, n);
            break;
         case 3: 
            printf("Exiting program...\n");
            break;
         default: 
            printf("Invalid choice, try again...\n");
            break;
      }
   } while(choice != 3);

   return 0;
}