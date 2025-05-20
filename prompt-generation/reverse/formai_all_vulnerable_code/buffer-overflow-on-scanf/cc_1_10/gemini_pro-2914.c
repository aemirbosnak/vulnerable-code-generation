//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines and customers
#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 100

// Define the structure of a medicine
typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} medicine_t;

// Define the structure of a customer
typedef struct {
    int id;
    char name[100];
    float balance;
} customer_t;

// Define the array of medicines
medicine_t medicines[MAX_MEDICINES];

// Define the array of customers
customer_t customers[MAX_CUSTOMERS];

// Define the current number of medicines and customers
int num_medicines = 0;
int num_customers = 0;

// Function to add a new medicine
void add_medicine() {
    // Get the medicine details from the user
    printf("Enter the medicine name: ");
    scanf("%s", medicines[num_medicines].name);

    printf("Enter the medicine price: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);

    // Increment the number of medicines
    num_medicines++;
}

// Function to add a new customer
void add_customer() {
    // Get the customer details from the user
    printf("Enter the customer name: ");
    scanf("%s", customers[num_customers].name);

    printf("Enter the customer balance: ");
    scanf("%f", &customers[num_customers].balance);

    // Increment the number of customers
    num_customers++;
}

// Function to sell a medicine
void sell_medicine() {
    // Get the medicine ID from the user
    int medicine_id;
    printf("Enter the medicine ID: ");
    scanf("%d", &medicine_id);

    // Get the customer ID from the user
    int customer_id;
    printf("Enter the customer ID: ");
    scanf("%d", &customer_id);

    // Get the quantity of medicine to be sold
    int quantity;
    printf("Enter the quantity of medicine to be sold: ");
    scanf("%d", &quantity);

    // Check if the medicine is available
    if (medicines[medicine_id].quantity >= quantity) {
        // Deduct the quantity from the medicine
        medicines[medicine_id].quantity -= quantity;

        // Add the price of the medicine to the customer's balance
        customers[customer_id].balance += medicines[medicine_id].price * quantity;

        // Print the receipt
        printf("Receipt:\n");
        printf("Medicine name: %s\n", medicines[medicine_id].name);
        printf("Quantity sold: %d\n", quantity);
        printf("Total price: %f\n", medicines[medicine_id].price * quantity);
    } else {
        // Print an error message
        printf("Error: Not enough medicine in stock.\n");
    }
}

// Function to display the list of medicines
void display_medicines() {
    // Print the header
    printf("List of Medicines:\n");
    printf("ID\tName\tPrice\tQuantity\n");

    // Print the details of each medicine
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t%f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to display the list of customers
void display_customers() {
    // Print the header
    printf("List of Customers:\n");
    printf("ID\tName\tBalance\n");

    // Print the details of each customer
    for (int i = 0; i < num_customers; i++) {
        printf("%d\t%s\t%f\n", customers[i].id, customers[i].name, customers[i].balance);
    }
}

// Main function
int main() {
    // Add some sample medicines and customers
    add_medicine();
    add_medicine();
    add_medicine();
    add_customer();
    add_customer();
    add_customer();

    // Display the list of medicines
    display_medicines();

    // Display the list of customers
    display_customers();

    // Sell a medicine
    sell_medicine();

    // Display the updated list of medicines
    display_medicines();

    // Display the updated list of customers
    display_customers();

    return 0;
}