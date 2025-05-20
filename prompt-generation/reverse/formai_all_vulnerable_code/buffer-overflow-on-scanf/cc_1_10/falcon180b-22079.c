//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[20];
    float amount;
} expense;

void add_expense(expense *expenses, int *count) {
    printf("Enter expense name: ");
    scanf("%s", (*count)? expenses[*count - 1].name : "");
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
}

void display_expenses(expense *expenses, int count) {
    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void sort_expenses(expense *expenses, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (expenses[j].amount < expenses[i].amount) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    expense expenses[MAX_ITEMS];
    int count = 0;

    printf("Enter number of expenses: ");
    scanf("%d", &count);

    printf("\nEnter expenses:\n");
    for (int i = 0; i < count; i++) {
        add_expense(expenses, &count);
    }

    display_expenses(expenses, count);
    sort_expenses(expenses, count);
    display_expenses(expenses, count);

    return 0;
}