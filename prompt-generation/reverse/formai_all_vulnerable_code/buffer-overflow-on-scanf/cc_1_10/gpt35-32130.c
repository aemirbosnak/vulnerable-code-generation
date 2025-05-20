//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for customer and account information
typedef struct {
    int id;
    char name[30];
    char address[100];
    char phone[15];
} Customer;

typedef struct {
    int acc_num;
    Customer customer;
    double balance;
    int open_year;
} Account;

// Define function prototypes
void add_customer();
void add_account();
void deposit();
void withdraw();
void display_customers();
void display_account_info();

// Global variables
Customer customers[100];
Account accounts[100];
int num_of_customers = 0;
int num_of_accounts = 0;

int main() {
    int choice;
    
    // Loop until user chooses to exit
    while (1) {
        printf("\nWelcome to the Banking Record System");
        printf("\nChoose an option:");
        printf("\n1. Add new customer");
        printf("\n2. Add new account");
        printf("\n3. Deposit money");
        printf("\n4. Withdraw money");
        printf("\n5. Display all customers");
        printf("\n6. Display account information");
        printf("\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                display_customers();
                break;
            case 6:
                display_account_info();
                break;
            case 7:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
}

void add_customer() {
    Customer new_customer;
    
    printf("\nEnter customer ID: ");
    scanf("%d", &new_customer.id);
    printf("Enter customer name: ");
    scanf("%s", &new_customer.name);
    printf("Enter customer address: ");
    scanf("%s", &new_customer.address);
    printf("Enter customer phone number: ");
    scanf("%s", &new_customer.phone);
    
    customers[num_of_customers++] = new_customer;
    
    printf("\nCustomer added successfully.");
}

void add_account() {
    Account new_account;
    int customer_id;
    int i;
    
    printf("\nEnter account number: ");
    scanf("%d", &new_account.acc_num);
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    
    // Find customer in array
    for (i = 0; i < num_of_customers; i++) {
        if (customers[i].id == customer_id) {
            new_account.customer = customers[i];
            printf("Customer found.\n");
            break;
        }
    }
    
    if (i == num_of_customers) {
        printf("Customer not found. Account not added.");
        return;
    }
    
    printf("Enter initial balance: ");
    scanf("%lf", &new_account.balance);
    printf("Enter year account was opened: ");
    scanf("%d", &new_account.open_year);
    
    accounts[num_of_accounts++] = new_account;
    
    printf("\nAccount added successfully.");
}

void deposit() {
    int acc_num;
    double amount;
    int i;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc_num);
    
    // Find account in array
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].acc_num == acc_num) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("\nDeposit successful.");
            break;
        }
    }
    
    if (i == num_of_accounts) {
        printf("\nAccount not found.");
    }
}

void withdraw() {
    int acc_num;
    double amount;
    int i;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc_num);
    
    // Find account in array
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].acc_num == acc_num) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("\nInsufficient balance.");
            } else {
                accounts[i].balance -= amount;
                printf("\nWithdrawal successful.");
            }
            break;
        }
    }
    
    if (i == num_of_accounts) {
        printf("\nAccount not found.");
    }
}

void display_customers() {
    int i;
    
    printf("\nCustomer List:\n");
    
    for (i = 0; i < num_of_customers; i++) {
        printf("\n%d\t%s\t%s\t%s", customers[i].id, customers[i].name, 
        customers[i].address, customers[i].phone);
    }
}

void display_account_info() {
    int acc_num;
    int i;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc_num);
    
    // Find account in array
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].acc_num == acc_num) {
            printf("\nAccount Information:\n");
            printf("Account number: %d\n", accounts[i].acc_num);
            printf("Customer ID: %d\n", accounts[i].customer.id);
            printf("Customer name: %s\n", accounts[i].customer.name);
            printf("Account balance: $%.2f\n", accounts[i].balance);
            printf("Account open year: %d\n", accounts[i].open_year);
            break;
        }
    }
    
    if (i == num_of_accounts) {
        printf("\nAccount not found.");
    }
}