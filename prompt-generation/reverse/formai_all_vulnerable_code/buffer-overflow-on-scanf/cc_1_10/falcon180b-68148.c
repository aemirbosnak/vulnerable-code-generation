//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    int quantity;
} Order;

Product products[100];
Order orders[100];
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
    num_orders++;
}

void view_products() {
    printf("Product ID | Product Name | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %d | %.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void view_orders() {
    printf("Order ID | Order Name | Quantity\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d | %s | %d\n", orders[i].id, orders[i].name, orders[i].quantity);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add product\n2. Add order\n3. View products\n4. View orders\n5. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}