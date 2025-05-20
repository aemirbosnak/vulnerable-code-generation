//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
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

void addCustomer(Customer customers[], int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*numCustomers].name);
    printf("Enter customer ID: ");
    scanf("%d", &customers[*numCustomers].id);
    (*numCustomers)++;
}

void displayCustomers(Customer customers[], int numCustomers) {
    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%s (%d)\n", customers[i].name, customers[i].id);
    }
}

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void addOrder(Order orders[], int *numOrders) {
    printf("Enter order name: ");
    scanf("%s", orders[*numOrders].name);
    printf("Enter order quantity: ");
    scanf("%d", &orders[*numOrders].quantity);
    printf("Enter order price: ");
    scanf("%f", &orders[*numOrders].price);
    (*numOrders)++;
}

void displayOrders(Order orders[], int numOrders) {
    printf("Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%s (%d) - $%.2f\n", orders[i].name, orders[i].quantity, orders[i].price);
    }
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    addCustomer(customers, &numCustomers);

    Item items[MAX_ITEMS];
    int numItems = 0;
    addItem(items, &numItems);

    Order orders[MAX_ITEMS];
    int numOrders = 0;
    addOrder(orders, &numOrders);

    return 0;
}