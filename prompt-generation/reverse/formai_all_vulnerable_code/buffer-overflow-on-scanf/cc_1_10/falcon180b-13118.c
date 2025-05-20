//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_ITEM_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int num_items;
} category;

typedef struct {
    char name[MAX_ITEM_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float cost;
    char date[MAX_DATE_LENGTH];
} item;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];
int num_categories, num_items;

void add_category() {
    char input[MAX_CATEGORY_LENGTH];
    printf("Enter a category name: ");
    scanf("%s", input);
    strcpy(categories[num_categories].name, input);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    char input[MAX_ITEM_LENGTH];
    printf("Enter an item name: ");
    scanf("%s", input);
    printf("Enter a category name: ");
    scanf("%s", input);
    strcpy(items[num_items].name, input);
    strcpy(items[num_items].category, input);
    printf("Enter the cost: ");
    scanf("%f", &items[num_items].cost);
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", items[num_items].date);
    num_items++;
    categories[num_categories - 1].num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].num_items);
    }
}

void display_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s (%s) - $%.2f - %s\n", items[i].name, items[i].category, items[i].cost, items[i].date);
    }
}

int main() {
    printf("Expense Tracker\n");
    num_categories = 0;
    num_items = 0;
    add_category();
    add_category();
    add_item();
    add_item();
    display_categories();
    display_items();
    return 0;
}