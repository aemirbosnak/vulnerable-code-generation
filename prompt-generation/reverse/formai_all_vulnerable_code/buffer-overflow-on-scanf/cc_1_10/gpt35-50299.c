//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME 50

struct Product {
    char name[MAX_PRODUCT_NAME];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int quantity, float price) {
    if (num_products == MAX_PRODUCTS) {
        printf("Sorry, the inventory is full\n");
        return;
    }

    struct Product new_product;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    new_product.price = price;

    products[num_products] = new_product;
    num_products++;

    printf("Product added to Inventory!\n");
}

void remove_product(char* name) {
    int i, product_index = -1;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            product_index = i;
            break;
        }
    }

    if (product_index == -1) {
        printf("Sorry, product not found in inventory\n");
        return;
    }

    for (i = product_index; i < num_products-1; i++) {
        products[i] = products[i+1];
    }

    num_products--;

    printf("Product removed from Inventory!\n");
}

void display_inventory() {
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");

    int i;
    for (i=0; i<num_products; i++) {
        printf("%-20s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    printf("-------------------------------------------------------------\n");
}

void program_menu() {
    printf("=============================================================\n");
    printf("Welcome to the Retro Product Inventory System!\n");
    printf("Select an option below:\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n");
    printf("=============================================================\n");
}

int main() {
    int choice, quantity;
    float price;
    char name[MAX_PRODUCT_NAME];

    while (1) {
        program_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Product Name: ");
                scanf("%s", name);

                printf("Enter Quantity: ");
                scanf("%d", &quantity);

                printf("Enter Price: ");
                scanf("%f", &price);

                add_product(name, quantity, price);

                break;
            case 2:
                printf("Enter Product Name: ");
                scanf("%s", name);

                remove_product(name);

                break;
            case 3:
                display_inventory();

                break;
            case 4:
                printf("Exiting Program\n");
                return 0;
                break;
            default:
                printf("Invalid Choice, try again!\n");
        }

        // flush stdin buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}