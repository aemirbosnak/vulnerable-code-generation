//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void removeExpense(Expense expenses[], int *count);
void viewExpenses(const Expense expenses[], int count);
void clearInputBuffer();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== Expense Tracker =====\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. View Expenses\n");
        printf("4. Exit\n");
        printf("==========================\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                removeExpense(expenses, &count);
                break;
            case 3:
                viewExpenses(expenses, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please select from the menu.\n");
        }
    }
    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Maximum expense limit reached. Cannot add more expenses.\n");
        return;
    }

    float amount;

    printf("Enter expense description (max %d characters): ", MAX_DESC_LENGTH - 1);
    clearInputBuffer();
    fgets(expenses[*count].description, sizeof(expenses[*count].description), stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount. Please try again.\n");
        clearInputBuffer();
        return;
    }
    expenses[*count].amount = amount;
    
    (*count)++;
    printf("Expense added successfully!\n");
}

void removeExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to remove.\n");
        return;
    }

    int index;

    printf("Select the expense index to remove (0 to %d): ", *count - 1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= *count) {
        printf("Invalid index. Please try again.\n");
        clearInputBuffer();
        return;
    }

    // Shift expenses down
    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    
    (*count)--;
    printf("Expense removed successfully!\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n===== Expenses =====\n");
    for (int i = 0; i < count; i++) {
        printf("Index %d: %s - $%.2f\n", i, expenses[i].description, expenses[i].amount);
    }
    printf("=====================\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}