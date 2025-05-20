//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char date[20];
    float amount;
} Expense;

void add_expense(Expense *expenses, int *num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[*num_expenses].date);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void display_expenses(Expense *expenses, int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - %s - $%.2f\n", i+1, expenses[i].name, expenses[i].date, expenses[i].amount);
    }
}

void sort_expenses(Expense *expenses, int num_expenses) {
    for (int i = 0; i < num_expenses-1; i++) {
        for (int j = i+1; j < num_expenses; j++) {
            if (expenses[j].date < expenses[i].date) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("How many expenses would you like to track? (Maximum %d): ", MAX_EXPENSES);
    scanf("%d", &num_expenses);

    printf("\nEnter your expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        add_expense(expenses, &num_expenses);
    }

    printf("\nSorted expenses by date:\n");
    sort_expenses(expenses, num_expenses);
    display_expenses(expenses, num_expenses);

    return 0;
}