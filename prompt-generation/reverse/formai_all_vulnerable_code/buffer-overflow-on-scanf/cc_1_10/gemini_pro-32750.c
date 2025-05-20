//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[100];
    float amount;
    int type; // 0 for expenses, 1 for income
} transaction;

int main() {
    // Initialize the program
    int num_transactions = 0;
    transaction transactions[MAX_TRANSACTIONS];

    // Get the user's input
    printf("Welcome to the Personal Finance Planner!\n");
    while (1) {
        printf("Enter a transaction (description, amount, type (0 for expenses, 1 for income)): ");
        scanf("%s %f %d", transactions[num_transactions].description, &transactions[num_transactions].amount, &transactions[num_transactions].type);
        num_transactions++;
        if (num_transactions == MAX_TRANSACTIONS) {
            printf("You have reached the maximum number of transactions. Please save your data and restart the program.\n");
            break;
        }
    }

    // Calculate the total expenses and income
    float total_expenses = 0;
    float total_income = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 0) {
            total_expenses += transactions[i].amount;
        } else {
            total_income += transactions[i].amount;
        }
    }

    // Calculate the net income
    float net_income = total_income - total_expenses;

    // Print the report
    printf("\nPersonal Finance Report\n");
    printf("-------------------------\n");
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Total Income: %.2f\n", total_income);
    printf("Net Income: %.2f\n", net_income);

    // Save the data to a file
    FILE *fp = fopen("transactions.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for (int i = 0; i < num_transactions; i++) {
        fprintf(fp, "%s %.2f %d\n", transactions[i].description, transactions[i].amount, transactions[i].type);
    }
    fclose(fp);

    // Exit the program
    return 0;
}