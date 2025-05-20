//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 50

typedef struct {
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

typedef struct {
    int id;
    int customerId;
    char date[20];
    float totalAmount;
} Order;

int main() {
    FILE *fp;
    Customer customers[MAX_CUSTOMERS];
    Item items[MAX_ITEMS];
    Order orders[MAX_ORDERS];
    int numCustomers = 0, numItems = 0, numOrders = 0;

    fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("Error opening customers file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %d\n", customers[numCustomers].name, customers[numCustomers].address, &customers[numCustomers].phone)!= EOF) {
        numCustomers++;
    }

    fclose(fp);

    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening items file\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %.2f %d\n", &items[numItems].id, items[numItems].name, &items[numItems].price, &items[numItems].quantity)!= EOF) {
        numItems++;
    }

    fclose(fp);

    fp = fopen("orders.txt", "r");
    if (fp == NULL) {
        printf("Error opening orders file\n");
        exit(1);
    }

    while (fscanf(fp, "%d %d %s %.2f\n", &orders[numOrders].id, &orders[numOrders].customerId, orders[numOrders].date, &orders[numOrders].totalAmount)!= EOF) {
        numOrders++;
    }

    fclose(fp);

    // Add code for managing customers, items, and orders

    return 0;
}