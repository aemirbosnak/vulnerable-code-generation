//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - $%.2f - %d\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses_by_date() {
    for (int i = 0; i < num_expenses-1; i++) {
        for (int j = i+1; j < num_expenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

void sort_expenses_by_amount() {
    for (int i = 0; i < num_expenses-1; i++) {
        for (int j = i+1; j < num_expenses; j++) {
            if (expenses[i].amount > expenses[j].amount) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    add_expense();
    add_expense();
    add_expense();
    display_expenses();
    sort_expenses_by_date();
    printf("\nSorted by date:\n");
    display_expenses();
    sort_expenses_by_amount();
    printf("\nSorted by amount:\n");
    display_expenses();
    return 0;
}