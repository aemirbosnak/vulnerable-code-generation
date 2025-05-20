//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    float amount;
} ExpenseItem;

ExpenseItem expenses[MAX_ITEMS];
char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int numCategories;
int numItems;

void addCategory() {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[numCategories]);
    numCategories++;
}

void addItem() {
    if (numItems >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    int categoryIndex = -1;
    printf("Enter category for this item (or -1 for no category): ");
    scanf("%d", &categoryIndex);

    if (categoryIndex >= 0 && categoryIndex < numCategories) {
        strcpy(expenses[numItems].category, categories[categoryIndex]);
    } else {
        strcpy(expenses[numItems].category, "No category");
    }

    printf("Enter item name: ");
    scanf("%s", expenses[numItems].name);

    printf("Enter item amount: $");
    scanf("%f", &expenses[numItems].amount);

    numItems++;
}

void displayItems() {
    printf("\nExpense items:\n");
    printf("--------------------\n");
    printf("Category\tItem\t\tAmount\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t%s\t\t$%.2f\n", expenses[i].category, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n\n");

    numCategories = 0;
    numItems = 0;

    addCategory();
    addCategory();
    addCategory();

    addItem();
    addItem();
    addItem();

    displayItems();

    return 0;
}