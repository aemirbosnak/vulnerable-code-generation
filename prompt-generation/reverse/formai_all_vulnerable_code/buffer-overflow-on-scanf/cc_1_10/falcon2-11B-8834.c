//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

void add_product(product* products, int max_products, char* name, int quantity, float price) {
    if (max_products == 0) {
        printf("Inventory is full.\n");
        return;
    }
    product new_product;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    new_product.price = price;
    products[max_products - 1] = new_product;
    max_products++;
}

void display_products(product* products, int max_products) {
    for (int i = 0; i < max_products; i++) {
        printf("%s (%d units) - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void remove_product(product* products, int max_products, char* name) {
    for (int i = 0; i < max_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < max_products - 1; j++) {
                products[j] = products[j + 1];
            }
            max_products--;
            break;
        }
    }
}

int main() {
    product products[10];
    int max_products = 0;
    int choice;

    do {
        printf("\nWelcome to the C Product Inventory System!\n");
        printf("1. Add a product\n2. Display all products\n3. Remove a product\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(products[max_products].name, sizeof(products[max_products].name), stdin);
                printf("Enter product quantity: ");
                scanf("%d", &products[max_products].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[max_products].price);
                add_product(products, max_products, products[max_products].name, products[max_products].quantity, products[max_products].price);
                break;
            case 2:
                display_products(products, max_products);
                break;
            case 3:
                printf("Enter product name to remove: ");
                fgets(products[max_products].name, sizeof(products[max_products].name), stdin);
                remove_product(products, max_products, products[max_products].name);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 4);

    return 0;
}