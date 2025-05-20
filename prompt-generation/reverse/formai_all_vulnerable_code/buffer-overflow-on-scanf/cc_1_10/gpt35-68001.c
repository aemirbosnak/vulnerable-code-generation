//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
/* 
   This C program is an artistic example of an expense tracker. 
   It has a GUI that helps you monitor your financial progress. 
   It shows you how much money you've spent so far, the amount of money remaining,
   and the expenses you've made during the day.

   The program also allows you to set a daily budget, edit and delete expenses, and view
   past expenses. 

   To keep things simple and easy to understand, the code for this expense tracker is 
   structured as follows:
   
   -> Global variables
   -> Function declarations
   -> Main function
   -> Supporting functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global variables */
char expenses[100][50]; // holds all expenses for the day
float spent = 0; // amount spent so far
float budget = 0; // daily budget
float remaining = 0; // remaining budget

/* Function declarations */
void addExpense();
void editExpense();
void deleteExpense();
void viewExpenses();
void viewProgress();

/* Main function */
int main()
{
   printf("Welcome to the Expense Tracker.\n\n");
   printf("Please enter your daily budget: ");
   scanf("%f", &budget);
   remaining = budget;
   printf("\n");

   int choice;
   do {
      printf("Please select an option:\n");
      printf("1. Add new expense\n");
      printf("2. Edit an expense\n");
      printf("3. Delete an expense\n");
      printf("4. View expenses\n");
      printf("5. View financial progress\n");
      printf("6. Exit\n");
      printf("\nYour choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:         
            addExpense(); 
            break;
         case 2:
            editExpense(); 
            break;
         case 3: 
            deleteExpense();
            break;
         case 4:         
            viewExpenses(); 
            break;
         case 5:
            viewProgress();
            break;
         case 6:
             printf("Thank you for using the Expense Tracker. Goodbye!\n");
             exit(0);
             break;
         default: 
            printf("Invalid choice. Please try again.\n\n");  
            break;
      }
   } while(choice != 6);

   return 0;
}

/* Supporting functions */
void addExpense()
{
   printf("\nAdd new expense:\n");
   char name[50];
   float cost;

   printf("Enter expense name: ");
   scanf("%s", name);
   printf("Enter expense cost: ");
   scanf("%f", &cost);

   if (cost > remaining) {
      printf("You do not have enough funds for this expense.\n\n");
   } else {
      strcpy(expenses[sizeof(expenses)/sizeof(expenses[0]) - 1], name);
      spent += cost;
      remaining -= cost;
      printf("Expense added successfully.\n\n");
   }
}

void editExpense()
{
   printf("\nEdit an expense:\nEnter the number of the expense you wish to edit: ");
   int index;
   scanf("%d", &index);
   index--;

   if (index < 0 || index > sizeof(expenses)/sizeof(expenses[0]) - 1 || expenses[index][0] == '\0') {
      printf("This expense does not exist.\n\n");
   } else {
      float original_cost = 0;
      char name[50];
      printf("Enter new expense name (or press enter to skip): ");
      scanf("%s", name);
      if(name[0]!='\0') {
         strcpy(expenses[index], name);
      }

      printf("Enter new expense cost (or press enter to skip): ");
      char input[50];
      scanf("%s", input);
      if(input[0]!='\0') {
         original_cost = atof(input);
         if (original_cost > remaining + spent) {
            printf("You do not have enough funds for this expense.\n\n");
         } else {
            remaining += expenses[index][0]!='\0'? original_cost - atof(&expenses[index][strlen(expenses[index]) - 1]) : -atof(&expenses[index][strlen(expenses[index]) - 1]);
            spent -= expenses[index][0]!='\0'? atof(&expenses[index][strlen(expenses[index]) - 1]) : 0;
            sprintf(&expenses[index][strlen(expenses[index]) - 1], "%.2f", original_cost);
            spent += original_cost;
         }
      } 
      printf("Expense updated successfully.\n\n");
   }
}

void deleteExpense()
{
   printf("\nDelete an expense:\nEnter the number of the expense you wish to delete: ");
   int index;
   scanf("%d", &index);
   index--;

   if (index < 0 || index > sizeof(expenses)/sizeof(expenses[0]) - 1 || expenses[index][0] == '\0') {
      printf("This expense does not exist.\n\n");
   } else {
      spent -= atof(&expenses[index][strlen(expenses[index]) - 1]);
      remaining += atof(&expenses[index][strlen(expenses[index]) - 1]);
      memset(expenses[index], 0, sizeof(expenses[index]));
      printf("Expense deleted successfully.\n\n");
   }
}

void viewExpenses()
{
   printf("\nDaily expenses:\n");
   for (int i = 0; i < sizeof(expenses)/sizeof(expenses[0]); i++) {
      if (expenses[i][0] != '\0') {
         printf("%d. %s $%s\n", i+1, expenses[i], &expenses[i][strlen(expenses[i]) - 1]);
      }
   }
   printf("\n");
}

void viewProgress()
{
   printf("\nFinancial progress:\n");
   printf("Daily budget: %.2f\n", budget);
   printf("Amount spent: %.2f\n", spent);
   printf("Remaining budget: %.2f\n\n", remaining);
}