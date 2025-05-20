//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

int item_count = 0;
Item items[MAX_ITEMS];

void add_item(char* name, int quantity, float price) {
    if (item_count >= MAX_ITEMS) {
        printf("Error: Warehouse is full. Cannot add more items\n");
        return;
    }

    strcpy(items[item_count].name, name);
    items[item_count].quantity = quantity;
    items[item_count].price = price;
    item_count++;

    printf("Item added successfully.\n");
}

void remove_item(char* name, int quantity) {
    int i, found = 0;
    for (i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            found = 1;
            if (items[i].quantity < quantity) {
                printf("Error: Quantity to be removed exceeds available quantity\n");
                return;
            }
            items[i].quantity -= quantity;
            printf("Item removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Error: Item not found\n");
    }
}

void display_items() {
    printf("%-20s%-10s%-10s\n", "Item Name", "Quantity", "Price");
    int i;
    for (i = 0; i < item_count; i++) {
        printf("%-20s%-10d%-10.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice, quantity;
    float price;
    char name[MAX_NAME_SIZE];
    while (1) {
        printf("\nWarehouse Menu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(name, quantity, price);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                remove_item(name, quantity);
                break;
            case 3:
                display_items();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}