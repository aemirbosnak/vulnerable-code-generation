//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: authentic
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
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
            inventory[i].id, 
            inventory[i].name, 
            inventory[i].quantity, 
            inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Updating Product: %s\n", product->name);

    printf("Enter new name (or press enter to keep unchanged): ");
    char name[NAME_LENGTH];
    fgets(name, NAME_LENGTH, stdin); // clean newline before reading
    fgets(name, NAME_LENGTH, stdin);
    if (strlen(name) > 1) {
        name[strcspn(name, "\n")] = 0; // remove newline
        strcpy(product->name, name);
    }

    printf("Enter new quantity (-1 to keep unchanged): ");
    int quantity;
    scanf("%d", &quantity);
    if (quantity != -1) {
        product->quantity = quantity;
    }

    printf("Enter new price (-1 to keep unchanged): ");
    float price;
    scanf("%f", &price);
    if (price != -1) {
        product->price = price;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 5);

    return 0;
}