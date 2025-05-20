//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_LEN 100

struct category {
    char name[MAX_LEN];
    double budget;
};

struct item {
    char name[MAX_LEN];
    double price;
    char category[MAX_LEN];
};

int num_categories, num_items;
struct category categories[MAX_CATEGORIES];
struct item items[MAX_ITEMS];

void read_categories() {
    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category name for category %d: ", i+1);
        scanf("%s", categories[i].name);
        printf("Enter budget for category %s: ", categories[i].name);
        scanf("%lf", &categories[i].budget);
    }
}

void read_items() {
    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter item name for item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter price for item %s: ", items[i].name);
        scanf("%lf", &items[i].price);
        printf("Enter category for item %s: ", items[i].name);
        scanf("%s", items[i].category);
    }
}

void print_plan() {
    printf("Personal Finance Plan\n");
    printf("=====================\n");

    for (int i = 0; i < num_categories; i++) {
        printf("Category %s:\n", categories[i].name);
        printf("  Budget: $%.2f\n", categories[i].budget);
    }

    printf("\nItemized Expenses:\n");
    for (int i = 0; i < num_items; i++) {
        printf("  %s - $%.2f (%s)\n", items[i].name, items[i].price, items[i].category);
    }
}

int main() {
    read_categories();
    read_items();
    print_plan();

    return 0;
}