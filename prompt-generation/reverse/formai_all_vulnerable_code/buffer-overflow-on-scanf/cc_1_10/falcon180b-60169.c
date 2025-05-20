//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int count;
} ExpenseItem;

typedef struct {
    char name[50];
    int numItems;
    ExpenseItem items[MAX_ITEMS];
} ExpenseCategory;

void addItem(ExpenseCategory *category) {
    ExpenseItem item;
    int i;

    printf("Enter item name: ");
    scanf("%s", item.name);

    for (i = 0; i < category->numItems; i++) {
        if (strcmp(item.name, category->items[i].name) == 0) {
            category->items[i].count++;
            return;
        }
    }

    if (category->numItems >= MAX_ITEMS) {
        printf("Too many items in category.\n");
        return;
    }

    category->items[category->numItems] = item;
    category->numItems++;
}

void printCategory(ExpenseCategory *category) {
    int i;

    printf("Category: %s\n", category->name);
    for (i = 0; i < category->numItems; i++) {
        printf("%s: %d\n", category->items[i].name, category->items[i].count);
    }
}

int main() {
    ExpenseCategory categories[MAX_CATEGORIES];
    int numCategories, i;

    numCategories = 0;
    while (numCategories < MAX_CATEGORIES) {
        printf("Enter category name: ");
        scanf("%s", categories[numCategories].name);
        numCategories++;
    }

    int choice;
    while (1) {
        printf("1. Add item\n2. Print category\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter category name: ");
            scanf("%s", categories[numCategories - 1].name);

            addItem(&categories[numCategories - 1]);
        } else if (choice == 2) {
            printf("Enter category name: ");
            scanf("%s", categories[numCategories - 1].name);

            printCategory(&categories[numCategories - 1]);
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}