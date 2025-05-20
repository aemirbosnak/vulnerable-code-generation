//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_HISTORY 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    double amount;
    char type[10]; // Deposit or Withdraw
} Transaction;

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    double balance;
    int transactionCount;
    Transaction transactions[MAX_TRANSACTION_HISTORY];
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer();
void viewCustomer(int accountNumber);
void deposit(int accountNumber, double amount);
void withdraw(int accountNumber, double amount);
void viewTransactionHistory(int accountNumber);
int findCustomer(int accountNumber);
void listAllCustomers();

int main() {
    int choice;

    while (1) {
        printf("\n===== Banking Record System =====\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. View Transaction History\n");
        printf("6. List All Customers\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2: {
                int accountNumber;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewCustomer(accountNumber);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(accountNumber, amount);
                break;
            }
            case 5: {
                int accountNumber;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewTransactionHistory(accountNumber);
                break;
            }
            case 6:
                listAllCustomers();
                break;
            case 7:
                printf("Exiting the Banking Record System.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &customers[customerCount].accountNumber);
    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", customers[customerCount].name);
    customers[customerCount].balance = 0.0;
    customers[customerCount].transactionCount = 0;
    customerCount++;

    printf("Customer added successfully.\n");
}

void viewCustomer(int accountNumber) {
    int index = findCustomer(accountNumber);
    if (index != -1) {
        printf("\n===== Customer Details =====\n");
        printf("Account Number: %d\n", customers[index].accountNumber);
        printf("Name: %s\n", customers[index].name);
        printf("Balance: %.2f\n", customers[index].balance);
    } else {
        printf("Customer not found.\n");
    }
}

void deposit(int accountNumber, double amount) {
    int index = findCustomer(accountNumber);
    if (index != -1) {
        if (amount <= 0) {
            printf("Deposit amount must be positive.\n");
            return;
        }
        
        customers[index].balance += amount;
        Transaction t;
        strcpy(t.date, "2023-10-01"); // Placeholder for date
        t.amount = amount;
        strcpy(t.type, "Deposit");
        customers[index].transactions[customers[index].transactionCount++] = t;

        printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, customers[index].accountNumber, customers[index].balance);
    } else {
        printf("Customer not found.\n");
    }
}

void withdraw(int accountNumber, double amount) {
    int index = findCustomer(accountNumber);
    if (index != -1) {
        if (amount <= 0) {
            printf("Withdrawal amount must be positive.\n");
            return;
        }
        if (amount > customers[index].balance) {
            printf("Insufficient funds.\n");
            return;
        }

        customers[index].balance -= amount;
        Transaction t;
        strcpy(t.date, "2023-10-01"); // Placeholder for date
        t.amount = amount;
        strcpy(t.type, "Withdraw");
        customers[index].transactions[customers[index].transactionCount++] = t;

        printf("Withdrawn %.2f from account number %d. New balance: %.2f\n", amount, customers[index].accountNumber, customers[index].balance);
    } else {
        printf("Customer not found.\n");
    }
}

void viewTransactionHistory(int accountNumber) {
    int index = findCustomer(accountNumber);
    if (index != -1) {
        printf("\n===== Transaction History for Account %d =====\n", accountNumber);
        for (int i = 0; i < customers[index].transactionCount; i++) {
            printf("%s: %.2f [%s]\n", customers[index].transactions[i].date, customers[index].transactions[i].amount, customers[index].transactions[i].type);
        }
    } else {
        printf("Customer not found.\n");
    }
}

int findCustomer(int accountNumber) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void listAllCustomers() {
    printf("\n===== List of All Customers =====\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
    }
}