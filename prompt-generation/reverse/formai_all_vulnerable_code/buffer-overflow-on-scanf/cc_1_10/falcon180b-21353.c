//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);

    num_items++;
}

void remove_item() {
    if (num_items == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    printf("Enter item name to remove: ");
    scanf("%s", inventory[num_items - 1].name);

    num_items--;
}

void display_inventory() {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n\n");

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Display inventory\n4. Exit\n");
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
                display_inventory();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}