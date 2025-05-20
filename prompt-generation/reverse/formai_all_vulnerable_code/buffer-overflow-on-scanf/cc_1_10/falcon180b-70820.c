//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[20];
} expense;

void add_expense(expense* expenses, int num_expenses, char* name, float amount, char* date) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);
    num_expenses++;
}

void display_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char name[50];
    float amount;
    char date[20];

    while (1) {
        printf("Enter name of expense: ");
        scanf("%s", name);
        printf("Enter amount: ");
        scanf("%f", &amount);
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
        add_expense(expenses, num_expenses, name, amount, date);
    }

    display_expenses(expenses, num_expenses);

    return 0;
}