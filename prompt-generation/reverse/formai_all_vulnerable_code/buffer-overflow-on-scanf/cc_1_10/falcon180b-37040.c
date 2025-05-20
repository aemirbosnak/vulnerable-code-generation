//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME_LENGTH 50
#define MAX_EXPENSE_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    char amount[MAX_EXPENSE_AMOUNT_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < num_expenses; i++) {
        expenses[i].name[0] = '\0';
        expenses[i].amount[0] = '\0';
    }

    int choice;
    do {
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (true);

    return 0;
}