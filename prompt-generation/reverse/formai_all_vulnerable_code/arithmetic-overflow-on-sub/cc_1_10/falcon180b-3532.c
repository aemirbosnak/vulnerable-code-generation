//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_CHAR 100

typedef struct {
    char name[MAX_CHAR];
    float amount;
} item;

typedef struct {
    char name[MAX_CHAR];
    int num_items;
    item items[MAX_ITEMS];
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category(void) {
    printf("Enter the name of the category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item(void) {
    printf("Enter the name of the item: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].name);
    printf("Enter the amount of the item: ");
    scanf("%f", &categories[num_categories - 1].items[categories[num_categories - 1].num_items].amount);
    categories[num_categories - 1].num_items++;
}

void display_categories(void) {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s (%d items)\n", i + 1, categories[i].name, categories[i].num_items);
    }
}

void display_items(int category_index) {
    printf("\nItems in category %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    num_categories = 0;
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        display_categories();
        printf("\nWhat would you like to do?\n1. Add a category\n2. Add an item\n3. Display items in a category\n4. Quit\n");
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
            printf("Enter the category index: ");
            scanf("%d", &num_categories);
            display_items(num_categories - 1);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}