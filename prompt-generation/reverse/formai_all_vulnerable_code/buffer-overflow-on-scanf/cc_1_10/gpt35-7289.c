//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CHARACTERS 50

typedef struct {
    char category[MAX_CHARACTERS];
    double amount;
} Expense;

int total_expenses = 0;
Expense expenses[MAX_ITEMS];

void addExpense() {
    printf("Enter category of expense: ");
    char category[MAX_CHARACTERS];
    scanf("%s", category);

    double amount;
    printf("Enter amount of expense: ");
    scanf("%lf", &amount);

    Expense newExpense;
    strcpy(newExpense.category, category);
    newExpense.amount = amount;

    expenses[total_expenses] = newExpense;
    total_expenses++;

    printf("Expense added successfully!\n");
}

void viewExpenses() {
    printf("%-15sAmount\n", "Category");
    printf("--------------------\n");

    double total_amount = 0;
    
    for (int i = 0; i < total_expenses; i++) {
        printf("%-15s$%.2f\n", expenses[i].category, expenses[i].amount);
        total_amount += expenses[i].amount;
    }

    printf("--------------------\n");
    printf("%-15s$%.2f\n", "Total", total_amount);
}

int main() {
    printf("Welcome to Expense Tracker!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1 - Add expense\n");
        printf("2 - View expenses\n");
        printf("3 - Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}