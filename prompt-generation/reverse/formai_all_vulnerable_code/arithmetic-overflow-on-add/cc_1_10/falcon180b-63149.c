//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

// Struct to hold a category
typedef struct {
    char name[MAX_NAME_LEN];
    int num_items;
    float total_cost;
} category;

// Struct to hold an item
typedef struct {
    char name[MAX_NAME_LEN];
    float cost;
} item;

// Function to add a new category
void add_category(category* categories, int num_categories, char* name) {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    strcpy(categories[num_categories].name, name);
    categories[num_categories].num_items = 0;
    categories[num_categories].total_cost = 0;

    num_categories++;
}

// Function to add a new item to a category
void add_item(item* items, int num_items, category* categories, int num_categories, char* name, float cost) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].cost = cost;

    int category_index = -1;
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            category_index = i;
            break;
        }
    }

    if (category_index == -1) {
        add_category(categories, num_categories, name);
        category_index = num_categories - 1;
    }

    categories[category_index].num_items++;
    categories[category_index].total_cost += cost;

    num_items++;
}

// Function to print the summary of expenses
void print_summary(category* categories, int num_categories, item* items, int num_items) {
    printf("\nSummary:\n");

    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        printf("Number of items: %d\n", categories[i].num_items);
        printf("Total cost: $%.2f\n", categories[i].total_cost);
        printf("\n");
    }
}

int main() {
    category categories[MAX_CATEGORIES];
    item items[MAX_ITEMS];

    int num_categories = 0;
    int num_items = 0;

    // Add some sample categories
    add_category(categories, num_categories, "Food");
    add_category(categories, num_categories, "Clothing");
    add_category(categories, num_categories, "Entertainment");

    // Add some sample items
    add_item(items, num_items, categories, num_categories, "Groceries", 100);
    add_item(items, num_items, categories, num_categories, "Shirt", 50);
    add_item(items, num_items, categories, num_categories, "Movie Ticket", 15);

    print_summary(categories, num_categories, items, num_items);

    return 0;
}