//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold product information
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void addProduct(struct Product *inventory, int *count);
void displayProducts(struct Product *inventory, int count);
void searchProduct(struct Product *inventory, int count);

// Main function
int main() {
    struct Product inventory[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n==============================\n");
        printf("  Medical Store Management     \n");
        printf("==============================\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again...\n");
        }
    }
    return 0;
}

// Function to add a product
void addProduct(struct Product *inventory, int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add more products...\n");
        return;
    }
    struct Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully! 🎉\n");
}

// Function to display all products
void displayProducts(struct Product *inventory, int count) {
    if (count == 0) {
        printf("No products in the inventory! 😢\n");
        return;
    }
    printf("\nProduct List:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("===================================\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to search for a product
void searchProduct(struct Product *inventory, int count) {
    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("\nProduct Found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found! 😱\n", id);
    }
}