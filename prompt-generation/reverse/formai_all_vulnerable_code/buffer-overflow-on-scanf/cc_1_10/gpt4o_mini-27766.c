//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LEN 100

typedef struct {
    char description[DESCRIPTION_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseList;

void addExpense(ExpenseList* list) {
    if (list->count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense description: ");
    getchar();  // Consume newline
    fgets(newExpense.description, DESCRIPTION_LEN, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    list->expenses[list->count++] = newExpense;
    printf("Expense added!\n");
}

void viewExpenses(const ExpenseList* list) {
    if (list->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, list->expenses[i].description, list->expenses[i].amount);
    }
}

void deleteExpense(ExpenseList* list) {
    if (list->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > list->count) {
        printf("Invalid expense number!\n");
        return;
    }

    for (int i = index - 1; i < list->count - 1; i++) {
        list->expenses[i] = list->expenses[i + 1];
    }
    list->count--;
    printf("Expense deleted!\n");
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

int main() {
    ExpenseList expenseList;
    expenseList.count = 0;

    while (1) {
        displayMenu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&expenseList);
                break;
            case 2:
                viewExpenses(&expenseList);
                break;
            case 3:
                deleteExpense(&expenseList);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}