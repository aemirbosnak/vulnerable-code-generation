//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct Product {
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function declarations
void addProduct();
void viewInventory();
void updateProduct();
void deleteProduct();
void calculateTotalValue();
void menu();
void clearInputBuffer();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n------ Product Inventory System ------\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Calculate Total Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: calculateTotalValue(); break;
            case 6: printf("Exiting the system.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    printf("Enter product name: ");
    fgets(inventory[productCount].name, NAME_LENGTH, stdin);
    inventory[productCount].name[strcspn(inventory[productCount].name, "\n")] = 0; // Remove newline

    printf("Enter product quantity: ");
    scanf("%d", &inventory[productCount].quantity);
    clearInputBuffer();

    printf("Enter product price: ");
    scanf("%lf", &inventory[productCount].price);
    clearInputBuffer();

    productCount++;
    printf("Product added successfully!\n");
}

void viewInventory() {
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("\n----- Current Inventory -----\n");
    printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-30s %-10d $%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    char name[NAME_LENGTH];
    printf("Enter the product name to update: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            clearInputBuffer();

            printf("Enter new price: ");
            scanf("%lf", &inventory[i].price);
            clearInputBuffer();
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct() {
    char name[NAME_LENGTH];
    printf("Enter the product name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void calculateTotalValue() {
    double totalValue = 0.0;
    for (int i = 0; i < productCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    printf("Total inventory value: $%.2f\n", totalValue);
}