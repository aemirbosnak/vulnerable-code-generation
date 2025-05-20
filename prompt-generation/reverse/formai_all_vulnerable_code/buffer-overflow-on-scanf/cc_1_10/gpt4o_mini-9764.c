//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer();
void deposit();
void withdraw();
void displayCustomer();
void displayAllCustomers();

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Add Customer\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Customer\n");
        printf("5. Display All Customers\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayCustomer();
                break;
            case 5:
                displayAllCustomers();
                break;
            case 6:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addCustomer() {
    if (customerCount < MAX_CUSTOMERS) {
        Customer newCustomer;
        newCustomer.accountNumber = customerCount + 1; // simple account number assignment
        printf("Enter customer name: ");
        getchar(); // clear buffer
        fgets(newCustomer.name, NAME_LENGTH, stdin);
        newCustomer.name[strcspn(newCustomer.name, "\n")] = 0; // remove newline
        newCustomer.balance = 0; // initial balance of 0

        customers[customerCount] = newCustomer;
        customerCount++;
        printf("Customer added successfully! Account Number: %d\n", newCustomer.accountNumber);
    } else {
        printf("Customer limit reached. Cannot add more customers.\n");
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= customerCount) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        if (amount > 0) {
            customers[accountNumber - 1].balance += amount;
            printf("Successfully deposited: %.2f. New balance: %.2f\n", amount, customers[accountNumber - 1].balance);
        } else {
            printf("Deposit amount must be positive.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= customerCount) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (amount > 0 && amount <= customers[accountNumber - 1].balance) {
            customers[accountNumber - 1].balance -= amount;
            printf("Successfully withdrew: %.2f. New balance: %.2f\n", amount, customers[accountNumber - 1].balance);
        } else {
            printf("Invalid withdrawal amount. Check balance or amount.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

void displayCustomer() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= customerCount) {
        Customer customer = customers[accountNumber - 1];
        printf("Account Number: %d\n", customer.accountNumber);
        printf("Customer Name: %s\n", customer.name);
        printf("Balance: %.2f\n", customer.balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void displayAllCustomers() {
    printf("\n=== List of All Customers ===\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}