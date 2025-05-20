//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct Medicine
{
    char name[50];
    int quantity;
    float price;
} Medicine;

// Define the structure of a customer
typedef struct Customer
{
    char name[50];
    int contact_number;
    char address[100];
} Customer;

// Function to add a medicine to the store
void add_medicine(Medicine *medicine)
{
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine->name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine->quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine->price);
}

// Function to remove a medicine from the store
void remove_medicine(Medicine *medicine)
{
    printf("Enter the name of the medicine you want to remove: ");
    scanf("%s", medicine->name);

    printf("Enter the quantity of the medicine you want to remove: ");
    scanf("%d", &medicine->quantity);
}

// Function to update the quantity of a medicine
void update_quantity(Medicine *medicine)
{
    printf("Enter the name of the medicine you want to update: ");
    scanf("%s", medicine->name);

    printf("Enter the new quantity of the medicine: ");
    scanf("%d", &medicine->quantity);
}

// Function to search for a medicine
void search_medicine(Medicine *medicine)
{
    printf("Enter the name of the medicine you are looking for: ");
    scanf("%s", medicine->name);

    printf("Here is the information about the medicine: \n");
    printf("Name: %s\n", medicine->name);
    printf("Quantity: %d\n", medicine->quantity);
    printf("Price: %.2f\n", medicine->price);
}

// Function to add a customer to the store
void add_customer(Customer *customer)
{
    printf("Enter the name of the customer: ");
    scanf("%s", customer->name);

    printf("Enter the contact number of the customer: ");
    scanf("%d", &customer->contact_number);

    printf("Enter the address of the customer: ");
    scanf("%s", customer->address);
}

// Function to remove a customer from the store
void remove_customer(Customer *customer)
{
    printf("Enter the name of the customer you want to remove: ");
    scanf("%s", customer->name);

    printf("Enter the contact number of the customer you want to remove: ");
    scanf("%d", &customer->contact_number);
}

// Function to update the contact number of a customer
void update_contact_number(Customer *customer)
{
    printf("Enter the name of the customer you want to update: ");
    scanf("%s", customer->name);

    printf("Enter the new contact number of the customer: ");
    scanf("%d", &customer->contact_number);
}

// Function to search for a customer
void search_customer(Customer *customer)
{
    printf("Enter the name of the customer you are looking for: ");
    scanf("%s", customer->name);

    printf("Here is the information about the customer: \n");
    printf("Name: %s\n", customer->name);
    printf("Contact Number: %d\n", customer->contact_number);
    printf("Address: %s\n", customer->address);
}

int main()
{
    Medicine medicine;
    Customer customer;

    // Add a medicine to the store
    add_medicine(&medicine);

    // Remove a medicine from the store
    remove_medicine(&medicine);

    // Update the quantity of a medicine
    update_quantity(&medicine);

    // Search for a medicine
    search_medicine(&medicine);

    // Add a customer to the store
    add_customer(&customer);

    // Remove a customer from the store
    remove_customer(&customer);

    // Update the contact number of a customer
    update_contact_number(&customer);

    // Search for a customer
    search_customer(&customer);

    return 0;
}