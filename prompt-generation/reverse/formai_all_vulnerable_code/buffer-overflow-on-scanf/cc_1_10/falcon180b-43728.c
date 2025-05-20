//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int count;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

typedef struct {
    char name[50];
    int category;
    double price;
} Item;

Item items[MAX_ITEMS];
int num_items;

void add_category(char* name) {
    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            categories[i].count++;
            return;
        }
    }
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Too many categories.\n");
        exit(1);
    }
    strcpy(categories[num_categories].name, name);
    categories[num_categories].count = 1;
    num_categories++;
}

void add_item(char* name, int category, double price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Too many items.\n");
        exit(1);
    }
    strcpy(items[num_items].name, name);
    items[num_items].category = category;
    items[num_items].price = price;
    num_items++;
}

int main() {
    int i, j;
    char input[100];

    num_categories = 0;
    num_items = 0;

    while (1) {
        printf("Enter a category name (or type 'done' to finish):\n");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        add_category(input);
    }

    while (1) {
        printf("Enter an item name, category (0-9), and price:\n");
        scanf("%s %d %lf", input, &j, &items[num_items-1].price);
        if (strcmp(input, "done") == 0) {
            break;
        }
        add_item(input, j, items[num_items-1].price);
    }

    printf("Category summary:\n");
    for (i = 0; i < num_categories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].count);
    }

    printf("\nItem summary:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f (Category %d)\n", items[i].name, items[i].price, items[i].category);
    }

    return 0;
}