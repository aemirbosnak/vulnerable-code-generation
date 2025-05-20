//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

void add_product(product *products, int *num_products) {
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);
    (*num_products)++;
}

void remove_product(product *products, int *num_products) {
    char name[50];
    printf("Enter product name to remove: ");
    scanf("%s", name);
    for (int i = 0; i < *num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < *num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            (*num_products)--;
            printf("Product removed successfully.\n");
            break;
        }
    }
}

void update_product(product *products, int *num_products) {
    char name[50];
    printf("Enter product name to update: ");
    scanf("%s", name);
    for (int i = 0; i < *num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully.\n");
            break;
        }
    }
}

void display_products(product *products, int num_products) {
    printf("Products in inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    product products[100];
    int num_products = 0;
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                display_products(products, num_products);
                break;
            case 5:
                printf("Thank you for using the Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}