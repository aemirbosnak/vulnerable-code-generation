//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold customer information
typedef struct customer {
    char name[50];
    int id;
    float balance;
} Customer;

// Function to add a customer
void addCustomer(Customer *cust) {
    printf("Enter customer name: ");
    scanf("%s", cust->name);
    printf("Enter customer ID: ");
    scanf("%d", &cust->id);
    printf("Enter customer balance: ");
    scanf("%f", &cust->balance);
}

// Function to remove a customer
void removeCustomer(Customer *cust) {
    printf("Enter customer ID to remove: ");
    scanf("%d", &cust->id);
    printf("Customer removed.\n");
}

// Function to update customer balance
void updateBalance(Customer *cust) {
    printf("Enter new balance: ");
    scanf("%f", &cust->balance);
    printf("Balance updated.\n");
}

// Function to display customer information
void displayCustomer(Customer *cust) {
    printf("Name: %s\n", cust->name);
    printf("ID: %d\n", cust->id);
    printf("Balance: %.2f\n", cust->balance);
}

int main() {
    Customer cust1;
    addCustomer(&cust1);
    displayCustomer(&cust1);
    removeCustomer(&cust1);
    updateBalance(&cust1);
    displayCustomer(&cust1);
    return 0;
}