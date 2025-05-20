//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char description[50];
    float cost;
    char category[20];
} Expense;

int main() {

    // Creating the expense array
    Expense expenses[100];
    int numExpenses = 0;

    // Main menu
    int choice = 0;
    while (choice != 4) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Search expenses by category\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clearing the newline character from input buffer
        
        switch (choice) {
            
            // Adding an expense
            case 1:
                printf("\nAdding Expense\n");
                
                // Getting expense details from user
                printf("Enter description: ");
                fgets(expenses[numExpenses].description, 50, stdin);
                printf("Enter cost: ");
                scanf("%f", &expenses[numExpenses].cost);
                getchar(); // Clearing newline character from input buffer
                printf("Enter category: ");
                fgets(expenses[numExpenses].category, 20, stdin);
                
                numExpenses++;
                printf("Expense added successfully!\n");
                break;
            
            // Printing all expenses
            case 2:
                printf("\nPrinting All Expenses\n");
                
                if (numExpenses == 0) {
                    printf("No expenses to display!\n");
                }
                else {
                    printf("Description\t\tCost\t\tCategory\n");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%s\t\t%.2f\t\t%s", expenses[i].description, expenses[i].cost, expenses[i].category);
                    }
                }
                break;

            // Searching expenses by category
            case 3:
                printf("\nSearching Expenses by Category\n");
                printf("Enter category: ");
                char searchCategory[20];
                fgets(searchCategory, 20, stdin);

                int foundExpenses = 0;
                for (int i = 0; i < numExpenses; i++) {
                    if (strcmp(expenses[i].category, searchCategory) == 0) {
                        printf("%s\t\t%.2f\t\t%s", expenses[i].description, expenses[i].cost, expenses[i].category);
                        foundExpenses++;
                    }
                }
                if (foundExpenses == 0) {
                    printf("No expenses found in category: %s\n", searchCategory);
                }
                break;

            // Exiting the program
            case 4:
                printf("\nGoodbye!\n");
                break;

            // Invalid option
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}