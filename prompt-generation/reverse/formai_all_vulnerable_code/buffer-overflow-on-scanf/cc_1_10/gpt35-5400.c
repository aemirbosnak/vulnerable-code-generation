//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#define MAX_CUSTOMERS 100 // Maximum number of customers that can be stored

struct customer {
    char name[50];
    int account_number;
    float balance;
} customers[MAX_CUSTOMERS];

int current_customer_count = 0; // Total number of customers stored in the bank record system

// Function to add a new customer to the database
void add_customer() {
    if (current_customer_count >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached!\n");
        return;
    }
    struct customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    printf("Enter initial balance: ");
    scanf("%f", &new_customer.balance);
    customers[current_customer_count++] = new_customer;
    printf("Customer added successfully!\n");
}

// Function to display all customers in the database
void display_customers() {
    if (current_customer_count == 0) {
        printf("No customers found!\n");
        return;
    }
    printf("Name\t\tAccount No.\tBalance\n");
    for (int i = 0; i < current_customer_count; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
    }
}

// Function to deposit funds to a customer's account
void deposit() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < current_customer_count; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("$%.2f deposited to %s's account (Account No. %d)\n", amount, customers[i].name, customers[i].account_number);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw funds from a customer's account
void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < current_customer_count; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (customers[i].balance < amount) {
                printf("Insufficient balance!\n");
                return;
            }
            customers[i].balance -= amount;
            printf("$%.2f withdrawn from %s's account (Account No. %d)\n", amount, customers[i].name, customers[i].account_number);
            return;
        }
    }
    printf("Account not found!\n");
}

// Main function
int main() {
    int choice;
    while(1) {
        printf("\nWelcome to Bank Record System\n");
        printf("1. Add new customer\n");
        printf("2. Display all customers\n");
        printf("3. Deposit funds\n");
        printf("4. Withdraw funds\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Thank you for using Bank Record System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}