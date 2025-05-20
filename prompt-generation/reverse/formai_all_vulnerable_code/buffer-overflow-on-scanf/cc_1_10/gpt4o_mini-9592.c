//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: optimized
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
int product_count = 0;

void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full. Can't add more products.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]%*c", new_product.name);
    
    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);
    
    printf("Enter price: ");
    scanf("%f", &new_product.price);
    
    inventory[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &inventory[id - 1];
    
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    
    printf("Enter new price: ");
    scanf("%f", &product->price);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    product_count--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char search_name[NAME_LENGTH];
    printf("Enter the product name to search: ");
    scanf(" %[^\n]%*c", search_name);

    int found = 0;
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < product_count; i++) {
        if (strstr(inventory[i].name, search_name) != NULL) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No products found with the name '%s'.\n", search_name);
    }
}

void saveInventory(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(inventory, sizeof(Product), product_count, file);
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous inventory found. Starting fresh.\n");
        return;
    }
    
    product_count = fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    printf("Inventory loaded successfully! %d products loaded.\n", product_count);
}

int main() {
    int choice;
    loadInventory("inventory.dat");

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Save Inventory\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: saveInventory("inventory.dat"); break;
            case 7: printf("Exiting... \n"); break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}