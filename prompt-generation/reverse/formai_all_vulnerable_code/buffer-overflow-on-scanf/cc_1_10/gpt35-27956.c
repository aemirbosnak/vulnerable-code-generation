//FormAI DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

struct product {
    char name[20];
    double price;
    int quantity;
};

void add_product(struct product products[], int *num_products);
void remove_product(struct product products[], int *num_products);
void list_products(struct product products[], int num_products);

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char option;
    
    do {
        printf("\n\nProduct Inventory System\n");
        printf("   [A]dd a product\n");
        printf("   [R]emove a product\n");
        printf("   [L]ist products\n");
        printf("   [Q]uit\n");
        printf("Choose an option: ");
        scanf("%c", &option);
        getchar(); // flush out newline character
        
        switch(option) {
            case 'a':
            case 'A':
                add_product(products, &num_products);
                break;
            case 'r':
            case 'R':
                remove_product(products, &num_products);
                break;
            case 'l':
            case 'L':
                list_products(products, num_products);
                break;
            case 'q':
            case 'Q':
                printf("Quitting the program...\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while(1);
    
    return 0;
}

void add_product(struct product products[], int *num_products) {
    if (*num_products == MAX_PRODUCTS) {
        printf("Cannot add any more products to inventory. Max limit reached.\n");
        return;
    }
    
    printf("Enter the name of the product: ");
    fgets(products[*num_products].name, 20, stdin);
    products[*num_products].name[strlen(products[*num_products].name) - 1] = '\0'; // remove newline character at the end
    printf("Enter the price of the product: ");
    scanf("%lf", &products[*num_products].price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &products[*num_products].quantity);
    
    printf("Product added successfully.\n");
    (*num_products)++;
}

void remove_product(struct product products[], int *num_products) {
    char name[20];
    int i, index = -1;
    
    printf("Enter the name of the product to remove: ");
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = '\0';
    
    for (i = 0; i < *num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Removing product %s from inventory.\n", products[i].name);
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Product %s not found in inventory.\n", name);
    } else {
        // shift all products after the removed one to the left
        for (i = index; i < *num_products - 1; i++) {
            products[i] = products[i+1];
        }
        (*num_products)--;
    }
}

void list_products(struct product products[], int num_products) {
    int i;
    
    printf("Current inventory:\n\n");
    printf("%-20s%-20s%-20s\n", "ProductName", "Price", "Quantity");
    for (i = 0; i < num_products; i++) {
        printf("%-20s%-20.2lf%-20d\n", products[i].name, products[i].price, products[i].quantity);
    }
}