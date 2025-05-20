//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double price;
    int quantity;
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
    printf("Enter price: ");
    scanf("%lf", &categories[category_index].items[categories[category_index].num_items].price);
    printf("Enter quantity: ");
    scanf("%d", &categories[category_index].items[categories[category_index].num_items].quantity);
    categories[category_index].num_items++;
}

void print_categories() {
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void print_items(int category_index) {
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%s - $%.2lf - %d\n", categories[category_index].items[i].name, categories[category_index].items[i].price, categories[category_index].items[i].quantity);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    num_categories = 0;
    while (num_categories < MAX_CATEGORIES) {
        printf("Do you want to add a category? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            add_category();
        } else {
            break;
        }
    }
    for (int i = 0; i < num_categories; i++) {
        printf("Enter expenses for %s:\n", categories[i].name);
        while (1) {
            int choice;
            printf("1. Add item\n2. Print items\n3. Back to categories\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    add_item(i);
                    break;
                case 2:
                    print_items(i);
                    break;
                case 3:
                    return 0;
            }
        }
    }
    return 0;
}