//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    strtok(newProduct.name, "\n"); // Remove newline character
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%lf", &newProduct.price);
    getchar(); // Clear the newline character after scanf

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewInventory() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nProduct Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-10d $%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the product to search for: ");
    fgets(searchName, NAME_LENGTH, stdin);
    strtok(searchName, "\n"); // Remove newline character

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Product found!\n");
            printf("Name: %s\nQuantity: %d\nPrice: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void menu() {
    int choice;
    do {
        printf("\nInventory Menu:\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character after scanf

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    menu();
    return 0;
}