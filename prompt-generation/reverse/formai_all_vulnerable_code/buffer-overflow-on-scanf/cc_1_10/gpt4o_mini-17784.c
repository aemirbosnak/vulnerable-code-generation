//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment starting from 1
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("| ID | Name                            | Quantity | Price   |\n");
    printf("|----|---------------------------------|----------|---------|\n");
    
    for (int i = 0; i < productCount; i++) {
        printf("| %2d | %-31s | %8d | %.2f  |\n", 
            inventory[i].id, 
            inventory[i].name, 
            inventory[i].quantity, 
            inventory[i].price);
    }
    printf("|----|---------------------------------|----------|---------|\n");
}

void updateProduct() {
    viewProducts();
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product* product = &inventory[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    viewProducts();
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    // Shift products down to fill the gap
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", 
            inventory[i].id, 
            inventory[i].name, 
            inventory[i].quantity, 
            inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No saved inventory to load. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
            &inventory[productCount].id, 
            inventory[productCount].name, 
            &inventory[productCount].quantity, 
            &inventory[productCount].price) == 4) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) break; // Prevent overflow
    }
    
    fclose(file);
    printf("Inventory loaded from inventory.txt\n");
}

int main() {
    loadInventory();
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: saveInventory(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    saveInventory(); // Save inventory before exiting
    return 0;
}