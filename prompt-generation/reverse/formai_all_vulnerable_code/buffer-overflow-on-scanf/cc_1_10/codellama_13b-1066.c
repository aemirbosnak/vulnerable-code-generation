//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: satisfied
// C Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void print_products(Product* products, int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d - %.2f\n", i + 1, products[i].name, products[i].quantity, products[i].price);
    }
}

void add_product(Product* products, int* num_products) {
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);
    (*num_products)++;
}

void remove_product(Product* products, int* num_products) {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= 0 && index < *num_products) {
        for (int i = index; i < *num_products - 1; i++) {
            products[i] = products[i + 1];
        }
        (*num_products)--;
    } else {
        printf("Invalid product index\n");
    }
}

void update_product(Product* products, int* num_products) {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= 0 && index < *num_products) {
        printf("Enter product quantity: ");
        scanf("%d", &products[index].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[index].price);
    } else {
        printf("Invalid product index\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("-----------------------\n");
        printf("a) Add product\n");
        printf("b) Remove product\n");
        printf("c) Update product\n");
        printf("d) Print products\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                add_product(products, &num_products);
                break;
            case 'b':
                remove_product(products, &num_products);
                break;
            case 'c':
                update_product(products, &num_products);
                break;
            case 'd':
                print_products(products, num_products);
                break;
            case 'e':
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);
    return 0;
}