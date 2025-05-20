//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void displayExpenses(Expense expenses[], int count);
void displayMenu();
void saveExpensesToFile(Expense expenses[], int count);
void loadExpensesFromFile(Expense expenses[], int *count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    char choice;

    loadExpensesFromFile(expenses, &count);

    do {
        displayMenu();
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addExpense(expenses, &count);
                break;
            case '2':
                displayExpenses(expenses, count);
                break;
            case '3':
                saveExpensesToFile(expenses, count);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count < MAX_EXPENSES) {
        printf("Enter the description of the expense: ");
        scanf(" %[^\n]", expenses[*count].description);
        printf("Enter the amount: ");
        scanf("%f", &expenses[*count].amount);
        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum number of expenses reached. Cannot add more.\n");
    }
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }
    printf("\nList of Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void displayMenu() {
    printf("\n=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Save Expenses to File\n");
    printf("4. Exit\n");
}

void saveExpensesToFile(Expense expenses[], int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s - $%.2f\n", expenses[i].description, expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void loadExpensesFromFile(Expense expenses[], int *count) {
    FILE *file = fopen("expenses.txt", "r");
    if (file) {
        while (fscanf(file, " %[^\n] - $%f\n", expenses[*count].description, &expenses[*count].amount) == 2) {
            (*count)++;
            if (*count >= MAX_EXPENSES) {
                break; // Stop if we reach the max count
            }
        }
        fclose(file);
        printf("Loaded %d expenses from file.\n", *count);
    } else {
        printf("No previous expenses found. Starting fresh!\n");
    }
}