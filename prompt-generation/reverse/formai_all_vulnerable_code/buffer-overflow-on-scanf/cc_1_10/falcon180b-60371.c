//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses yet.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses() {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < num_expenses - 1; i++) {
            if (expenses[i].date > expenses[i+1].date) {
                Expense temp = expenses[i];
                expenses[i] = expenses[i+1];
                expenses[i+1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    printf("Expense Tracker\n");

    int choice = 0;
    while (choice!= 4) {
        printf("\nChoose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Sort expenses\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                sort_expenses();
                printf("Expenses sorted by date.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}