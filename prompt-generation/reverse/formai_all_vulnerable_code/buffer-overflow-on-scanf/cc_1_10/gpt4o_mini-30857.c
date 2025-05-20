//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count);
void viewProducts(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void displayMenu();
void clearInputBuffer();

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                viewProducts(inventory, productCount);
                break;
            case 3:
                deleteProduct(inventory, &productCount);
                break;
            case 4:
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove the newline character
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    clearInputBuffer();
    
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void viewProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("Product %d: Name: %s, Quantity: %d, Price: %.2f\n", 
               i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------\n");
}

void deleteProduct(Product *inventory, int *count) {
    if (*count == 0) {
        printf("No products to delete.\n");
        return;
    }

    viewProducts(inventory, *count);
    int index;
    printf("Enter the index of the product to delete (1 to %d): ", *count);
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid index! Deletion failed.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Inventory System Menu ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}