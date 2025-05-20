//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

typedef struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int total_items = 0;

void add_item() {
    if (total_items == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    inventory[total_items++] = new_item;

    printf("%s added to inventory.\n", new_item.name);
}

void remove_item() {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < total_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            Item removed = inventory[i];
            inventory[i] = inventory[--total_items];
            printf("%s removed from inventory.\n", removed.name);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void list_inventory() {
    printf("Item Name\tQuantity\tPrice\n");

    for (int i = 0; i < total_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    printf("Welcome to the post-apocalyptic inventory system!\n");

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. List inventory\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                list_inventory();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}