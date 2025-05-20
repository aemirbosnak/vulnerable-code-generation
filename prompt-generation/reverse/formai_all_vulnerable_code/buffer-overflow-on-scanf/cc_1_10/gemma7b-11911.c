//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void display_inventory() {
    int i = 0;
    printf("Inventory:\n");
    for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void add_item() {
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    int i = 0;
    for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (strcmp(items[i].name, new_item.name) == 0) {
            printf("Item already exists.\n");
            return;
        }
    }

    items[i] = new_item;
    printf("Item added successfully.\n");
}

void update_item() {
    Item updated_item;
    printf("Enter item name: ");
    scanf("%s", updated_item.name);
    printf("Enter new item quantity: ");
    scanf("%d", &updated_item.quantity);
    printf("Enter new item price: ");

    int i = 0;
    for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (strcmp(items[i].name, updated_item.name) == 0) {
            items[i].quantity = updated_item.quantity;
            items[i].price = updated_item.price;
            printf("Item updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void remove_item() {
    Item removed_item;
    printf("Enter item name: ");
    scanf("%s", removed_item.name);

    int i = 0;
    for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (strcmp(items[i].name, removed_item.name) == 0) {
            items[i].name[0] = '\0';
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Inventory Management System\n");
    printf("1. Display Inventory\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display_inventory();
            break;
        case 2:
            add_item();
            break;
        case 3:
            update_item();
            break;
        case 4:
            remove_item();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}