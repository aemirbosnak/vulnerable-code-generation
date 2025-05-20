//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNT_NAME_LEN 20
#define MAX_ACCOUNT_NUMBER_LEN 10
#define MAX_BALANCE_LEN 8

struct Account {
    char name[MAX_ACCOUNT_NAME_LEN];
    char number[MAX_ACCOUNT_NUMBER_LEN];
    char balance[MAX_BALANCE_LEN];
};

struct Bank {
    struct Account accounts[100];
    int num_accounts;
};

void create_account(struct Bank* bank, char* name, char* number) {
    if (bank->num_accounts >= 100) {
        printf("Bank is full.\n");
        return;
    }

    char temp[MAX_ACCOUNT_NAME_LEN];
    strcpy(temp, name);
    strcpy(bank->accounts[bank->num_accounts].name, temp);
    strcpy(bank->accounts[bank->num_accounts].number, number);
    strcpy(bank->accounts[bank->num_accounts].balance, "0");

    bank->num_accounts++;
}

void deposit(struct Bank* bank, int account_number, int amount) {
    if (bank->num_accounts <= account_number || bank->accounts[account_number].balance[0] == '\0') {
        printf("Invalid account number or account doesn't exist.\n");
        return;
    }

    int balance_len = strlen(bank->accounts[account_number].balance);
    int new_balance = atoi(bank->accounts[account_number].balance) + amount;

    if (balance_len >= MAX_BALANCE_LEN || new_balance < 0) {
        printf("Invalid balance or insufficient funds.\n");
        return;
    }

    char balance_str[MAX_BALANCE_LEN];
    sprintf(balance_str, "%d", new_balance);
    strcpy(bank->accounts[account_number].balance, balance_str);
}

void withdraw(struct Bank* bank, int account_number, int amount) {
    if (bank->num_accounts <= account_number || bank->accounts[account_number].balance[0] == '\0') {
        printf("Invalid account number or account doesn't exist.\n");
        return;
    }

    int balance_len = strlen(bank->accounts[account_number].balance);
    int new_balance = atoi(bank->accounts[account_number].balance) - amount;

    if (balance_len >= MAX_BALANCE_LEN || new_balance < 0) {
        printf("Invalid balance or insufficient funds.\n");
        return;
    }

    char balance_str[MAX_BALANCE_LEN];
    sprintf(balance_str, "%d", new_balance);
    strcpy(bank->accounts[account_number].balance, balance_str);
}

void check_balance(struct Bank* bank, int account_number) {
    if (bank->num_accounts <= account_number || bank->accounts[account_number].balance[0] == '\0') {
        printf("Invalid account number or account doesn't exist.\n");
        return;
    }

    printf("Account balance: %.2f\n", atof(bank->accounts[account_number].balance));
}

int main() {
    struct Bank bank;
    bank.num_accounts = 0;

    char account_name[MAX_ACCOUNT_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    int amount;

    printf("Enter account name: ");
    scanf("%s", account_name);
    printf("Enter account number: ");
    scanf("%s", account_number);

    create_account(&bank, account_name, account_number);
    printf("Account created successfully.\n");

    while (1) {
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &amount);

        switch (amount) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                deposit(&bank, atoi(account_number), amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                withdraw(&bank, atoi(account_number), amount);
                break;
            case 3:
                check_balance(&bank, atoi(account_number));
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}