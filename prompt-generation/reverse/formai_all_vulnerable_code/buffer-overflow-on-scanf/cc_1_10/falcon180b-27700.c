//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 10

typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

typedef struct {
    int id;
    char name[50];
} customer;

product products[MAX_PRODUCTS];
customer customers[MAX_CUSTOMERS];

int num_products = 0;
int num_customers = 0;

void add_product(product p) {
    products[num_products] = p;
    num_products++;
}

void add_customer(customer c) {
    customers[num_customers] = c;
    num_customers++;
}

void *customer_thread(void *arg) {
    int id = *(int *) arg;
    customer c = customers[id];

    printf("Customer %s is browsing the store...\n", c.name);
    sleep(1);

    int product_id;
    printf("Customer %s wants to buy product ID: ", c.name);
    scanf("%d", &product_id);

    product p = products[product_id];

    if (p.quantity > 0) {
        p.quantity--;
        printf("Customer %s bought %s for $%.2f\n", c.name, p.name, p.price);
    } else {
        printf("Customer %s could not find %s\n", c.name, p.name);
    }

    return NULL;
}

int main() {
    // Add products
    add_product((product) {"Apple", 10, 1.00});
    add_product((product) {"Banana", 5, 0.50});
    add_product((product) {"Orange", 20, 0.75});

    // Add customers
    add_customer((customer) {"John", 1});
    add_customer((customer) {"Jane", 2});

    // Start customer threads
    pthread_t threads[MAX_CUSTOMERS];
    int ids[MAX_CUSTOMERS];

    for (int i = 0; i < num_customers; i++) {
        ids[i] = i + 1; // Customer IDs start from 1
        pthread_create(&threads[i], NULL, customer_thread, &ids[i]);
    }

    // Join customer threads
    for (int i = 0; i < num_customers; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}