//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if(numProducts == MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    Product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[numProducts++] = newProduct;

    printf("Product added successfully!\n");
}

void displayInventory() {
    printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");

    for(int i = 0; i < numProducts; i++) {
        printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void searchProduct() {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);

    for(int i = 0; i < numProducts; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("Product Found!\n");
            printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");
            printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }

    printf("Product not found!\n");
}

int main() {
    int option;

    do {
        printf("\n------Product Inventory System------\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != 4);

    return 0;
}