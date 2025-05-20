//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a product
typedef struct product {
    char name[20];
    int quantity;
    float price;
} product;

// Define the structure of a customer
typedef struct customer {
    char name[20];
    char address[50];
    int phone_number;
} customer;

// Function to add a product to the inventory
void add_product(product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter product price: ");
    scanf("%f", &p->price);
}

// Function to remove a product from the inventory
void remove_product(product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter quantity to remove: ");
    scanf("%d", &p->quantity);
}

// Function to view the inventory
void view_inventory(product *p) {
    printf("Product List:\n");
    for (int i = 0; i < p->quantity; i++) {
        printf("%s, %d, %.2f\n", p->name[i], p->quantity, p->price);
    }
}

// Function to bill a customer
void bill_customer(customer *c, product *p) {
    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter customer address: ");
    scanf("%s", c->address);
    printf("Enter customer phone number: ");
    scanf("%d", &c->phone_number);

    int total_amount = 0;
    for (int i = 0; i < p->quantity; i++) {
        total_amount += p->quantity * p->price;
    }

    printf("Total amount: $%d\n", total_amount);
    printf("Payment received: $%d\n", total_amount);
    printf("Change: $%d\n", total_amount - total_amount);
}

int main() {
    // Create an array of products
    product products[10];

    // Create an array of customers
    customer customers[5];

    // Add some products to the inventory
    add_product(products);

    // Remove some products from the inventory
    remove_product(products);

    // View the inventory
    view_inventory(products);

    // Bill a customer
    bill_customer(customers, products);

    return 0;
}