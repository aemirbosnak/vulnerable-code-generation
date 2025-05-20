//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
} item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_items;
    item items[MAX_ITEMS];
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    num_categories++;
    printf("Enter category name: ");
    scanf("%s", categories[num_categories-1].name);
    categories[num_categories-1].num_items = 0;
}

void add_item(int category_index) {
    if (categories[category_index].num_items >= MAX_ITEMS) {
        printf("Category is full.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", categories[category_index].items[categories[category_index].num_items].name);
    printf("Enter item description: ");
    scanf("%s", categories[category_index].items[categories[category_index].num_items].description);
    printf("Enter item price: ");
    scanf("%f", &categories[category_index].items[categories[category_index].num_items].price);
    categories[category_index].num_items++;
}

void view_category(int category_index) {
    printf("Category: %s\n", categories[category_index].name);
    printf("Items:\n");
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%s - $%.2f - %s\n", categories[category_index].items[i].name, categories[category_index].items[i].price, categories[category_index].items[i].description);
    }
}

int main() {
    num_categories = 0;
    while (num_categories < MAX_CATEGORIES) {
        printf("Enter category name (leave blank to stop): ");
        scanf("%s", categories[num_categories].name);
        if (categories[num_categories].name[0] == '\0') {
            break;
        }
        num_categories++;
    }
    printf("Enter category index to view items:\n");
    int category_index;
    scanf("%d", &category_index);
    view_category(category_index);
    return 0;
}