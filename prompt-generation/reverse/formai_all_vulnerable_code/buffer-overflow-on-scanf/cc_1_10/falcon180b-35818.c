//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000

typedef struct {
    char date[11];
    char description[51];
    float amount;
    char category[21];
} Transaction;

void add_transaction(Transaction transactions[], int num_transactions, char date[], char description[], float amount, char category[]) {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    strcpy(transactions[num_transactions].date, date);
    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;
    strcpy(transactions[num_transactions].category, category);

    num_transactions++;
}

void print_transactions(Transaction transactions[], int num_transactions) {
    printf("Date\tDescription\tAmount\tCategory\n");

    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t%s\t%.2f\t%s\n", transactions[i].date, transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;

    char date[11];
    char description[51];
    float amount;
    char category[21];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter description: ");
        scanf("%s", description);

        printf("Enter amount: ");
        scanf("%f", &amount);

        printf("Enter category: ");
        scanf("%s", category);

        add_transaction(transactions, num_transactions, date, description, amount, category);

        printf("\nTransaction added.\n");

        if (num_transactions == 0) {
            printf("No transactions yet.\n");
        } else {
            print_transactions(transactions, num_transactions);
        }
    }

    return 0;
}