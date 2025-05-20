//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 1000

typedef struct {
    char name[50];
    int age;
    float bill;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int item_id;
    int quantity;
    float price;
} Order;

int num_items = 0, num_customers = 0, num_orders = 0;
Item items[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];
Order orders[MAX_ORDERS];

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[num_customers].age);
    num_customers++;
}

void place_order() {
    int i, j;
    printf("Enter customer ID: ");
    scanf("%d", &j);
    printf("Enter order items and quantities:\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s (%f)\n", i+1, items[i].name, items[i].price);
    }
    scanf("%d", &orders[num_orders].item_id);
    scanf("%d", &orders[num_orders].quantity);
    orders[num_orders].price = items[orders[num_orders].item_id-1].price * orders[num_orders].quantity;
    num_orders++;
}

void view_orders() {
    int i;
    printf("Order history for customer %s:\n", customers[0].name);
    for (i = 0; i < num_orders; i++) {
        printf("%d. %s (%f)\n", i+1, items[orders[i].item_id-1].name, orders[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Add customer\n");
        printf("3. Place order\n");
        printf("4. View order history\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                place_order();
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