//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // maximum number of items in the inventory

// structure to represent an inventory item
typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS]; // initialize inventory as an empty array of items
int num_items = 0; // keep track of the number of items in the inventory

// function to add an item to the inventory
void add_item(char* name, int quantity, float price) {
    // check if inventory is already full
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full\n");
        return;
    }
    // create a new item
    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    // add the item to the inventory
    inventory[num_items] = new_item;
    num_items++;
    printf("Item added successfully\n");
}

// function to remove an item from the inventory by name
void remove_item(char* name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // item found, remove it
            int j;
            for (j = i; j < num_items; j++) {
                inventory[j] = inventory[j+1];
            }
            num_items--;
            printf("Item removed successfully\n");
            return;
        }
    }
    // item not found
    printf("Item not found\n");
}

// function to display all items in the inventory
void display_inventory() {
    printf("Name\tQuantity\tPrice\n");
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // menu-driven program to manage inventory
    int choice;
    char name[20];
    int quantity;
    float price;
    do {
        printf("\n***Inventory Management System***\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // add an item
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(name, quantity, price);
                break;
            case 2: // remove an item
                printf("Enter item name: ");
                scanf("%s", name);
                remove_item(name);
                break;
            case 3: // display inventory
                display_inventory();
                break;
            case 4: // exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}