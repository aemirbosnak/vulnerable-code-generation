//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

int total_products = 0;
struct product products[MAX_PRODUCTS];

// function to add product to inventory
void add_product() {
    if(total_products == MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n\n");
        return;
    }

    struct product new_product;
    printf("Enter product name: ");
    fgets(new_product.name, 50, stdin);
    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter price: ");
    scanf("%f", &new_product.price);
    getchar(); // to clear the newline character from buffer

    products[total_products++] = new_product;
    printf("Product added successfully.\n\n");
}

// function to display inventory
void display_inventory() {
    if(total_products == 0) {
        printf("Inventory is empty.\n\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    for(int i=0; i<total_products; i++) {
        printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("\n");
}

// function to search for a product by name
void search_product() {
    char product_name[50];
    printf("Enter product name to search: ");
    fgets(product_name, 50, stdin);

    for(int i=0; i<total_products; i++) {
        if(strcmp(products[i].name, product_name) == 0) {
            printf("Product found!\n");
            printf("%s\t\t%d\t\t%.2f\n\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }

    printf("Product not found.\n\n");
}

int main() {
    int option;

    while(1) {
        printf("Welcome to Product Inventory System\n\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search product\n");
        printf("4. Exit\n\n");

        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); // to clear the newline character from buffer
        printf("\n");

        switch(option) {
            case 1:
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Thank you for using Product Inventory System.\n");
                exit(0);
            default:
                printf("Invalid option.\n\n");
                break;
        }
    }

    return 0;
}