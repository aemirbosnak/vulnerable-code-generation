//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Item;

typedef struct {
    char name[50];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

Category categories[MAX_CATEGORIES];
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

void print_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void print_items(int category_index) {
    printf("\nItems in %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%s: $%.2f\n", categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    printf("Expense Tracker\n");
    printf("=================\n");

    num_categories = 0;
    while (num_categories < MAX_CATEGORIES) {
        printf("\nEnter category name (or press enter to finish): ");
        char input[50];
        scanf("%s", input);
        if (input[0]!= '\0') {
            add_category();
        }
    }

    int category_index;
    printf("\nSelect category:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
    scanf("%d", &category_index);

    while (1) {
        printf("\nOptions:\n1. Add item\n2. Print items\n3. Back to categories\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(category_index);
                break;
            case 2:
                print_items(category_index);
                break;
            case 3:
                main();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}