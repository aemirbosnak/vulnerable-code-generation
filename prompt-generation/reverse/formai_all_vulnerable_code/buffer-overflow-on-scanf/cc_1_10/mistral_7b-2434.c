//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[50];
    float amount;
} Expense;

typedef struct ExpenseList {
    Expense expenses[100];
    int count;
} ExpenseList;

void inputExpense(ExpenseList *expList) {
    if (expList->count >= 100) {
        printf("Expense list is full.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expList->expenses[expList->count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expList->expenses[expList->count].amount);

    expList->count++;
}

void viewExpenses(ExpenseList expList) {
    printf("\nExpense List:\n");
    for (int i = 0; i < expList.count; i++) {
        printf("%d. %s: %.2f\n", i+1, expList.expenses[i].description, expList.expenses[i].amount);
    }
}

void removeExpense(ExpenseList *expList, int index) {
    if (index < 1 || index > expList->count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index-1; i < expList->count; i++) {
        expList->expenses[i] = expList->expenses[i+1];
    }

    expList->count--;
}

int main() {
    ExpenseList myExpenses = {0};
    int choice, index;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Remove Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputExpense(&myExpenses);
                break;
            case 2:
                viewExpenses(myExpenses);
                break;
            case 3:
                printf("Enter index of expense to remove: ");
                scanf("%d", &index);
                removeExpense(&myExpenses, index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}