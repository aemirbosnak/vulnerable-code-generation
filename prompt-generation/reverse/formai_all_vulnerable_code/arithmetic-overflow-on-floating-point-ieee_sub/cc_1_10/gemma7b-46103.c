//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct customer {
    char name[20];
    int account_no;
    double balance;
} customer;

customer customers[MAX_CUSTOMERS];

void create_customer(int customer_id) {
    printf("Enter customer name: ");
    scanf("%s", customers[customer_id].name);

    printf("Enter account number: ");
    scanf("%d", &customers[customer_id].account_no);

    printf("Enter initial balance: ");
    scanf("%lf", &customers[customer_id].balance);
}

void deposit(int customer_id) {
    double deposit_amount;

    printf("Enter deposit amount: ");
    scanf("%lf", &deposit_amount);

    customers[customer_id].balance += deposit_amount;
    printf("Deposit successful!\n");
}

void withdraw(int customer_id) {
    double withdrawal_amount;

    printf("Enter withdrawal amount: ");
    scanf("%lf", &withdrawal_amount);

    if (withdrawal_amount <= customers[customer_id].balance) {
        customers[customer_id].balance -= withdrawal_amount;
        printf("Withdrawal successful!\n");
    } else {
        printf("Insufficient funds.\n");
    }
}

void view_account(int customer_id) {
    printf("Customer name: %s\n", customers[customer_id].name);
    printf("Account number: %d\n", customers[customer_id].account_no);
    printf("Balance: %.2lf\n", customers[customer_id].balance);
}

int main() {
    int customer_id;

    // Create a customer
    create_customer(0);

    // Deposit money
    deposit(0);

    // Withdraw money
    withdraw(0);

    // View account balance
    view_account(0);

    return 0;
}