//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_AMOUNT_LENGTH 20
#define MAX_TRANSACTION_TYPE_LENGTH 20
#define MAX_TRANSACTION_DATE_LENGTH 20

typedef struct {
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    char transaction_type[MAX_TRANSACTION_TYPE_LENGTH];
    char transaction_date[MAX_TRANSACTION_DATE_LENGTH];
    char transaction_amount[MAX_TRANSACTION_AMOUNT_LENGTH];
} Transaction;

Transaction transactions[MAX_ROWS];
int num_transactions = 0;

void add_transaction() {
    if (num_transactions >= MAX_ROWS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%s", transactions[num_transactions].account_number);

    printf("Enter name: ");
    scanf("%s", transactions[num_transactions].name);

    printf("Enter transaction type: ");
    scanf("%s", transactions[num_transactions].transaction_type);

    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", transactions[num_transactions].transaction_date);

    printf("Enter transaction amount: ");
    scanf("%s", transactions[num_transactions].transaction_amount);

    num_transactions++;
}

void display_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        printf("\nAccount number: %s\n", transactions[i].account_number);
        printf("Name: %s\n", transactions[i].name);
        printf("Transaction type: %s\n", transactions[i].transaction_type);
        printf("Transaction date: %s\n", transactions[i].transaction_date);
        printf("Transaction amount: %s\n\n", transactions[i].transaction_amount);
    }
}

int main() {
    printf("Welcome to the banking record system!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add transaction\n");
        printf("2. Display transactions\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                display_transactions();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}