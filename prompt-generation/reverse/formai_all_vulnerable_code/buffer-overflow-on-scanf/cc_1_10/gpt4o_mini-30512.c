//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: complex
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

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. List Products\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int getProductIndex(Product products[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple id generation
    printf("Enter product name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully! ID: %d\n", newProduct.id);
}

void updateProduct(Product products[], int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    int index = getProductIndex(products, count, id);
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    printf("Updating product: %s\n", products[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &products[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &products[index].price);
    
    printf("Product updated successfully!\n");
}

void deleteProduct(Product products[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    int index = getProductIndex(products, *count, id);
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    
    for (int i = index; i < (*count) - 1; i++) {
        products[i] = products[i + 1];
    }
    
    (*count)--;
    printf("Product deleted successfully!\n");
}

void listProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }
    
    printf("\n=== List of Products ===\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                updateProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                listProducts(products, count);
                break;
            case 5:
                printf("Exiting application...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}