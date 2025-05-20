//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and customers
#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100

// Define the structures for product and customer
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

typedef struct customer {
    int id;
    char name[50];
    char address[100];
    char phone[20];
} customer;

// Define the global arrays for products and customers
product products[MAX_PRODUCTS];
customer customers[MAX_CUSTOMERS];

// Define the global variables for the number of products and customers
int num_products = 0;
int num_customers = 0;

// Function to add a new product
void add_product() {
    // Get the product details from the user
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    // Increment the number of products
    num_products++;
}

// Function to add a new customer
void add_customer() {
    // Get the customer details from the user
    printf("Enter customer ID: ");
    scanf("%d", &customers[num_customers].id);
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);
    printf("Enter customer phone: ");
    scanf("%s", customers[num_customers].phone);

    // Increment the number of customers
    num_customers++;
}

// Function to display all products
void display_products() {
    // Loop through the products array and print the details of each product
    for (int i = 0; i < num_products; i++) {
        printf("Product ID: %d\n", products[i].id);
        printf("Product Name: %s\n", products[i].name);
        printf("Product Price: %.2f\n", products[i].price);
        printf("Product Quantity: %d\n\n", products[i].quantity);
    }
}

// Function to display all customers
void display_customers() {
    // Loop through the customers array and print the details of each customer
    for (int i = 0; i < num_customers; i++) {
        printf("Customer ID: %d\n", customers[i].id);
        printf("Customer Name: %s\n", customers[i].name);
        printf("Customer Address: %s\n", customers[i].address);
        printf("Customer Phone: %s\n\n", customers[i].phone);
    }
}

// Function to search for a product by ID
product* search_product_by_id(int id) {
    // Loop through the products array and find the product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }

    // If the product is not found, return NULL
    return NULL;
}

// Function to search for a customer by ID
customer* search_customer_by_id(int id) {
    // Loop through the customers array and find the customer with the given ID
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == id) {
            return &customers[i];
        }
    }

    // If the customer is not found, return NULL
    return NULL;
}

// Function to place an order
void place_order() {
    // Get the customer ID and product ID from the user
    int customer_id;
    int product_id;
    int quantity;
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Search for the customer and product
    customer* customer = search_customer_by_id(customer_id);
    product* product = search_product_by_id(product_id);

    // If the customer or product is not found, display an error message
    if (customer == NULL || product == NULL) {
        printf("Customer or product not found!\n");
        return;
    }

    // Check if the product has sufficient quantity
    if (product->quantity < quantity) {
        printf("Insufficient product quantity!\n");
        return;
    }

    // Reduce the product quantity
    product->quantity -= quantity;

    // Display the order details
    printf("Order placed successfully!\n");
    printf("Customer Name: %s\n", customer->name);
    printf("Product Name: %s\n", product->name);
    printf("Quantity: %d\n", quantity);
    printf("Total Price: %.2f\n", quantity * product->price);
}

// Main function
int main() {
    // Add some sample products and customers
    add_product();
    add_product();
    add_product();
    add_customer();
    add_customer();
    add_customer();

    // Display the products and customers
    printf("Products:\n");
    display_products();
    printf("Customers:\n");
    display_customers();

    // Place an order
    place_order();

    return 0;
}