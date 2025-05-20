//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char type[100];
    float amount;
    char date[100];
};

// Function to print a single expense
void printExpense(struct Expense e) {
    printf("%-20s $%-10.2f %s\n", e.type, e.amount, e.date);
}

// Function to add an expense to the list
void addExpense(struct Expense expenses[], int *numExpenses) {
    printf("Enter expense type: ");
    scanf("%s", expenses[*numExpenses].type);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense date: ");
    scanf("%s", expenses[*numExpenses].date);
    (*numExpenses)++;
}

// Function to print all expenses
void printAllExpenses(struct Expense expenses[], int numExpenses) {
    printf("%-20s %-10s %s\n", "Expense Type", "Amount", "Date");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }
}

// Function to print expenses within a given date range
void printExpensesWithinRange(struct Expense expenses[], int numExpenses, char startDate[], char endDate[]) {
    printf("%-20s %-10s %s\n", "Expense Type", "Amount", "Date");
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, startDate) >= 0 && strcmp(expenses[i].date, endDate) <= 0) {
            printExpense(expenses[i]);
        }
    }
}

int main() {
    struct Expense expenses[100];
    int numExpenses = 0;
    int choice;
    char startDate[100];
    char endDate[100];

    while (1) {
        printf("\n1. Add expense\n2. Print all expenses\n3. Print expenses within a date range\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printAllExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Enter start date: ");
                scanf("%s", startDate);
                printf("Enter end date: ");
                scanf("%s", endDate);
                printExpensesWithinRange(expenses, numExpenses, startDate, endDate);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}