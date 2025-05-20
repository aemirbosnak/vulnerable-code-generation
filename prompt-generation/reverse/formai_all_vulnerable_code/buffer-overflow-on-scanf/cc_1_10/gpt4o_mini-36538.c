//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    scanf("%s", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    expenses[expenseCount] = newExpense;
    expenseCount++;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("----- Expenses -----\n");
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("--------------------\n");
    printf("Total Expenses: $%.2f\n", total);
}

void deleteExpense() {
    if (expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1 - %d): ", expenseCount);
    scanf("%d", &index);

    if (index < 1 || index > expenseCount) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully!\n");
}

void saveExpensesToFile() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s %.2f\n", expenses[i].description, expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to 'expenses.txt'\n");
}

void loadExpensesFromFile() {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expense records found.\n");
        return;
    }

    while (fscanf(file, "%s %f", expenses[expenseCount].description, &expenses[expenseCount].amount) != EOF) {
        expenseCount++;
        if (expenseCount >= MAX_EXPENSES) {
            printf("Expense limit reached while loading from file.\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded successfully from 'expenses.txt'\n");
}

void displayMenu() {
    printf("\n----- Expense Tracker -----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;

    loadExpensesFromFile();

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                saveExpensesToFile();
                break;
            case 5:
                loadExpensesFromFile();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}