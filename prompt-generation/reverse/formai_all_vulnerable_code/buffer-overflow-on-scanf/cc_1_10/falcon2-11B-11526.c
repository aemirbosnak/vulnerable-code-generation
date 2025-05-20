//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct product_info {
    char name[50];
    int quantity;
} ProductInfo;

void display_products() {
    ProductInfo products[10]; // Array to store product information
    int i;

    for (i = 0; i < 10; i++) {
        printf("Product %d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("\n");
    }
}

void add_product(int quantity) {
    ProductInfo products[10]; // Array to store product information
    int i;

    for (i = 0; i < 10; i++) {
        if (products[i].quantity < 10) {
            printf("Adding product %d:\n", i+1);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            break;
        }
    }
}

int main() {
    int choice, product_id, quantity;
    ProductInfo products[10]; // Array to store product information

    do {
        printf("Product Inventory System\n");
        printf("1. Display products\n");
        printf("2. Add product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_products();
                break;
            case 2:
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                add_product(quantity);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}