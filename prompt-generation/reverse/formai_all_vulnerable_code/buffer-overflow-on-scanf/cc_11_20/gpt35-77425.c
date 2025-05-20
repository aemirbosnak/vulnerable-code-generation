//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for expenses
struct expenses {
  char date[20];
  char description[200];
  float amount;
};


int main() {
  int i = 0, n = 0, option = 0;
  char choice = '\0';
  float total_expenses = 0;

  // Array of structures to store expenses
  struct expenses expense[100];

  printf("------------Welcome to Expense Tracker------------");

  do {
    printf("\nPlease select from the following options:");
    printf("\n1. Add Expense");
    printf("\n2. View All Expenses");
    printf("\n3. View Expenses for a Specific Date");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("\nEnter the date of expense (DD/MM/YYYY): ");
        scanf("%s", expense[i].date);

        printf("\nEnter the description of expense: ");
        scanf(" %[^\n]s", expense[i].description);

        printf("\nEnter the amount of expense: ");
        scanf("%f", &expense[i].amount);
        
        total_expenses += expense[i].amount; // Updating total expenses
        
        printf("\nExpense added successfully!\n");
        i++; // Incrementing counter
        break;
      case 2:
        if(i == 0) {
          printf("\nNo expenses added yet!\n");
        }
        else {
          printf("\n------------All Expenses------------\n");
          for(int j = 0; j < i; j++) {
            printf("Date: %s\n", expense[j].date);
            printf("Description: %s\n", expense[j].description);
            printf("Amount: %.2f\n", expense[j].amount);
            printf("\n");
          }
          
          printf("Total Expenses: %.2f", total_expenses);
        }
        break;
      case 3:
        if(i == 0) {
          printf("\nNo expenses added yet!\n");
        }
        else {
          char date[20];
          bool date_found = false;

          printf("\nEnter the date for which you want to view expenses (DD/MM/YYYY): ");
          scanf("%s", date);

          printf("\n------------Expenses for %s------------\n", date);
          for(int j = 0; j < i; j++) {
            if(strcmp(expense[j].date, date) == 0) {
              printf("Description: %s\n", expense[j].description);
              printf("Amount: %.2f\n", expense[j].amount);
              printf("\n");
              date_found = true;
            }
          }

          if(!date_found) {
            printf("\nNo expenses found for the given date!\n");
          }
        }
        break;
      case 4:
        printf("\nThank you for using Expense Tracker! Have a nice day!");
        exit(0); // Terminating the program
        break;
      default:
        printf("\nInvalid choice! Please enter a valid choice.\n");
        break;
    }

    printf("\nDo you want to continue (Y/N)?: ");
    scanf(" %c", &choice);

  } while(choice == 'Y' || choice == 'y');

  return 0;
}