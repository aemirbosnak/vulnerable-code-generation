//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each product
typedef struct {
    char name[100];
    int quantity;
    double price;
} Product;

// Function to add a new product to the inventory
void addProduct(Product* inventory, int size, int maxSize) {
    char input[100];
    printf("Enter the name of the product: ");
    scanf("%s", input);
    strcpy(inventory[size].name, input);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[size].quantity);
    printf("Enter the price of the product: ");
    scanf("%lf", &inventory[size].price);
    size++;
    if (size >= maxSize) {
        printf("Inventory is full. Cannot add more products.\n");
        exit(0);
    }
}

// Function to display the current inventory
void displayInventory(Product* inventory, int size) {
    printf("\nProduct Inventory:\n");
    printf("-----------------------------------------------------\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t$%.2lf\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------------------------------\n");
}

// Function to search for a product in the inventory
int searchProduct(Product* inventory, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of a product in the inventory
void updateQuantity(Product* inventory, int size, int id, int quantity) {
    int index = searchProduct(inventory, size, inventory[id].name);
    if (index!= -1) {
        inventory[index].quantity += quantity;
        printf("Quantity of %s updated successfully.\n", inventory[index].name);
    } else {
        printf("Product not found.\n");
    }
}

// Function to delete a product from the inventory
void deleteProduct(Product* inventory, int size, int id) {
    int index = searchProduct(inventory, size, inventory[id].name);
    if (index!= -1) {
        for (int i = index; i < size-1; i++) {
            strcpy(inventory[i].name, inventory[i+1].name);
            inventory[i].quantity = inventory[i+1].quantity;
            inventory[i].price = inventory[i+1].price;
        }
        size--;
        printf("Product deleted successfully.\n");
    } else {
        printf("Product not found.\n");
    }
}

// Main function
int main() {
    Product inventory[100];
    int size = 0;

    // Initialize the inventory with some products
    addProduct(inventory, size, 100);
    addProduct(inventory, size, 100);
    addProduct(inventory, size, 100);

    // Display the current inventory
    displayInventory(inventory, size);

    // Search for a product and update its quantity
    int id = searchProduct(inventory, size, "Product 1");
    updateQuantity(inventory, size, id, 10);

    // Display the updated inventory
    displayInventory(inventory, size);

    // Delete a product from the inventory
    int delId = searchProduct(inventory, size, "Product 2");
    deleteProduct(inventory, size, delId);

    // Display the final inventory
    displayInventory(inventory, size);

    return 0;
}