//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure for bank account
struct Account {
    int account_number;
    char account_holder_name[50];
    char account_type[20];
    float balance;
};

// Function to create a new account
void create_account(struct Account *account) {
    printf("Enter account holder name: ");
    scanf("%s", account->account_holder_name);

    printf("Enter account type (Savings/Current): ");
    scanf("%s", account->account_type);

    printf("Enter initial balance: ");
    scanf("%f", &account->balance);

    account->account_number = rand() % 100000; // Generate random account number
    printf("Your account number is %d\n", account->account_number);
}

// Function to deposit money into an account
void deposit_money(struct Account *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(struct Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: %.2f\n", account->balance);
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check account balance
void check_balance(struct Account *account) {
    printf("Current balance: %.2f\n", account->balance);
}

// Function to close an account
void close_account(struct Account *account) {
    printf("Account closed successfully\n");
}

// Main function
int main() {
    struct Account my_account;

    int choice, search_account_number;
    float amount;

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Close Account\n");
        printf("6. Search Account\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&my_account);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit_money(&my_account, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw_money(&my_account, amount);
                break;
            case 4:
                check_balance(&my_account);
                break;
            case 5:
                close_account(&my_account);
                break;
            case 6:
                printf("Enter account number to search: ");
                scanf("%d", &search_account_number);

                if (search_account_number == my_account.account_number) {
                    printf("Account found\n");
                } else {
                    printf("Account not found\n");
                }
                break;
            case 7:
                printf("Thank you for using our banking system\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 7);

    return 0;
}