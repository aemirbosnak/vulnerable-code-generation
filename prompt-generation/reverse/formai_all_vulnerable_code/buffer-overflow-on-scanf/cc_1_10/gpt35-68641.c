//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

// Structure for each customer's record
struct customer {
    int account_number;
    char name[30];
    float balance;
};

// Array to store the records of all customers
struct customer customers[MAX_CUSTOMERS];

// Function to add a new customer record
void add_customer() {
    printf("Enter account number: ");
    scanf("%d", &customers[MAX_CUSTOMERS-1].account_number);
    printf("Enter name: ");
    scanf("%s", customers[MAX_CUSTOMERS-1].name);
    printf("Enter initial balance: ");
    scanf("%f", &customers[MAX_CUSTOMERS-1].balance);
}

// Function to search for a customer record based on account number
int search_customer(int account_number) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}

// Function to deposit amount to a customer's account
void deposit() {
    int account_number, index;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    index = search_customer(account_number);
    if (index != -1) {
        float amount;
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        customers[index].balance += amount;
        printf("Deposit successful.\n");
    } else {
        printf("Customer not found.\n");
    }
}

// Function to withdraw amount from a customer's account
void withdraw() {
    int account_number, index;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    index = search_customer(account_number);
    if (index != -1) {
        float amount;
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (customers[index].balance >= amount) {
            customers[index].balance -= amount;
            printf("Withdrawal successful.\n");
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Customer not found.\n");
    }
}

// Function to display details of a customer
void display_customer(int index) {
    printf("Account number: %d\n", customers[index].account_number);
    printf("Name: %s\n", customers[index].name);
    printf("Balance: %.2f\n", customers[index].balance);
}

// Function to display details of all customers
void display_all_customers() {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number != 0) {
            display_customer(i);
            printf("\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\nBanking Record System\n");
        printf("1. Add new customer\n");
        printf("2. Deposit amount\n");
        printf("3. Withdraw amount\n");
        printf("4. Display all customers\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display_all_customers();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}