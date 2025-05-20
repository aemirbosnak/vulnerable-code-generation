//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product description: ");
    scanf(" %[^\n]", newProduct.description);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n=== Product List ===\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Description: %s, Price: %.2f, Quantity: %d\n",
               inventory[i].id, inventory[i].name, inventory[i].description,
               inventory[i].price, inventory[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product not found.\n");
        return;
    }

    Product *product = &inventory[id - 1];

    printf("Updating product: %s\n", product->name);
    printf("Enter new name (or '-' to keep current): ");
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName);
    
    if (strcmp(newName, "-") != 0) {
        strcpy(product->name, newName);
    }

    printf("Enter new description (or '-' to keep current): ");
    char newDesc[DESC_LENGTH];
    scanf(" %[^\n]", newDesc);
    
    if (strcmp(newDesc, "-") != 0) {
        strcpy(product->description, newDesc);
    }

    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    
    if (newPrice != -1) {
        product->price = newPrice;
    }

    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    
    if (newQuantity != -1) {
        product->quantity = newQuantity;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product not found.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    productCount--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", searchName);

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, searchName)) {
            printf("ID: %d, Name: %s, Description: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].id, inventory[i].name, inventory[i].description,
                   inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with that name.\n");
    }
}

int main() {
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}