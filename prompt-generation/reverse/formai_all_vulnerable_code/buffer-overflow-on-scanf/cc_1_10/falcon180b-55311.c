//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 100
#define MAX_ORDER_ITEMS 10

struct customer {
    char name[50];
    int customer_id;
};

struct order {
    int order_id;
    int customer_id;
    int num_items;
    struct item_order *items;
};

struct item {
    char name[50];
    double price;
};

struct item_order {
    struct item *item;
    int quantity;
};

void initialize_customers() {
    FILE *fp = fopen("customers.txt", "w");

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        struct customer customer;
        sprintf(customer.name, "Customer %d", i + 1);
        customer.customer_id = i + 1;
        fprintf(fp, "%s\n", customer.name);
    }

    fclose(fp);
}

void initialize_items() {
    FILE *fp = fopen("items.txt", "w");

    struct item item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        sprintf(item.name, "Item %d", i + 1);
        item.price = (double) i + 1;
        fprintf(fp, "%s %.2f\n", item.name, item.price);
    }

    fclose(fp);
}

int main() {
    initialize_customers();
    initialize_items();

    int choice;
    while (1) {
        printf("\nCafe Billing System\n");
        printf("1. Add Customer\n");
        printf("2. Place Order\n");
        printf("3. View Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}