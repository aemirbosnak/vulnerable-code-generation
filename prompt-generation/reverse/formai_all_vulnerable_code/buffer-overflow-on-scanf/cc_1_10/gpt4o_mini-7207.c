//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

struct Product {
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

// Global array to hold inventory
struct Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function to add a product to the inventory
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Warning: Inventory full! Cannot add more products.\n");
        return;
    }

    struct Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    // Validate if product already exists to avoid duplication
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, newProduct.name) == 0) {
            printf("Warning: Product '%s' already exists! Confirm to update (Y/N): ", newProduct.name);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
                printf("Enter new quantity: ");
                scanf("%d", &inventory[i].quantity);
                printf("Enter new price: ");
                scanf("%f", &inventory[i].price);
                printf("Product '%s' updated.\n", newProduct.name);
                return;
            } else {
                printf("Product not added or updated.\n");
                return;
            }
        }
    }

    // Add new product
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    inventory[productCount++] = newProduct;

    printf("Product '%s' added to inventory.\n", newProduct.name);
}

// Function to view all products in inventory
void viewProducts() {
    if (productCount == 0) {
        printf("Warning: Inventory is empty!\n");
        return;
    }

    printf("Current Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. Name: %s | Quantity: %d | Price: %.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to delete a product from the inventory
void deleteProduct() {
    if (productCount == 0) {
        printf("Warning: No products to delete!\n");
        return;
    }
    printf("Enter product name to delete: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products left
            }
            productCount--;
            printf("Product '%s' deleted from inventory.\n", name);
            return;
        }
    }
    printf("Warning: Product '%s' not found!\n", name);
}

// Function to search for a product by name
void searchProduct() {
    if (productCount == 0) {
        printf("Warning: Inventory is empty!\n");
        return;
    }

    printf("Enter product name to search: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product Found: %s | Quantity: %d | Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Warning: Product '%s' not found!\n", name);
}

// Function to save inventory to a file
void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error: Could not open file for saving inventory!\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully.\n");
}

// Function to load inventory from a file
void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("Warning: Could not open file, starting with empty inventory.\n");
        return;
    }

    while (fscanf(file, "%s %d %f", inventory[productCount].name, &inventory[productCount].quantity, &inventory[productCount].price) != EOF) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) {
            printf("Warning: Inventory full while loading from file!\n");
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded successfully.\n");
}

int main() {
    loadInventory(); // Load existing inventory
    int choice;
    
    while (1) {
        printf("\nInventory System Menu:\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // flush input
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: deleteProduct(); break;
            case 4: searchProduct(); break;
            case 5: saveInventory(); break;
            case 6: printf("Exiting program. Remember to save your changes!\n"); exit(0);
            default: printf("Warning: Invalid choice! Please try again.\n");
        }
    }
    return 0;
}