//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int total_products = 0;

void addProduct() {
    if (total_products < MAX_PRODUCTS) {
        Product newProduct;
        newProduct.id = total_products + 1;

        printf("Enter product name: ");
        scanf("%s", newProduct.name);
        
        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);

        printf("Enter product price: ");
        scanf("%f", &newProduct.price);
        
        inventory[total_products++] = newProduct;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void viewProducts() {
    if (total_products == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("\nCurrent Inventory:\n");
        printf("ID\tName\t\tQuantity\tPrice\n");
        for (int i = 0; i < total_products; i++) {
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= total_products) {
        printf("Updating Product ID %d\n", id);
        printf("Enter new name (current: %s): ", inventory[id - 1].name);
        scanf("%s", inventory[id - 1].name);
        
        printf("Enter new quantity (current: %d): ", inventory[id - 1].quantity);
        scanf("%d", &inventory[id - 1].quantity);
        
        printf("Enter new price (current: %.2f): ", inventory[id - 1].price);
        scanf("%f", &inventory[id - 1].price);
        
        printf("Product updated successfully!\n");
    } else {
        printf("Invalid ID!\n");
    }
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= total_products) {
        for (int i = id - 1; i < total_products - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        total_products--;
        printf("Product deleted successfully!\n");
    } else {
        printf("Invalid ID!\n");
    }
}

void searchProduct() {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product Found! ID: %d, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: printf("Exiting the program.\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}