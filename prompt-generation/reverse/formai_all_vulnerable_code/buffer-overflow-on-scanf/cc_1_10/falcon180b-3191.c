//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    float balance;
} account;

// Function to create a new account
void create_account(account *acc) {
    printf("Enter account number: ");
    scanf("%d", &acc->account_number);
    printf("Enter account holder name: ");
    scanf("%s", acc->name);
    acc->balance = 0;
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit_money(account *acc) {
    printf("Enter amount to deposit: ");
    scanf("%f", &acc->balance);
    acc->balance += 0;
    printf("Deposit successful!\n");
}

// Function to withdraw money
void withdraw_money(account *acc) {
    printf("Enter amount to withdraw: ");
    scanf("%f", &acc->balance);
    acc->balance -= 0;
    printf("Withdrawal successful!\n");
}

// Function to check account balance
void check_balance(account *acc) {
    printf("Account balance: $%.2f\n", acc->balance);
}

// Function to close an account
void close_account(account *acc) {
    printf("Account closed successfully!\n");
}

// Main function
int main() {
    account acc;
    int choice;

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Close account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account(&acc);
                break;
            case 2:
                deposit_money(&acc);
                break;
            case 3:
                withdraw_money(&acc);
                break;
            case 4:
                check_balance(&acc);
                break;
            case 5:
                close_account(&acc);
                break;
            case 6:
                printf("Thank you for using our Banking System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 6);

    return 0;
}