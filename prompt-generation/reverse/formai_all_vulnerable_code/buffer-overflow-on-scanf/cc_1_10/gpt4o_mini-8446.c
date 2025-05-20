//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[30];
    float amount;
} Expense;

typedef struct {
    char category[30];
    Expense expenses[MAX_EXPENSES];
    int expenseCount;
} ExpenseCategory;

ExpenseCategory categories[MAX_CATEGORIES];
int categoryCount = 0;

void addCategory(const char *categoryName) {
    strcpy(categories[categoryCount].category, categoryName);
    categories[categoryCount].expenseCount = 0;
    categoryCount++;
}

void addExpense(const char *categoryName, const char *expenseName, float amount) {
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].category, categoryName) == 0) {
            strcpy(categories[i].expenses[categories[i].expenseCount].name, expenseName);
            categories[i].expenses[categories[i].expenseCount].amount = amount;
            categories[i].expenseCount++;
            return;
        }
    }
    printf("Category not found!\n");
}

void viewExpenses(const char *categoryName) {
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].category, categoryName) == 0) {
            printf("Expenses for category '%s':\n", categoryName);
            for (int j = 0; j < categories[i].expenseCount; j++) {
                printf("- %s: $%.2f\n", categories[i].expenses[j].name, categories[i].expenses[j].amount);
            }
            return;
        }
    }
    printf("Category not found!\n");
}

void viewTotalExpenses() {
    float total = 0.0;
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < categories[i].expenseCount; j++) {
            total += categories[i].expenses[j].amount;
        }
    }
    printf("Total expenses: $%.2f\n", total);
}

void viewSummary() {
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s\n", categories[i].category);
        viewExpenses(categories[i].category);
        printf("\n");
    }
}

int main() {
    int choice;
    char categoryName[30], expenseName[30];
    float amount;

    while (1) {
        printf("Expense Tracker Menu:\n");
        printf("1. Add Expense Category\n");
        printf("2. Add Expense\n");
        printf("3. View Expenses by Category\n");
        printf("4. View Total Expenses\n");
        printf("5. View Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter category name: ");
                scanf("%s", categoryName);
                addCategory(categoryName);
                printf("Category '%s' added successfully!\n", categoryName);
                break;
            case 2:
                printf("Enter category name: ");
                scanf("%s", categoryName);
                printf("Enter expense name: ");
                scanf("%s", expenseName);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(categoryName, expenseName, amount);
                printf("Expense '%s' added to category '%s'!\n", expenseName, categoryName);
                break;
            case 3:
                printf("Enter category name: ");
                scanf("%s", categoryName);
                viewExpenses(categoryName);
                break;
            case 4:
                viewTotalExpenses();
                break;
            case 5:
                viewSummary();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }

    return 0;
}