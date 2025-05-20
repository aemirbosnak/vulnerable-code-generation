//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void viewProducts();
void editProduct();
void deleteProduct();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: editProduct(); break;
            case 4: deleteProduct(); break;
            case 5: printf("Exiting the system.\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Edit Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }
    
    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].price,
               inventory[i].quantity);
    }
}

void editProduct() {
    int id;
    printf("Enter product ID to edit: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *prod = &inventory[id - 1];
    printf("Editing product - ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", prod->id, prod->name, prod->price, prod->quantity);
    printf("Enter new name (or '-' to keep the same): ");
    char newName[NAME_LENGTH];
    scanf(" %[^\n]s", newName);
    if (strcmp(newName, "-") != 0) {
        strcpy(prod->name, newName);
    }
    
    printf("Enter new price (-1 to keep the same): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        prod->price = newPrice;
    }

    printf("Enter new quantity (-1 to keep the same): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        prod->quantity = newQuantity;
    }
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    // Shift products down to fill the gap
    for (int i = id-1; i < productCount-1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}