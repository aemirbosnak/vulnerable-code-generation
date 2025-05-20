//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 1000

struct customer {
    char name[50];
    char account_number[20];
    double balance;
    struct tm last_transaction_date;
    int active;
};

struct customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer() {
    struct customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter account number: ");
    scanf("%s", new_customer.account_number);
    printf("Enter initial balance: ");
    scanf("%lf", &new_customer.balance);
    new_customer.active = 1;
    time_t current_time = time(NULL);
    new_customer.last_transaction_date = *localtime(&current_time);
    customers[num_customers++] = new_customer;
    printf("Customer added successfully!\n");
}

void print_customer(struct customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Account number: %s\n", customer.account_number);
    printf("Balance: $%.2lf\n", customer.balance);
    printf("Last transaction date: %02d/%02d/%d\n", customer.last_transaction_date.tm_mday, customer.last_transaction_date.tm_mon + 1, customer.last_transaction_date.tm_year + 1900);
    printf("%s\n", customer.active ? "Active" : "Inactive");
}

void print_customers() {
    printf("\n*** BANKING RECORDS ***\n\n");
    for (int i = 0; i < num_customers; i++) {
        printf("CUSTOMER #%d\n", i + 1);
        print_customer(customers[i]);
        printf("\n");
    }
}

int find_customer(char *account_number) {
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].account_number, account_number) == 0) {
            return i;
        }
    }
    return -1;
}

void deposit() {
    char account_number[20];
    printf("Enter account number: ");
    scanf("%s", account_number);
    int index = find_customer(account_number);
    if (index == -1) {
        printf("Customer not found!\n");
        return;
    }
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    customers[index].balance += amount;
    time_t current_time = time(NULL);
    customers[index].last_transaction_date = *localtime(&current_time);
    printf("Deposit successful!\n");
}

void withdraw() {
    char account_number[20];
    printf("Enter account number: ");
    scanf("%s", account_number);
    int index = find_customer(account_number);
    if (index == -1) {
        printf("Customer not found!\n");
        return;
    }
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount > customers[index].balance) {
        printf("Insufficient balance!\n");
        return;
    }
    customers[index].balance -= amount;
    time_t current_time = time(NULL);
    customers[index].last_transaction_date = *localtime(&current_time);
    printf("Withdrawal successful!\n");
}

void toggle_active() {
    char account_number[20];
    printf("Enter account number: ");
    scanf("%s", account_number);
    int index = find_customer(account_number);
    if (index == -1) {
        printf("Customer not found!\n");
        return;
    }
    customers[index].active = !customers[index].active;
    printf("Customer status updated successfully!\n");
}

int main() {
    int choice;
    do {
        printf("=====================\n");
        printf("BANKING RECORDS SYSTEM\n");
        printf("=====================\n");
        printf("1 - Add customer\n");
        printf("2 - View all customers\n");
        printf("3 - Deposit\n");
        printf("4 - Withdraw\n");
        printf("5 - Toggle customer status\n");
        printf("0 - Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                print_customers();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                toggle_active();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);
    return 0;
}