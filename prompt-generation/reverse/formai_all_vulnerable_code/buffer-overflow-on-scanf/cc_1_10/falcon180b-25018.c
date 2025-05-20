//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int quantity;
    float price;
} Order;

void addCustomer(Customer customers[], int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*numCustomers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[*numCustomers].age);
    printf("Enter customer address: ");
    scanf("%s", customers[*numCustomers].address);
    (*numCustomers)++;
}

void displayCustomers(Customer customers[], int numCustomers) {
    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%s %d %s\n", customers[i].name, customers[i].age, customers[i].address);
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
        printf("%s $%.2f\n", items[i].name, items[i].price);
    }
}

void addOrder(Order orders[], int *numOrders) {
    printf("Enter order quantity: ");
    scanf("%d", &orders[*numOrders].quantity);
    printf("Enter order price: ");
    scanf("%f", &orders[*numOrders].price);
    (*numOrders)++;
}

void displayOrders(Order orders[], int numOrders) {
    printf("Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("Quantity: %d, Price: $%.2f\n", orders[i].quantity, orders[i].price);
    }
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    addCustomer(customers, &numCustomers);
    displayCustomers(customers, numCustomers);

    Item items[MAX_ITEMS];
    int numItems = 0;
    addItem(items, &numItems);
    displayItems(items, numItems);

    Order orders[MAX_ORDERS];
    int numOrders = 0;
    addOrder(orders, &numOrders);
    displayOrders(orders, numOrders);

    return 0;
}