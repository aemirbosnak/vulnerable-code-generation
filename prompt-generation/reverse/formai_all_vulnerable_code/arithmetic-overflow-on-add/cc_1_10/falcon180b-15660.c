//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} Item;

typedef struct {
    char name[MAX_NAME_LEN];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter the name of the category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].name);
    printf("Enter the category of the item: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].category);
    printf("Enter the price of the item: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].price);
    categories[num_categories - 1].num_items++;
}

void display_categories() {
    for(int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for(int j = 0; j < categories[i].num_items; j++) {
            printf("\t%s - %s - %s\n", categories[i].items[j].name, categories[i].items[j].category, categories[i].items[j].price);
        }
    }
}

int main() {
    num_categories = 0;
    add_category();
    add_category();
    add_category();
    add_item();
    add_item();
    add_item();
    display_categories();
    return 0;
}