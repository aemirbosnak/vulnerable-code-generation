//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
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

void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
int findProductById(int id);
void displayMenu();

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
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
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

    printf("\n--- Product List ---\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = findProductById(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    printf("Updating product ID: %d\n", id);
    printf("Enter new product name: ");
    scanf("%s", inventory[index].name);
    printf("Enter new product quantity: ");
    scanf("%d", &inventory[index].quantity);
    printf("Enter new product price: ");
    scanf("%f", &inventory[index].price);

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int index = findProductById(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    for (int i = index; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    product_count--;
    printf("Product deleted successfully!\n");
}

int findProductById(int id) {
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}