//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
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
        printf("Oh no! The inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment
    printf("What's the name of the product?\n");
    scanf(" %[^\n]", newProduct.name);
    printf("How many units of %s do you have?\n", newProduct.name);
    scanf("%d", &newProduct.quantity);
    printf("What is the price of %s?\n", newProduct.name);
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product %s added successfully!\n", newProduct.name);
}

void viewProducts() {
    if (productCount == 0) {
        printf("Hmm, it looks like the inventory is empty.\n");
        return;
    }
    
    printf("Here's a look at the products we have:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: $%.2f\n",
               inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Which product ID would you like to update?\n");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Hmm, no product found with ID %d.\n", id);
        return;
    }
    
    printf("Updating product %s...\n", inventory[id - 1].name);
    printf("New name for the product (current: %s)? (leave blank to keep current)\n", inventory[id - 1].name);
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName);
    
    if (strlen(newName) > 0) {
        strcpy(inventory[id - 1].name, newName);
    }
    
    printf("New quantity for the product? (current: %d)\n", inventory[id - 1].quantity);
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity >= 0) {
        inventory[id - 1].quantity = newQuantity;
    }
    
    printf("New price for the product? (current: $%.2f)\n", inventory[id - 1].price);
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0.0) {
        inventory[id - 1].price = newPrice;
    }
    
    printf("Product ID %d updated successfully!\n", inventory[id - 1].id);
}

void deleteProduct() {
    int id;
    printf("Which product ID would you like to delete?\n");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Hmm, no product found with ID %d.\n", id);
        return;
    }
    
    printf("Are you sure you want to delete %s? (y/n)\n", inventory[id - 1].name);
    char confirmation;
    scanf(" %c", &confirmation);
    
    if (confirmation == 'y' || confirmation == 'Y') {
        for (int i = id - 1; i < productCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        productCount--;
        printf("Product %d deleted successfully!\n", id);
    } else {
        printf("Deletion of product %d aborted.\n", id);
    }
}

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: printf("Exiting the inventory system. Goodbye!\n"); break;
            default: printf("Hmm, that's not a valid option. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}