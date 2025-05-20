//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 50

typedef struct {
    char name[50];
    char description[100];
    int quantity;
    double price;
} Product;

typedef struct {
    int order_id;
    char customer_name[50];
    int total_price;
} Order;

Product products[MAX_PRODUCTS];
Order orders[MAX_ORDERS];
int num_products = 0;
int num_orders = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void view_products() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s (%d units) - $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
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
        printf("%d. %s - Total Price: $%.2f\n", i+1, orders[i].customer_name, orders[i].total_price);
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Add order\n");
        printf("4. View orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}