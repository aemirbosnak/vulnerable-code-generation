//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define global variables
int counter = 0;
int maxProducts = 100;

// Define structure for each product
struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Define array to hold the products
struct product inventory[100];

// Function to add a new product
void addProduct() {
    // Check if inventory is full
    if (counter == maxProducts) {
        printf("Inventory is full.\n");
        return;
    }

    // Get product details from user
    struct product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    // Assign new ID
    p.id = counter + 1;

    // Add product to inventory
    inventory[counter] = p;
    counter++;

    printf("Product added to inventory with ID %d.\n", p.id);
}

// Function to remove a product
void removeProduct() {
    // Get ID of product to remove
    int id;
    printf("Enter ID of product to remove: ");
    scanf("%d", &id);

    // Search for product in inventory
    int index = -1;
    for (int i = 0; i < counter; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    // Remove product from inventory
    for (int i = index; i < counter - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    counter--;

    printf("Product with ID %d has been removed from inventory.\n", id);
}

// Function to display all products
void displayProducts() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < counter; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        // Get user choice
        scanf("%d", &choice);

        // Perform action based on choice
        switch(choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: displayProducts(); break;
            case 4: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}