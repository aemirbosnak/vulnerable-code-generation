//FormAI DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct expense {
    char date[15];
    char name[50];
    float cost;
};

int main() {
    struct expense expenses[MAX];
    int num_expenses = 0;
    float total_expenses = 0.0;
    char choice, buffer[100];

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nMenu:\n1. Add Expense\n2. View Expenses\n3. Exit\n");
        printf("\nEnter your choice: ");
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%c", &choice);

        switch (choice) {
            case '1':
                if (num_expenses == MAX) {
                    printf("\nMaximum number of expenses reached. Cannot add more expenses.\n");
                    break;
                }
                printf("\nEnter date of expense (in DD/MM/YYYY format): ");
                fgets(expenses[num_expenses].date, 15, stdin);
                printf("Enter name of expense: ");
                fgets(expenses[num_expenses].name, 50, stdin);
                printf("Enter cost of expense: ");
                fgets(buffer, 100, stdin);
                sscanf(buffer, "%f", &expenses[num_expenses].cost);
                total_expenses += expenses[num_expenses].cost;
                num_expenses++;
                printf("\nExpense added successfully!\n");
                break;
            case '2':
                if (num_expenses == 0) {
                    printf("\nNo expenses to display.\n");
                    break;
                }
                printf("\nExpenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("Date: %sName: %sCost: $%.2f\n", expenses[i].date, expenses[i].name, expenses[i].cost);
                }
                printf("Total Expenses: $%.2f\n", total_expenses);
                break;
            case '3':
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}