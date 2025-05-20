//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int month;
    int year;
} Transaction;

void print_menu() {
    printf("---------------------\n");
    printf("| Personal Finance |\n");
    printf("|      Planner     |\n");
    printf("---------------------\n");
    printf("1. Add transaction\n");
    printf("2. List transactions\n");
    printf("3. Calculate balance\n");
    printf("4. Save and exit\n");
}

void add_transaction(Transaction transactions[], int *num_transactions, char name[], float amount, int month, int year) {
    if (*num_transactions < MAX_TRANSACTIONS) {
        strcpy(transactions[*num_transactions].name, name);
        transactions[*num_transactions].amount = amount;
        transactions[*num_transactions].month = month;
        transactions[*num_transactions].year = year;
        (*num_transactions)++;
    } else {
        printf("Max number of transactions reached.\n");
    }
}

void list_transactions(Transaction transactions[], int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s %d/%d - %.2f\n", transactions[i].name, transactions[i].month, transactions[i].year, transactions[i].amount);
    }
}

void calculate_balance(Transaction transactions[], int num_transactions, float *balance) {
    *balance = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        *balance += transactions[i].amount;
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    float balance = 0.0;
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;
    int month, year;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter month: ");
                scanf("%d", &month);
                printf("Enter year: ");
                scanf("%d", &year);
                add_transaction(transactions, &num_transactions, name, amount, month, year);
                break;
            case 2:
                list_transactions(transactions, num_transactions);
                break;
            case 3:
                calculate_balance(transactions, num_transactions, &balance);
                printf("Current balance: %.2f\n", balance);
                break;
            case 4:
                printf("Saving and exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}