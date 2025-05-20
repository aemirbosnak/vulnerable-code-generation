//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
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
        printf("Expense tracker is full.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYYMM): ");
    scanf("%d", &expenses[num_expenses].date);

    num_expenses++;
}

void print_expenses() {
    printf("\nExpense Tracker\n");
    printf("-----------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("Expense %d:\n", i + 1);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %d\n", expenses[i].date);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker Menu\n");
        printf("----------------------\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}