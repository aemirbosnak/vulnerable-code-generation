//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void modifyProduct() {
    int id, i;
    printf("Enter Product ID to modify: ");
    scanf("%d", &id);
    for (i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new Product Name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new Product Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Product modified successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct() {
    int id, i, j;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift left
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("\nID\tName\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void searchProduct() {
    int id, i;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("\nFound Product:\nID: %d\nName: %s\nQuantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. Modify Product\n");
    printf("3. Delete Product\n");
    printf("4. List Products\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

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
                modifyProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}