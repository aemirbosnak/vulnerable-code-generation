//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
struct product {
    char name[50];
    int code;
    float price;
    int quantity;
};

// Function to add a product
void add_product(struct product *products, int *num_products) {
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter product code: ");
    scanf("%d", &products[*num_products].code);
    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    (*num_products)++;
}

// Function to display products
void display_products(struct product *products, int num_products) {
    printf("\nProduct List:\n");
    for(int i=0; i<num_products; i++) {
        printf("%d. %s - %d - %.2f - %d\n", i+1, products[i].name, products[i].code, products[i].price, products[i].quantity);
    }
}

// Function to search for a product
int search_product(struct product *products, int num_products, int code) {
    for(int i=0; i<num_products; i++) {
        if(products[i].code == code) {
            return i;
        }
    }
    return -1;
}

// Function to update product quantity
void update_quantity(struct product *products, int num_products, int index, int quantity) {
    if(index >= 0 && index < num_products) {
        products[index].quantity += quantity;
        printf("\nProduct quantity updated successfully.\n");
    } else {
        printf("\nInvalid product index.\n");
    }
}

int main() {
    struct product products[100];
    int num_products = 0;

    // Add products
    add_product(products, &num_products);
    add_product(products, &num_products);
    add_product(products, &num_products);

    // Display products
    display_products(products, num_products);

    // Search for a product
    int index = search_product(products, num_products, 101);
    if(index >= 0) {
        printf("\nProduct found at index %d.\n", index);
    } else {
        printf("\nProduct not found.\n");
    }

    // Update product quantity
    update_quantity(products, num_products, 0, 10);

    return 0;
}