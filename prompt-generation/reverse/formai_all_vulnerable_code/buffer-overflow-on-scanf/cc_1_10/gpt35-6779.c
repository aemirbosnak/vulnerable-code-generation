//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int account_number;
    char name[50];
    float balance;
};

typedef struct customer Customer;

void addCustomer(Customer *customers, int *numberOfCustomers);
void deposit(Customer *customers, int numberOfCustomers);
void withdraw(Customer *customers, int numberOfCustomers);
void display(Customer *customers, int numberOfCustomers);

int main() {
    Customer customers[100]; // maximum of 100 customers
    int numberOfCustomers = 0;
    int choice;
    char continueChoice;

    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Add a new customer\n");
        printf("2. Deposit money into an account\n");
        printf("3. Withdraw money from an account\n");
        printf("4. Display all customers\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCustomer(customers, &numberOfCustomers);
                break;
            case 2:
                deposit(customers, numberOfCustomers);
                break;
            case 3:
                withdraw(customers, numberOfCustomers);
                break;
            case 4:
                display(customers, numberOfCustomers);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &continueChoice);
    } while(continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

void addCustomer(Customer *customers, int *numberOfCustomers) {
    int accountNumber;
    char name[50];
    float balance;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    // check if account number already exists
    for(int i=0; i<*numberOfCustomers; i++) {
        if(customers[i].account_number == accountNumber) {
            printf("An account with that number already exists. Try again.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter balance: ");
    scanf("%f", &balance);

    customers[*numberOfCustomers].account_number = accountNumber;
    strcpy(customers[*numberOfCustomers].name, name);
    customers[*numberOfCustomers].balance = balance;

    printf("Customer added successfully!\n");
    (*numberOfCustomers)++;
}

void deposit(Customer *customers, int numberOfCustomers) {
    int accountNumber;
    float amount;

    printf("\nEnter account number to deposit into: ");
    scanf("%d", &accountNumber);

    // find the customer with the account number
    int customerIndex = -1;
    for(int i=0; i<numberOfCustomers; i++) {
        if(customers[i].account_number == accountNumber) {
            customerIndex = i;
            break;
        }
    }

    if(customerIndex == -1) {
        printf("Customer account not found. Try again.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    customers[customerIndex].balance += amount;

    printf("Deposit successful!\n");
}

void withdraw(Customer *customers, int numberOfCustomers) {
    int accountNumber;
    float amount;

    printf("\nEnter account number to withdraw from: ");
    scanf("%d", &accountNumber);

    // find the customer with the account number
    int customerIndex = -1;
    for(int i=0; i<numberOfCustomers; i++) {
        if(customers[i].account_number == accountNumber) {
            customerIndex = i;
            break;
        }
    }

    if(customerIndex == -1) {
        printf("Customer account not found. Try again.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount > customers[customerIndex].balance) {
        printf("Insufficient balance in account. Try again.\n");
        return;
    }

    customers[customerIndex].balance -= amount;

    printf("Withdrawal successful!\n");
}

void display(Customer *customers, int numberOfCustomers) {
    printf("\n---- All Customers ----\n\n");
    printf("Account Number\tName\t\tBalance\n");
    for(int i=0; i<numberOfCustomers; i++) {
        printf("%d\t\t%s\t\t$%.2f\n", customers[i].account_number, customers[i].name, customers[i].balance);
    }
    printf("\n");
}