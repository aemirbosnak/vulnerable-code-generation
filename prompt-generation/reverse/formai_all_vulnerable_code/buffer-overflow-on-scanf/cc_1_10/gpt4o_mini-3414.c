//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    char category[30];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product p;
    printf("Enter product name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter product category: ");
    scanf(" %[^\n]", p.category);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    
    inventory[productCount++] = p;
    printf("Product added successfully!\n");
}

void deleteProduct() {
    char name[50];
    printf("Enter product name to delete: ");
    scanf(" %[^\n]", name);

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

void searchProduct() {
    char name[50];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Category: %s\n", inventory[i].category);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("%-20s %-15s %-10s %-10s\n", "Product Name", "Category", "Quantity", "Price");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-15s %-10d %-10.2f\n", inventory[i].name, inventory[i].category, inventory[i].quantity, inventory[i].price);
    }
}

void showMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Product\n");
    printf("2. Delete Product\n");
    printf("3. Search Product\n");
    printf("4. Display Inventory\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}