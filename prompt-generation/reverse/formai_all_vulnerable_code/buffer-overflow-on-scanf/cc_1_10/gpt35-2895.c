//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct bank_account {
    char account_number[50];
    char customer_name[50];
    float balance;
    char password[50];
    int counter;
};

struct bank_account accounts[MAX_ACCOUNTS];

int num_accounts = 0;

void display_menu() {
    printf("Welcome to the Paranoid Banking Record System!\n");
    printf("---------------------------------------------\n");
    printf("1. Create a New Account\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Funds\n");
    printf("4. View Account Information\n");
    printf("5. Exit\n");
}

int get_account_index(char* account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            return i;
        }
    }
    return -1;
}

void create_account() {
    printf("Enter Account Number: ");
    char account_number[50];
    scanf("%s", account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Error: Account number already exists.\n");
            return;
        }
    }

    printf("Enter Customer Name: ");
    char customer_name[50];
    scanf("%s", customer_name);

    printf("Enter Password: ");
    char password[50];
    scanf("%s", password);

    printf("Enter Starting Balance: $");
    float balance;
    scanf("%f", &balance);

    struct bank_account new_account = {
        .balance = balance,
        .counter = 0
    };
    strcpy(new_account.account_number, account_number);
    strcpy(new_account.customer_name, customer_name);
    strcpy(new_account.password, password);

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account created successfully.\n");
}

void deposit_funds() {
    printf("Enter Account Number: ");
    char account_number[50];
    scanf("%s", account_number);

    int account_index = get_account_index(account_number);
    if (account_index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Password: ");
    char password[50];
    scanf("%s", password);

    if (strcmp(accounts[account_index].password, password) != 0) {
        printf("Error: Password incorrect.\n");
        return;
    }

    printf("Enter Deposit Amount: $");
    float deposit_amount;
    scanf("%f", &deposit_amount);

    if (deposit_amount < 0) {
        printf("Error: Cannot deposit negative amount.\n");
        return;
    }

    accounts[account_index].balance += deposit_amount;
    accounts[account_index].counter++;

    printf("Deposit of $%.2f successful. New balance: $%.2f.\n",
           deposit_amount, accounts[account_index].balance);
}

void withdraw_funds() {
    printf("Enter Account Number: ");
    char account_number[50];
    scanf("%s", account_number);

    int account_index = get_account_index(account_number);
    if (account_index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Password: ");
    char password[50];
    scanf("%s", password);

    if (strcmp(accounts[account_index].password, password) != 0) {
        printf("Error: Password incorrect.\n");
        return;
    }

    printf("Enter Withdrawal Amount: $");
    float withdrawal_amount;
    scanf("%f", &withdrawal_amount);

    if (withdrawal_amount < 0) {
        printf("Error: Cannot withdraw negative amount.\n");
        return;
    }

    if (withdrawal_amount > accounts[account_index].balance) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    accounts[account_index].balance -= withdrawal_amount;
    accounts[account_index].counter++;

    printf("Withdrawal of $%.2f successful. New balance: $%.2f.\n",
           withdrawal_amount, accounts[account_index].balance);
}

void view_information() {
    printf("Enter Account Number: ");
    char account_number[50];
    scanf("%s", account_number);

    int account_index = get_account_index(account_number);
    if (account_index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Password: ");
    char password[50];
    scanf("%s", password);

    if (strcmp(accounts[account_index].password, password) != 0) {
        printf("Error: Password incorrect.\n");
        return;
    }

    printf("Account Number: %s\n", accounts[account_index].account_number);
    printf("Customer Name: %s\n", accounts[account_index].customer_name);
    printf("Current Balance: $%.2f\n", accounts[account_index].balance);
    printf("Transaction Counter: %d\n", accounts[account_index].counter);
}

int main() {
    int choice;

    while (1) {
        display_menu();

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_account();
            break;
        case 2:
            deposit_funds();
            break;
        case 3:
            withdraw_funds();
            break;
        case 4:
            view_information();
            break;
        case 5:
            printf("Exiting the Paranoid Banking System...\n");
            exit(0);
        default:
            printf("Error: Invalid Choice.\n");
            break;
        }
    }

    return 0;
}