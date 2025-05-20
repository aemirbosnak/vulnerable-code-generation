//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

void addExpense(Expense *expenses, int *expenseCount);
void viewExpenses(Expense *expenses, int expenseCount);
float calculateTotal(Expense *expenses, int expenseCount);

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                printf("Total Expense: %.2f\n", calculateTotal(expenses, expenseCount));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addExpense(Expense *expenses, int *expenseCount) {
    if (*expenseCount >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*expenseCount].amount);
    
    (*expenseCount)++;
    printf("Expense added: %s - %.2f\n", expenses[*expenseCount - 1].description, expenses[*expenseCount - 1].amount);
}

void viewExpenses(Expense *expenses, int expenseCount) {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nList of Expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s - %.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

float calculateTotal(Expense *expenses, int expenseCount) {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}