//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    int id;
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count);
void viewProducts(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void displayMenu();

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Please select an option (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                viewProducts(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                printf("Exiting the Product Inventory System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void addProduct(Product *inventory, int *count) {
    if (*count < MAX_PRODUCTS) {
        Product newProduct;
        newProduct.id = *count + 1; // Simple ID assignment
        printf("Enter product name: ");
        getchar(); // consume newline
        fgets(newProduct.name, PRODUCT_NAME_LENGTH, stdin);
        strtok(newProduct.name, "\n"); // Remove newline character
        printf("Enter quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter price: ");
        scanf("%f", &newProduct.price);
        
        inventory[*count] = newProduct;
        (*count)++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full! Unable to add new product.\n");
    }
}

void viewProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in the inventory.\n");
        return;
    }
    
    printf("\n--- Current Product Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }
    
    Product *product = &inventory[id - 1];
    printf("Current Name: %s\n", product->name);
    printf("Enter new name (or press enter to keep current): ");
    getchar(); // consume newline
    char newName[PRODUCT_NAME_LENGTH];
    fgets(newName, PRODUCT_NAME_LENGTH, stdin);
    strtok(newName, "\n"); // Remove newline character
    if (strlen(newName) > 0) {
        strcpy(product->name, newName);
    }

    printf("Current Quantity: %d\n", product->quantity);
    printf("Enter new quantity (-1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        product->quantity = newQuantity;
    }

    printf("Current Price: %.2f\n", product->price);
    printf("Enter new price (-1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        product->price = newPrice;
    }
    printf("Product updated successfully!\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products left
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}