//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int quantity;
    int price;
    int category;
} ITEM;

typedef struct {
    char name[20];
    int total_items;
    int total_value;
} CATEGORY;

ITEM items[MAX_ITEMS];
CATEGORY categories[MAX_CATEGORIES];

int num_items = 0;
int num_categories = 0;

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

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void display_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d - $%d - Category %d\n", items[i].name, items[i].quantity, items[i].price, items[i].category);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s - %d items - $%d total value\n", categories[i].name, categories[i].total_items, categories[i].total_value);
    }
}

void calculate_value() {
    for (int i = 0; i < num_categories; i++) {
        categories[i].total_items = 0;
        categories[i].total_value = 0;
    }
    for (int i = 0; i < num_items; i++) {
        int category_index = items[i].category - 1;
        categories[category_index].total_items++;
        categories[category_index].total_value += items[i].price * items[i].quantity;
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Add category\n");
        printf("3. Display items\n");
        printf("4. Display categories\n");
        printf("5. Calculate total value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_category();
                break;
            case 3:
                display_items();
                break;
            case 4:
                display_categories();
                break;
            case 5:
                calculate_value();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 6);
    return 0;
}