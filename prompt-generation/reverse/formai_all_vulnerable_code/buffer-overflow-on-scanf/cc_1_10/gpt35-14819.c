//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for expense information
struct Expense {
    char date[20];
    char description[100];
    float amount;
};

int main() {
    // Initializing variables
    int choice, num_expenses = 0;
    float total_spent = 0.0;
    struct Expense expense[100];

    printf("Welcome to the Expense Tracker!\n");

    do {
        // Prompting user for choice
        printf("\nChoose an option:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View total spending\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Adding an expense
                printf("\nEnter the expense date in YYYY-MM-DD format: ");
                scanf("%s", expense[num_expenses].date);
                printf("Enter a short description of the expense: ");
                scanf("%s", expense[num_expenses].description);
                printf("Enter the expense amount: ");
                scanf("%f", &expense[num_expenses].amount);
                total_spent += expense[num_expenses].amount;
                num_expenses++;
                printf("\nExpense added successfully!\n");
                break;
            
            case 2:
                // Displaying all expenses
                printf("\nAll expenses:\n");
                printf("DATE\t   DESCRIPTION\t\tAMOUNT\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%s\t%s\t%.2f\n", expense[i].date, expense[i].description, expense[i].amount);
                }
                break;

            case 3:
                // Displaying total spending
                printf("\nTotal spending: $%.2f\n", total_spent);
                break;

            case 4:
                // Exiting the program
                printf("\nThanks for using Expense Tracker!\n");
                break;

            default:
                // Handling invalid input
                printf("\nInvalid choice! Please choose again.\n");
        }

    } while(choice != 4);

    return 0;
}