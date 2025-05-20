//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 1000

typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

void addCustomer(Customer customers[], int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", &customers[*numCustomers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[*numCustomers].age);
    printf("Enter customer address: ");
    scanf("%s", &customers[*numCustomers].address);
    (*numCustomers)++;
}

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void printCustomer(Customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Age: %d\n", customer.age);
    printf("Address: %s\n", customer.address);
}

void printItem(Item item) {
    printf("Name: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
}

void orderItem(Customer customer, Item item, float *totalPrice) {
    printf("Customer %s ordered %s for %.2f\n", customer.name, item.name, item.price);
    *totalPrice += item.price;
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    Item items[MAX_ITEMS];
    int numItems = 0;
    float totalPrice = 0;

    addCustomer(customers, &numCustomers);
    addItem(items, &numItems);

    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printCustomer(customers[i]);
    }

    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printItem(items[i]);
    }

    printf("\nOrder:\n");
    for (int i = 0; i < numCustomers; i++) {
        for (int j = 0; j < numItems; j++) {
            orderItem(customers[i], items[j], &totalPrice);
        }
    }

    printf("\nTotal price: %.2f\n", totalPrice);

    return 0;
}