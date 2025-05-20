//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int count = 0;

void addProduct(char name[], int quantity, float price) {
    if (count >= MAX_PRODUCTS) {
        printf("Error: Maximum product limit reached\n");
        return;
    }

    // Create a new product and add to the inventory
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;

    products[count++] = newProduct;
}

void removeProduct(int id) {
    if (id < 0 || id >= count) {
        printf("Error: Invalid product ID!\n");
        return;
    }

    // Shift products left to remove the product from the inventory
    for (int i = id; i < count - 1; i++) {
        products[i] = products[i + 1];
    }

    count--;
}

void displayProducts() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", i, products[i].name, products[i].quantity, products[i].price);
    }
}

void editProduct(int id, char name[], int quantity, float price) {
    if (id < 0 || id >= count) {
        printf("Error: Invalid product ID!\n");
        return;
    }

    // Update product with new values
    strcpy(products[id].name, name);
    products[id].quantity = quantity;
    products[id].price = price;
}

int main() {
    int choice;
    char name[50];
    int quantity, id;
    float price;

    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Edit Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(name, 50, stdin);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Enter product ID to edit: ");
                scanf("%d", &id);
                printf("Enter new product name: ");
                fgets(name, 50, stdin);
                printf("Enter new product quantity: ");
                scanf("%d", &quantity);
                printf("Enter new product price: ");
                scanf("%f", &price);
                editProduct(id, name, quantity, price);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}