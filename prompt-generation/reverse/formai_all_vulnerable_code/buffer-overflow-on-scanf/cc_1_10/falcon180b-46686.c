//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int code;
} category;

typedef struct {
    char name[50];
    int category_code;
    float price;
} item;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];

int num_categories;
int num_items;

void add_category() {
    printf("Enter the name of the category: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter the code for the category (1-9): ");
    scanf("%d", &categories[num_categories].code);
    num_categories++;
}

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the category code for the item (1-9): ");
    scanf("%d", &items[num_items].category_code);
    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].code, categories[i].name);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f (Category: %d)\n", items[i].name, items[i].price, items[i].category_code);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a category\n");
        printf("2. Add an item\n");
        printf("3. Display categories\n");
        printf("4. Display items\n");
        printf("5. Exit\n");
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
                printf("Thank you for using the Expense Tracker!");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice!= 5);
    return 0;
}