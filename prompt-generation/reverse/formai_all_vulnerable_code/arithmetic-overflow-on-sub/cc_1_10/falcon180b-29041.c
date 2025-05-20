//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", categories[num_categories-1].items[categories[num_categories-1].num_items].name);
    printf("Enter item amount: ");
    scanf("%f", &categories[num_categories-1].items[categories[num_categories-1].num_items].amount);
    categories[num_categories-1].num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void display_items(int category_index) {
    printf("\nItems in %s:\n", categories[category_index].name);
    for(int i=0; i<categories[category_index].num_items; i++) {
        printf("%s - $%.2f\n", categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("How many categories do you want to create? ");
    scanf("%d", &num_categories);
    for(int i=0; i<num_categories; i++) {
        add_category();
    }
    int choice;
    while(1) {
        printf("\nWhat do you want to do?\n1. Add category\n2. Add item\n3. Display categories\n4. Display items\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_item();
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}