//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Expense tracker is full. Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    fgets(expenses[num_expenses].name, MAX_NAME_LEN, stdin);
    expenses[num_expenses].name[strcspn(expenses[num_expenses].name, "\n")] = '\0';

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;

    printf("Expense added successfully!\n");
}

void list_expenses() {
    if (num_expenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("\nExpense Tracker:\n");
    printf("------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("---------------\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                printf("Thank you for using Expense Tracker. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}