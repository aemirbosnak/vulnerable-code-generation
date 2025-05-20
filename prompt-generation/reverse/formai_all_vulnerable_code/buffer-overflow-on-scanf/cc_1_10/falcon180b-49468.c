//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    float amount;
    char category[50];
    char date[20];
} Expense;

void addExpense(Expense* expenses, int* numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[*numExpenses].date);
    (*numExpenses)++;
}

void printExpenses(Expense* expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%.2f\t%s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add expense\n2. Print expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numExpenses >= MAX_EXPENSES) {
                printf("Maximum number of expenses reached.\n");
            } else {
                addExpense(expenses, &numExpenses);
            }
            break;

        case 2:
            printExpenses(expenses, numExpenses);
            break;

        case 3:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}