//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int id;
};

struct order {
    char item[50];
    float price;
    int quantity;
};

void addCustomer(struct customer* customers, int size, int count) {
    printf("Enter customer name: ");
    scanf("%s", &customers[count].name);
    printf("Enter customer ID: ");
    scanf("%d", &customers[count].id);
    count++;
    size++;
    customers = (struct customer*) realloc(customers, sizeof(struct customer) * size);
}

void addOrder(struct order* orders, int size, int count) {
    printf("Enter order item: ");
    scanf("%s", &orders[count].item);
    printf("Enter order price: ");
    scanf("%f", &orders[count].price);
    printf("Enter order quantity: ");
    scanf("%d", &orders[count].quantity);
    count++;
    size++;
    orders = (struct order*) realloc(orders, sizeof(struct order) * size);
}

void displayCustomers(struct customer* customers, int size) {
    printf("Customer Name\tCustomer ID\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\n", customers[i].name, customers[i].id);
    }
}

void displayOrders(struct order* orders, int size) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%.2f\t%d\n", orders[i].item, orders[i].price, orders[i].quantity);
    }
}

void main() {
    int choice;
    struct customer customers[10];
    int customerCount = 0;
    struct order orders[10];
    int orderCount = 0;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add customer\n");
        printf("2. Add order\n");
        printf("3. Display customers\n");
        printf("4. Display orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, customerCount, orderCount);
                break;
            case 2:
                addOrder(orders, orderCount, customerCount);
                break;
            case 3:
                displayCustomers(customers, customerCount);
                break;
            case 4:
                displayOrders(orders, orderCount);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
}