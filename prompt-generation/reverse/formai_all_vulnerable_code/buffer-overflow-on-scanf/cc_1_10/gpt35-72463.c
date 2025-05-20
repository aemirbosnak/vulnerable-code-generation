//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: introspective
//Warehouse Management System Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000 //The maximum number of products the warehouse can handle
#define MAX_NAME_LENGTH 50 //The maximum length of a product name
#define MAX_QUANTITY 999 //The maximum quantity of a product allowed in the warehouse

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product_t;

product_t warehouse[MAX_PRODUCTS]; //The actual warehouse that stores the products
int num_products = 0; //The current number of products in the warehouse

void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Sorry, the warehouse is full!\n");
    } else {
        printf("Enter the name of the product: ");
        scanf("%s", warehouse[num_products].name);
        printf("Enter the quantity of the product: ");
        scanf("%d", &warehouse[num_products].quantity);
        if (warehouse[num_products].quantity > MAX_QUANTITY) {
            printf("Sorry, the maximum quantity allowed per product is: %d\n", MAX_QUANTITY);
            warehouse[num_products].quantity = MAX_QUANTITY;
        }
        printf("Enter the price of the product: ");
        scanf("%f", &warehouse[num_products].price);
        num_products++;
        printf("Product added to warehouse!\n");
    }
}

void removeProduct() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the product you want to remove: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, warehouse[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Sorry, product not found in warehouse!\n");
    } else {
        for (int i = index; i < num_products-1; i++) {
            warehouse[i] = warehouse[i+1];
        }
        num_products--;
        printf("Product removed from warehouse!\n");
    }
}

void displayProducts() {
    printf("\nWarehouse Products:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-10d %-10.2f\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void menuOptions() {
    printf("\n");
    printf("Menu Options:\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Products\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menuOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    }
    return 0;
}