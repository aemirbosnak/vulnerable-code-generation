//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_CUSTOMERS 100
#define MAX_ITEMS_PER_ORDER 5

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    int id;
    char name[50];
    int amount;
} Customer;

typedef struct {
    int id;
    char name[50];
    int total;
} Order;

int main() {
    srand(time(NULL));

    int numCustomers = rand() % MAX_CUSTOMERS + 1;
    int numItems = rand() % MAX_ITEMS + 1;
    int numOrders = rand() % MAX_ITEMS_PER_ORDER + 1;

    printf("Cafe Billing System\n");
    printf("Customers: %d\n", numCustomers);
    printf("Items: %d\n", numItems);
    printf("Orders: %d\n", numOrders);

    for (int i = 0; i < numCustomers; i++) {
        Customer* customer = (Customer*) malloc(sizeof(Customer));
        customer->id = i + 1;
        sprintf(customer->name, "Customer %d", i + 1);
        customer->amount = 1000 * rand() % 10000 + 10000;
        printf("Customer %d: $%d\n", i + 1, customer->amount);
    }

    for (int i = 0; i < numItems; i++) {
        Item* item = (Item*) malloc(sizeof(Item));
        item->id = i + 1;
        sprintf(item->name, "Item %d", i + 1);
        item->quantity = 1;
        printf("Item %d: $%d\n", i + 1, item->quantity);
    }

    for (int i = 0; i < numOrders; i++) {
        Order* order = (Order*) malloc(sizeof(Order));
        order->id = i + 1;
        sprintf(order->name, "Order %d", i + 1);
        order->total = 0;

        for (int j = 0; j < numItems; j++) {
            Item* item = (Item*) malloc(sizeof(Item));
            item->id = j + 1;
            sprintf(item->name, "Item %d", j + 1);
            item->quantity = 1;

            if (rand() % 2 == 0) {
                item->quantity = 2;
            }

            order->total += item->quantity * item->quantity;
            printf("Order %d: $%d\n", i + 1, order->total);

            free(item);
        }

        free(order);
    }

    return 0;
}