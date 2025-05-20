//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense* expenses[MAX_EXPENSES];
int expenseCount = 0;

void clearBuffer() {
    while (getchar() != '\n');
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }
    
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter expense description: ");
    fgets(newExpense->description, DESCRIPTION_LENGTH, stdin);
    newExpense->description[strcspn(newExpense->description, "\n")] = '\0'; // Remove newline character

    printf("Enter expense amount: ");
    while (scanf("%f", &newExpense->amount) != 1 || newExpense->amount < 0) {
        printf("Invalid amount. Please enter a valid positive number: ");
        clearBuffer();
    }
    clearBuffer(); // Clear the buffer after reading amount

    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n----- Expense List -----\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, expenses[i]->description, expenses[i]->amount);
    }
    printf("------------------------\n");
}

void deleteExpense() {
    if (expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1 to %d): ", expenseCount);
    while (scanf("%d", &index) != 1 || index < 1 || index > expenseCount) {
        printf("Invalid index. Please enter a valid number between 1 and %d: ", expenseCount);
        clearBuffer();
    }
    clearBuffer(); // Clear the buffer after reading index

    index -= 1; // Adjust for 0-based index

    free(expenses[index]); // Free the memory allocated for the expense
    for (int i = index; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1]; // Shift expenses left
    }
    expenseCount--;

    printf("Expense deleted successfully!\n");
}

void freeMemory() {
    for (int i = 0; i < expenseCount; i++) {
        free(expenses[i]); // Free allocated memory for each expense
    }
}

int main() {
    int choice;

    do {
        printf("\n----- Expense Tracker -----\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice. Please choose between 1 and 4: ");
            clearBuffer();
        }
        clearBuffer(); // Clear the buffer after reading choice

        switch(choice) {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (choice != 4);

    freeMemory(); // Free allocated memory before exiting
    return 0;
}