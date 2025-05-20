//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

typedef struct {
    char name[50];
    int num_items;
    item items[MAX_ITEMS];
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
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
    categories[num_categories-1].items[categories[num_categories-1].num_items].category = num_categories-1;
    categories[num_categories-1].num_items++;
}

void print_categories() {
    printf("Categories:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void print_items() {
    printf("Items:\n");
    for(int i=0; i<categories[num_categories-1].num_items; i++) {
        printf("%-20s $%.2f\n", categories[num_categories-1].items[i].name, categories[num_categories-1].items[i].amount);
    }
}

int main() {
    printf("Expense Tracker\n");
    printf("-----------------\n");
    num_categories = 0;
    add_category();
    add_category();
    add_category();
    add_item();
    add_item();
    add_item();
    print_categories();
    print_items();
    return 0;
}