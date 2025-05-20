//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
    struct Transaction *next;
} Transaction;

Transaction *transactions = NULL;
float balance = 0.0;

void add_transaction(const char *description, float amount) {
    Transaction *new_transaction = (Transaction *) malloc(sizeof(Transaction));

    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = transactions;

    transactions = new_transaction;

    balance += amount;
}

void view_transaction_history() {
    Transaction *current = transactions;

    printf("\nTransaction History:\n");
    printf("----------------------\n");

    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void print_balance() {
    printf("\nCurrent Balance: %.2f\n", balance);
}

int main() {
    char input_description[50];
    float input_amount;
    int choice;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("------------------------\n");
        printf("1. Add Transaction\n");
        printf("2. View Transaction History\n");
        printf("3. Print Current Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction description: ");
                scanf("%s", input_description);
                printf("Enter transaction amount: ");
                scanf("%f", &input_amount);
                add_transaction(input_description, input_amount);
                break;
            case 2:
                view_transaction_history();
                break;
            case 3:
                print_balance();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}