//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and customers
#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Define the customer structure
typedef struct customer {
    int id;
    char name[50];
    float balance;
} customer;

// Define the array of products
product products[MAX_PRODUCTS];

// Define the array of customers
customer customers[MAX_CUSTOMERS];

// Define the current number of products and customers
int num_products = 0;
int num_customers = 0;

// Function to add a new product
void add_product() {
    // Get the product details from the user
    printf("Enter the product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter the product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter the product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter the product quantity: ");
    scanf("%d", &products[num_products].quantity);

    // Increment the number of products
    num_products++;
}

// Function to add a new customer
void add_customer() {
    // Get the customer details from the user
    printf("Enter the customer ID: ");
    scanf("%d", &customers[num_customers].id);
    printf("Enter the customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter the customer balance: ");
    scanf("%f", &customers[num_customers].balance);

    // Increment the number of customers
    num_customers++;
}

// Function to sell a product
void sell_product() {
    // Get the product ID and quantity from the user
    int product_id;
    int quantity;
    printf("Enter the product ID: ");
    scanf("%d", &product_id);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Find the product in the array
    int product_index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            product_index = i;
            break;
        }
    }

    // Check if the product was found
    if (product_index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Check if the product has enough quantity
    if (products[product_index].quantity < quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    // Update the product quantity
    products[product_index].quantity -= quantity;

    // Get the customer ID and balance from the user
    int customer_id;
    float balance;
    printf("Enter the customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter the customer balance: ");
    scanf("%f", &balance);

    // Find the customer in the array
    int customer_index = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == customer_id) {
            customer_index = i;
            break;
        }
    }

    // Check if the customer was found
    if (customer_index == -1) {
        printf("Customer not found.\n");
        return;
    }

    // Check if the customer has enough balance
    if (customers[customer_index].balance < products[product_index].price * quantity) {
        printf("Insufficient balance.\n");
        return;
    }

    // Update the customer balance
    customers[customer_index].balance -= products[product_index].price * quantity;

    // Print the receipt
    printf("Receipt:\n");
    printf("Product: %s\n", products[product_index].name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", products[product_index].price);
    printf("Total: %.2f\n", products[product_index].price * quantity);
    printf("Customer: %s\n", customers[customer_index].name);
    printf("Balance: %.2f\n", customers[customer_index].balance);
}

// Function to list all products
void list_products() {
    // Print the header
    printf("ID | Name | Price | Quantity\n");

    // Loop through the array of products and print the details
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %.2f | %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to list all customers
void list_customers() {
    // Print the header
    printf("ID | Name | Balance\n");

    // Loop through the array of customers and print the details
    for (int i = 0; i < num_customers; i++) {
        printf("%d | %s | %.2f\n", customers[i].id, customers[i].name, customers[i].balance);
    }
}

// Main function
int main() {
    // Display the menu
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new product\n");
        printf("2. Add a new customer\n");
        printf("3. Sell a product\n");
        printf("4. List all products\n");
        printf("5. List all customers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                sell_product();
                break;
            case 4:
                list_products();
                break;
            case 5:
                list_customers();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}