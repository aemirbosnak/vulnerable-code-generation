//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    float amount;
    char description[MAX_DESC_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense();
void viewExpenses();
void deleteExpense();
void saveExpenses();
void loadExpenses();
void displayMenu();

int main() {
    loadExpenses();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
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
                saveExpenses();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Save Expenses\n");
    printf("5. Exit\n");
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    printf("Enter the expense description: ");
    scanf(" %[^\n]%*c", expenses[expenseCount].description);  // Read string with spaces
    printf("Enter the expense amount: ");
    scanf("%f", &expenses[expenseCount].amount);
    expenseCount++;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nList of Expenses:\n");
    printf("Description\t\tAmount\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%-20s\t%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense() {
    if (expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", expenseCount - 1);
    scanf("%d", &index);
    if (index < 0 || index >= expenseCount) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully!\n");
}

void saveExpenses() {
    FILE *file = fopen("expenses.csv", "w");
    if (file == NULL) {
        printf("Error saving expenses.\n");
        return;
    }
    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s,%.2f\n", expenses[i].description, expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved successfully to expenses.csv!\n");
}

void loadExpenses() {
    FILE *file = fopen("expenses.csv", "r");
    if (file == NULL) {
        printf("No previous expenses found, starting fresh!\n");
        return;
    }
    while (fscanf(file, " %49[^,],%f\n", expenses[expenseCount].description, &expenses[expenseCount].amount) == 2) {
        expenseCount++;
    }
    fclose(file);
    printf("Previous expenses loaded successfully!\n");
}