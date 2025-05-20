//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} item_t;

typedef struct {
    char name[50];
    int num_items;
    item_t items[MAX_ITEMS];
} category_t;

category_t categories[MAX_CATEGORIES];
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
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void print_items(int category_index) {
    printf("Items in %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%s - $%.2f\n", categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    num_categories = 0;
    add_category();
    add_category();

    int choice;
    while (1) {
        printf("1. Add category\n2. Add item\n3. Print categories\n4. Print items\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                printf("Enter category index: ");
                scanf("%d", &choice);
                add_item(choice - 1);
                break;
            case 3:
                print_categories();
                break;
            case 4:
                printf("Enter category index: ");
                scanf("%d", &choice);
                print_items(choice - 1);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}