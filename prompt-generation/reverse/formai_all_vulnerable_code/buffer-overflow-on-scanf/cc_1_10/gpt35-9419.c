//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Customer structure
typedef struct Customer {
    int id;
    char* name;
    char* email;
    char* phone_number;
} Customer;

//Array of customers
Customer customers[5] = {
    {1, "John Wayne", "johnwayne@email.com", "123-456-7890"},
    {2, "Lucy Lane", "lucylane@email.com", "234-567-8901"},
    {3, "Lionel Messi", "lionelmessi@email.com", "345-678-9012"},
    {4, "Maria Sharapova", "mariasharapova@email.com", "456-789-0123"},
    {5, "Roger Federer", "rogerfederer@email.com", "567-890-1234"},
};

//Function to get customer by ID
Customer get_customer_by_id(int id) {
    Customer default_customer = {0, "", "", ""};
    for(int i=0; i<5; i++) {
        Customer customer = customers[i];
        if(customer.id == id) {
            return customer;
        }
    }
    return default_customer;
}

//Function to get customer by name
Customer get_customer_by_name(char* name) {
    Customer default_customer = {0, "", "", ""};
    for(int i=0; i<5; i++) {
        Customer customer = customers[i];
        if(strcmp(customer.name, name) == 0) {
            return customer;
        }
    }
    return default_customer;
}

//Function to print customer details
void print_customer(Customer customer) {
    printf("Customer ID: %d\n", customer.id);
    printf("Name: %s\n", customer.name);
    printf("Email: %s\n", customer.email);
    printf("Phone Number: %s\n", customer.phone_number);
}

//Main function
int main() {
    printf("Welcome to the Customer Database\n");
    printf("================================\n\n");

    //Get customer by ID
    int id;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    Customer customer_by_id = get_customer_by_id(id);
    if(customer_by_id.id != 0) {
        printf("\nCustomer details by ID:\n");
        print_customer(customer_by_id);
    } else {
        printf("\nCustomer not found\n");
    }

    //Get customer by name
    char name[50];
    printf("\nEnter customer name: ");
    scanf("%s", name);
    Customer customer_by_name = get_customer_by_name(name);
    if(customer_by_name.id != 0) {
        printf("\nCustomer details by name:\n");
        print_customer(customer_by_name);
    } else {
        printf("\nCustomer not found\n");
    }

    return 0;
}