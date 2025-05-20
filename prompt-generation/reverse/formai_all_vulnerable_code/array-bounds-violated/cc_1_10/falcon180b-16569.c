//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_CHARACTERS 50

typedef struct {
    char name[MAX_CHARACTERS];
    float amount;
} item_t;

typedef struct {
    char name[MAX_CHARACTERS];
    item_t items[MAX_ITEMS];
    int num_items;
} category_t;

category_t categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter the name of the new category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    int category_index;
    printf("Enter the category index: ");
    scanf("%d", &category_index);
    if (category_index >= 0 && category_index < num_categories) {
        printf("Enter the item name: ");
        scanf("%s", categories[category_index].items[categories[category_index].num_items].name);
        printf("Enter the item amount: ");
        scanf("%f", &categories[category_index].items[categories[category_index].num_items].amount);
        categories[category_index].num_items++;
    } else {
        printf("Invalid category index.\n");
    }
}

void print_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: ", categories[i].name);
        for (int j = 0; j < categories[i].num_items; j++) {
            printf("%s - $%.2f ", categories[i].items[j].name, categories[i].items[j].amount);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Enter the number of categories you want to create: ");
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        add_category();
    }
    int choice;
    while (1) {
        printf("\nChoose an option:\n1. Add category\n2. Add item\n3. Print categories\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_item();
                break;
            case 3:
                print_categories();
                break;
            case 4:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}