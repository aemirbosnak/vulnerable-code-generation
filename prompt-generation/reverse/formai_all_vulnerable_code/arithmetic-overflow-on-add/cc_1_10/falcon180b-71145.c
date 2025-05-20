//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} Item;

typedef struct {
    char name[50];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter the name of the new category: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", categories[num_categories-1].items[categories[num_categories-1].num_items].name);
    printf("Enter the amount of the item: ");
    scanf("%f", &categories[num_categories-1].items[categories[num_categories-1].num_items].amount);
    categories[num_categories-1].num_items++;
}

void view_categories() {
    printf("Categories:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void view_items(int category_index) {
    printf("Items in %s:\n", categories[category_index].name);
    for(int i=0; i<categories[category_index].num_items; i++) {
        printf("%s - $%.2f\n", categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    num_categories = 0;
    printf("Welcome to the Personal Finance Planner!\n");
    while(1) {
        printf("\n1. Add category\n2. Add item\n3. View categories\n4. View items\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
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
                printf("Enter the category index: ");
                scanf("%d", &choice);
                view_items(choice);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}