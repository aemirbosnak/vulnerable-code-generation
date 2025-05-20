//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines and customers
#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
} medicine;

// Define the structure of a customer
typedef struct customer {
    char name[50];
    char address[100];
    int phone_number;
} customer;

// Define the array of medicines
medicine medicines[MAX_MEDICINES];

// Define the array of customers
customer customers[MAX_CUSTOMERS];

// Initialize the number of medicines and customers
int num_medicines = 0;
int num_customers = 0;

// Function to add a new medicine
void add_medicine() {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[num_medicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[num_medicines].price);

    // Increment the number of medicines
    num_medicines++;
}

// Function to add a new customer
void add_customer() {
    // Get the customer details from the user
    printf("Enter the name of the customer: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter the address of the customer: ");
    scanf("%s", customers[num_customers].address);
    printf("Enter the phone number of the customer: ");
    scanf("%d", &customers[num_customers].phone_number);

    // Increment the number of customers
    num_customers++;
}

// Function to sell a medicine
void sell_medicine() {
    // Get the name of the medicine from the user
    char medicine_name[50];
    printf("Enter the name of the medicine to be sold: ");
    scanf("%s", medicine_name);

    // Find the medicine in the array of medicines
    int medicine_index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, medicine_name) == 0) {
            medicine_index = i;
            break;
        }
    }

    // If the medicine is not found, display an error message
    if (medicine_index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    // Get the quantity of the medicine to be sold
    int quantity;
    printf("Enter the quantity of the medicine to be sold: ");
    scanf("%d", &quantity);

    // If the quantity is greater than the available quantity, display an error message
    if (quantity > medicines[medicine_index].quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    // Update the quantity of the medicine
    medicines[medicine_index].quantity -= quantity;

    // Display the bill
    float bill_amount = quantity * medicines[medicine_index].price;
    printf("Bill amount: %.2f\n", bill_amount);
}

// Function to display the list of medicines
void display_medicines() {
    // Print the header
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Medicine Name", "Quantity", "Price");
    printf("--------------------------------------------------------------------------------\n");

    // Print the details of each medicine
    for (int i = 0; i < num_medicines; i++) {
        printf("| %-20s | %-10d | %-10.2f |\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    // Print the footer
    printf("--------------------------------------------------------------------------------\n");
}

// Function to display the list of customers
void display_customers() {
    // Print the header
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-50s | %-20s |\n", "Customer Name", "Customer Address", "Customer Phone Number");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Print the details of each customer
    for (int i = 0; i < num_customers; i++) {
        printf("| %-20s | %-50s | %-20d |\n", customers[i].name, customers[i].address, customers[i].phone_number);
    }

    // Print the footer
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Display the welcome message
    printf("Welcome to the Medical Store Management System!\n");

    // Display the main menu
    int choice;
    do {
        printf("\n--------------------------------------------------------------------------------\n");
        printf("1. Add a new medicine\n");
        printf("2. Add a new customer\n");
        printf("3. Sell a medicine\n");
        printf("4. Display the list of medicines\n");
        printf("5. Display the list of customers\n");
        printf("6. Exit\n");
        printf("--------------------------------------------------------------------------------\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                sell_medicine();
                break;
            case 4:
                display_medicines();
                break;
            case 5:
                display_customers();
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}