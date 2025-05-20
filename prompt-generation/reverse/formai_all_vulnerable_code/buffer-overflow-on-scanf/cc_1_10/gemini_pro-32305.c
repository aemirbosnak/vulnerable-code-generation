//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines and customers
#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 100

// Define the structure of a medicine
typedef struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

// Define the structure of a customer
typedef struct Customer {
    int id;
    char name[50];
    float balance;
} Customer;

// Define the array of medicines
Medicine medicines[MAX_MEDICINES];

// Define the array of customers
Customer customers[MAX_CUSTOMERS];

// Initialize the number of medicines and customers to 0
int num_medicines = 0;
int num_customers = 0;

// Function to add a new medicine
void add_medicine() {
    // Get the details of the new medicine
    printf("Enter the ID of the new medicine: ");
    scanf("%d", &medicines[num_medicines].id);
    printf("Enter the name of the new medicine: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter the price of the new medicine: ");
    scanf("%f", &medicines[num_medicines].price);
    printf("Enter the quantity of the new medicine: ");
    scanf("%d", &medicines[num_medicines].quantity);

    // Increment the number of medicines
    num_medicines++;
}

// Function to add a new customer
void add_customer() {
    // Get the details of the new customer
    printf("Enter the ID of the new customer: ");
    scanf("%d", &customers[num_customers].id);
    printf("Enter the name of the new customer: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter the balance of the new customer: ");
    scanf("%f", &customers[num_customers].balance);

    // Increment the number of customers
    num_customers++;
}

// Function to sell a medicine
void sell_medicine() {
    // Get the ID of the medicine to be sold
    int medicine_id;
    printf("Enter the ID of the medicine to be sold: ");
    scanf("%d", &medicine_id);

    // Find the medicine by its ID
    int medicine_index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == medicine_id) {
            medicine_index = i;
            break;
        }
    }

    // Check if the medicine was found
    if (medicine_index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    // Get the quantity of the medicine to be sold
    int quantity;
    printf("Enter the quantity of the medicine to be sold: ");
    scanf("%d", &quantity);

    // Check if the medicine is in stock
    if (medicines[medicine_index].quantity < quantity) {
        printf("Medicine out of stock.\n");
        return;
    }

    // Calculate the total price of the medicine
    float total_price = medicines[medicine_index].price * quantity;

    // Get the ID of the customer
    int customer_id;
    printf("Enter the ID of the customer: ");
    scanf("%d", &customer_id);

    // Find the customer by its ID
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
    if (customers[customer_index].balance < total_price) {
        printf("Customer does not have enough balance.\n");
        return;
    }

    // Deduct the quantity of the medicine from the stock
    medicines[medicine_index].quantity -= quantity;

    // Deduct the total price of the medicine from the customer's balance
    customers[customer_index].balance -= total_price;

    // Print the receipt
    printf("Receipt:\n");
    printf("Medicine: %s\n", medicines[medicine_index].name);
    printf("Quantity: %d\n", quantity);
    printf("Total price: %.2f\n", total_price);
    printf("Customer: %s\n", customers[customer_index].name);
    printf("Balance: %.2f\n", customers[customer_index].balance);
}

// Function to display the list of medicines
void display_medicines() {
    printf("List of medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d %s %.2f %d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to display the list of customers
void display_customers() {
    printf("List of customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d %s %.2f\n", customers[i].id, customers[i].name, customers[i].balance);
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

    return 0;
}