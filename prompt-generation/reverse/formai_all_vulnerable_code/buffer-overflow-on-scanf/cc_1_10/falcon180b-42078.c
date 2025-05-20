//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_PRODUCTS 50

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Order;

Product products[MAX_PRODUCTS];
Order orders[MAX_SIZE];
int num_products = 0;
int num_orders = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void add_order() {
    printf("Enter order ID: ");
    scanf("%d", &orders[num_orders].id);
    printf("Enter order name: ");
    scanf("%s", orders[num_orders].name);
    printf("Enter order quantity: ");
    scanf("%d", &orders[num_orders].quantity);
    printf("Enter order price: ");
    scanf("%f", &orders[num_orders].price);
    num_orders++;
}

void view_products() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void view_orders() {
    printf("\nOrder List:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, orders[i].name, orders[i].quantity, orders[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Add order\n");
        printf("3. View products\n");
        printf("4. View orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_order();
                break;
            case 3:
                view_products();
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

    return 0;
}