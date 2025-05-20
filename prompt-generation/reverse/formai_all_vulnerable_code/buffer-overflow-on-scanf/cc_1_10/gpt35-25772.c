//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Maximum number of customers that can be stored */
#define MAX_CUSTOMERS 100

/* Structure to hold customer record */
struct customer {
    int accountNumber;
    char fullName[50];
    float accountBalance;
};

/* Initialize an array to hold customer records */
struct customer customers[MAX_CUSTOMERS];

/* Keep track of number of customers currently stored */
int numCustomers = 0;

/* Function to add a new customer record */
void addCustomer() {
    /* Check if maximum capacity reached */
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Maximum capacity reached.\n");
        return;
    }

    /* Prompt user for customer information */
    printf("Enter account number: ");
    scanf("%d", &customers[numCustomers].accountNumber);
    printf("Enter full name: ");
    scanf("%s", customers[numCustomers].fullName);
    printf("Enter account balance: ");
    scanf("%f", &customers[numCustomers].accountBalance);

    /* Increment number of customers stored */
    numCustomers++;

    printf("Customer record added.\n");
}

/* Function to display all customer records */
void displayCustomers() {
    /* Check if any customers are stored */
    if (numCustomers == 0) {
        printf("No customers found.\n");
        return;
    }

    printf("%-15s %-30s %-15s\n", "Account Number", "Full Name", "Account Balance");

    /* Display each customer record */
    for (int i = 0; i < numCustomers; i++) {
        printf("%-15d %-30s %-15.2f\n", customers[i].accountNumber, customers[i].fullName, customers[i].accountBalance);
    }
}

/* Function to search for a customer record by account number */
void searchCustomer() {
    int accountNumber;
    int foundIndex = -1;

    /* Prompt user for account number to search for */
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    /* Search for customer record by account number */
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            foundIndex = i;
            break;
        }
    }

    /* Display search results */
    if (foundIndex == -1) {
        printf("Customer not found.\n");
    } else {
        printf("%-15s %-30s %-15s\n", "Account Number", "Full Name", "Account Balance");
        printf("%-15d %-30s %-15.2f\n", customers[foundIndex].accountNumber, customers[foundIndex].fullName, customers[foundIndex].accountBalance);
    }
}

/* Function to update a customer record */
void updateCustomer() {
    int accountNumber;
    int foundIndex = -1;

    /* Prompt user for account number to update */
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    /* Search for customer record by account number */
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            foundIndex = i;
            break;
        }
    }

    /* Prompt user for updated customer information */
    if (foundIndex == -1) {
        printf("Customer not found.\n");
    } else {
        printf("Enter full name: ");
        scanf("%s", customers[foundIndex].fullName);
        printf("Enter account balance: ");
        scanf("%f", &customers[foundIndex].accountBalance);

        printf("Customer record updated.\n");
    }
}

/* Function to delete a customer record */
void deleteCustomer() {
    int accountNumber;
    int foundIndex = -1;

    /* Prompt user for account number to delete */
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    /* Search for customer record by account number */
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            foundIndex = i;
            break;
        }
    }

    /* Shift remaining customer records down */
    if (foundIndex != -1) {
        for (int i = foundIndex; i < numCustomers - 1; i++) {
            customers[i] = customers[i + 1];
        }
        numCustomers--;
        printf("Customer record deleted.\n");
    } else {
        printf("Customer not found.\n");
    }
}

/* Function to show the menu of options */
void showMenu() {
    printf("1. Add new customer\n");
    printf("2. Display all customers\n");
    printf("3. Search customer\n");
    printf("4. Update customer\n");
    printf("5. Delete customer\n");
    printf("6. Exit\n");
    printf("Enter option: ");
}

/* Entry point of the program */
int main() {
    int option;

    /* Display menu of options and process user input */
    do {
        showMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomers();
                break;
            case 3:
                searchCustomer();
                break;
            case 4:
                updateCustomer();
                break;
            case 5:
                deleteCustomer();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 6);

    return 0;
}