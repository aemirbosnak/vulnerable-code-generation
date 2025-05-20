//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME 50

// Define structures
typedef struct {
    char name[MAX_NAME];
    float amount;
} Item;

typedef struct {
    char name[MAX_NAME];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

// Function to initialize category
void init_category(Category *category) {
    category->num_items = 0;
    strcpy(category->name, "");
}

// Function to add item to category
void add_item(Category *category, Item *item) {
    category->items[category->num_items++] = *item;
}

// Function to print category
void print_category(Category *category) {
    printf("Category: %s\n", category->name);
    for (int i = 0; i < category->num_items; i++) {
        printf("Item %d: %s - $%.2f\n", i + 1, category->items[i].name, category->items[i].amount);
    }
}

// Function to initialize item
void init_item(Item *item) {
    strcpy(item->name, "");
    item->amount = 0.0;
}

// Function to prompt user for item name and amount
void get_item(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item amount: $");
    scanf("%f", &item->amount);
}

// Function to initialize category with items
void init_category_items(Category *category) {
    category->num_items = 0;
    strcpy(category->name, "");
}

// Function to prompt user for category name and items
void get_category_items(Category *category) {
    printf("Enter category name: ");
    scanf("%s", category->name);
    printf("Enter number of items: ");
    scanf("%d", &category->num_items);
    for (int i = 0; i < category->num_items; i++) {
        Item item;
        init_item(&item);
        get_item(&item);
        add_item(category, &item);
    }
}

// Function to print categories and items
void print_categories_items() {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        Category category;
        init_category(&category);
        printf("Category %d:\n", i + 1);
        get_category_items(&category);
        print_category(&category);
        printf("\n");
    }
}

// Main function
int main() {
    print_categories_items();
    return 0;
}