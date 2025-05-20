//FormAI DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the data structure to store account information
struct account {
    int account_number;
    char name[50];
    float balance;
};

// Function to create a new account
void create_account(struct account* acc) {
    printf("Enter account number: ");
    scanf("%d", &(acc->account_number));
    printf("Enter account holder name: ");
    scanf("%s", acc->name);
    acc->balance = 0;
    printf("Account created successfully.\n");
}

// Function to deposit money into an account
void deposit(struct account* acc, float amount) {
    acc->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct account* acc, float amount) {
    if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        acc->balance -= amount;
    }
}

// Function to view account details and balance
void view_account(struct account* acc) {
    printf("Account number: %d\n", acc->account_number);
    printf("Account holder name: %s\n", acc->name);
    printf("Account balance: %.2f\n", acc->balance);
}

// The main function to test the different functionalities of the program
int main() {
    struct account acc;
    int choice;
    float amount;

    // Menu loop
    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. View account details\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account(&acc);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;
            case 4:
                view_account(&acc);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}