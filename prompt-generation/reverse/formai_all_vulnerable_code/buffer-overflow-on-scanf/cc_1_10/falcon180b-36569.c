//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_CHAR 50

typedef struct {
    char name[MAX_CHAR];
    int id;
} category;

typedef struct {
    char name[MAX_CHAR];
    int id;
    int category_id;
    float price;
} item;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];

int num_categories = 0;
int num_items = 0;

void add_category() {
    char name[MAX_CHAR];
    int id = num_categories + 1;

    printf("Enter category name: ");
    scanf("%s", name);

    strcpy(categories[id].name, name);
    categories[id].id = id;

    num_categories++;
}

void add_item() {
    char name[MAX_CHAR];
    int id, category_id;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter category ID: ");
    scanf("%d", &category_id);

    printf("Enter item ID: ");
    scanf("%d", &id);

    printf("Enter item price: ");
    scanf("%f", &price);

    strcpy(items[id].name, name);
    items[id].id = id;
    items[id].category_id = category_id;
    items[id].price = price;

    num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f (Category: %d)\n", items[i].id, items[i].name, items[i].price, items[i].category_id);
    }
}

void search_item() {
    char name[MAX_CHAR];
    int id;

    printf("\nEnter item name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("\nItem found:\n");
            printf("%s - $%.2f (Category: %d)\n", items[i].name, items[i].price, items[i].category_id);
            return;
        }
    }

    printf("\nItem not found.\n");
}

int main() {
    srand(time(NULL));

    printf("\nWelcome to the Expense Tracker!\n");

    add_category();
    add_category();

    display_categories();

    add_item();
    add_item();

    display_items();

    search_item();

    return 0;
}