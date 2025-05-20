//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// structure for a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// structure for an order
typedef struct {
    int order_id;
    Product product;
    int quantity;
} Order;

void addProduct(Product products[], int *size) {
    printf("Enter product name: ");
    scanf("%s", products[*size].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*size].price);
    (*size)++;
}

void displayProducts(Product products[], int size) {
    printf("\nProduct List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void placeOrder(Order orders[], int *size) {
    int product_id;
    printf("\nEnter product ID: ");
    scanf("%d", &product_id);

    for (int i = 0; i < *size; i++) {
        if (orders[i].product.name[0] == product_id) {
            printf("\nOrder placed for %s\n", orders[i].product.name);
            orders[i].quantity += 1;
            break;
        }
    }
}

void displayOrders(Order orders[], int size) {
    printf("\nOrder List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, orders[i].product.name, orders[i].quantity, orders[i].product.price * orders[i].quantity);
    }
}

int main() {
    Product products[MAX_SIZE];
    int product_size = 0;

    Order orders[MAX_SIZE];
    int order_size = 0;

    int choice;
    while(1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n2. Display Products\n3. Place Order\n4. Display Orders\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &product_size);
                break;
            case 2:
                displayProducts(products, product_size);
                break;
            case 3:
                placeOrder(orders, &order_size);
                break;
            case 4:
                displayOrders(orders, order_size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}