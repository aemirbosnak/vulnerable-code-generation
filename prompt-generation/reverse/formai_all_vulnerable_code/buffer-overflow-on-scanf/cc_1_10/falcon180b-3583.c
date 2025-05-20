//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    time_t date;
} ExpenseItem;

typedef struct {
    char name[50];
    int numItems;
    ExpenseItem items[MAX_ITEMS];
} ExpenseCategory;

void initCategory(ExpenseCategory* category) {
    category->numItems = 0;
}

void addItem(ExpenseCategory* category, ExpenseItem item) {
    if (category->numItems >= MAX_ITEMS) {
        printf("Category is full\n");
        return;
    }

    category->items[category->numItems++] = item;
}

void printCategory(ExpenseCategory category) {
    printf("Category: %s\n", category.name);
    printf("Number of items: %d\n", category.numItems);
    printf("Items:\n");

    for (int i = 0; i < category.numItems; i++) {
        printf("Name: %s\nAmount: $%.2f\nDate: %s\n",
               category.items[i].name, category.items[i].amount,
               ctime(&category.items[i].date));
    }
}

void initExpenseTracker() {
    ExpenseCategory categories[MAX_CATEGORIES];

    initCategory(categories);

    int choice;
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n2. Add item\n3. Print categories\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter category name: ");
            scanf("%s", categories[0].name);
            break;
        case 2:
            printf("Enter category name: ");
            scanf("%s", categories[0].name);

            ExpenseItem item;
            printf("Enter item name: ");
            scanf("%s", item.name);
            printf("Enter amount: $");
            scanf("%f", &item.amount);
            time(&item.date);
            addItem(categories, item);
            break;
        case 3:
            for (int i = 0; i < MAX_CATEGORIES; i++) {
                if (categories[i].numItems > 0) {
                    printCategory(categories[i]);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

int main() {
    initExpenseTracker();
    return 0;
}