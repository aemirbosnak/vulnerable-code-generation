//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
// This program helps users track their expenses. 
// It was created in the spirit of Ada Lovelace, who is considered to be the world's first computer programmer.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char name[20];
    double amount;
} Transaction;

void print_menu() {
    printf("Welcome to Ada's Expense Tracker! What would you like to do?\n");
    printf("1. Add a new transaction\n");
    printf("2. View all transactions\n");
    printf("3. View total spending\n");
    printf("4. Exit\n");
}

void add_transaction(Transaction* transactions, int* num_transactions) {
    if (*num_transactions >= MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached. Cannot add another.\n");
        return;
    }
    printf("Enter name of transaction: ");
    scanf("%s", transactions[*num_transactions].name);
    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[*num_transactions].amount);
    (*num_transactions)++;
}

void view_transactions(Transaction* transactions, int num_transactions) {
    if (num_transactions == 0) {
        printf("No transactions to display.\n");
        return;
    }
    printf("All transactions: \n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t\t$%.2lf\n", transactions[i].name, transactions[i].amount);
    }
}

void view_total_spending(Transaction* transactions, int num_transactions) {
    if (num_transactions == 0) {
        printf("No transactions to display.\n");
        return;
    }
    double total = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        total += transactions[i].amount;
    }
    printf("Total spending: $%.2lf\n", total);
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                view_transactions(transactions, num_transactions);
                break;
            case 3:
                view_total_spending(transactions, num_transactions);
                break;
            case 4:
                printf("Exiting... Thank you for using Ada's Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return EXIT_SUCCESS;
}