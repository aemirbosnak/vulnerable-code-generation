//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char category[MAX_DESC_LENGTH];
    int num_items;
    float total_expense;
} Category;

typedef struct {
    char name[MAX_DESC_LENGTH];
    float cost;
} Item;

int main() {
    int num_categories, num_items;
    Category categories[MAX_CATEGORIES];
    Item items[MAX_ITEMS];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].category);
        categories[i].num_items = 0;
        categories[i].total_expense = 0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the cost of item %d: ", i+1);
        scanf("%f", &items[i].cost);
    }

    printf("Enter the category of each item: ");
    for (int i = 0; i < num_items; i++) {
        int category_index;
        printf("Enter the category of item %d (1-%d): ", i+1, num_categories);
        scanf("%d", &category_index);
        strcpy(categories[category_index-1].category, items[i].name);
        categories[category_index-1].num_items++;
        categories[category_index-1].total_expense += items[i].cost;
    }

    printf("\nExpense Tracker\n");
    printf("==============\n");

    for (int i = 0; i < num_categories; i++) {
        printf("\nCategory: %s\n", categories[i].category);
        printf("Number of items: %d\n", categories[i].num_items);
        printf("Total expense: $%.2f\n\n", categories[i].total_expense);
    }

    return 0;
}