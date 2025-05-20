//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000
#define MAX_NAME_LENGTH 30
#define MAX_ACCOUNT_NUM_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char account_num[MAX_ACCOUNT_NUM_LENGTH];
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;


void add_customer() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }
    Customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter account number: ");
    scanf("%s", new_customer.account_num);
    printf("Enter initial balance: ");
    scanf("%lf", &new_customer.balance);
    customers[num_customers] = new_customer;
    num_customers++;
    printf("New customer added successfully!\n");
}


void display_customers() {
    printf("Customers:\n");
    printf("%-30s%-20s%-10s\n", "Name", "Account Number", "Balance");
    for (int i = 0; i < num_customers; i++) {
        printf("%-30s%-20s$%-9.2lf\n",
               customers[i].name,
               customers[i].account_num,
               customers[i].balance);
    }
}


void deposit() {
    char account_num[MAX_ACCOUNT_NUM_LENGTH];
    double amount;
    int found = 0;
    printf("Enter account number: ");
    scanf("%s", account_num);
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_num, account_num) == 0) {
            found = 1;
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            customers[i].balance += amount;
            printf("New balance: $%.2lf\n", customers[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Error: Account not found.\n");
    }
}


void withdraw() {
    char account_num[MAX_ACCOUNT_NUM_LENGTH];
    double amount;
    int found = 0;
    printf("Enter account number: ");
    scanf("%s", account_num);
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_num, account_num) == 0) {
            found = 1;
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (customers[i].balance < amount) {
                printf("Error: Insufficient funds.\n");
                break;
            } else {
                customers[i].balance -= amount;
                printf("New balance: $%.2lf\n", customers[i].balance);
                break;
            }
        }
    }
    if (!found) {
        printf("Error: Account not found.\n");
    }
}


int main() {
    int choice = 0;
    do {
        printf("\nBanking Record System\n");
        printf("1. Add Customer\n");
        printf("2. Display Customers\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                display_customers();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}