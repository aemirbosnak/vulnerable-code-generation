//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Product struct definition
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Product inventory array
struct Product inventory[MAX_PRODUCTS];

// Function prototypes
void addProduct();
void removeProduct();
void searchProduct();
void printInventory();

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System");
        printf("\n------------------------");
        printf("\n1. Add Product");
        printf("\n2. Remove Product");
        printf("\n3. Search Product");
        printf("\n4. Print Inventory");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printInventory();
                break;
            case 5:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 5);
    return 0;
}

// Function to add a product to the inventory
void addProduct() {
    int id;
    char name[50];
    int quantity;
    float price;
    // Ask for product details
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    // Check if ID already exists
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            printf("\nProduct with ID %d already exists.", id);
            return;
        }
    }
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%f", &price);
    // Add product to inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == 0) {
            inventory[i].id = id;
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            printf("\nProduct added to inventory.");
            return;
        }
    }
    printf("\nProduct inventory is full.");
}

// Function to remove a product from the inventory
void removeProduct() {
    int id;
    // Ask for product ID to be removed
    printf("\nEnter product ID to be removed: ");
    scanf("%d", &id);
    // Search for product with given ID
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            // If found, remove product from inventory
            inventory[i].id = 0;
            inventory[i].name[0] = '\0';
            inventory[i].quantity = 0;
            inventory[i].price = 0.0;
            printf("\nProduct removed from inventory.");
            return;
        }
    }
    printf("\nProduct with ID %d not found in inventory.", id);
}

// Function to search for a product in the inventory
void searchProduct() {
    int id;
    // Ask for product ID to be searched
    printf("\nEnter product ID to be searched: ");
    scanf("%d", &id);
    // Search for product with given ID
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            // If found, print its details
            printf("\nProduct ID: %d", inventory[i].id);
            printf("\nProduct Name: %s", inventory[i].name);
            printf("\nProduct Quantity: %d", inventory[i].quantity);
            printf("\nProduct Price: %.2f", inventory[i].price);
            return;
        }
    }
    printf("\nProduct with ID %d not found in inventory.", id);
}

// Function to print the entire inventory
void printInventory() {
    // Print header
    printf("\n%-10s %-20s %-10s %-10s", "ID", "Name", "Quantity", "Price");
    printf("\n------------------------------------------------------------");
    // Print each product in the inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id != 0) {
            printf("\n%-10d %-20s %-10d %-10.2f", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}