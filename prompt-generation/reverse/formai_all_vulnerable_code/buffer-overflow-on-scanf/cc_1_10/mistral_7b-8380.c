//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
    char type[10];
} Transaction;

Transaction transactions[MAX_ENTRIES];
int num_transactions = 0;
float balance = 0.0;
float available_funds = 0.0;

void add_transaction(char *description, float amount, char *type) {
    if (num_transactions >= MAX_ENTRIES) {
        printf("Error: Max number of transactions reached.\n");
        return;
    }

    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;
    strcpy(transactions[num_transactions].type, type);

    num_transactions++;

    if (strcmp(type, "income") == 0) {
        balance += amount;
        available_funds += amount;
    } else if (strcmp(type, "expense") == 0) {
        balance += amount;
        available_funds -= amount;
    }
}

void display_transactions() {
    if (num_transactions == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s %s %.2f\n", i+1, transactions[i].type, transactions[i].description, transactions[i].amount);
        if (strcmp(transactions[i].type, "expense") == 0) {
            available_funds -= transactions[i].amount;
        }
    }

    printf("\nBalance: %.2f\n", balance);
    printf("Available Funds: %.2f\n", available_funds);
}

int main() {
    char description[50];
    char type[10];
    float amount;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Description: ");
                scanf("%s", description);
                printf("Amount: ");
                scanf("%f", &amount);
                printf("Type (income/expense): ");
                scanf("%s", type);
                add_transaction(description, amount, type);
                break;
            case 2:
                display_transactions();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}