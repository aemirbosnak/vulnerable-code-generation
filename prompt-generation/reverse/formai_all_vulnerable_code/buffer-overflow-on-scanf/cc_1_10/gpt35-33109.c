//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// struct to hold account details
struct Account {
    int account_number;
    float balance;
    char account_holder[50];
};

// global variables to hold account data
struct Account accounts[100];
int num_accounts = 0;

// function to create a new account
void create_account() {
    struct Account account;
    printf("Enter account holder name: ");
    scanf("%s", account.account_holder);
    printf("Enter account number: ");
    scanf("%d", &account.account_number);
    printf("Enter initial balance: ");
    scanf("%f", &account.balance);
    accounts[num_accounts] = account;
    num_accounts++;
    printf("Account created successfully!\n");
}

// function to check account balance
void check_balance() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account holder name: %s\n", accounts[i].account_holder);
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// function to deposit money into an account
void deposit_money() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            printf("New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// function to withdraw money from an account
void withdraw_money() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
                printf("New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Create account\n");
        printf("2. Check balance\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                check_balance();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while(1);
    return 0;
}