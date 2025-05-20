//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    (*numExpenses)++;
}

void viewExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void deleteExpense(Expense *expenses, int *numExpenses) {
    printf("\nEnter expense name to delete: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < *numExpenses; i++) {
        if (strcmp(name, expenses[i].name) == 0) {
            for (int j = i; j < *numExpenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            (*numExpenses)--;
            break;
        }
    }
}

void calculateTotal(Expense *expenses, int numExpenses) {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2f\n", total);
}

int main() {
    Expense expenses[MAX_ITEMS];
    int numExpenses = 0;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n2. View expenses\n3. Delete expense\n4. Calculate total\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                deleteExpense(expenses, &numExpenses);
                break;
            case 4:
                calculateTotal(expenses, numExpenses);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}