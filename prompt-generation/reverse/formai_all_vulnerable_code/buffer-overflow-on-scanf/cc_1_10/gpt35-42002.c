//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for strings and arrays
#define MAX_STRING_LENGTH 30
#define MAX_ARRAY_LENGTH 100

// Define the struct for warehouse items
typedef struct {
    int item_number;
    char name[MAX_STRING_LENGTH];
    int quantity;
    float price;
} WarehouseItem;

// Declare global array to store items in warehouse
WarehouseItem warehouse[MAX_ARRAY_LENGTH];
int num_items = 0;  // Initialize to zero since no items in warehouse yet

// Function to add an item to the warehouse
void add_item() {
    if (num_items == MAX_ARRAY_LENGTH) {
        printf("Warehouse is currently at maximum capacity.\n");
        return;
    }
    WarehouseItem new_item;
    printf("Enter item number: ");
    scanf("%d", &new_item.item_number);
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter price: ");
    scanf("%f", &new_item.price);
    warehouse[num_items] = new_item;
    num_items++;
    printf("Item successfully added to warehouse.\n");
}

// Function to remove an item from the warehouse
void remove_item() {
    int item_number;
    printf("Enter item number to remove: ");
    scanf("%d", &item_number);
    int i;
    for (i = 0; i < num_items; i++) {
        if (warehouse[i].item_number == item_number) {
            int j;
            for (j = i; j < num_items - 1; j++) {
                warehouse[j] = warehouse[j+1];
            }
            num_items--;
            printf("Item removed from warehouse.\n");
            return;
        }
    }
    printf("Item not found in warehouse.\n");
}

// Function to display information for all items in warehouse
void display_items() {
    if (num_items == 0) {
        printf("No items currently in warehouse.\n");
        return;
    }
    printf("%-15s%-20s%-10s%-10s\n", "Item Number", "Item Name", "Quantity", "Price");
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%-15d%-20s%-10d%-10.2f\n", warehouse[i].item_number, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("[1] Add item\n");
        printf("[2] Remove item\n");
        printf("[3] Display items\n");
        printf("[4] Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}