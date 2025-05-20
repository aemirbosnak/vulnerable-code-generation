//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double amount;
    int date;
} Transaction;

void add_transaction(Transaction* transactions, int index, char* name, double amount, int date) {
    if (index < MAX_TRANSACTIONS) {
        strcpy(transactions[index].name, name);
        transactions[index].amount = amount;
        transactions[index].date = date;
    } else {
        printf("Error: Maximum number of transactions reached.\n");
    }
}

void print_transactions(Transaction* transactions) {
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        printf("Name: %s, Amount: $%.2f, Date: %d\n", transactions[i].name, transactions[i].amount, transactions[i].date);
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;

    while (1) {
        printf("Enter transaction details (or 'q' to quit):\n");
        char name[50];
        double amount;
        int date;

        printf("Name: ");
        scanf("%s", name);

        printf("Amount: ");
        scanf("%lf", &amount);

        printf("Date (MM/DD/YYYY): ");
        scanf("%d", &date);

        add_transaction(transactions, num_transactions, name, amount, date);

        printf("Transaction added.\n");

        printf("Add another transaction? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    print_transactions(transactions);

    return 0;
}