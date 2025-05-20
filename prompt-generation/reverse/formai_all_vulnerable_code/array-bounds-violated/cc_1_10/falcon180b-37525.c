//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ITEMS 100
#define MAX_ORDERS 1000

typedef struct {
    char name[50];
    int customer_id;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int customer_id;
    int item_id;
    int quantity;
    float total_price;
} Order;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];
Order orders[MAX_ORDERS];

int num_customers = 0;
int num_items = 0;
int num_orders = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    customers[num_customers].customer_id = num_customers + 1;
    num_customers++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void add_order() {
    int customer_id, item_id, quantity;
    float total_price;

    printf("Enter customer ID: ");
    scanf("%d", &customer_id);

    printf("Enter item ID: ");
    scanf("%d", &item_id);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    total_price = items[item_id - 1].price * quantity;

    orders[num_orders].customer_id = customer_id;
    orders[num_orders].item_id = item_id;
    orders[num_orders].quantity = quantity;
    orders[num_orders].total_price = total_price;

    num_orders++;
}

void view_orders() {
    int i, j;

    printf("Customer ID\tItem ID\tQuantity\tTotal Price\n");

    for (i = 0; i < num_orders; i++) {
        printf("%d\t", orders[i].customer_id);
        printf("%d\t", orders[i].item_id);
        printf("%d\t", orders[i].quantity);
        printf("%.2f\n", orders[i].total_price);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add customer\n");
        printf("2. Add item\n");
        printf("3. Add order\n");
        printf("4. View orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_item();
                break;
            case 3:
                add_order();
                break;
            case 4:
                view_orders();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}