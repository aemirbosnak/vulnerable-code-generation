//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

// Function to create a new account
void create_account(Account* account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    printf("Your account has been created with balance $0.\n");
}

// Function to deposit money into an account
void deposit_money(Account* account, float amount) {
    account->balance += amount;
    printf("You have successfully deposited $%.2f into your account.\n", amount);
    printf("Your new balance is $%.2f.\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(Account* account, float amount) {
    if(amount > account->balance) {
        printf("Insufficient funds. Please enter a lower amount.\n");
    } else {
        account->balance -= amount;
        printf("You have successfully withdrawn $%.2f from your account.\n", amount);
        printf("Your new balance is $%.2f.\n", account->balance);
    }
}

// Function to check the balance of an account
void check_balance(Account* account) {
    printf("Your current balance is $%.2f.\n", account->balance);
}

// Main function
int main() {
    Account my_account;
    int choice;

    // Create a new account
    create_account(&my_account);

    // Loop until the user chooses to exit
    do {
        printf("\nWelcome to the Bank of Cheerful Programming!\n");
        printf("What would you like to do?\n");
        printf("1. Deposit money\n");
        printf("2. Withdraw money\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the amount you would like to deposit: ");
                scanf("%f", &my_account.balance);
                deposit_money(&my_account, my_account.balance);
                break;
            case 2:
                printf("Enter the amount you would like to withdraw: ");
                scanf("%f", &my_account.balance);
                withdraw_money(&my_account, my_account.balance);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                printf("Thank you for using the Bank of Cheerful Programming! Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}