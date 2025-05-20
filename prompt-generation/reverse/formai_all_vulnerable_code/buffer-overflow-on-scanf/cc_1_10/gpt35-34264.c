//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Maximum number of transactions
#define MAX_CHARS 50 // Max length of transaction description

typedef struct {
    char description[MAX_CHARS];
    float amount;
} Transaction;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void add_transaction(Transaction *transactions, int *num_transactions) {
    if (*num_transactions >= MAX) {
        printf("Transaction limit reached.\n");
        return;
    }
    Transaction t;
    printf("Enter transaction description (max %d characters): ", MAX_CHARS);
    fgets(t.description, MAX_CHARS+2, stdin);
    t.description[strcspn(t.description, "\n")] = 0; // Remove newline character
    printf("Enter transaction amount: $");
    while (scanf("%f", &t.amount) != 1) {
        printf("Invalid input. Enter transaction amount: $");
        clear_input_buffer();
    }
    clear_input_buffer();
    transactions[*num_transactions] = t;
    (*num_transactions)++;
}

void print_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s: $%.2f\n", i+1, transactions[i].description, transactions[i].amount);
    }
}

void calculate_balance(Transaction *transactions, int num_transactions) {
    float balance = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        balance += transactions[i].amount;
    }
    printf("Balance: $%.2f\n", balance);
}

int main() {
    printf("Welcome to the Cryptic Personal Finance Planner!\n\n");
    Transaction transactions[MAX];
    int num_transactions = 0;
    char input;

    while (1) {
        printf("Enter a command (a - add transaction, p - print transactions, b - calculate balance, q - quit): ");
        input = getchar();
        clear_input_buffer();
        switch (input) {
            case 'a':
                add_transaction(transactions, &num_transactions);
                break;
            case 'p':
                print_transactions(transactions, num_transactions);
                break;
            case 'b':
                calculate_balance(transactions, num_transactions);
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    return 0;
}