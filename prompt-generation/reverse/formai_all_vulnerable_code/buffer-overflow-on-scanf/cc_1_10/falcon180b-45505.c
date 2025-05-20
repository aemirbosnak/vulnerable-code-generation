//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct order {
    int id;
    char customer_name[50];
    int total_price;
} Order;

Product products[100];
Order orders[100];
int num_products = 0, num_orders = 0;

void add_product() {
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void view_products() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void add_order() {
    printf("\nEnter customer name: ");
    scanf("%s", orders[num_orders].customer_name);
    num_orders++;
}

void view_orders() {
    printf("\nOrder List:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d. %s\n", orders[i].id, orders[i].customer_name);
    }
}

void main() {
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n2. View products\n3. Add order\n4. View orders\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                add_order();
                break;
            case 4:
                view_orders();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
}