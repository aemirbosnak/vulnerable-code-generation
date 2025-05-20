//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50

// Customer Structure
typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Customer;

// Function prototypes
void displayMenu();
void addCustomer(Customer *customers, int *customerCount);
void viewCustomers(Customer *customers, int customerCount);
void depositFunds(Customer *customers, int customerCount);
void withdrawFunds(Customer *customers, int customerCount);
void viewCustomerBalance(Customer *customers, int customerCount);

int main() {
    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, &customerCount);
                break;
            case 2:
                viewCustomers(customers, customerCount);
                break;
            case 3:
                depositFunds(customers, customerCount);
                break;
            case 4:
                withdrawFunds(customers, customerCount);
                break;
            case 5:
                viewCustomerBalance(customers, customerCount);
                break;
            case 6:
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Add New Customer\n");
    printf("2. View All Customers\n");
    printf("3. Deposit Funds\n");
    printf("4. Withdraw Funds\n");
    printf("5. View Customer Balance\n");
    printf("6. Exit\n");
}

void addCustomer(Customer *customers, int *customerCount) {
    if (*customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached! Cannot add more customers.\n");
        return;
    }

    int accountNumber;
    char name[NAME_LENGTH];
    float balance;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    printf("Enter Customer Name: ");
    scanf("%s", name);
    printf("Enter Initial Balance: ");
    scanf("%f", &balance);

    customers[*customerCount].accountNumber = accountNumber;
    strncpy(customers[*customerCount].name, name, NAME_LENGTH);
    customers[*customerCount].balance = balance;
    (*customerCount)++;

    printf("Customer added successfully!\n");
}

void viewCustomers(Customer *customers, int customerCount) {
    if (customerCount == 0) {
        printf("No customers found.\n");
        return;
    }

    printf("\n--- List of Customers ---\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               customers[i].accountNumber,
               customers[i].name,
               customers[i].balance);
    }
}

void depositFunds(Customer *customers, int customerCount) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter Account Number to deposit into: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            customers[i].balance += amount;
            found = 1;
            printf("Deposited %.2f to account number %d. New Balance: %.2f\n",
                   amount, accountNumber, customers[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account number not found!\n");
    }
}

void withdrawFunds(Customer *customers, int customerCount) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                found = 1;
                printf("Withdrawn %.2f from account number %d. New Balance: %.2f\n",
                       amount, accountNumber, customers[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Account number not found!\n");
    }
}

void viewCustomerBalance(Customer *customers, int customerCount) {
    int accountNumber;
    int found = 0;

    printf("Enter Account Number to view balance: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",
                   customers[i].accountNumber,
                   customers[i].name,
                   customers[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account number not found!\n");
    }
}