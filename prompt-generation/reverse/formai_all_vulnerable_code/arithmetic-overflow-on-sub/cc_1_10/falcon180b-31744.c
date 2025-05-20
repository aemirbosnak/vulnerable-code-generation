//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[100];
    int id;
} category;

typedef struct {
    char name[100];
    float price;
    int category;
} item;

category categories[MAX_CATEGORIES];
int num_categories = 0;

item items[MAX_ITEMS];
int num_items = 0;

void add_category(char* name) {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    strcpy(categories[num_categories].name, name);
    categories[num_categories].id = num_categories;

    num_categories++;
}

void add_item(char* name, float price, int category) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].category = category;

    num_items++;
}

void print_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void print_items(int category) {
    printf("Items in category '%s':\n", categories[category].name);

    for (int i = 0; i < num_items; i++) {
        if (items[i].category == category) {
            printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
        }
    }
}

void main() {
    add_category("Groceries");
    add_category("Entertainment");
    add_category("Clothing");

    add_item("Milk", 3.50, 0);
    add_item("Bread", 2.50, 0);
    add_item("Eggs", 2.00, 0);
    add_item("Movie Ticket", 10.00, 1);
    add_item("Shirt", 20.00, 2);

    print_categories();

    int choice;
    printf("Enter category number to view items: ");
    scanf("%d", &choice);

    print_items(choice-1);
}