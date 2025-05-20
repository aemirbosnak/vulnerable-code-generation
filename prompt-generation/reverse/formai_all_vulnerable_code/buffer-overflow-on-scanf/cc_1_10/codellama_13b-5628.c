//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: energetic
// Banking Record System

#include <stdio.h>
#include <string.h>

// Define structure for bank accounts
struct bank_account {
    char name[50];
    int account_number;
    float balance;
};

// Function to add a new account
void add_account(struct bank_account *accounts, int *num_accounts) {
    printf("Enter name: ");
    scanf("%s", accounts[*num_accounts].name);
    printf("Enter account number: ");
    scanf("%d", &accounts[*num_accounts].account_number);
    printf("Enter balance: ");
    scanf("%f", &accounts[*num_accounts].balance);
    *num_accounts += 1;
}

// Function to display all accounts
void display_accounts(struct bank_account *accounts, int num_accounts) {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s - %d - $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }
}

// Function to deposit money into an account
void deposit(struct bank_account *accounts, int num_accounts) {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            float amount;
            scanf("%f", &amount);
            accounts[i].balance += amount;
            break;
        }
    }
}

// Function to withdraw money from an account
void withdraw(struct bank_account *accounts, int num_accounts) {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            float amount;
            scanf("%f", &amount);
            if (accounts[i].balance < amount) {
                printf("Insufficient funds\n");
            } else {
                accounts[i].balance -= amount;
            }
            break;
        }
    }
}

int main() {
    struct bank_account accounts[100];
    int num_accounts = 0;
    char command[20];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            add_account(accounts, &num_accounts);
        } else if (strcmp(command, "display") == 0) {
            display_accounts(accounts, num_accounts);
        } else if (strcmp(command, "deposit") == 0) {
            deposit(accounts, num_accounts);
        } else if (strcmp(command, "withdraw") == 0) {
            withdraw(accounts, num_accounts);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}