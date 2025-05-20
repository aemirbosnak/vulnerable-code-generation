//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 20
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    item items[MAX_ITEMS];
    int numItems;
} category;

category categories[MAX_CATEGORIES];
int numCategories;

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    numCategories++;
}

void addItem() {
    printf("Enter item name: ");
    scanf("%s", categories[numCategories-1].items[categories[numCategories-1].numItems].name);
    printf("Enter item amount: $");
    scanf("%f", &categories[numCategories-1].items[categories[numCategories-1].numItems].amount);
    categories[numCategories-1].numItems++;
}

void displayCategories() {
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void displayItems(category cat) {
    printf("Items in %s:\n", cat.name);
    for (int i = 0; i < cat.numItems; i++) {
        printf("%s: $%.2f\n", cat.items[i].name, cat.items[i].amount);
    }
}

int main() {
    numCategories = 0;
    printf("Welcome to Personal Finance Planner!\n");
    while (1) {
        printf("\n1. Add Category\n2. Add Item\n3. Display Categories\n4. Display Items\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (numCategories >= MAX_CATEGORIES) {
                    printf("Maximum number of categories reached.\n");
                } else {
                    addCategory();
                }
                break;
            case 2:
                if (numCategories == 0) {
                    printf("No categories added yet.\n");
                } else {
                    addItem();
                }
                break;
            case 3:
                displayCategories();
                break;
            case 4:
                printf("Enter category name: ");
                scanf("%s", categories[numCategories-1].name);
                displayItems(categories[numCategories-1]);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}