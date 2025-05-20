//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_CUSTOMERS 1000

typedef struct {
    int id;
    char name[50];
    char address[100];
    int phone;
} Customer;

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

void addCustomer(Customer* customers, int numCustomers) {
    printf("Enter customer details:\n");
    printf("ID: ");
    scanf("%d", &customers[numCustomers].id);
    printf("Name: ");
    scanf("%s", customers[numCustomers].name);
    printf("Address: ");
    scanf("%s", customers[numCustomers].address);
    printf("Phone: ");
    scanf("%d", &customers[numCustomers].phone);
}

void addItem(Item* items, int numItems) {
    printf("Enter item details:\n");
    printf("ID: ");
    scanf("%d", &items[numItems].id);
    printf("Name: ");
    scanf("%s", items[numItems].name);
    printf("Price: ");
    scanf("%f", &items[numItems].price);
    printf("Quantity: ");
    scanf("%d", &items[numItems].quantity);
}

void displayCustomers(Customer* customers, int numCustomers) {
    printf("Customer details:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("ID: %d\n", customers[i].id);
        printf("Name: %s\n", customers[i].name);
        printf("Address: %s\n", customers[i].address);
        printf("Phone: %d\n", customers[i].phone);
    }
}

void displayItems(Item* items, int numItems) {
    printf("Item details:\n");
    for (int i = 0; i < numItems; i++) {
        printf("ID: %d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Price: %f\n", items[i].price);
        printf("Quantity: %d\n", items[i].quantity);
    }
}

void main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    Item items[MAX_ITEMS];
    int numItems = 0;

    // Add customers
    while (numCustomers < MAX_CUSTOMERS) {
        addCustomer(customers, numCustomers);
        numCustomers++;
    }

    // Add items
    while (numItems < MAX_ITEMS) {
        addItem(items, numItems);
        numItems++;
    }

    // Display customers
    displayCustomers(customers, numCustomers);

    // Display items
    displayItems(items, numItems);
}