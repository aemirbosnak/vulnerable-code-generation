//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    double amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

int main() {
    // Initialize the program
    transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;
    double totalIncome = 0, totalExpense = 0, netIncome = 0;

    // Get user input
    printf("Welcome to the Personal Finance Planner!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a transaction\n");
        printf("2. View all transactions\n");
        printf("3. Calculate net income\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                // Add a transaction
                printf("Enter a description for the transaction: ");
                scanf(" %[^\n]", transactions[numTransactions].description);
                printf("Enter the amount of the transaction: ");
                scanf("%lf", &transactions[numTransactions].amount);
                printf("Enter the type of transaction (I for income, E for expense): ");
                scanf(" %c", &transactions[numTransactions].type);
                numTransactions++;
                break;
            case 2:
                // View all transactions
                printf("\nAll transactions:\n");
                for (int i = 0; i < numTransactions; i++) {
                    printf("%s\t%.2lf\t%c\n", transactions[i].description, transactions[i].amount, transactions[i].type);
                }
                break;
            case 3:
                // Calculate net income
                totalIncome = 0;
                totalExpense = 0;
                for (int i = 0; i < numTransactions; i++) {
                    if (transactions[i].type == 'I') {
                        totalIncome += transactions[i].amount;
                    } else if (transactions[i].type == 'E') {
                        totalExpense += transactions[i].amount;
                    }
                }
                netIncome = totalIncome - totalExpense;
                printf("\nYour net income is: %.2lf\n", netIncome);
                break;
            case 4:
                // Quit the program
                printf("Thank you for using the Personal Finance Planner!\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }
    }

    return 0;
}