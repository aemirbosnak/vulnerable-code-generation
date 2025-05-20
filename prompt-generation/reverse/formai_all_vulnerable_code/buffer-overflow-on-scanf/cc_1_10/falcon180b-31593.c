//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
    char category[20];
};

struct Category {
    char name[20];
    float total;
};

void addExpense(struct Expense *expenses, int *numExpenses, struct Category *categories, int *numCategories) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    for (int i = 0; i < *numCategories; i++) {
        if (strcmp(categories[i].name, expenses[*numExpenses].category) == 0) {
            categories[i].total += expenses[*numExpenses].amount;
            break;
        }
    }

    (*numExpenses)++;
}

void addCategory(struct Category *categories, int *numCategories) {
    printf("Enter category name: ");
    scanf("%s", categories[*numCategories].name);
    categories[*numCategories].total = 0;

    (*numCategories)++;
}

void displayExpenses(struct Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s - %.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void displayCategories(struct Category *categories, int numCategories) {
    printf("\nCategories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s - $%.2f\n", categories[i].name, categories[i].total);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    struct Category categories[MAX_CATEGORIES];
    int numCategories = 0;

    addCategory(categories, &numCategories);

    while (numCategories < MAX_CATEGORIES) {
        printf("Do you want to add another category? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            addCategory(categories, &numCategories);
        } else {
            break;
        }
    }

    while (numExpenses < MAX_EXPENSES) {
        addExpense(expenses, &numExpenses, categories, &numCategories);
    }

    displayExpenses(expenses, numExpenses);
    displayCategories(categories, numCategories);

    return 0;
}