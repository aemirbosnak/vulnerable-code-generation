//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
// Warehouse Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Define the product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the inventory structure
typedef struct inventory {
    int capacity;
    int count;
    Product* products;
} Inventory;

// Define the customer structure
typedef struct customer {
    char name[50];
    int balance;
} Customer;

// Define the sales transaction structure
typedef struct transaction {
    Product product;
    int quantity;
    float total;
} Transaction;

// Initialize the inventory
Inventory* init_inventory(int capacity) {
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->capacity = capacity;
    inventory->count = 0;
    inventory->products = malloc(capacity * sizeof(Product));
    return inventory;
}

// Add a product to the inventory
void add_product(Inventory* inventory, Product product) {
    inventory->products[inventory->count] = product;
    inventory->count++;
}

// Get a product from the inventory
Product* get_product(Inventory* inventory, int index) {
    if (index >= inventory->count) {
        return NULL;
    }
    return &inventory->products[index];
}

// Update the inventory
void update_inventory(Inventory* inventory, Product product, int quantity) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, product.name) == 0) {
            inventory->products[i].quantity += quantity;
            return;
        }
    }
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    for (int i = 0; i < inventory->count; i++) {
        printf("%s: %d\n", inventory->products[i].name, inventory->products[i].quantity);
    }
}

// Initialize the customer
Customer* init_customer(char* name) {
    Customer* customer = malloc(sizeof(Customer));
    strcpy(customer->name, name);
    customer->balance = 0;
    return customer;
}

// Print the customer balance
void print_customer_balance(Customer* customer) {
    printf("Balance: %d\n", customer->balance);
}

// Make a sales transaction
Transaction* make_transaction(Inventory* inventory, Customer* customer, Product product, int quantity) {
    Transaction* transaction = malloc(sizeof(Transaction));
    transaction->product = product;
    transaction->quantity = quantity;
    transaction->total = quantity * product.price;

    // Update the inventory
    update_inventory(inventory, product, -quantity);

    // Update the customer balance
    customer->balance += transaction->total;

    return transaction;
}

// Print the sales transaction
void print_transaction(Transaction* transaction) {
    printf("%s: %d @ %0.2f\n", transaction->product.name, transaction->quantity, transaction->product.price);
}

// Print the receipt
void print_receipt(Transaction* transaction) {
    printf("Receipt:\n");
    print_transaction(transaction);
    printf("Total: %0.2f\n", transaction->total);
}

int main() {
    // Initialize the inventory
    Inventory* inventory = init_inventory(5);

    // Initialize the customers
    Customer* customer1 = init_customer("John");
    Customer* customer2 = init_customer("Mary");

    // Add products to the inventory
    Product product1 = {"Apple", 10, 1.5};
    Product product2 = {"Banana", 20, 0.5};
    Product product3 = {"Cherry", 30, 2.0};
    add_product(inventory, product1);
    add_product(inventory, product2);
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Make sales transactions
    Transaction* transaction1 = make_transaction(inventory, customer1, product1, 5);
    Transaction* transaction2 = make_transaction(inventory, customer2, product2, 10);
    Transaction* transaction3 = make_transaction(inventory, customer1, product3, 2);

    // Print the sales transactions
    print_transaction(transaction1);
    print_transaction(transaction2);
    print_transaction(transaction3);

    // Print the customer balances
    print_customer_balance(customer1);
    print_customer_balance(customer2);

    // Print the receipts
    print_receipt(transaction1);
    print_receipt(transaction2);
    print_receipt(transaction3);

    // Free the memory
    free(inventory->products);
    free(inventory);
    free(customer1);
    free(customer2);

    return 0;
}