//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} item;

typedef struct {
    char name[MAX_NAME_LENGTH];
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
    printf("Enter item price: ");
    scanf("%f", &categories[category_index].items[categories[category_index].num_items].price);
    categories[category_index].num_items++;
}

void print_categories() {
    for (int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for (int j = 0; j < categories[i].num_items; j++) {
            printf("- %s: $%.2f\n", categories[i].items[j].name, categories[i].items[j].price);
        }
    }
}

int main() {
    num_categories = 0;
    printf("Welcome to the Expense Tracker!\n");
    printf("How many categories do you want to track? ");
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        add_category();
    }
    int choice;
    while (1) {
        printf("\n1. Add category\n2. Add item\n3. Print categories\n4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}