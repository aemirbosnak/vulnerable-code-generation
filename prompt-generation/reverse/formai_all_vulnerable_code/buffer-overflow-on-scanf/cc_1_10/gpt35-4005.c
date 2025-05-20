//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products in the inventory
#define MAX_NAME_LENGTH 50 // maximum length of product name
#define MAX_DESC_LENGTH 200 // maximum length of product description

// define the product struct
typedef struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    float price;
    int quantity;
} Product;

// define the inventory struct
typedef struct inventory {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

// function to add a new product to the inventory
void addProduct(Inventory *inventory) {
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product description: ");
    scanf("%s", product.description);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    product.id = inventory->count + 1;
    inventory->products[inventory->count++] = product;
    printf("Product added successfully.\n");
}

// function to search for a product by name
void searchProduct(Inventory *inventory) {
    char query[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", query);
    for(int i = 0; i < inventory->count; i++) {
        if(strcmp(inventory->products[i].name, query) == 0) {
            printf("Product id: %d\n", inventory->products[i].id);
            printf("Product name: %s\n", inventory->products[i].name);
            printf("Product description: %s\n", inventory->products[i].description);
            printf("Product price: %.2f\n", inventory->products[i].price);
            printf("Product quantity: %d\n", inventory->products[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

// function to update a product's quantity
void updateQuantity(Inventory *inventory) {
    int id, quantity;
    printf("Enter product id to update: ");
    scanf("%d", &id);
    for(int i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            inventory->products[i].quantity = quantity;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// function to display all products in the inventory
void displayProducts(Inventory *inventory) {
    printf("%-5s %-20s %-30s %-10s %-10s\n", "ID", "Name", "Description", "Price", "Quantity");
    for(int i = 0; i < inventory->count; i++) {
        printf("%-5d %-20s %-30s %-10.2f %-10d\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].description, inventory->products[i].price, inventory->products[i].quantity);
    }
}

int main() {
    Inventory inventory;
    inventory.count = 0;
    int choice;
    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Update quantity\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                searchProduct(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                displayProducts(&inventory);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}