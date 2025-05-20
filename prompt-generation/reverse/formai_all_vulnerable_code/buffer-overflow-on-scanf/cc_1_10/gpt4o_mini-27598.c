//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for products in the warehouse
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct(Product *inventory, int *count);
void viewInventory(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void searchProduct(Product *inventory, int count);
void displayMenu();

// Main function
int main() {
    Product inventory[100]; // Inventory to hold 100 products
    int count = 0; // Number of current products
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                viewInventory(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                searchProduct(inventory, count);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. View Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

// Function to add a product to the inventory
void addProduct(Product *inventory, int *count) {
    if (*count >= 100) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    Product p;
    p.id = *count + 1; // ID is automatically assigned based on count
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    
    inventory[*count] = p; // Add product to inventory
    (*count)++; // Increment count
    printf("Product added successfully!\n");
}

// Function to view all products in the inventory
void viewInventory(Product *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to update a product's details
void updateProduct(Product *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty. Cannot update.\n");
        return;
    }
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product: %s\n", inventory[i].name);
            printf("Enter new name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to delete a product from the inventory
void deleteProduct(Product *inventory, int *count) {
    if (*count == 0) {
        printf("Inventory is empty. Cannot delete.\n");
        return;
    }
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products left
            }
            (*count)--; // Decrement count
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to search for a product by name
void searchProduct(Product *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty. Cannot search.\n");
        return;
    }
    char name[50];
    int found = 0;
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    printf("Search Results:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("ID: %d, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].quantity, inventory[i].price);
        }
    }
    if (!found) {
        printf("No product found with name %s.\n", name);
    }
}