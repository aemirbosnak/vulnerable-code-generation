//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

typedef struct {
    char name[50];
    int count;
} Category;

void addExpense(Expense* expenses, int numExpenses, Category* categories, int numCategories) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);
    printf("Enter expense category (0-%d): ", numCategories-1);
    scanf("%d", &expenses[numExpenses].category);
}

void addCategory(Category* categories, int numCategories) {
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    categories[numCategories].count = 0;
    numCategories++;
}

void printExpenses(Expense* expenses, int numExpenses, Category* categories, int numCategories) {
    printf("\nExpenses:\n");
    for(int i=0; i<numExpenses; i++) {
        printf("%s - $%.2f (Category: %s)\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category].name);
    }
}

void printCategories(Category* categories, int numCategories) {
    printf("\nCategories:\n");
    for(int i=0; i<numCategories; i++) {
        printf("%s - %d expenses\n", categories[i].name, categories[i].count);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    Category categories[MAX_CATEGORIES];
    int numExpenses = 0, numCategories = 0;

    addCategory(categories, numCategories);

    while(numExpenses < MAX_EXPENSES) {
        addExpense(expenses, numExpenses, categories, numCategories);
        numExpenses++;
    }

    while(1) {
        printf("\nOptions:\n1. Add expense\n2. Print expenses\n3. Print categories\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(numExpenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    addExpense(expenses, numExpenses, categories, numCategories);
                    numExpenses++;
                }
                break;
            case 2:
                printExpenses(expenses, numExpenses, categories, numCategories);
                break;
            case 3:
                printCategories(categories, numCategories);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}