//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 50

// Define the structure for a transaction
struct Transaction {
    char name[25];
    float amount;
};

// Define the function for displaying the main menu
void displayMainMenu() {
    printf("\n========== EXPENSE TRACKER ==========\n");
    printf("1. Add a transaction\n");
    printf("2. View all transactions\n");
    printf("3. View total expenses\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

int main() {
    // Declare variables
    int choice = 0;
    int num_transactions = 0;
    struct Transaction transactions[MAX_TRANSACTIONS];
    float total_expenses = 0.0;

    // Display the main menu initially
    displayMainMenu();

    // Loop until the user chooses to exit
    while (1) {
        // Read the user's choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a transaction
                if (num_transactions < MAX_TRANSACTIONS) {
                    struct Transaction t;
                    printf("\nEnter the name of the transaction: ");
                    scanf("%s", t.name);
                    printf("Enter the amount of the transaction: ");
                    scanf("%f", &t.amount);
                    transactions[num_transactions] = t;
                    num_transactions++;
                    total_expenses += t.amount;
                    printf("\nTransaction added successfully!\n");
                } else {
                    printf("\nMaximum transactions reached!\n");
                }
                
                // Display the main menu again
                displayMainMenu();
                break;
                
            case 2:
                // View all transactions
                printf("\n========== ALL TRANSACTIONS ==========\n");
                printf("%-25s %-10s\n", "NAME", "AMOUNT");
                printf("-------------------------------------\n");
                for (int i = 0; i < num_transactions; i++) {
                    printf("%-25s $%-9.2f\n", transactions[i].name, transactions[i].amount);
                }
                printf("\n");
                
                // Display the main menu again
                displayMainMenu();
                break;
                
            case 3:
                // View total expenses
                printf("\n========== TOTAL EXPENSES ==========\n");
                printf("Total expenses: $%.2f\n\n", total_expenses);
                
                // Display the main menu again
                displayMainMenu();
                break;
                
            case 4:
                // Exit
                printf("\nGoodbye!\n\n");
                exit(0);
                break;
                
            default:
                // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
                
                // Display the main menu again
                displayMainMenu();
                break;
        }
    }
    
    return 0;
}