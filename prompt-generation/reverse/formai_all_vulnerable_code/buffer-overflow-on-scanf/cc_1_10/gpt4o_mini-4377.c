//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: surprised
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
int count = 0;

void displayMenu() {
    printf("\n*** Product Inventory System ***\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addProduct() {
    if (count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = count + 1;
    
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[count++] = newProduct;
    printf("Product added successfully! Product ID: %d\n", newProduct.id);
}

void viewProducts() {
    printf("\n*** List of Products ***\n");
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].id, inventory[i].name, 
                inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid Product ID!\n");
        return;
    }
    
    int index = id - 1;
    
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

    if (id < 1 || id > count) {
        printf("Invalid Product ID!\n");
        return;
    }
    
    for (int i = id - 1; i < count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    count--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);

    printf("\n*** Search Results ***\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                    inventory[i].id, inventory[i].name, 
                    inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Product not found!\n");
    }
}

int main() {
    int choice;
    do {
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
                searchProduct();
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}