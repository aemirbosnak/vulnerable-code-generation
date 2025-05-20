//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
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

typedef struct {
    char name[50];
    double price;
    int category;
} Item;

Category categories[MAX_CATEGORIES];
Item items[MAX_ITEMS];
int num_categories = 0;
int num_items = 0;

void add_category() {
    char name[50];
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[num_categories].name, name);
    categories[num_categories].count = 0;
    num_categories++;
}

void add_item() {
    char name[50];
    double price;
    int category;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%lf", &price);
    printf("Enter item category (0-%d): ", num_categories - 1);
    scanf("%d", &category);
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].category = category;
    categories[category].count++;
    num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].count);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f (Category: %s)\n", items[i].name, items[i].price, categories[items[i].category].name);
    }
}

void main() {
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nOptions:\n1. Add Category\n2. Add Item\n3. Display Categories\n4. Display Items\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_item();
                break;
            case 3:
                display_categories();
                break;
            case 4:
                display_items();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
}