//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char category[20];
    float amount;
    char date[11];
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    struct expense e;

    printf("Enter category: ");
    scanf("%s", e.category);

    printf("Enter amount: ");
    scanf("%f", &e.amount);

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", e.date);

    expenses[num_expenses++] = e;

    printf("\nExpense added successfully!\n");
}

void print_expenses() {
    if (num_expenses == 0) {
        printf("\nNo expenses to display.\n");
        return;
    }

    printf("\nExpenses:\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f (%s)\n", i+1, expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}