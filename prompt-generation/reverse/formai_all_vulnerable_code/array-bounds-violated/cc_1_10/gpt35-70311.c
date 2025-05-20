//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[20];
    double amount;
} Expense;

typedef struct {
    char name[20];
    Expense expenses[MAX_EXPENSES];
    int numExpenses;
} Category;

int numCategories = 0;
Category categories[MAX_CATEGORIES];

void addExpense(char* categoryName, Expense expense) {
    int i;
    for (i = 0; i < numCategories; i++) {
        if (strcmp(categories[i].name, categoryName) == 0) {
            categories[i].expenses[categories[i].numExpenses++] = expense;
            printf("Expense added to category %s.\n", categoryName);
            return;
        }
    }
    printf("Category %s does not exist.\n", categoryName);
}

void printExpenses() {
    int i, j;
    printf("Expenses\n");
    for (i = 0; i < numCategories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (j = 0; j < categories[i].numExpenses; j++) {
            printf("\t%s: %.2f\n", categories[i].expenses[j].name, categories[i].expenses[j].amount);
        }
    }
}

void addCategory(char* categoryName) {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Maximum number of categories reached.\n");
        return;
    }
    int i;
    for (i = 0; i < numCategories; i++) {
        if (strcmp(categories[i].name, categoryName) == 0) {
            printf("Category %s already exists.\n", categoryName);
            return;
        }
    }
    strcpy(categories[numCategories++].name, categoryName);
    printf("Category %s added.\n", categoryName);
}

int main() {
    char buffer[100];
    while (1) {
        printf("\n1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Print expenses\n");
        printf("4. Exit\n");

        int choice;
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter category name: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strlen(buffer) - 1] = '\0';
            addCategory(buffer);
            break;
        case 2: {
            printf("Enter category name: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strlen(buffer) - 1] = '\0';
            char categoryName[20];
            strcpy(categoryName, buffer);

            printf("Enter expense name: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strlen(buffer) - 1] = '\0';
            char expenseName[20];
            strcpy(expenseName, buffer);

            printf("Enter expense amount: ");
            fgets(buffer, sizeof(buffer), stdin);
            double expenseAmount;
            sscanf(buffer, "%lf", &expenseAmount);

            Expense expense;
            strcpy(expense.name, expenseName);
            expense.amount = expenseAmount;
            addExpense(categoryName, expense);
            break;
        }
        case 3:
            printExpenses();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}