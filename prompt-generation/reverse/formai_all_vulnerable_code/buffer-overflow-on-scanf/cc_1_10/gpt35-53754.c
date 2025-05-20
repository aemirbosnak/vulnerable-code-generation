//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

void add_product(Product products[], int *product_count);
void remove_product(Product products[], int *product_count);
void display_products(Product products[], int product_count);
void search_product(Product products[], int product_count);

int main() {
    Product products[MAX_PRODUCTS];
    int product_count = 0;
    int choice;

    do {
        printf("\n-------------------------\n");
        printf("Product Inventory System\n");
        printf("-------------------------\n\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Search Product\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(products, &product_count);
                break;
            case 2:
                remove_product(products, &product_count);
                break;
            case 3:
                display_products(products, product_count);
                break;
            case 4:
                search_product(products, product_count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void add_product(Product products[], int *product_count) {
    Product new_product;

    printf("\nEnter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    products[*product_count] = new_product;
    (*product_count)++;

    printf("\nProduct added successfully!\n");
}

void remove_product(Product products[], int *product_count) {
    int id_to_remove;
    int index_to_remove = -1;

    printf("\nEnter ID of product to remove: ");
    scanf("%d", &id_to_remove);

    for(int i = 0; i < *product_count; i++) {
        if(products[i].id == id_to_remove) {
            index_to_remove = i;
            break;
        }
    }

    if(index_to_remove != -1) {
        for(int j = index_to_remove; j < *product_count; j++) {
            products[j] = products[j+1];
        }
        (*product_count)--;
        printf("\nProduct removed successfully!\n");
    } else {
        printf("\nProduct not found!\n");
    }
}

void display_products(Product products[], int product_count) {
    printf("\n%-10s | %-20s | %-8s | %-8s\n", "ID", "NAME", "QUANTITY", "PRICE");
    printf("------------------------------------------------------\n");
    for(int i = 0; i < product_count; i++) {
        printf("%-10d | %-20s | %-8d | $%-.2f\n", products[i].id, products[i].name,
         products[i].quantity, products[i].price);
    }
}

void search_product(Product products[], int product_count) {
    int id_to_search;
    int index_to_search = -1;

    printf("\nEnter ID of product to search: ");
    scanf("%d", &id_to_search);

    for(int i = 0; i < product_count; i++) {
        if(products[i].id == id_to_search) {
            index_to_search = i;
            break;
        }
    }

    if(index_to_search != -1) {
        printf("\nProduct found!\n\n");
        printf("%-10s | %-20s | %-8s | %-8s\n", "ID", "NAME", "QUANTITY", "PRICE");
        printf("------------------------------------------------------\n");
        printf("%-10d | %-20s | %-8d | $%-.2f\n", products[index_to_search].id, products[index_to_search].name,
         products[index_to_search].quantity, products[index_to_search].price);
    } else {
        printf("\nProduct not found!\n");
    }
}