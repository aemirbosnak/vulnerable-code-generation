//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
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

void addProduct();
void viewProducts();
void removeProduct();
void updateProductQuantity();
void searchProduct();
void displayMenu();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                updateProductQuantity();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting the Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System Menu ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Remove Product\n");
    printf("4. Update Product Quantity\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        Product newProduct;

        printf("Enter Product ID: ");
        scanf("%d", &newProduct.id);
        clearBuffer();
        
        printf("Enter Product Name: ");
        fgets(newProduct.name, NAME_LENGTH, stdin);
        newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
        
        printf("Enter Product Quantity: ");
        scanf("%d", &newProduct.quantity);
        
        printf("Enter Product Price: ");
        scanf("%f", &newProduct.price);

        inventory[productCount] = newProduct;
        productCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full! Cannot add more products.\n");
    }
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
}

void removeProduct() {
    if (productCount == 0) {
        printf("No products to remove.\n");
        return;
    }

    int id;
    printf("Enter Product ID to remove: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}

void updateProductQuantity() {
    if (productCount == 0) {
        printf("No products to update.\n");
        return;
    }

    int id;
    printf("Enter Product ID to update quantity: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            int newQuantity;
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Product quantity updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}

void searchProduct() {
    if (productCount == 0) {
        printf("No products to search.\n");
        return;
    }

    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name,
                   inventory[i].quantity, inventory[i].price);
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}