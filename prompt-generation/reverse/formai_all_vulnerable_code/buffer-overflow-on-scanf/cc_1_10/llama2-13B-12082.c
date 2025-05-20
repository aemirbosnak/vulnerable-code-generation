//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 100

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int age;
} customer_t;

// Structure to store order information
typedef struct {
    char customer_name[50];
    char food_item[50];
    int quantity;
    int total_cost;
} order_t;

// Global variables to store customer and order information
customer_t customers[MAX_CUSTOMERS];
order_t orders[MAX_ORDERS];

// Function to read customer information
void read_customer(customer_t *cust) {
    printf("Enter customer name: ");
    fgets(cust->name, 50, stdin);
    printf("Enter address: ");
    fgets(cust->address, 100, stdin);
    printf("Enter age: ");
    scanf("%d", &cust->age);
}

// Function to read order information
void read_order(order_t *ord) {
    printf("Enter customer name: ");
    fgets(ord->customer_name, 50, stdin);
    printf("Enter food item: ");
    fgets(ord->food_item, 50, stdin);
    printf("Enter quantity: ");
    scanf("%d", &ord->quantity);
    printf("Enter total cost: ");
    scanf("%d", &ord->total_cost);
}

// Function to add a new customer to the database
void add_customer(customer_t *cust) {
    int i;
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (strcmp(customers[i].name, "") == 0) {
            break;
        }
    }
    if (i == MAX_CUSTOMERS) {
        printf("Sorry, no more space for customers! :(");
        return;
    }
    strcpy(customers[i].name, cust->name);
    strcpy(customers[i].address, cust->address);
    customers[i].age = cust->age;
    printf("New customer added: %s (%s, %d)\n", cust->name, cust->address, cust->age);
}

// Function to add a new order to the database
void add_order(order_t *ord) {
    int i;
    for (i = 0; i < MAX_ORDERS; i++) {
        if (strcmp(orders[i].customer_name, "") == 0) {
            break;
        }
    }
    if (i == MAX_ORDERS) {
        printf("Sorry, no more space for orders! :(");
        return;
    }
    strcpy(orders[i].customer_name, ord->customer_name);
    strcpy(orders[i].food_item, ord->food_item);
    orders[i].quantity = ord->quantity;
    orders[i].total_cost = ord->total_cost;
    printf("New order added: %s (%s, %d, %d)\n", ord->customer_name, ord->food_item, ord->quantity, ord->total_cost);
}

int main() {
    int i, j;

    // Add some customers to the database
    customer_t cust;
    read_customer(&cust);
    add_customer(&cust);

    // Add some orders to the database
    order_t ord;
    read_order(&ord);
    add_order(&ord);

    // Print out the customer and order information
    printf("Customers:\n");
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        printf("    %s (%s, %d)\n", customers[i].name, customers[i].address, customers[i].age);
    }

    printf("Orders:\n");
    for (j = 0; j < MAX_ORDERS; j++) {
        printf("    %s (%s, %d, %d)\n", orders[j].customer_name, orders[j].food_item, orders[j].quantity, orders[j].total_cost);
    }

    return 0;
}