//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char account_holder[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1; // Simple auto-increment account number
    printf("Enter Account Holder Name: ");
    getchar(); // to consume newline
    fgets(new_account.account_holder, NAME_LENGTH, stdin);
    new_account.account_holder[strcspn(new_account.account_holder, "\n")] = '\0'; // Remove newline
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully! Your Account Number is %d.\n", new_account.account_number);
}

void view_balance() {
    int account_number;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > account_count) {
        printf("Account not found.\n");
        return;
    }

    Account acc = accounts[account_number - 1];
    printf("Account Holder: %s\nAccount Number: %d\nBalance: %.2f\n", acc.account_holder, acc.account_number, acc.balance);
}

void deposit() {
    int account_number;
    double amount;

    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    printf("Enter Deposit Amount: ");
    scanf("%lf", &amount);

    if (account_number < 1 || account_number > account_count) {
        printf("Account not found.\n");
        return;
    }

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited %.2f to Account Number %d.\n", amount, account_number);
}

void withdraw() {
    int account_number;
    double amount;

    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    printf("Enter Withdraw Amount: ");
    scanf("%lf", &amount);

    if (account_number < 1 || account_number > account_count) {
        printf("Account not found.\n");
        return;
    }

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f from Account Number %d.\n", amount, account_number);
}

void display_accounts() {
    printf("List of Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d, Account Holder: %s, Balance: %.2f\n",
               accounts[i].account_number, accounts[i].account_holder, accounts[i].balance);
    }
}

void show_menu() {
    printf("\n---- Banking System ----\n");
    printf("1. Create Account\n");
    printf("2. View Balance\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
    printf("------------------------\n");
}

int main() {
    int choice;

    do {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_balance();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}