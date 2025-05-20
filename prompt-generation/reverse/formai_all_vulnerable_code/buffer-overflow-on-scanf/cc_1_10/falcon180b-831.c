//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

struct Category {
    char name[50];
    int count;
};

struct Item {
    char name[50];
    double price;
    int category;
};

void read_categories(struct Category categories[MAX_CATEGORIES]) {
    int i;
    for (i = 0; i < MAX_CATEGORIES; i++) {
        printf("Enter category %d name: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].count = 0;
    }
}

void read_items(struct Item items[MAX_ITEMS], struct Category categories[MAX_CATEGORIES]) {
    int i, j;
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter item %d price: ", i + 1);
        scanf("%lf", &items[i].price);
        printf("Enter item %d category (1-%d): ", i + 1, MAX_CATEGORIES - 1);
        scanf("%d", &items[i].category);
        categories[items[i].category - 1].count++;
    }
}

void print_categories(struct Category categories[MAX_CATEGORIES]) {
    int i;
    for (i = 0; i < MAX_CATEGORIES; i++) {
        printf("%d. %s (%d items)\n", i + 1, categories[i].name, categories[i].count);
    }
}

void print_items(struct Item items[MAX_ITEMS], struct Category categories[MAX_CATEGORIES]) {
    int i, j;
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s ($%.2f) - %s\n", i + 1, items[i].name, items[i].price, categories[items[i].category - 1].name);
    }
}

void print_total_cost(struct Item items[MAX_ITEMS], struct Category categories[MAX_CATEGORIES]) {
    int i, j;
    double total_cost = 0.0;
    for (i = 0; i < MAX_ITEMS; i++) {
        total_cost += items[i].price;
    }
    printf("Total cost: $%.2f\n", total_cost);
}

int main() {
    struct Category categories[MAX_CATEGORIES];
    struct Item items[MAX_ITEMS];

    read_categories(categories);
    read_items(items, categories);
    print_categories(categories);
    print_items(items, categories);
    print_total_cost(items, categories);

    return 0;
}