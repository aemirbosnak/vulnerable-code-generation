//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char name[MAX_DESCRIPTION_LENGTH];
    int id;
} category;

category categories[MAX_CATEGORIES];
int num_categories;

typedef struct {
    char name[MAX_DESCRIPTION_LENGTH];
    int category_id;
    float price;
} item;

item items[MAX_ITEMS];
int num_items;

void add_category() {
    printf("Enter category name: ");
    char name[MAX_DESCRIPTION_LENGTH];
    scanf("%s", name);
    int id = num_categories + 1;
    strcpy(categories[num_categories].name, name);
    categories[num_categories].id = id;
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    char name[MAX_DESCRIPTION_LENGTH];
    scanf("%s", name);
    int category_id;
    printf("Enter category ID: ");
    scanf("%d", &category_id);
    float price;
    printf("Enter price: ");
    scanf("%f", &price);
    strcpy(items[num_items].name, name);
    items[num_items].category_id = category_id;
    items[num_items].price = price;
    num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void display_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s (%d) - $%.2f\n", items[i].name, items[i].category_id, items[i].price);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter the number of categories you would like to create: ");
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        add_category();
    }
    printf("Please enter the number of items you would like to add: ");
    scanf("%d", &num_items);
    for (int i = 0; i < num_items; i++) {
        add_item();
    }
    printf("Categories:\n");
    display_categories();
    printf("Items:\n");
    display_items();
    return 0;
}