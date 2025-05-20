//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} category_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int category_id;
    float amount;
} item_t;

category_t categories[MAX_CATEGORIES];
item_t items[MAX_ITEMS];
int num_categories = 0;
int num_items = 0;

void add_category() {
    char name[MAX_NAME_LENGTH];
    int id = num_categories + 1;
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[id - 1].name, name);
    categories[id - 1].id = id;
    num_categories++;
}

void add_item() {
    char name[MAX_NAME_LENGTH];
    int category_id, id = num_items + 1;
    float amount;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter category ID: ");
    scanf("%d", &category_id);
    strcpy(items[id - 1].name, name);
    items[id - 1].category_id = category_id;
    printf("Enter item amount: ");
    scanf("%f", &amount);
    items[id - 1].amount = amount;
    num_items++;
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void view_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f - %d\n", i + 1, items[i].name, items[i].amount, items[i].category_id);
    }
}

int main() {
    add_category();
    add_category();
    add_item();
    add_item();
    view_categories();
    view_items();
    return 0;
}