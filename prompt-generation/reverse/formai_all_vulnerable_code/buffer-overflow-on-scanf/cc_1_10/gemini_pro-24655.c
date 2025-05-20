//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char *description;
    float amount;
    int type; // 0 for expense, 1 for income
} transaction_t;

void print_menu() {
    printf("Retro Personal Finance Planner\n");
    printf("==============================\n");
    printf("1. Add a transaction\n");
    printf("2. List transactions\n");
    printf("3. Get balance\n");
    printf("4. Quit\n");
    printf("> ");
}

void add_transaction(transaction_t *transactions, int *num_transactions) {
    char description[100];
    float amount;
    int type;

    printf("Enter transaction description: ");
    scanf("%s", description);

    printf("Enter transaction amount: ");
    scanf("%f", &amount);

    printf("Enter transaction type (0 for expense, 1 for income): ");
    scanf("%d", &type);

    transactions[*num_transactions].description = strdup(description);
    transactions[*num_transactions].amount = amount;
    transactions[*num_transactions].type = type;
    (*num_transactions)++;
}

void list_transactions(transaction_t *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f\n", transactions[i].description, transactions[i].amount);
    }
}

float get_balance(transaction_t *transactions, int num_transactions) {
    float balance = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 0) {
            balance -= transactions[i].amount;
        } else {
            balance += transactions[i].amount;
        }
    }
    return balance;
}

int main() {
    transaction_t transactions[MAX_TRANSACTIONS];
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
                list_transactions(transactions, num_transactions);
                break;
            case 3:
                printf("Your balance is: $%.2f\n", get_balance(transactions, num_transactions));
                break;
            case 4:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].description);
    }

    return 0;
}