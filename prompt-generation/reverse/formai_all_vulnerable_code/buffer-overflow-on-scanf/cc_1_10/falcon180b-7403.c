//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} item;

typedef struct {
    char name[50];
    item items[MAX_ITEMS];
    int num_items;
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item(int category_index) {
    printf("Enter item name: ");
    scanf("%s", categories[category_index].items[categories[category_index].num_items].name);
    printf("Enter item amount: ");
    scanf("%f", &categories[category_index].items[categories[category_index].num_items].amount);
    categories[category_index].num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void display_items(int category_index) {
    printf("\nItems in %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    num_categories = 0;
    printf("Welcome to the Expense Tracker!\n");
    while (num_categories == 0) {
        printf("\nYou haven't added any categories yet. Do you want to add a category? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_category();
        } else if (choice!= 'n' && choice!= 'N') {
            printf("Invalid choice. Please try again.\n");
        }
    }
    int category_index;
    while (1) {
        display_categories();
        printf("\nSelect a category to view/edit its items: ");
        scanf("%d", &category_index);
        if (category_index < 1 || category_index > num_categories) {
            printf("Invalid category index. Please try again.\n");
            continue;
        }
        display_items(category_index - 1);
        char choice;
        printf("\nDo you want to add an item to this category? (y/n): ");
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_item(category_index - 1);
        } else if (choice!= 'n' && choice!= 'N') {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}