//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store each item in inventory with its quantity
typedef struct product {
    char name[20];
    int quantity;
} product;

// Function to add a new item to the inventory
void add_product(product* inventory, int* num_products) {
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    (*num_products)++;
    printf("\nItem added successfully.\n");
}

// Function to remove an item from the inventory
void remove_product(product* inventory, int* num_products) {
    if (*num_products == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    char name[20];
    printf("Enter product name: ");
    scanf("%s", name);
    for (int i = 0; i < *num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < (*num_products)-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*num_products)--;
            printf("\nItem removed successfully.\n");
            return;
        }
    }
    printf("\nItem not found in inventory.\n");
}

// Function to display the current inventory
void display_inventory(product* inventory, int num_products) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
    }
    printf("\n");
}

int main() {
    product inventory[50];
    int num_products = 0;
    int choice = 0;
    while (choice != 4) {
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                remove_product(inventory, &num_products);
                break;
            case 3:
                display_inventory(inventory, num_products);
                break;
            case 4:
                printf("\nExiting.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}