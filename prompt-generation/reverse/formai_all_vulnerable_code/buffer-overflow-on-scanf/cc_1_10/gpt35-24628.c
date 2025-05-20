//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

struct Product {
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct Product[], int *);
void removeProduct(struct Product[], int *);
void displayInventory(struct Product[], int);

int main() {
    int numOfProducts = 0;
    int choice;

    struct Product products[MAX_PRODUCTS];

    while(1) {
        printf("\n\n===== Product Inventory System =====\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &numOfProducts);
                break;

            case 2:
                removeProduct(products, &numOfProducts);
                break;

            case 3:
                displayInventory(products, numOfProducts);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.");
        }
    }
}

void addProduct(struct Product products[], int *numOfProducts) {
    // Check if the inventory is full
    if(*numOfProducts == MAX_PRODUCTS) {
        printf("The inventory is full. Cannot add more products.");
        return;
    }

    struct Product p;
    printf("Enter the name of the product: ");
    scanf("%s", p.name);

    printf("Enter the price of the product: ");
    scanf("%f", &p.price);

    printf("Enter the quantity of the product: ");
    scanf("%d", &p.quantity);

    products[*numOfProducts] = p;
    (*numOfProducts)++;

    printf("Product added successfully.");
}

void removeProduct(struct Product products[], int *numOfProducts) {
    char productName[50];
    int i, j;

    printf("Enter the name of the product to be removed: ");
    scanf("%s", productName);

    // Find the product
    for(i = 0; i < *numOfProducts; i++) {
        if(strcmp(productName, products[i].name) == 0) {
            // Remove the product by shifting everything after it by one index to the left
            for(j = i; j < *numOfProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            (*numOfProducts)--;
            printf("Product removed successfully.");
            return;
        }
    }

    printf("Product not found in the inventory.");
}

void displayInventory(struct Product products[], int numOfProducts) {
    int i;

    printf("\n\n===== Inventory =====\n");
    printf("%-30s%-10s%-10s\n", "Name", "Price", "Qty");

    for(i = 0; i < numOfProducts; i++) {
        printf("%-30s%-10.2f%-10d\n", products[i].name, products[i].price, products[i].quantity);
    }
}