//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int amount;
} Item;

typedef struct {
    char name[50];
    int total_spent;
} Category;

int num_items;
Item items[MAX_ITEMS];
int num_categories;
Category categories[MAX_CATEGORIES];

void add_category() {
    printf("Enter the name of the new category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].total_spent = 0;
    num_categories++;
}

void add_item() {
    printf("Enter the name of the new item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the amount spent: ");
    scanf("%d", &items[num_items].amount);
    int category_index;
    printf("Enter the category index (or -1 to skip): ");
    scanf("%d", &category_index);
    if (category_index >= 0 && category_index < num_categories) {
        categories[category_index].total_spent += items[num_items].amount;
    }
    num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d\n", categories[i].name, categories[i].total_spent);
    }
}

void display_items() {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", items[i].name, items[i].amount);
    }
}

int main() {
    printf("\nWelcome to the Expense Tracker!\n");
    printf("In this kingdom, thou shalt keep track of thy expenses.\n");
    printf("Let us begin.\n\n");

    num_categories = 0;
    add_category(); // add the first category

    while (1) {
        printf("\nWhat wouldst thou like to do?\n");
        printf("1. Add an item\n");
        printf("2. Display categories\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        scanf("%d", &num_categories);

        switch (num_categories) {
        case 1:
            add_item();
            break;
        case 2:
            display_categories();
            break;
        case 3:
            display_items();
            break;
        case 4:
            printf("\nFarewell, and may thy expenses be ever in check.\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}