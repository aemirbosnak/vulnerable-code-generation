//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
} Product;

void print_menu() {
    printf("1. Add product\n");
    printf("2. Update product\n");
    printf("3. Delete product\n");
    printf("4. Display product list\n");
    printf("5. Exit\n");
}

void add_product(Product *products, int *count) {
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%d", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    products[*count] = product;
    (*count)++;
}

void update_product(Product *products, int count) {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= count || index < 0) {
        printf("Invalid index\n");
        return;
    }
    printf("Enter new product name: ");
    scanf("%s", products[index].name);
    printf("Enter new product price: ");
    scanf("%d", &products[index].price);
    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);
}

void delete_product(Product *products, int *count) {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= *count || index < 0) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    (*count)--;
}

void display_product_list(Product *products, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d - %d\n", i, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int option;
    while (1) {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_product(products, &count);
                break;
            case 2:
                update_product(products, count);
                break;
            case 3:
                delete_product(products, &count);
                break;
            case 4:
                display_product_list(products, count);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}