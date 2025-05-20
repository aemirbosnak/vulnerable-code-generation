//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
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
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full, cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    getchar(); // consume newline character
    printf("Enter Product Name: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // remove newline
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("Product Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product ID %d:\n", id);
            printf("Enter new Product Name: ");
            getchar(); // consume newline character
            fgets(inventory[i].name, sizeof(inventory[i].name), stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // remove newline
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

int main() {
    int option;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}