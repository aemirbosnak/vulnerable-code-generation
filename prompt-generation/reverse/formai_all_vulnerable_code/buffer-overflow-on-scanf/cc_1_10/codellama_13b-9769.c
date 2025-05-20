//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: scalable
// Database simulation program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 1000
#define MAX_PRODUCTS 1000
#define MAX_TRANSACTIONS 1000000

// Define data structures
typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    float price;
} Product;

typedef struct {
    int customer_id;
    int product_id;
    int quantity;
    float total_price;
} Transaction;

// Define functions
void read_customers(Customer customers[], int num_customers) {
    for (int i = 0; i < num_customers; i++) {
        printf("Enter customer %d: ", i + 1);
        scanf("%s %d %s", customers[i].name, &customers[i].age, customers[i].address);
    }
}

void read_products(Product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("Enter product %d: ", i + 1);
        scanf("%s %f", products[i].name, &products[i].price);
    }
}

void read_transactions(Transaction transactions[], int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction %d: ", i + 1);
        scanf("%d %d %d %f", &transactions[i].customer_id, &transactions[i].product_id, &transactions[i].quantity, &transactions[i].total_price);
    }
}

void simulate_database(Customer customers[], Product products[], Transaction transactions[], int num_customers, int num_products, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        Customer customer = customers[transactions[i].customer_id - 1];
        Product product = products[transactions[i].product_id - 1];
        float total_price = product.price * transactions[i].quantity;
        printf("Customer %s (age %d, address %s) purchased %d units of product %s at a total cost of %f.\n", customer.name, customer.age, customer.address, transactions[i].quantity, product.name, total_price);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Read customer data
    Customer customers[MAX_CUSTOMERS];
    int num_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);
    read_customers(customers, num_customers);

    // Read product data
    Product products[MAX_PRODUCTS];
    int num_products;
    printf("Enter the number of products: ");
    scanf("%d", &num_products);
    read_products(products, num_products);

    // Read transaction data
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);
    read_transactions(transactions, num_transactions);

    // Simulate database
    simulate_database(customers, products, transactions, num_customers, num_products, num_transactions);

    return 0;
}