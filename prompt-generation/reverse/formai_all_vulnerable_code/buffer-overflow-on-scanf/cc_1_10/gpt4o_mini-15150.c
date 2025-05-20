//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayInventory();
void updateProduct();
void deleteProduct();
void searchProduct();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    
    loadFromFile();

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: saveToFile(); printf("Exiting... \n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
        
    } while (choice != 6);

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product code: ");
    scanf("%s", newProduct.code);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: Name: %s, Code: %s, Quantity: %d, Price: %.2f\n",
               i + 1, inventory[i].name, inventory[i].code, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    char code[CODE_LENGTH];
    printf("Enter the product code to update: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with code %s not found.\n", code);
}

void deleteProduct() {
    char code[CODE_LENGTH];
    printf("Enter the product code to delete: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with code %s not found.\n", code);
}

void searchProduct() {
    char code[CODE_LENGTH];
    printf("Enter the product code to search: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Product found: Name: %s, Code: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].name, inventory[i].code, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with code %s not found.\n", code);
}

void saveToFile() {
    FILE *file = fopen("inventory.dat", "wb");
    if (file == NULL) {
        printf("Error saving to file.\n");
        return;
    }
    fwrite(inventory, sizeof(Product), productCount, file);
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("inventory.dat", "rb");
    if (file == NULL) {
        printf("No previous inventory found.\n");
        return;
    }
    productCount = fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    printf("Inventory loaded successfully!\n");
}