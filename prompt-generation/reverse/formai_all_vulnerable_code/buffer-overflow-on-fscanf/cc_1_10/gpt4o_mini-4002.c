//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_FILE "accounts.txt"
#define MAX_NAME_LENGTH 50
#define INITIAL_BALANCE 1000.0

typedef struct {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void load_accounts() {
    FILE *file = fopen(ACCOUNT_FILE, "r");
    if (file == NULL) {
        printf("No previous account data found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %d %lf", accounts[account_count].name,
                  &accounts[account_count].account_number,
                  &accounts[account_count].balance) != EOF) {
        account_count++;
    }
    fclose(file);
}

void save_accounts() {
    FILE *file = fopen(ACCOUNT_FILE, "w");
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %d %.2f\n", accounts[i].name,
                accounts[i].account_number,
                accounts[i].balance);
    }
    fclose(file);
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1;
    new_account.balance = INITIAL_BALANCE;

    printf("Enter your name: ");
    scanf("%s", new_account.name);

    accounts[account_count] = new_account;
    account_count++;
    save_accounts();
    printf("Account created! Your account number is %d\n", new_account.account_number);
}

void deposit_money() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    accounts[account_number - 1].balance += amount;
    save_accounts();
    printf("Amount deposited successfully. New balance is: %.2f\n", accounts[account_number - 1].balance);
}

void withdraw_money() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    save_accounts();
    printf("Amount withdrawn successfully. New balance is: %.2f\n", accounts[account_number - 1].balance);
}

void display_account_details() {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    Account account = accounts[account_number - 1];
    printf("Account Number: %d\n", account.account_number);
    printf("Account Holder Name: %s\n", account.name);
    printf("Account Balance: %.2f\n", account.balance);
}

void display_menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    load_accounts();
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit_money(); break;
            case 3: withdraw_money(); break;
            case 4: display_account_details(); break;
            case 5: printf("Exiting the system.\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}