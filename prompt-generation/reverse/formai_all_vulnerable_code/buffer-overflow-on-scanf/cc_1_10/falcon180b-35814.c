//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 50
#define MAX_EXPENSES 100

struct expense {
    char category[50];
    char description[100];
    float amount;
    int date;
};

struct category {
    char name[50];
    int count;
    float total;
};

void addExpense(struct expense expenses[], int *numExpenses) {
    printf("Enter category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter description: ");
    scanf("%s", expenses[*numExpenses].description);
    printf("Enter amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%d", &expenses[*numExpenses].date);
    (*numExpenses)++;
}

void addCategory(struct category categories[], int *numCategories) {
    printf("Enter category name: ");
    scanf("%s", categories[*numCategories].name);
    categories[*numCategories].count = 0;
    categories[*numCategories].total = 0.0;
    (*numCategories)++;
}

void viewExpenses(struct expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s - %.2f - %d\n", expenses[i].category, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void viewCategories(struct category categories[], int numCategories) {
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s - %d expenses - %.2f total\n", categories[i].name, categories[i].count, categories[i].total);
    }
}

void calculateTotal(struct expense expenses[], struct category categories[], int numExpenses, int numCategories) {
    for (int i = 0; i < numExpenses; i++) {
        for (int j = 0; j < numCategories; j++) {
            if (strcmp(expenses[i].category, categories[j].name) == 0) {
                categories[j].count++;
                categories[j].total += expenses[i].amount;
                break;
            }
        }
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    struct category categories[MAX_CATEGORIES];
    int numCategories = 0;

    addCategory(categories, &numCategories);
    addExpense(expenses, &numExpenses);

    while (1) {
        printf("1. Add expense\n2. View expenses\n3. View categories\n4. Calculate total\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                viewCategories(categories, numCategories);
                break;
            case 4:
                calculateTotal(expenses, categories, numExpenses, numCategories);
                viewCategories(categories, numCategories);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}