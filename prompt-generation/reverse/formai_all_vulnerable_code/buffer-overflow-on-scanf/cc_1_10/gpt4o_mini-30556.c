//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: random
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
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product p;
    p.id = productCount + 1;

    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
  
    inventory[productCount] = p;
    productCount++;
    printf("Product added successfully! Product ID: %d\n", p.id);
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n--- Product Inventory ---\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", 
            inventory[i].id,
            inventory[i].name,
            inventory[i].quantity,
            inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
  
    if (id < 1 || id > productCount) {
        printf("Invalid Product ID!\n");
        return;
    }
  
    productCount--;
    Product p = inventory[id - 1];

    printf("Updating product: %s\n", p.name);
    printf("Enter new quantity (current: %d): ", p.quantity);
    scanf("%d", &p.quantity);
    printf("Enter new price (current: %.2f): ", p.price);
    scanf("%f", &p.price);

    inventory[id - 1] = p;
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
  
    if (id < 1 || id > productCount) {
        printf("Invalid Product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);
  
    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
            found = 1;
        }
    }
  
    if (!found) {
        printf("No products found with that name.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Inventory Management System ---\n");
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
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}