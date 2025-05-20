//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: introspective
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

typedef struct {
    Product products[MAX_PRODUCTS];
    int size;
} Inventory;

// Function declarations
void addProduct(Inventory *inventory);
void viewProducts(const Inventory *inventory);
void updateProduct(Inventory *inventory);
void deleteProduct(Inventory *inventory);
void searchProduct(const Inventory *inventory);
void displayMenu();
void clearBuffer();

int main() {
    Inventory inventory = { .size = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                viewProducts(&inventory);
                break;
            case 3:
                updateProduct(&inventory);
                break;
            case 4:
                deleteProduct(&inventory);
                break;
            case 5:
                searchProduct(&inventory);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a product to the inventory
void addProduct(Inventory *inventory) {
    if (inventory->size >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    clearBuffer();
    printf("Enter product name: ");
    fgets(newProduct.name, 50, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory->products[inventory->size] = newProduct;
    inventory->size++;
    printf("Product added successfully!\n");
}

// Function to view all products in the inventory
void viewProducts(const Inventory *inventory) {
    printf("Product ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("%d\t\t%s\t%d\t\t%.2f\n",
               inventory->products[i].id,
               inventory->products[i].name,
               inventory->products[i].quantity,
               inventory->products[i].price);
    }
}

// Function to update a product in the inventory
void updateProduct(Inventory *inventory) {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", inventory->products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory->products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory->products[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to delete a product from the inventory
void deleteProduct(Inventory *inventory) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            found = 1;
            inventory->products[i] = inventory->products[inventory->size - 1]; // Replace with last product
            inventory->size--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to search for a product in the inventory
void searchProduct(const Inventory *inventory) {
    int id, found = 0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            found = 1;
            printf("Found product: %s - Quantity: %d, Price: %.2f\n",
                   inventory->products[i].name,
                   inventory->products[i].quantity,
                   inventory->products[i].price);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nInventory Management System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}