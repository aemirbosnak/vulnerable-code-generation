//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
    int month;
    int year;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int current_transaction = 0;
float current_balance = 0.0;

void add_transaction(char *description, float amount, int month, int year) {
    transactions[current_transaction].amount = amount;
    strcpy(transactions[current_transaction].description, description);
    transactions[current_transaction].month = month;
    transactions[current_transaction].year = year;
    current_balance += amount;
    current_transaction++;
}

void display_balance() {
    printf("\nCurrent Balance: %.2f", current_balance);
}

void display_transactions() {
    int i;
    printf("\nTransactions:\n");
    for (i = 0; i < current_transaction; i++) {
        printf("%s (%d/%d) %.2f\n", transactions[i].description, transactions[i].month, transactions[i].year, transactions[i].amount);
    }
}

void display_averages() {
    int total_months = 0;
    float total_income = 0.0, total_expenses = 0.0;

    for (int i = 0; i < current_transaction; i++) {
        if (transactions[i].amount > 0) {
            total_income += transactions[i].amount;
        } else {
            total_expenses += transactions[i].amount;
        }
        total_months++;
    }

    float average_balance = current_balance / total_months;
    printf("\nAverage Monthly Balance: %.2f", average_balance);
}

int main() {
    char description[50];
    int month, year;
    float amount;

    while (1) {
        printf("\nPersonal Finance Planner\n"
               "1. Add Transaction\n"
               "2. Display Balance\n"
               "3. Display Transactions\n"
               "4. Display Average Balance\n"
               "5. Exit\n"
               "Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf("%s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter month: ");
                scanf("%d", &month);
                printf("Enter year: ");
                scanf("%d", &year);
                add_transaction(description, amount, month, year);
                break;
            case 2:
                display_balance();
                break;
            case 3:
                display_transactions();
                break;
            case 4:
                display_averages();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}