//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CUSTOMERS 1000
#define MAX_ORDERS 10000
#define MAX_PRODUCTS 100

// Structure to store customer data
typedef struct {
    char name[50];
    char email[50];
    int total_spent;
} customer_t;

// Structure to store order data
typedef struct {
    int order_id;
    int customer_id;
    int product_id;
    int quantity;
    int price;
    int total;
} order_t;

// Structure to store product data
typedef struct {
    int product_id;
    char name[50];
    int price;
    int quantity;
} product_t;

// Function to read log files and store data in arrays
void read_log(char *log_file, customer_t *customers, order_t *orders, product_t *products) {
    int i, j, k;
    char line[100];

    // Open log file and read lines
    FILE *log_fp = fopen(log_file, "r");
    if (log_fp == NULL) {
        printf("Error: Unable to open log file %s\n", log_file);
        return;
    }

    for (i = 0; i < MAX_CUSTOMERS; i++) {
        // Read customer data
        fscanf(log_fp, "%s %s %d", customers[i].name, customers[i].email, &customers[i].total_spent);

        // Check for invalid data
        if (customers[i].name[0] == '\0' || customers[i].email[0] == '\0' || customers[i].total_spent == 0) {
            printf("Error: Invalid customer data found\n");
            return;
        }
    }

    for (j = 0; j < MAX_ORDERS; j++) {
        // Read order data
        fscanf(log_fp, "%d %d %d %d %d", &orders[j].order_id, &orders[j].customer_id, &orders[j].product_id, &orders[j].quantity, &orders[j].price);

        // Check for invalid data
        if (orders[j].order_id == 0 || orders[j].customer_id == 0 || orders[j].product_id == 0 || orders[j].quantity == 0 || orders[j].price == 0) {
            printf("Error: Invalid order data found\n");
            return;
        }

        // Check for duplicate orders
        for (k = 0; k < j; k++) {
            if (orders[j].order_id == orders[k].order_id) {
                printf("Error: Duplicate order found\n");
                return;
            }
        }
    }

    for (k = 0; k < MAX_PRODUCTS; k++) {
        // Read product data
        fscanf(log_fp, "%d %s %d", &products[k].product_id, products[k].name, &products[k].quantity);

        // Check for invalid data
        if (products[k].product_id == 0 || products[k].name[0] == '\0' || products[k].quantity == 0) {
            printf("Error: Invalid product data found\n");
            return;
        }
    }

    // Close log file
    fclose(log_fp);
}

int main() {
    char log_file[] = "sales_log.txt";
    customer_t customers[MAX_CUSTOMERS];
    order_t orders[MAX_ORDERS];
    product_t products[MAX_PRODUCTS];

    // Read log file and store data in arrays
    read_log(log_file, customers, orders, products);

    // Analyze data and print results
    int total_revenue = 0;
    int total_customers = 0;
    int top_selling_product = 0;
    int top_customer = 0;

    // Calculate total revenue
    for (int i = 0; i < MAX_ORDERS; i++) {
        total_revenue += orders[i].total;
    }

    // Calculate total number of customers
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        total_customers++;
    }

    // Find top selling product
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity > top_selling_product) {
            top_selling_product = products[i].quantity;
        }
    }

    // Find top customer
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].total_spent > top_customer) {
            top_customer = customers[i].total_spent;
        }
    }

    // Print results
    printf("Total revenue: %d\n", total_revenue);
    printf("Total number of customers: %d\n", total_customers);
    printf("Top selling product: %s (%d units)\n", products[top_selling_product].name, top_selling_product);
    printf("Top customer: %s (%d)\n", customers[top_customer].name, customers[top_customer].total_spent);

    return 0;
}