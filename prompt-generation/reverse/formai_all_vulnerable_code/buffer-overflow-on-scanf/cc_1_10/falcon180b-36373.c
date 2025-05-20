//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_CHAR 100

typedef struct {
    char name[MAX_CHAR];
    double amount;
} Item;

typedef struct {
    char name[MAX_CHAR];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

int num_categories = 0;
Category categories[MAX_CATEGORIES];

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
    scanf("%lf", &categories[category_index].items[categories[category_index].num_items].amount);
    categories[category_index].num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void display_items(int category_index) {
    printf("Items in %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. Display categories\n");
        printf("4. Display items\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_category();
                break;
            case 2:
                printf("Enter category index: ");
                scanf("%d", &choice);
                add_item(choice-1);
                break;
            case 3:
                display_categories();
                break;
            case 4:
                printf("Enter category index: ");
                scanf("%d", &choice);
                display_items(choice-1);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);
    return 0;
}