//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int id;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
} Order;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];
Order orders[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;
int num_orders = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer ID: ");
    scanf("%d", &customers[num_customers].id);
    num_customers++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void place_order(int customer_id) {
    printf("Customer %d placing order\n", customer_id);
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
    printf("Enter item name: ");
    scanf("%s", orders[num_orders].name);
    printf("Enter quantity: ");
    scanf("%d", &orders[num_orders].quantity);
    printf("Enter price: ");
    scanf("%f", &orders[num_orders].price);
    num_orders++;
}

void print_orders() {
    printf("\nOrders:\n");
    int i;
    for (i = 0; i < num_orders; i++) {
        printf("%s - %d x $%.2f = $%.2f\n", orders[i].name, orders[i].quantity, orders[i].price, orders[i].quantity * orders[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add customer\n");
        printf("2. Add item\n");
        printf("3. Place order\n");
        printf("4. Print orders\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_item();
                break;
            case 3:
                printf("Enter customer ID: ");
                int customer_id;
                scanf("%d", &customer_id);
                place_order(customer_id);
                break;
            case 4:
                print_orders();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}