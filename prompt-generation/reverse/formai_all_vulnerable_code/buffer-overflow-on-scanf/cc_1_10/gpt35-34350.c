//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

/* Struct for bank account */
typedef struct {
    int account_number;
    char account_name[50];
    float balance;
} Account;

/* Struct for each transaction */
typedef struct {
    int account_number;
    char type[10];
    float amount;
} Transaction;

/* Initializing the arrays to store accounts and transactions */
Account accounts_array[MAX_ACCOUNTS];
Transaction transactions_array[MAX_TRANSACTIONS];

/* Function to display the main menu */
void display_menu() {
    printf("MAIN MENU\n");
    printf("1. Add Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. View Transactions\n");
    printf("6. Exit\n");
}

/* Function to check if an account exists */
int account_exists(int acc_num) {
    int i;

    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts_array[i].account_number == acc_num) {
            return 1;
        }
    }

    return 0;
}

/* Function to add an account */
void add_account() {
    int acc_num, i;

    /* Prompt for account number */
    printf("Enter account number:\n");
    scanf("%d", &acc_num);

    /* Check if account already exists */
    if (account_exists(acc_num)) {
        printf("Account already exists!\n");
        return;
    }

    /* Find the first empty slot */
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts_array[i].account_number == 0) {
            accounts_array[i].account_number = acc_num;

            /* Prompt for account name and balance */
            printf("Enter account name:\n");
            scanf("%s", accounts_array[i].account_name);

            printf("Enter opening balance:\n");
            scanf("%f", &accounts_array[i].balance);

            printf("Account added successfully!\n");
            return;
        }
    }

    /* No empty slot found */
    printf("Cannot add more accounts!\n");
}

/* Function to view an account */
void view_account() {
    int acc_num, i;

    /* Prompt for account number */
    printf("Enter account number:\n");
    scanf("%d", &acc_num);

    /* Check if account exists */
    if (!account_exists(acc_num)) {
        printf("Account does not exist!\n");
        return;
    }

    /* Find the account */
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts_array[i].account_number == acc_num) {
            /* Print account details */
            printf("Account Number: %d\n", accounts_array[i].account_number);
            printf("Account Holder Name: %s\n", accounts_array[i].account_name);
            printf("Account Balance: %.2f\n", accounts_array[i].balance);

            return;
        }
    }
}

/* Function to deposit money */
void deposit_money() {
    int acc_num, i;

    /* Prompt for account number */
    printf("Enter account number:\n");
    scanf("%d", &acc_num);

    /* Check if account exists */
    if (!account_exists(acc_num)) {
        printf("Account does not exist!\n");
        return;
    }

    /* Find the account */
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts_array[i].account_number == acc_num) {
            /* Prompt for deposit amount */
            float amount;
            printf("Enter deposit amount:\n");
            scanf("%f", &amount);

            /* Update account balance */
            accounts_array[i].balance += amount;

            /* Add transaction */
            transactions_array[i].account_number = acc_num;
            strcpy(transactions_array[i].type, "Deposit");
            transactions_array[i].amount = amount;

            printf("Deposit successful!\n");

            return;
        }
    }
}

/* Function to withdraw money */
void withdraw_money() {
    int acc_num, i;

    /* Prompt for account number */
    printf("Enter account number:\n");
    scanf("%d", &acc_num);

    /* Check if account exists */
    if (!account_exists(acc_num)) {
        printf("Account does not exist!\n");
        return;
    }

    /* Find the account */
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts_array[i].account_number == acc_num) {
            /* Prompt for withdrawal amount */
            float amount;
            printf("Enter withdrawal amount:\n");
            scanf("%f", &amount);

            /* Check if withdrawal amount is valid */
            if (amount > accounts_array[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }

            /* Update account balance */
            accounts_array[i].balance -= amount;

            /* Add transaction */
            transactions_array[i].account_number = acc_num;
            strcpy(transactions_array[i].type, "Withdrawal");
            transactions_array[i].amount = amount;

            printf("Withdrawal successful!\n");

            return;
        }
    }
}

/* Function to view transactions */
void view_transactions() {
    int acc_num, i;

    /* Prompt for account number */
    printf("Enter account number:\n");
    scanf("%d", &acc_num);

    /* Check if account exists */
    if (!account_exists(acc_num)) {
        printf("Account does not exist!\n");
        return;
    }

    printf("TRANSACTION HISTORY\n");
    printf("------------------------------------------------\n");
    printf("Account Number\tTransaction Type\tTransaction Amount\n");
    printf("------------------------------------------------\n");

    /* Find the account */
    for (i = 0; i < MAX_TRANSACTIONS; i++) {
        if (transactions_array[i].account_number == acc_num) {
            /* Print transaction details */
            printf("%d\t\t%s\t\t%.2f\n", transactions_array[i].account_number, transactions_array[i].type, transactions_array[i].amount);
        }
    }

    printf("------------------------------------------------\n");
}

/* Main function */
int main() {
    int choice;

    /* Initialize accounts and transactions array */
    memset(accounts_array, 0, sizeof(accounts_array));
    memset(transactions_array, 0, sizeof(transactions_array));

    /* Display menu and prompt for choice */
    do {
        display_menu();
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                view_transactions();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}