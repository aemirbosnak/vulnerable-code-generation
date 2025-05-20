//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define structure for transactions
typedef struct {
    char type[20];
    float amount;
    char date[20];
} transaction;

// Function to add a new transaction
void addTransaction() {
    transaction t;
    printf("Enter transaction type (income/expense): ");
    scanf("%s", t.type);
    printf("Enter transaction amount: ");
    scanf("%f", &t.amount);
    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", t.date);
    // Add transaction to a list or file
}

// Function to display all transactions
void displayTransactions() {
    // Retrieve transactions from a list or file and display them
}

// Function to calculate total income and expenses
void calculateTotal() {
    float totalIncome = 0.0, totalExpenses = 0.0;
    // Iterate through all transactions and calculate total income and expenses
    printf("Total income: $%.2f\n", totalIncome);
    printf("Total expenses: $%.2f\n", totalExpenses);
}

int main() {
    int choice;
    do {
        printf("Personal Finance Planner\n");
        printf("1. Add transaction\n");
        printf("2. Display transactions\n");
        printf("3. Calculate total income and expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                displayTransactions();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
    return 0;
}