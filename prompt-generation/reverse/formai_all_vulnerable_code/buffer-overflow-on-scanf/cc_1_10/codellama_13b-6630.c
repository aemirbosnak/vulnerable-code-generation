//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures
typedef struct {
    char name[20];
    char address[50];
    char phone[15];
} Customer;

typedef struct {
    char name[20];
    char category[20];
    int price;
    int quantity;
} Product;

// Function declarations
void createCustomer(Customer *customer);
void displayCustomer(Customer *customer);
void createProduct(Product *product);
void displayProduct(Product *product);
void displayBill(Customer *customer, Product *product);

// Main function
int main() {
    Customer customer;
    Product product;

    createCustomer(&customer);
    displayCustomer(&customer);

    createProduct(&product);
    displayProduct(&product);

    displayBill(&customer, &product);

    return 0;
}

// Function definitions
void createCustomer(Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer address: ");
    scanf("%s", customer->address);
    printf("Enter customer phone number: ");
    scanf("%s", customer->phone);
}

void displayCustomer(Customer *customer) {
    printf("Customer name: %s\n", customer->name);
    printf("Customer address: %s\n", customer->address);
    printf("Customer phone number: %s\n", customer->phone);
}

void createProduct(Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);
    printf("Enter product category: ");
    scanf("%s", product->category);
    printf("Enter product price: ");
    scanf("%d", &product->price);
    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);
}

void displayProduct(Product *product) {
    printf("Product name: %s\n", product->name);
    printf("Product category: %s\n", product->category);
    printf("Product price: %d\n", product->price);
    printf("Product quantity: %d\n", product->quantity);
}

void displayBill(Customer *customer, Product *product) {
    printf("Customer name: %s\n", customer->name);
    printf("Product name: %s\n", product->name);
    printf("Total price: %d\n", product->price * product->quantity);
}