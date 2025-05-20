//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char type[10]; // Income or Expense
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

void add_transaction() {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction list is full!\n");
        return;
    }
    
    Transaction new_transaction;
    
    printf("Enter the name of the transaction: ");
    scanf("%s", new_transaction.name);

    printf("Enter the amount: ");
    scanf("%f", &new_transaction.amount);

    printf("Enter type (Income/Expense): ");
    scanf("%s", new_transaction.type);

    transactions[transaction_count++] = new_transaction;
    printf("Transaction added successfully!\n");
}

void display_transactions() {
    if (transaction_count == 0) {
        printf("No transactions to display!\n");
        return;
    }
    
    printf("\nYour Transactions:\n");
    printf("%-20s %-10s %s\n", "Name", "Amount", "Type");
    printf("--------------------------------------\n");

    for (int i = 0; i < transaction_count; i++) {
        printf("%-20s %-10.2f %s\n", transactions[i].name, transactions[i].amount, transactions[i].type);
    }
}

void calculate_balance() {
    float total_income = 0;
    float total_expense = 0;

    for (int i = 0; i < transaction_count; i++) {
        if (strcmp(transactions[i].type, "Income") == 0) {
            total_income += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "Expense") == 0) {
            total_expense += transactions[i].amount;
        }
    }

    float balance = total_income - total_expense;

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Your Balance: %.2f\n", balance);
}

void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. Display Transactions\n");
    printf("3. Calculate Balance\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                display_transactions();
                break;
            case 3:
                calculate_balance();
                break;
            case 4:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}