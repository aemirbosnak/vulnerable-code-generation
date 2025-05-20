//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Simple id assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", 
               inventory[i].id, 
               inventory[i].name,
               inventory[i].price, 
               inventory[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    printf("Enter new price: ");
    scanf("%f", &p->price);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error saving inventory.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d\t%s\t%.2f\t%d\n", 
                inventory[i].id, 
                inventory[i].name,
                inventory[i].price, 
                inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No previous inventory found.\n");
        return;
    }

    while(fscanf(file, "%d\t%s\t%f\t%d", 
               &inventory[productCount].id, 
               inventory[productCount].name,
               &inventory[productCount].price, 
               &inventory[productCount].quantity) != EOF) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) {
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded successfully!\n");
}

void displayMenu() {
    printf("\n=================== Product Inventory Menu ===================\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Inventory\n");
    printf("6. Load Inventory\n");
    printf("7. Exit\n");
    printf("==============================================================\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
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
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}