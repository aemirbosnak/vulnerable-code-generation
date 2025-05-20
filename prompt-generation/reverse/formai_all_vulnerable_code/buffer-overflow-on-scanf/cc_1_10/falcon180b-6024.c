//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int customer_id;
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

int num_customers = 0;
Customer customers[MAX_CUSTOMERS];

int num_items = 0;
Item items[MAX_ITEMS];

void add_customer(char name[]) {
    Customer new_customer;
    strcpy(new_customer.name, name);
    new_customer.customer_id = num_customers;
    customers[num_customers] = new_customer;
    num_customers++;
}

void add_item(char name[], float price) {
    Item new_item;
    strcpy(new_item.name, name);
    new_item.price = price;
    items[num_items] = new_item;
    num_items++;
}

void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void place_order(int customer_id, char order[], float total_price) {
    printf("Customer %d placed an order for %s and paid $%.2f\n", customer_id, order, total_price);
}

int main() {
    add_customer("John Doe");
    add_customer("Jane Smith");
    add_item("Coffee", 2.50);
    add_item("Tea", 1.75);
    add_item("Donut", 1.00);

    int choice;
    while (1) {
        printf("Enter 1 to view menu, 2 to place an order, 3 to exit:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            print_menu();
            break;
        case 2:
            printf("Enter customer ID:\n");
            int customer_id;
            scanf("%d", &customer_id);

            printf("Enter order:\n");
            char order[50];
            scanf("%s", order);

            float total_price = 0;
            printf("Enter quantity of each item:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%s (%d): ", items[i].name, i);
                int quantity;
                scanf("%d", &quantity);
                total_price += items[i].price * quantity;
            }

            place_order(customer_id, order, total_price);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}