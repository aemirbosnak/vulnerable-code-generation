//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display available options
void displayOptions() {
  printf("*********************************************\n");
  printf("*          Welcome to Expense Tracker!       *\n");
  printf("*********************************************\n");
  printf("* 1. Add an expense                          *\n");
  printf("* 2. View expenses                           *\n");
  printf("* 3. Total expenses for the month            *\n");
  printf("* 4. Exit                                    *\n");
  printf("*********************************************\n");
}

// Main function
int main() {
  int choice, i, expenses[100], totalExpenses = 0;
  char desc[100], date[20], ans[5];

  do {
    // Display available options
    displayOptions();

    // Ask the user for choice
    printf("\nEnter your choice:");
    scanf("%d", &choice);

    // Handle the choice
    switch(choice) {
      case 1:
        // Ask for expense details
        printf("\nEnter description:");
        scanf("%s", desc);
        printf("Enter date (dd/mm/yyyy):");
        scanf("%s", date);
        printf("Enter amount:");
        scanf("%d", &expenses[i]);

        // Update total expenses
        totalExpenses += expenses[i];

        // Confirm the expense
        printf("\nExpense added successfully!\n");
        printf("Do you want to add more expenses? (y/n):");
        scanf("%s", ans);

        // Increment counter
        i++;

        // Loop until user enters n
        while (strcmp(ans, "y") == 0) {
          printf("\nEnter description:");
          scanf("%s", desc);
          printf("Enter date (dd/mm/yyyy):");
          scanf("%s", date);
          printf("Enter amount:");
          scanf("%d", &expenses[i]);

          // Update total expenses
          totalExpenses += expenses[i];

          // Confirm the expense
          printf("\nExpense added successfully!\n");
          printf("Do you want to add more expenses? (y/n):");
          scanf("%s", ans);

          // Increment counter
          i++;
        }
        break;
      
      case 2:
        // Display all expenses
        printf("\nDescription\tDate\tAmount\n");
        for(int j=0;j<i;j++){
          printf("%s\t%s\t%d\n", desc, date, expenses[j]);
        }
        break;
      
      case 3:
        // Display total expenses
        printf("\nTotal expenses for the month: $%d\n", totalExpenses);
        break;
      
      case 4:
        // Exit the program
        printf("\nGoodbye!\n");
        exit(0);
      
      default:
        // Invalid choice
        printf("\nInvalid choice!\n");
        break;
    }

  } while(choice != 4);

  return 0;
}