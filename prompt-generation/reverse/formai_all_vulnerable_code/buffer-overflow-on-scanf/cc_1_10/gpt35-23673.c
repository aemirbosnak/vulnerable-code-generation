//FormAI DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 50

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

void printMenu();
void addCustomer();
void viewCustomer();
void deposit();
void withdraw();

int main() {
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomer();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Thank you for using our system!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void printMenu() {
    printf("\nWelcome to our Banking Record System!\n");
    printf("------------------------------------\n");
    printf("1. Add a new customer\n");
    printf("2. View customer details\n");
    printf("3. Deposit money into an account\n");
    printf("4. Withdraw money from an account\n");
    printf("5. Exit system\n");
    printf("------------------------------------\n");
    printf("Enter your choice: ");
}

void addCustomer() {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Sorry, the maximum number of customers has been reached.\n");
        return;
    }

    Customer newCustomer;

    printf("\nEnter customer name: ");
    scanf(" %[^\n]", newCustomer.name);

    printf("\nEnter account number: ");
    scanf("%d", &newCustomer.accountNumber);

    printf("\nEnter initial balance: ");
    scanf("%f", &newCustomer.balance);

    customers[numCustomers++] = newCustomer;

    printf("\nNew customer added successfully!\n");
}

void viewCustomer() {
    int accountNumber, i;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\nCustomer details:\n");
            printf("Name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].accountNumber);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }

    printf("\nSorry, no customer found with account number %d.\n", accountNumber);
}

void deposit() {
    int accountNumber, i;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);

            customers[i].balance += amount;

            printf("\nDeposit of %.2f successful!\n", amount);
            printf("New balance: %.2f\n", customers[i].balance);

            return;
        }
    }

    printf("\nSorry, no customer found with account number %d.\n", accountNumber);
}

void withdraw() {
    int accountNumber, i;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if (customers[i].balance < amount) {
                printf("\nWithdrawal failed, insufficient funds.\n");
                return;
            }

            customers[i].balance -= amount;

            printf("\nWithdrawal of %.2f successful!\n", amount);
            printf("New balance: %.2f\n", customers[i].balance);

            return;
        }
    }

    printf("\nSorry, no customer found with account number %d.\n", accountNumber);
}