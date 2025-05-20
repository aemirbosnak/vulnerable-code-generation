//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 50

typedef struct {
    char name[50];
    int quantity;
    int price;
    int category;
} item;

typedef struct {
    char name[50];
    int category;
} category;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];

int num_categories = 0;
int num_items = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].category = num_categories;
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter price: ");
    scanf("%d", &items[num_items].price);
    printf("Enter category: ");
    scanf("%d", &items[num_items].category);
    num_items++;
}

void display_categories() {
    printf("\nCategories:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void display_items() {
    printf("\nItems:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s - %d units - $%d - Category: %d\n", i+1, items[i].name, items[i].quantity, items[i].price, items[i].category);
    }
}

void search_item_by_category() {
    int category;
    printf("\nEnter category number: ");
    scanf("%d", &category);
    for(int i=0; i<num_items; i++) {
        if(items[i].category == category) {
            printf("\n%s - %d units - $%d\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. Display categories\n");
        printf("4. Display items\n");
        printf("5. Search item by category\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
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
                display_items();
                break;
            case 5:
                search_item_by_category();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice!= 6);

    return 0;
}