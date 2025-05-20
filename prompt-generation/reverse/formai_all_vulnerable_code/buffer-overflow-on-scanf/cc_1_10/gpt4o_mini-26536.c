//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold product information
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function declarations
void addProduct(Product *products, int *count);
void removeProduct(Product *products, int *count);
void displayProducts(const Product *products, int count);
void saveProductsToFile(const Product *products, int count);
void loadProductsFromFile(Product *products, int *count);

int main() {
    Product products[100]; // Array to store products
    int count = 0; // Number of products
    int option;

    loadProductsFromFile(products, &count); // Load existing products

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Save Products to File\n");
        printf("5. Load Products from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                removeProduct(products, &count);
                break;
            case 3:
                displayProducts(products, count);
                break;
            case 4:
                saveProductsToFile(products, count);
                break;
            case 5:
                loadProductsFromFile(products, &count);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 6);

    return 0;
}

// Function to add a product
void addProduct(Product *products, int *count) {
    if (*count >= 100) {
        printf("Product list is full, unable to add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name); // Validated input for simplicity
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    products[*count] = newProduct; // Add new product to the list
    (*count)++;
    printf("Product added successfully!\n");
}

// Function to remove a product
void removeProduct(Product *products, int *count) {
    int id, index = -1;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        for (int i = index; i < (*count) - 1; i++) {
            products[i] = products[i + 1]; // Shift products left
        }
        (*count)--;
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found!\n");
    }
}

// Function to display all products
void displayProducts(const Product *products, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nProduct ID\tProduct Name\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to save products to a file
void saveProductsToFile(const Product *products, int count) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    fclose(file);
    printf("Products saved to file successfully!\n");
}

// Function to load products from a file
void loadProductsFromFile(Product *products, int *count) {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("No existing file found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%d %s %d %f", &products[*count].id, products[*count].name, &products[*count].quantity, &products[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Products loaded from file successfully!\n");
}