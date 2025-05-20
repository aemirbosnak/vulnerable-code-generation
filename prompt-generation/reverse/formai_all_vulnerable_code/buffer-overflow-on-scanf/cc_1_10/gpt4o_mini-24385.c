//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Current Product Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", 
            i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    char name[NAME_LEN];
    printf("Enter the product name to update: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating product %s\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct() {
    char name[NAME_LEN];
    printf("Enter the product name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void saveInventory() {
    FILE *file = fopen("inventory.dat", "wb");
    if (!file) {
        printf("Unable to open file for writing!\n");
        return;
    }
    fwrite(inventory, sizeof(Product), productCount, file);
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventory() {
    FILE *file = fopen("inventory.dat", "rb");
    if (!file) {
        printf("Unable to open file for reading!\n");
        return;
    }
    productCount = fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    printf("Inventory loaded successfully!\n");
}

void showMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Inventory\n");
    printf("6. Load Inventory\n");
    printf("7. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                saveInventory();
                break;
            case 6:
                loadInventory();
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}