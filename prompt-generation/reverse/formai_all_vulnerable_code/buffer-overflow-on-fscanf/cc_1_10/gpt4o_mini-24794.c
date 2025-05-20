//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of products
#define MAX_PRODUCTS 100

// Struct to represent a product in inventory
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function declarations
void addProduct(Product *inventory, int *productCount);
void displayInventory(Product *inventory, int productCount);
void searchProduct(Product *inventory, int productCount);
void updateProduct(Product *inventory, int productCount);
void deleteProduct(Product *inventory, int *productCount);
void saveInventory(Product *inventory, int productCount);
void loadInventory(Product *inventory, int *productCount);

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    // Load existing inventory from file
    loadInventory(inventory, &productCount);

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Save Inventory\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                displayInventory(inventory, productCount);
                break;
            case 3:
                searchProduct(inventory, productCount);
                break;
            case 4:
                updateProduct(inventory, productCount);
                break;
            case 5:
                deleteProduct(inventory, &productCount);
                break;
            case 6:
                saveInventory(inventory, productCount);
                break;
            case 7:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to add a new product
void addProduct(Product *inventory, int *productCount) {
    if (*productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    getchar(); // Clear newline character
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline character
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*productCount] = newProduct;
    (*productCount)++;
    printf("Product added successfully!\n");
}

// Function to display all products
void displayInventory(Product *inventory, int productCount) {
    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a product
void searchProduct(Product *inventory, int productCount) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to update a product's details
void updateProduct(Product *inventory, int productCount) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating details for: ID: %d, Name: %s\n", inventory[i].id, inventory[i].name);
            printf("Enter new name: ");
            getchar(); // Clear newline character
            fgets(inventory[i].name, sizeof(inventory[i].name), stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // Remove newline character
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to delete a product
void deleteProduct(Product *inventory, int *productCount) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products left
            }
            (*productCount)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to save inventory to a file
void saveInventory(Product *inventory, int productCount) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error saving inventory.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
}

// Function to load inventory from a file
void loadInventory(Product *inventory, int *productCount) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No previous inventory file found, starting with an empty inventory.\n");
        return;
    }
    
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &inventory[*productCount].id, 
                  inventory[*productCount].name, 
                  &inventory[*productCount].quantity, 
                  &inventory[*productCount].price) != EOF) {
        (*productCount)++;
    }
    fclose(file);
    printf("Inventory loaded successfully!\n");
}