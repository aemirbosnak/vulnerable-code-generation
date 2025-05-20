//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines and customers
#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 100

// Define the structure of a medicine
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

// Define the structure of a customer
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Customer;

// Declare the arrays of medicines and customers
Medicine medicines[MAX_MEDICINES];
Customer customers[MAX_CUSTOMERS];

// Declare the number of medicines and customers
int num_medicines = 0;
int num_customers = 0;

// Function to add a medicine
void add_medicine() {
    // Get the details of the medicine
    printf("Enter the medicine ID: ");
    scanf("%d", &medicines[num_medicines].id);
    printf("Enter the medicine name: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);
    printf("Enter the medicine price: ");
    scanf("%f", &medicines[num_medicines].price);

    // Increment the number of medicines
    num_medicines++;
}

// Function to add a customer
void add_customer() {
    // Get the details of the customer
    printf("Enter the customer ID: ");
    scanf("%d", &customers[num_customers].id);
    printf("Enter the customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter the customer age: ");
    scanf("%d", &customers[num_customers].age);
    printf("Enter the customer address: ");
    scanf("%s", customers[num_customers].address);

    // Increment the number of customers
    num_customers++;
}

// Function to sell a medicine
void sell_medicine() {
    // Get the ID of the medicine and the quantity to be sold
    int medicine_id;
    int quantity;
    printf("Enter the ID of the medicine to be sold: ");
    scanf("%d", &medicine_id);
    printf("Enter the quantity to be sold: ");
    scanf("%d", &quantity);

    // Find the medicine in the array
    int medicine_index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == medicine_id) {
            medicine_index = i;
            break;
        }
    }

    // If the medicine is not found, display an error message
    if (medicine_index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    // Check if the medicine has sufficient quantity
    if (medicines[medicine_index].quantity < quantity) {
        printf("Insufficient quantity!\n");
        return;
    }

    // Update the quantity of the medicine
    medicines[medicine_index].quantity -= quantity;

    // Calculate the total price of the sale
    float total_price = quantity * medicines[medicine_index].price;

    // Display the total price
    printf("Total price: %.2f\n", total_price);
}

// Function to display the list of medicines
void display_medicines() {
    // Display the header
    printf("ID\tName\t\tQuantity\tPrice\n");

    // Display the medicines
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to display the list of customers
void display_customers() {
    // Display the header
    printf("ID\tName\t\tAge\tAddress\n");

    // Display the customers
    for (int i = 0; i < num_customers; i++) {
        printf("%d\t%s\t\t%d\t%s\n", customers[i].id, customers[i].name, customers[i].age, customers[i].address);
    }
}

// Main function
int main() {
    // Display the menu
    int choice;
    while (1) {
        printf("\n1. Add a medicine\n2. Add a customer\n3. Sell a medicine\n4. Display the list of medicines\n5. Display the list of customers\n6. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}