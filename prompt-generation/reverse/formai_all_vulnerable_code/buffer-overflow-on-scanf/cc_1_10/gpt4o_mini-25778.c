//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    int id;
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count);
void displayProducts(Product *inventory, int count);
void searchProduct(Product *inventory, int count);
void clearBuffer();

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                displayProducts(inventory, productCount);
                break;
            case 3:
                searchProduct(inventory, productCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple ID assignment based on count

    printf("Enter product name: ");
    fgets(newProduct.name, PRODUCT_NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    clearBuffer(); // Clear the buffer after inputs

    inventory[*count] = newProduct; // Add product to inventory
    (*count)++;
    printf("Product \"%s\" added successfully!\n", newProduct.name);
}

void displayProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    char searchName[PRODUCT_NAME_LENGTH];
    printf("Enter the product name to search: ");
    fgets(searchName, PRODUCT_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(inventory[i].name, searchName) == 0) {
            printf("Product found: ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product \"%s\" not found in the inventory.\n", searchName);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}