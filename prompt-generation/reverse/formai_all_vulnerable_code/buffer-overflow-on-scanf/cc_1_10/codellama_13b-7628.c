//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PRODUCTS 100
#define MAX_INPUT_LENGTH 256

struct Product {
    char name[MAX_INPUT_LENGTH];
    int quantity;
    float price;
};

void add_product(struct Product *products, int *num_products) {
    printf("Enter product name: ");
    fgets(products[*num_products].name, MAX_INPUT_LENGTH, stdin);
    products[*num_products].name[strcspn(products[*num_products].name, "\n")] = '\0';

    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);

    (*num_products)++;
}

void remove_product(struct Product *products, int *num_products) {
    if (*num_products == 0) {
        printf("No products to remove.\n");
        return;
    }

    int index;
    printf("Enter product index to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_products) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    (*num_products)--;
}

void update_product(struct Product *products, int *num_products) {
    if (*num_products == 0) {
        printf("No products to update.\n");
        return;
    }

    int index;
    printf("Enter product index to update: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_products) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new product name: ");
    fgets(products[index].name, MAX_INPUT_LENGTH, stdin);
    products[index].name[strcspn(products[index].name, "\n")] = '\0';

    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);

    printf("Enter new product price: ");
    scanf("%f", &products[index].price);
}

void print_products(struct Product *products, int num_products) {
    if (num_products == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("Product List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s (%d units at $%.2f each)\n", i + 1, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int num_products = 0;

    int command;
    while (1) {
        printf("Enter command (1-add, 2-remove, 3-update, 4-print, 5-exit): ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                update_product(products, &num_products);
                break;
            case 4:
                print_products(products, num_products);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}