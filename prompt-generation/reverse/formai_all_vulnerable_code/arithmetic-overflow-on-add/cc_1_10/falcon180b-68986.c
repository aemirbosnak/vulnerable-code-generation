//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Item;

typedef struct {
    char name[MAX_NAME_LEN];
    Item items[MAX_ITEMS];
    int num_items;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].name);
    printf("Enter item category: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].category);
    printf("Enter item amount: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].amount);
    categories[num_categories - 1].num_items++;
}

void view_items() {
    printf("Category: %s\n", categories[num_categories - 1].name);
    printf("Items:\n");
    for (int i = 0; i < categories[num_categories - 1].num_items; i++) {
        printf("- %s (%s) - $%s\n", categories[num_categories - 1].items[i].name, categories[num_categories - 1].items[i].category, categories[num_categories - 1].items[i].amount);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

int main() {
    printf("Welcome to the expense tracker!\n");
    add_category();
    add_item();
    add_item();
    add_category();
    add_item();

    view_categories();

    return 0;
}