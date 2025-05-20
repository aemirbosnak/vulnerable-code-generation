//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum products
#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

// Structure to hold product information
struct Product {
    int id;
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
};

// Function Prototypes
void addProduct(struct Product inventory[], int *count);
void displayProducts(struct Product inventory[], int count);
void searchProduct(struct Product inventory[], int count);
void modifyProduct(struct Product inventory[], int count);
void deleteProduct(struct Product inventory[], int *count);

int main() {
    struct Product inventory[MAX_PRODUCTS];
    int count = 0; // Current number of products
    int choice;

    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Modify Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                modifyProduct(inventory, count);
                break;
            case 5:
                deleteProduct(inventory, &count);
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addProduct(struct Product inventory[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    struct Product newProduct;

    newProduct.id = *count + 1;  // ID starts from 1
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[*count] = newProduct; 
    (*count)++; 

    printf("Product added successfully!\n");
}

void displayProducts(struct Product inventory[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n== Products in Inventory ==\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].id, inventory[i].name, 
               inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(struct Product inventory[], int count) {
    char searchName[PRODUCT_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   inventory[i].id, inventory[i].name, 
                   inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void modifyProduct(struct Product inventory[], int count) {
    int id;
    printf("Enter product ID to modify: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid ID, no product found.\n");
        return;
    }

    struct Product *product = &inventory[id - 1];
    printf("Modify details for ID: %d, current name: %s, quantity: %d, price: %.2f\n", 
           product->id, product->name, product->quantity, product->price);
    
    printf("Enter new product name: ");
    scanf("%s", product->name);
    printf("Enter new product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new product price: ");
    scanf("%f", &product->price);

    printf("Product modified successfully!\n");
}

void deleteProduct(struct Product inventory[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid ID, no product found.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products to the left
    }
    
    (*count)--;
    printf("Product deleted successfully!\n");
}