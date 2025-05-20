//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense description: ");
    getchar(); // Clear newline from buffer
    fgets(expenses[*count].description, DESCRIPTION_LENGTH, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet. Go ahead and add some!\n");
        return;
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("----------------\n");
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1-%d): ", *count);
    scanf("%d", &index); 

    if (index < 1 || index > *count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully!\n");
}

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    while (1) {
        clearScreen();
        printf("=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("========================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                deleteExpense(expenses, &expenseCount);
                break;
            case 4:
                printf("Exiting the program. Keep track of your finances!\n");
                exit(0);
            default:
                printf("Invalid option, please select a valid one!\n");
                break;
        }
        printf("Press Enter to continue...");
        getchar(); // Wait for Enter key
        getchar(); // To consume the newline
    }

    return 0;
}