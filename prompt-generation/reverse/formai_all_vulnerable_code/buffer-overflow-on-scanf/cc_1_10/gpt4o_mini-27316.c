//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define a product
typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
} Product;

// Function prototypes
void clearInputBuffer();
void addProduct(Product *inventory, int *count);
void displayInventory(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void saveInventoryToFile(Product *inventory, int count, const char *filename);
void loadInventoryFromFile(Product *inventory, int *count, const char *filename);

// Main function to drive the program
int main() {
    Product inventory[100]; // Max capacity of 100 products
    int count = 0; // Number of products
    int choice;
    const char *filename = "inventory.dat";

    // Load inventory from file if exists
    loadInventoryFromFile(inventory, &count, filename);

    do {
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save and Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        clearInputBuffer(); // To clear newline character after scanf

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                saveInventoryToFile(inventory, count, filename);
                printf("Inventory saved. Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Function to add a product
void addProduct(Product *inventory, int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = *count + 1; // ID based on count
    printf("Enter product name: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    clearInputBuffer();
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

// Function to display all products
void displayInventory(Product *inventory, int count) {
    printf("\nInventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to update product details
void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < count; ++i) {
        if (inventory[i].id == id) {
            printf("Updating Product: %s\n", inventory[i].name);
            printf("Current Quantity: %d, Current Price: %.2f\n", inventory[i].quantity, inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            clearInputBuffer();
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product ID not found!\n");
}

// Function to delete a product
void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < *count; ++i) {
        if (inventory[i].id == id) {
            for (int j = i; j < *count - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product ID not found!\n");
}

// Function to save inventory to file
void saveInventoryToFile(Product *inventory, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error saving inventory to file!\n");
        return;
    }
    fwrite(inventory, sizeof(Product), count, file);
    fclose(file);
}

// Function to load inventory from file
void loadInventoryFromFile(Product *inventory, int *count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return; // File not found, can be ignored
    }
    *count = fread(inventory, sizeof(Product), 100, file);
    fclose(file);
}