//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *expenseCount) {
    if (*expenseCount >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached!\n");
        return;
    }

    Expense newExpense;
    printf("Enter Category: ");
    scanf("%s", newExpense.category);
    printf("Enter Description: ");
    scanf("%s", newExpense.description);
    printf("Enter Amount: ");
    scanf("%f", &newExpense.amount);

    expenses[*expenseCount] = newExpense;
    (*expenseCount)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int expenseCount) {
    if (expenseCount == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n---- Expenses ----\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Category: %s | Description: %s | Amount: %.2f\n",
               expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    printf("-------------------\n");
}

float calculateTotal(Expense expenses[], int expenseCount) {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void deleteExpense(Expense expenses[], int *expenseCount) {
    if (*expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", *expenseCount - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *expenseCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < *expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*expenseCount)--;
    printf("Expense deleted successfully!\n");
}

void menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3: {
                float total = calculateTotal(expenses, expenseCount);
                printf("Total Expenses: %.2f\n", total);
                break;
            }
            case 4:
                deleteExpense(expenses, &expenseCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}