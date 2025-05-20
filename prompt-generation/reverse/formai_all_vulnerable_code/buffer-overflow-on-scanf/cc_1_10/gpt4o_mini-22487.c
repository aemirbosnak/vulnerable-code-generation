//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple sequential ID
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully! \n");
}

void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void restockProduct(Product products[], int count) {
    int id, quantity;
    printf("Enter the product ID to restock: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= count) {
        printf("Enter quantity to add: ");
        scanf("%d", &quantity);
        products[id - 1].quantity += quantity;
        printf("Product restocked successfully! New quantity: %d\n", products[id - 1].quantity);
    } else {
        printf("Invalid Product ID!\n");
    }
}

void sellProduct(Product products[], int count) {
    int id, quantity;
    printf("Enter the product ID to sell: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= count) {
        printf("Enter quantity to sell: ");
        scanf("%d", &quantity);
        
        if (quantity <= products[id - 1].quantity) {
            products[id - 1].quantity -= quantity;
            printf("Sold %d units of %s. Remaining quantity: %d\n", quantity, products[id - 1].name, products[id - 1].quantity);
        } else {
            printf("Not enough stock available!\n");
        }
    } else {
        printf("Invalid Product ID!\n");
    }
}

void deleteProduct(Product products[], int *count) {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= *count) {
        for (int i = id - 1; i < *count - 1; i++) {
            products[i] = products[i + 1]; // Shift products left
        }
        (*count)--;
        printf("Product deleted successfully!\n");
    } else {
        printf("Invalid Product ID!\n");
    }
}

void showMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Restock Product\n");
    printf("4. Sell Product\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int option;

    while (1) {
        showMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                restockProduct(products, count);
                break;
            case 4:
                sellProduct(products, count);
                break;
            case 5:
                deleteProduct(products, &count);
                break;
            case 6:
                printf("Exiting the program. Thank you for using the Warehouse Management System!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}