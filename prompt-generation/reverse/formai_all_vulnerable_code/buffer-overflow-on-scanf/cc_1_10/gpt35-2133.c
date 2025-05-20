//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

// define structures
struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
};

struct ProductInventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

// function declarations
void menu();
int addProduct(struct ProductInventory *inventory, struct Product product);
void listProducts(struct ProductInventory *inventory);
int findProductById(struct ProductInventory *inventory, int id);
void updateProduct(struct ProductInventory *inventory, int id, struct Product updatedProduct);
void deleteProduct(struct ProductInventory *inventory, int id);

// main function
int main() {
    // declare variables
    struct ProductInventory inventory;
    inventory.count = 0;
    struct Product product;
    int choice, id;
    char name[MAX_NAME_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
    struct Product updatedProduct;

    // display menu
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // add product
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product description: ");
                scanf("%s", description);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                product.id = inventory.count + 1;
                strcpy(product.name, name);
                strcpy(product.description, description);
                product.price = price;
                product.quantity = quantity;
                addProduct(&inventory, product);
                break;
            case 2:
                // list products
                listProducts(&inventory);
                break;
            case 3:
                // update product
                printf("Enter product ID: ");
                scanf("%d", &id);
                if (findProductById(&inventory, id) != -1) {
                    printf("Enter updated product name: ");
                    scanf("%s", name);
                    printf("Enter updated product description: ");
                    scanf("%s", description);
                    printf("Enter updated product price: ");
                    scanf("%f", &price);
                    printf("Enter updated product quantity: ");
                    scanf("%d", &quantity);
                    updatedProduct.id = id;
                    strcpy(updatedProduct.name, name);
                    strcpy(updatedProduct.description, description);
                    updatedProduct.price = price;
                    updatedProduct.quantity = quantity;
                    updateProduct(&inventory, id, updatedProduct);
                } else {
                    printf("Product not found.\n");
                }
                break;
            case 4:
                // delete product
                printf("Enter product ID: ");
                scanf("%d", &id);
                if (findProductById(&inventory, id) != -1) {
                    deleteProduct(&inventory, id);
                } else {
                    printf("Product not found.\n");
                }
                break;
            case 5:
                // exit program
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// function definitions
void menu() {
    printf("=======================================\n");
    printf("             PRODUCT MENU\n");
    printf("=======================================\n");
    printf("1. Add product\n");
    printf("2. List products\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Exit\n");
}

int addProduct(struct ProductInventory *inventory, struct Product product) {
    if (inventory->count < MAX_PRODUCTS) {
        inventory->products[inventory->count] = product;
        inventory->count++;
        printf("Product added successfully.\n");
        return 1;
    } else {
        printf("Product inventory is full. Cannot add more products.\n");
        return 0;
    }
}

void listProducts(struct ProductInventory *inventory) {
    printf("=======================================\n");
    printf("             PRODUCT LIST\n");
    printf("=======================================\n");
    printf("%-5s %-30s %-30s %-10s %-10s\n", "ID", "Name", "Description", "Price", "Quantity");
    for (int i = 0; i < inventory->count; i++) {
        printf("%-5d %-30s %-30s $%-9.2f %-10d\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].description, inventory->products[i].price, inventory->products[i].quantity);
    }
}

int findProductById(struct ProductInventory *inventory, int id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            return i;
        }
    }
    return -1;
}

void updateProduct(struct ProductInventory *inventory, int id, struct Product updatedProduct) {
    int index = findProductById(inventory, id);
    if (index != -1) {
        inventory->products[index] = updatedProduct;
        printf("Product updated successfully.\n");
    } else {
        printf("Product not found.\n");
    }
}

void deleteProduct(struct ProductInventory *inventory, int id) {
    int index = findProductById(inventory, id);
    if (index != -1) {
        for (int i = index; i < inventory->count - 1; i++) {
            inventory->products[i] = inventory->products[i + 1];
        }
        inventory->count--;
        printf("Product deleted successfully.\n");
    } else {
        printf("Product not found.\n");
    }
}