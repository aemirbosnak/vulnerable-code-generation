//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]%*c", expenses[expenseCount].description);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[expenseCount].amount);
        expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense list is full!\n");
    }
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses logged yet!\n");
        return;
    }
    printf("\nYour Expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense() {
    if (expenseCount == 0) {
        printf("No expenses to delete!\n");
        return;
    }
    int index;
    viewExpenses();
    printf("Enter the number of the expense to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > expenseCount) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully!\n");
}

void calculateTotalExpenses() {
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void menu() {
    printf("=========================================\n");
    printf("       Expense Tracker Menu\n");
    printf("=========================================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Exit\n");
    printf("=========================================\n");
}

int main() {
    int choice;
    
    do {
        menu();
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
                calculateTotalExpenses();
                break;
            case 5:
                printf("Exiting Expense Tracker. Keep tracking your spending!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}