//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_TRANSACTIONS 1000
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_CATEGORY_NAME_LENGTH 20

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    double price;
} Item;

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int num_items;
} Category;

Category categories[MAX_CATEGORIES];
Item items[MAX_TRANSACTIONS];
int num_categories;
int num_items;

void add_category() {
    char name[MAX_CATEGORY_NAME_LENGTH];
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[num_categories].name, name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    char name[MAX_ITEM_NAME_LENGTH];
    double price;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%lf", &price);
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    num_items++;
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void view_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2lf\n", items[i].name, items[i].price);
    }
}

void main() {
    char choice;
    do {
        printf("Welcome to the Expense Tracker!\n");
        printf("What would you like to do?\n");
        printf("A) Add category\n");
        printf("B) Add item\n");
        printf("C) View categories\n");
        printf("D) View items\n");
        printf("E) Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case 'A':
                add_category();
                break;
            case 'B':
                add_item();
                break;
            case 'C':
                view_categories();
                break;
            case 'D':
                view_items();
                break;
            case 'E':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'E');
}