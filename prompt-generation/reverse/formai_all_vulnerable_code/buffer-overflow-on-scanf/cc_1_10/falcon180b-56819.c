//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} item;

typedef struct {
    char name[50];
    item items[MAX_ITEMS];
    int num_items;
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Cannot add more categories.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", categories[num_categories-1].items[categories[num_categories-1].num_items].name);

    printf("Enter item amount: ");
    scanf("%f", &categories[num_categories-1].items[categories[num_categories-1].num_items].amount);

    printf("Enter item category: ");
    scanf("%s", categories[num_categories-1].items[categories[num_categories-1].num_items].category);

    categories[num_categories-1].num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void display_items(category cat) {
    printf("\nItems in %s:\n", cat.name);
    for (int i = 0; i < cat.num_items; i++) {
        printf("%s - $%.2f - %s\n", cat.items[i].name, cat.items[i].amount, cat.items[i].category);
    }
}

int main() {
    num_categories = 0;

    add_category();
    add_category();
    add_category();

    display_categories();

    return 0;
}