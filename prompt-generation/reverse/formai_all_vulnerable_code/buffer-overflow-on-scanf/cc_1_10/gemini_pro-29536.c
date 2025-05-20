//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of customers and accounts
#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 10

// Define the data structures for customer and account
struct customer {
    char name[50];
    int age;
    char address[100];
    int num_accounts;
    int account_ids[MAX_ACCOUNTS];
};

struct account {
    int account_id;
    double balance;
    char type[50];
};

// Define the global variables
struct customer customers[MAX_CUSTOMERS];
struct account accounts[MAX_ACCOUNTS];
int num_customers = 0;
int num_accounts = 0;

// Function to create a new customer
void create_customer() {
    // Get the customer details from the user
    printf("Enter the customer name: ");
    scanf("%s", customers[num_customers].name);

    printf("Enter the customer age: ");
    scanf("%d", &customers[num_customers].age);

    printf("Enter the customer address: ");
    scanf("%s", customers[num_customers].address);

    // Initialize the number of accounts to 0
    customers[num_customers].num_accounts = 0;

    // Increment the number of customers
    num_customers++;
}

// Function to create a new account
void create_account() {
    // Get the account details from the user
    printf("Enter the account type: ");
    scanf("%s", accounts[num_accounts].type);

    printf("Enter the account balance: ");
    scanf("%lf", &accounts[num_accounts].balance);

    // Assign a unique account ID
    accounts[num_accounts].account_id = num_accounts + 1;

    // Increment the number of accounts
    num_accounts++;
}

// Function to deposit money into an account
void deposit_money() {
    // Get the account ID and the amount to be deposited
    int account_id;
    double amount;

    printf("Enter the account ID: ");
    scanf("%d", &account_id);

    printf("Enter the amount to be deposited: ");
    scanf("%lf", &amount);

    // Find the account with the given account ID
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_id == account_id) {
            account_index = i;
            break;
        }
    }

    // Check if the account was found
    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    // Deposit the money into the account
    accounts[account_index].balance += amount;

    printf("Money deposited successfully.\n");
}

// Function to withdraw money from an account
void withdraw_money() {
    // Get the account ID and the amount to be withdrawn
    int account_id;
    double amount;

    printf("Enter the account ID: ");
    scanf("%d", &account_id);

    printf("Enter the amount to be withdrawn: ");
    scanf("%lf", &amount);

    // Find the account with the given account ID
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_id == account_id) {
            account_index = i;
            break;
        }
    }

    // Check if the account was found
    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    // Check if the account has sufficient balance
    if (accounts[account_index].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }

    // Withdraw the money from the account
    accounts[account_index].balance -= amount;

    printf("Money withdrawn successfully.\n");
}

// Function to print the details of a customer
void print_customer_details(int customer_index) {
    // Print the customer details
    printf("Name: %s\n", customers[customer_index].name);
    printf("Age: %d\n", customers[customer_index].age);
    printf("Address: %s\n", customers[customer_index].address);

    // Print the account details
    printf("Accounts: \n");
    for (int i = 0; i < customers[customer_index].num_accounts; i++) {
        int account_id = customers[customer_index].account_ids[i];
        int account_index = -1;
        for (int j = 0; j < num_accounts; j++) {
            if (accounts[j].account_id == account_id) {
                account_index = j;
                break;
            }
        }

        if (account_index != -1) {
            printf("  - Account ID: %d\n", accounts[account_index].account_id);
            printf("    - Type: %s\n", accounts[account_index].type);
            printf("    - Balance: %.2f\n", accounts[account_index].balance);
        }
    }
}

// Function to print the details of all customers
void print_all_customers() {
    // Print the details of each customer
    for (int i = 0; i < num_customers; i++) {
        print_customer_details(i);
        printf("\n");
    }
}

// Main function
int main() {
    // Create some sample customers and accounts
    create_customer();
    create_customer();
    create_account();
    create_account();

    // Print the details of all customers
    print_all_customers();

    return 0;
}