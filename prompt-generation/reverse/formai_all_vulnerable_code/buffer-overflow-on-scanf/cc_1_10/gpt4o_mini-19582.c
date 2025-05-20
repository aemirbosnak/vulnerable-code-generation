//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if(productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    Product newProduct;

    printf("Enter Product Name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;

    printf("Product added successfully!\n");
}

void viewProducts() {
    if(productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-8s | %-10s |\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < productCount; i++) {
        printf("| %-5d | %-20s | %-8d | $%-9.2f |\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------------------------------------\n");
}

void updateProduct() {
    int id, found = 0;

    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < productCount; i++) {
        if(inventory[i].id == id) {
            found = 1;

            printf("Updating Product: %s\n", inventory[i].name);
            printf("Enter new quantity (current: %d): ", inventory[i].quantity);
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price (current: $%.2f): ", inventory[i].price);
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;

    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < productCount; i++) {
        if(inventory[i].id == id) {
            found = 1;
            for(int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if(!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void searchProduct() {
    int id, found = 0;

    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < productCount; i++) {
        if(inventory[i].id == id) {
            found = 1;
            printf("Product found: %s - Quantity: %d, Price: $%.2f\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            break;
        }
    }

    if(!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void menu() {
    int choice;

    do {
        printf("\n----- Inventory Management System -----\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while(choice != 6);
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    menu();
    return 0;
}