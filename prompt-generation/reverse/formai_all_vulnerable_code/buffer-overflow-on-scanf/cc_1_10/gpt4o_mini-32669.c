//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int size;
} Inventory;

// Function declarations
void initializeInventory(Inventory* inventory);
void addProduct(Inventory* inventory);
void deleteProduct(Inventory* inventory);
void displayProducts(Inventory* inventory);
void searchProduct(Inventory* inventory);
void menu();

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    menu(&inventory);
    return 0;
}

void initializeInventory(Inventory* inventory) {
    inventory->size = 0;
}

void addProduct(Inventory* inventory) {
    if (inventory->size >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = inventory->size + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory->products[inventory->size] = newProduct;
    inventory->size++;
    printf("Product added successfully!\n");
}

void deleteProduct(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty. No products to delete.\n");
        return;
    }

    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > inventory->size) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < inventory->size - 1; ++i) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->size--;
    printf("Product deleted successfully!\n");
}

void displayProducts(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProducts in Inventory:\n");
    for (int i = 0; i < inventory->size; ++i) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
               inventory->products[i].id,
               inventory->products[i].name,
               inventory->products[i].price,
               inventory->products[i].quantity);
    }
}

void searchProduct(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("No products in inventory.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    int found = 0;

    printf("Search Results:\n");
    for (int i = 0; i < inventory->size; ++i) {
        if (strcmp(inventory->products[i].name, searchName) == 0) {
            printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                   inventory->products[i].id,
                   inventory->products[i].name,
                   inventory->products[i].price,
                   inventory->products[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

void menu(Inventory* inventory) {
    int choice;
    do {
        printf("\nInventory Menu:\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Products\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                deleteProduct(inventory);
                break;
            case 3:
                displayProducts(inventory);
                break;
            case 4:
                searchProduct(inventory);
                break;
            case 5:
                printf("Exiting the inventory system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}