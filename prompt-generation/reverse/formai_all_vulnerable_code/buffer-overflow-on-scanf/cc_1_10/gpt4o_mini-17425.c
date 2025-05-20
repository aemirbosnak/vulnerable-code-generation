//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: rigorous
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

void listProducts(Product products[], int count);
void addProduct(Product products[], int *count);
void updateProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);
void saveToFile(Product products[], int count);
void loadFromFile(Product products[], int *count);
void displayMenu();

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;
    loadFromFile(products, &count);
    
    do {
        displayMenu();
        printf("Choose an option (1-5, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listProducts(products, count);
                break;
            case 2:
                addProduct(products, &count);
                break;
            case 3:
                updateProduct(products, count);
                break;
            case 4:
                deleteProduct(products, &count);
                break;
            case 5:
                saveToFile(products, count);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. List Products\n");
    printf("2. Add Product\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save to File\n");
    printf("0. Exit\n");
}

void listProducts(Product products[], int count) {
    printf("\n--- Product List ---\n");
    if (count == 0) {
        printf("No products available.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                products[i].id, 
                products[i].name, 
                products[i].quantity, 
                products[i].price);
    }
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Cannot add more products. Inventory full.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple incremental ID
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully.\n");
}

void updateProduct(Product products[], int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new price: ");
    scanf("%f", &product->price);
    printf("Product updated successfully.\n");
}

void deleteProduct(Product products[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully.\n");
}

void saveToFile(Product products[], int count) {
    FILE *file = fopen("products.txt", "w");
    if (!file) {
        printf("Unable to save to file.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %.2f\n", 
                products[i].id, 
                products[i].name, 
                products[i].quantity, 
                products[i].price);
    }
    fclose(file);
    printf("Products saved to file successfully.\n");
}

void loadFromFile(Product products[], int *count) {
    FILE *file = fopen("products.txt", "r");
    if (!file) {
        printf("No existing inventory file found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d %s %d %f", 
                  &products[*count].id, 
                  products[*count].name, 
                  &products[*count].quantity, 
                  &products[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Products loaded from file successfully.\n");
}