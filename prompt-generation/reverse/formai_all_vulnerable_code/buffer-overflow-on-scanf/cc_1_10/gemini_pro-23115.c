//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_BALANCE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void print_account(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Address: %s\n", account->address);
    printf("Phone: %s\n", account->phone);
    printf("Balance: $%.2f\n\n", account->balance);
}

void create_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, the maximum number of accounts has been reached.\n");
        return;
    }

    Account *account = &accounts[num_accounts++];

    printf("Enter your name: ");
    scanf(" %s", account->name);

    printf("Enter your address: ");
    scanf(" %[^\n]s", account->address);

    printf("Enter your phone number: ");
    scanf(" %s", account->phone);

    account->balance = 0.0;

    printf("Account created successfully!\n");
}

void deposit() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf(" %d", &account_number);

    if (account_number < 0 || account_number >= num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    Account *account = &accounts[account_number];

    printf("Enter the amount you want to deposit: ");
    scanf(" %lf", &amount);

    if (amount <= 0.0) {
        printf("Invalid amount.\n");
        return;
    }

    account->balance += amount;

    printf("Deposit successful!\n");
}

void withdraw() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf(" %d", &account_number);

    if (account_number < 0 || account_number >= num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    Account *account = &accounts[account_number];

    printf("Enter the amount you want to withdraw: ");
    scanf(" %lf", &amount);

    if (amount <= 0.0 || amount > account->balance) {
        printf("Invalid amount.\n");
        return;
    }

    account->balance -= amount;

    printf("Withdraw successful!\n");
}

void transfer() {
    int from_account_number;
    int to_account_number;
    double amount;

    printf("Enter the account number from which you want to transfer money: ");
    scanf(" %d", &from_account_number);

    if (from_account_number < 0 || from_account_number >= num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    Account *from_account = &accounts[from_account_number];

    printf("Enter the account number to which you want to transfer money: ");
    scanf(" %d", &to_account_number);

    if (to_account_number < 0 || to_account_number >= num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    Account *to_account = &accounts[to_account_number];

    printf("Enter the amount you want to transfer: ");
    scanf(" %lf", &amount);

    if (amount <= 0.0 || amount > from_account->balance) {
        printf("Invalid amount.\n");
        return;
    }

    from_account->balance -= amount;
    to_account->balance += amount;

    printf("Transfer successful!\n");
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        print_account(&accounts[i]);
    }
}

void delete_account() {
    int account_number;

    printf("Enter your account number: ");
    scanf(" %d", &account_number);

    if (account_number < 0 || account_number >= num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    for (int i = account_number + 1; i < num_accounts; i++) {
        accounts[i - 1] = accounts[i];
    }

    num_accounts--;

    printf("Account deleted successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n---------------------------------------------------------\n");
        printf("    Welcome to the Banking Record System!\n");
        printf("---------------------------------------------------------\n");
        printf("    1. Create an account\n");
        printf("    2. Deposit money\n");
        printf("    3. Withdraw money\n");
        printf("    4. Transfer money\n");
        printf("    5. Print all accounts\n");
        printf("    6. Delete an account\n");
        printf("    0. Exit\n");
        printf("---------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                print_accounts();
                break;
            case 6:
                delete_account();
                break;
            case 0:
                printf("Thank you for using the Banking Record System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}