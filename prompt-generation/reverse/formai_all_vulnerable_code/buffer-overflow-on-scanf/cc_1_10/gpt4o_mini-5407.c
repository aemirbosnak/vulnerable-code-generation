//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int total_products = 0;

void add_product() {
    if (total_products >= MAX_PRODUCTS) {
        printf("Inventory full. Can't add more products.\n");
        return;
    }

    Product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter price: ");
    scanf("%f", &new_product.price);

    inventory[total_products] = new_product;
    total_products++;
    printf("Product added successfully!\n");
}

void display_products() {
    if (total_products == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("Current Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < total_products; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    char name[NAME_LENGTH];
    printf("Enter the product name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Current quantity: %d, Current price: $%.2f\n", inventory[i].quantity, inventory[i].price);
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

void delete_product() {
    char name[NAME_LENGTH];
    printf("Enter the product name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < total_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            total_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void save_inventory(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file for saving.\n");
        return;
    }
    fwrite(inventory, sizeof(Product), total_products, file);
    fclose(file);
    printf("Inventory saved to %s\n", filename);
}

void load_inventory(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file for loading.\n");
        return;
    }
    total_products = fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    printf("Inventory loaded from %s\n", filename);
}

void menu() {
    printf("\n--- Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Inventory\n");
    printf("6. Load Inventory\n");
    printf("7. Exit\n");
    printf("--------------------------\n");
}

int main() {
    char filename[] = "inventory.dat";
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                save_inventory(filename);
                break;
            case 6:
                load_inventory(filename);
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}