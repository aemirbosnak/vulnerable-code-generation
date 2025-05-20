//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

struct expense {
    char category[MAX_LENGTH];
    double amount;
};

void add_expense(struct expense expenses[], int* size);
void display_expenses(struct expense expenses[], int size);
void display_total(struct expense expenses[], int size);

int main() {
    struct expense expenses[MAX_LENGTH];
    int size = 0;
    char choice;

    printf("Welcome to Expense Tracker!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("(a)dd an expense\n");
        printf("(d)isplay expenses\n");
        printf("(t)otal expenses\n");
        printf("(q)uit\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_expense(expenses, &size);
                break;
            case 'd':
                display_expenses(expenses, size);
                break;
            case 't':
                display_total(expenses, size);
                break;
            case 'q':
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_expense(struct expense expenses[], int* size) {
    printf("Enter the category for this expense: ");
    scanf("%s", expenses[*size].category);
    printf("Enter the amount of the expense: ");
    scanf("%lf", &expenses[*size].amount);
    *size += 1;
}

void display_expenses(struct expense expenses[], int size) {
    if (size == 0) {
        printf("\nYou have no expenses recorded.\n");
        return;
    }
    printf("\nExpenses:\n");
    printf("%-20s%-10s\n", "Category", "Amount");
    for (int i = 0; i < size; i++) {
        printf("%-20s%-10.2f\n", expenses[i].category, expenses[i].amount);
    }
}

void display_total(struct expense expenses[], int size) {
    if (size == 0) {
        printf("\nYou have no expenses recorded.\n");
        return;
    }
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2f\n", total);
}