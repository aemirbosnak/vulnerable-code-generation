//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

// Structure that defines a product
typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct(Product products[], int *count);
void viewInventory(Product products[], int count);
void searchProduct(Product products[], int count);
void removeProduct(Product products[], int *count);
void clearInputBuffer();

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search Product\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                viewInventory(products, productCount);
                break;
            case 3:
                searchProduct(products, productCount);
                break;
            case 4:
                removeProduct(products, &productCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    clearInputBuffer(); // Clear the input buffer

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully.\n");
}

void viewInventory(Product products[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product products[], int count) {
    if (count == 0) {
        printf("No products in inventory to search.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    printf("Enter the product name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("Product found: \n");
            printf("Name: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

void removeProduct(Product products[], int *count) {
    if (*count == 0) {
        printf("No products to remove.\n");
        return;
    }
    char removeName[NAME_LENGTH];
    printf("Enter the product name to remove: ");
    fgets(removeName, NAME_LENGTH, stdin);
    removeName[strcspn(removeName, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(products[i].name, removeName) == 0) {
            products[i] = products[*count - 1]; // Replace with last product
            (*count)--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}