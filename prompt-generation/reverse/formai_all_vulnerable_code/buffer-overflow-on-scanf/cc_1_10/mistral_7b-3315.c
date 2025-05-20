//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
} account;

typedef struct {
    char description[100];
    int month;
    int year;
    account income;
    account expense;
} transaction;

void add_transaction(transaction *transactions, int *num_transactions, int month, int year, char *description, float income, float expense) {
    if (*num_transactions >= 100) {
        printf("Transaction log is full.\n");
        return;
    }

    strcpy(transactions[*num_transactions].description, description);
    transactions[*num_transactions].month = month;
    transactions[*num_transactions].year = year;
    transactions[*num_transactions].income = (account){ .amount = income };
    transactions[*num_transactions].expense = (account){ .amount = expense };
    (*num_transactions)++;
}

void display_transactions(transaction *transactions, int num_transactions) {
    printf("\nTransaction Log - Year %d\n", transactions[0].year);
    for (int i = 0; i < num_transactions; i++) {
        printf("\nMonth %d:\n", transactions[i].month);
        printf("Description: %s\n", transactions[i].description);
        printf("Income: %s %s\n", transactions[i].income.amount > 0 ? "Added" : "Subtracted", transactions[i].income.amount > 0 ? "" : "-");
        printf("%.2f\n", transactions[i].income.amount);
        printf("Expense: %s %s\n", transactions[i].expense.amount > 0 ? "Deducted" : "Added", transactions[i].expense.amount > 0 ? "" : "-");
        printf("%.2f\n", transactions[i].expense.amount);
        printf("------------------------\n");
    }
}

int main() {
    transaction *transactions = NULL;
    int num_transactions = 0;

    printf("Lord's Personal Finance Planner v1.0.0\n\n");

    while (1) {
        int month, year;
        char description[100];
        float income, expense;

        printf("Enter the month (1-12): ");
        scanf("%d", &month);
        printf("Enter the year: ");
        scanf("%d", &year);

        printf("Describe the transaction: ");
        scanf("%s", description);

        printf("Enter the income amount: ");
        scanf("%f", &income);

        printf("Enter the expense amount: ");
        scanf("%f", &expense);

        add_transaction(transactions, &num_transactions, month, year, description, income, expense);

        printf("Do you want to add another transaction? Y/N\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }
    }

    display_transactions(transactions, num_transactions);

    free(transactions);

    return 0;
}