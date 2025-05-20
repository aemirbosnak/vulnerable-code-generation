//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} expense;

void add_expense(expense *expenses, int *num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void display_expenses(expense *expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void sort_expenses(expense *expenses, int num_expenses) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[j].amount < expenses[i].amount) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your expenses:\n");

    while (num_expenses < MAX_EXPENSES) {
        add_expense(expenses, &num_expenses);
        printf("\nDo you want to enter another expense? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    printf("\nYour expenses:\n");
    display_expenses(expenses, num_expenses);

    sort_expenses(expenses, num_expenses);
    printf("\nSorted by amount:\n");
    display_expenses(expenses, num_expenses);

    return 0;
}