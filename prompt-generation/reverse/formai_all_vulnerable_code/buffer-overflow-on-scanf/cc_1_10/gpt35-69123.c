//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    int accountNumber;
    char name[50];
    double balance;
};

int numberOfCustomers = 0;
struct Customer customers[MAX_CUSTOMERS];

int findCustomer(int accountNumber) {
    for (int i = 0; i < numberOfCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            return i;
        }
    }

    return -1;
}

void addCustomer() {
    if (numberOfCustomers >= MAX_CUSTOMERS) {
        printf("Sorry, the maximum number of customers has been reached.\n");
        return;
    }

    struct Customer customer;
    printf("Enter the account number: ");
    scanf("%d", &customer.accountNumber);

    if (findCustomer(customer.accountNumber) != -1) {
        printf("Sorry, a customer with that account number already exists.\n");
        return;
    }

    printf("Enter the customer name: ");
    scanf(" %[^\n]", customer.name);

    printf("Enter the opening balance: ");
    scanf("%lf", &customer.balance);

    customers[numberOfCustomers] = customer;
    numberOfCustomers++;

    printf("New customer added successfully.\n");
}

void viewCustomerDetails() {
    int accountNumber;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    int index = findCustomer(accountNumber);

    if (index == -1) {
        printf("Sorry, a customer with that account number does not exist.\n");
        return;
    }

    struct Customer customer = customers[index];
    printf("Account Number: %d\n", customer.accountNumber);
    printf("Customer Name: %s\n", customer.name);
    printf("Balance: %.2lf\n", customer.balance);
}

void transferMoney() {
    int fromAccountNumber, toAccountNumber;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &fromAccountNumber);

    int fromIndex = findCustomer(fromAccountNumber);

    if (fromIndex == -1) {
        printf("Sorry, a customer with that account number does not exist.\n");
        return;
    }

    printf("Enter the recipient's account number: ");
    scanf("%d", &toAccountNumber);

    int toIndex = findCustomer(toAccountNumber);

    if (toIndex == -1) {
        printf("Sorry, a customer with that account number does not exist.\n");
        return;
    }

    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    if (amount > customers[fromIndex].balance) {
        printf("Sorry, you do not have enough money to make that transfer.\n");
        return;
    }

    customers[fromIndex].balance -= amount;
    customers[toIndex].balance += amount;

    printf("Transfer of %.2lf successful.\n", amount);
}

int main() {
    int choice;

    while (1) {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Add a new customer\n");
        printf("2. View customer details\n");
        printf("3. Transfer money\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                viewCustomerDetails();
                break;

            case 3:
                transferMoney();
                break;

            case 4:
                printf("Thanks for using the Banking Record System.\n");
                return 0;

            default:
                printf("Sorry, that is an invalid choice.\n");
                break;
        }
    }
}