//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 20

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product_t;

void print_menu();
void add_product(product_t* products, int* num_products);
void remove_product(product_t* products, int* num_products);
void search_product(product_t* products, int num_products);
void print_products(product_t* products, int num_products);

int main() {
    product_t products[MAX_PRODUCTS];
    int num_products = 0;
    int quit = 0;
    int choice = 0;

    while (!quit) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                search_product(products, num_products);
                break;
            case 4:
                print_products(products, num_products);
                break;
            case 5:
                quit = 1;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("Product Inventory System\n");
    printf("-------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Search product by name\n");
    printf("4. Print inventory\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void add_product(product_t* products, int* num_products) {
    product_t new_product;
    new_product.id = *num_products + 1;

    printf("Enter product name: ");
    scanf("%s", new_product.name);

    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter price: ");
    scanf("%f", &new_product.price);

    products[*num_products] = new_product;
    *num_products += 1;

    printf("Product added!\n");
}

void remove_product(product_t* products, int* num_products) {
    int id_to_remove;
    int found = 0;

    printf("Enter ID of product to remove: ");
    scanf("%d", &id_to_remove);

    for (int i = 0; i < *num_products; i++) {
        if (products[i].id == id_to_remove) {
            for (int j = i; j < *num_products - 1; j++) {
                products[j] = products[j+1];
            }
            found = 1;
            break;
        }
    }

    if (found) {
        *num_products -= 1;
        printf("Product removed!\n");
    } else {
        printf("Product not found\n");
    }
}

void search_product(product_t* products, int num_products) {
    char name_to_search[50];
    int found = 0;

    printf("Enter name of product to search: ");
    scanf("%s", name_to_search);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name_to_search) == 0) {
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found\n");
    }
}

void print_products(product_t* products, int num_products) {
    printf("ID | Name | Quantity | Price\n");
    printf("-----------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %d | %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}