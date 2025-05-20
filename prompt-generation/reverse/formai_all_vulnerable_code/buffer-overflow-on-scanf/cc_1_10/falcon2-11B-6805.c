//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 5

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void add_item(Item* items, int* count, int capacity) {
    if (*count >= capacity) {
        fprintf(stderr, "Inventory is full, cannot add item.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[*count].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
}

void remove_item(Item* items, int* count, int capacity) {
    if (*count <= 0) {
        fprintf(stderr, "Inventory is empty, cannot remove item.\n");
        return;
    }
    printf("Enter item name to remove: ");
    scanf("%s", items[*count - 1].name);
    (*count)--;
}

void display_inventory(Item items[], int count) {
    printf("Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %5d %6.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;

    while (1) {
        printf("Inventory system menu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count, MAX_ITEMS);
                break;
            case 2:
                remove_item(items, &count, MAX_ITEMS);
                break;
            case 3:
                display_inventory(items, count);
                break;
            case 4:
                return 0;
            default:
                fprintf(stderr, "Invalid choice.\n");
        }
    }

    return 0;
}