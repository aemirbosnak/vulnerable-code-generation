//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[100];
    double budget;
} category;

typedef struct {
    char name[100];
    double amount;
    int category_index;
} item;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];

int num_categories;
int num_items;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter category budget: ");
    scanf("%lf", &categories[num_categories].budget);
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item amount: ");
    scanf("%lf", &items[num_items].amount);
    printf("Enter item category (0-9): ");
    scanf("%d", &items[num_items].category_index);
    num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s - Budget: $%.2lf\n", i+1, categories[i].name, categories[i].budget);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Amount: $%.2lf - Category: %s\n", i+1, items[i].name, items[i].amount, categories[items[i].category_index].name);
    }
}

int main() {
    printf("Personal Finance Planner\n");
    printf("-------------------------\n");

    num_categories = 0;
    num_items = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("\nAdd a category? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_category();
        } else {
            break;
        }
    }

    while (num_items < MAX_ITEMS) {
        printf("\nAdd an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_item();
        } else {
            break;
        }
    }

    printf("\nCategories:\n");
    display_categories();

    printf("\nItems:\n");
    display_items();

    return 0;
}