//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n====================================\n");
    printf("!!! WELCOME TO PRODUCT INVENTORY !!!\n");
    printf("====================================\n");
    printf("1. Add New Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. View Products\n");
    printf("5. Exit\n");
    printf("====================================\n");
    printf("Please enter your choice: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("!!! Oops! Can't add more products, inventory is full! !!!\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%lf", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("!!! Product Added Successfully! ID: %d !!!\n", newProduct.id);
}

void updateProduct() {
    int id;
    printf("Enter Product ID to Update: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("!!! Invalid Product ID! No such product exists! !!!\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Updating Product ID: %d\n", product->id);
    printf("Current Name: %s, Quantity: %d, Price: %.2f\n", product->name, product->quantity, product->price);
    
    printf("Enter new product name: ");
    scanf("%s", product->name);
    printf("Enter new product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new product price: ");
    scanf("%lf", &product->price);

    printf("!!! Product Updated Successfully! ID: %d !!!\n", product->id);
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to Delete: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("!!! Invalid Product ID! No such product exists! !!!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("!!! Product Deleted Successfully! ID: %d !!!\n", id);
}

void viewProducts() {
    if (productCount == 0) {
        printf("!!! No products in inventory! Add some products first! !!!\n");
        return;
    }
    
    printf("====================================\n");
    printf("!!! Product Inventory List !!!\n");
    printf("====================================\n");
    for (int i = 0; i < productCount; ++i) {
        Product p = inventory[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", p.id, p.name, p.quantity, p.price);
    }
    printf("====================================\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                printf("!!! Thank you for using the Inventory System! Goodbye! !!!\n");
                exit(0);
            default:
                printf("!!! Invalid choice! Please select a valid option! !!!\n");
                break;
        }
    }
    return 0;
}