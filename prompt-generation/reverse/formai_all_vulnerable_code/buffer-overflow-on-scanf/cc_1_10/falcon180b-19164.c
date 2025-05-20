//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int count;
} Category;

typedef struct {
    char name[MAX_NAME];
    int price;
    int category;
} Item;

Category categories[MAX_CATEGORIES];
Item items[MAX_ITEMS];
int num_categories;
int num_items;

void add_category() {
    printf("Enter the name of the category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].count = 0;
    num_categories++;
}

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the price of the item: ");
    scanf("%d", &items[num_items].price);
    printf("Enter the category of the item (0-9): ");
    scanf("%d", &items[num_items].category);
    categories[items[num_items].category].count++;
    num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s - %d items\n", i+1, categories[i].name, categories[i].count);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d - Category: %d\n", i+1, items[i].name, items[i].price, items[i].category);
    }
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s - $%d\n", categories[i].name, categories[i].count * items[0].price);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    num_categories = 0;
    num_items = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("\nDo you want to add a category? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_category();
        }
    }

    while (num_items < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_item();
        }
    }

    display_categories();
    display_items();
    display_expenses();

    return 0;
}