//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
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

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full, unable to add more products.\n");
        return;
    }
    
    Product p;
    p.id = *count + 1; // ID based on current count
    printf("Enter product name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    products[*count] = p;
    (*count)++;
    
    printf("Product added successfully!\n");
}

void displayProducts(Product products[], int count) {
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product products[], int count) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Product Found: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateProduct(Product products[], int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Updating product %s\n", products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct(Product products[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                deleteProduct(products, &count);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}