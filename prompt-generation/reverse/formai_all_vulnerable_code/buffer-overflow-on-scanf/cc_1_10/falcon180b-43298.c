//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_AMOUNT_LENGTH 10
#define MAX_CATEGORY_LENGTH 20
#define MAX_TRANSACTION_LENGTH 80

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    char transaction[MAX_TRANSACTION_LENGTH];
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter category: ");
    scanf("%s", transactions[num_transactions].category);

    printf("Enter amount: ");
    if (fgets(transactions[num_transactions].transaction, MAX_TRANSACTION_LENGTH, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return;
    }

    char *amount_str = strstr(transactions[num_transactions].transaction, "$");
    if (amount_str == NULL) {
        printf("Error: Invalid amount format.\n");
        return;
    }

    amount_str += 1;
    transactions[num_transactions].amount = atof(amount_str);

    num_transactions++;
}

void print_transactions() {
    printf("Category\tAmount\tTransaction\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%-20s$%.2f\t%s\n", transactions[i].category, transactions[i].amount, transactions[i].transaction);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add transaction\n");
        printf("2. Print transactions\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_transaction();
            break;
        case 2:
            print_transactions();
            break;
        case 3:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}