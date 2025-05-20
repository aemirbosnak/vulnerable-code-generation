//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Struct to store warehouse items
struct Item {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
};

// Declare warehouse inventory as a global variable
struct Item inventory[100];
int num_items = 0;

// Function to add a new item to the warehouse inventory
void add_item() {
    printf("Enter the item ID: ");
    scanf("%d", &inventory[num_items].item_id);

    printf("Enter the item name: ");
    scanf("%s", inventory[num_items].item_name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &inventory[num_items].quantity);

    printf("Enter the price per unit of the item: ");
    scanf("%f", &inventory[num_items].price);

    num_items++;
}

// Function to remove an item from the warehouse inventory by ID
void remove_item() {
    int item_id, i, found = 0;
    printf("Enter the item ID to remove: ");
    scanf("%d", &item_id);

    for (i = 0; i < num_items; i++) {
        if (inventory[i].item_id == item_id) {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Item not found in inventory\n");
    } else {
        for (i = i; i < num_items - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_items--;
        printf("Item removed from inventory\n");
    }
}

// Function to display the entire warehouse inventory
void display_inventory() {
    int i;
    printf("Item ID\tItem Name\t\tQuantity\tPrice per Unit\n");

    for (i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t\t%d\t\t%.2f\n", inventory[i].item_id, inventory[i].item_name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    printf("Warehouse Management System\n");

    while (1) {
        printf("\n1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}