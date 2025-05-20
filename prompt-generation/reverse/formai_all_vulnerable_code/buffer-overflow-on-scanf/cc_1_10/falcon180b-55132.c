//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
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

void add_item() {
    printf("Enter item name: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].name);
    printf("Enter item amount: ");
    scanf("%lf", &categories[num_categories - 1].items[categories[num_categories - 1].num_items].amount);
    categories[num_categories - 1].num_items++;
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void view_items(category cat) {
    printf("Items in %s:\n", cat.name);
    for (int i = 0; i < cat.num_items; i++) {
        printf("%s: $%.2f\n", cat.items[i].name, cat.items[i].amount);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    num_categories = 0;
    add_category();

    while (1) {
        printf("\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. View categories\n");
        printf("4. View items\n");
        printf("5. Exit\n");
        printf("\n");

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
                view_categories();
                break;
            case 4:
                printf("Enter category name: ");
                scanf("%s", categories[num_categories - 1].name);
                view_items(categories[num_categories - 1]);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}