//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int id;
    char address[100];
};

struct Medicine {
    char name[50];
    int id;
    float price;
};

struct Product {
    struct Medicine medicine;
    struct Customer customer;
};

int main() {
    int n, m, p;
    struct Product products[100];

    // Initialize the memory for the products
    for (int i = 0; i < 100; i++) {
        products[i].medicine.id = -1;
        products[i].customer.id = -1;
    }

    // Input the number of medicines and customers
    printf("Enter the number of medicines: ");
    scanf("%d", &n);

    printf("Enter the number of customers: ");
    scanf("%d", &m);

    printf("Enter the number of products: ");
    scanf("%d", &p);

    for (int i = 0; i < p; i++) {
        // Input the medicine details
        printf("Enter the medicine details: ");
        scanf("%s %d %f", products[i].medicine.name, &products[i].medicine.id, &products[i].medicine.price);

        // Input the customer details
        printf("Enter the customer details: ");
        scanf("%s %d %s", products[i].customer.name, &products[i].customer.id, products[i].customer.address);
    }

    for (int i = 0; i < p; i++) {
        // Print the details of the product
        printf("Medicine Name: %s\n", products[i].medicine.name);
        printf("Medicine ID: %d\n", products[i].medicine.id);
        printf("Customer Name: %s\n", products[i].customer.name);
        printf("Customer ID: %d\n", products[i].customer.id);
        printf("Price: %.2f\n", products[i].medicine.price);
        printf("Address: %s\n", products[i].customer.address);
        printf("\n");
    }

    return 0;
}