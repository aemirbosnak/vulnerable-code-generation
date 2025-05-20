//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20
#define ACCOUNT_SIZE 100

typedef struct {
    char name[NAME_LENGTH];
    int account_number;
    double balance;
} account;

int num_accounts = 0;
account accounts[ACCOUNT_SIZE];

void add_account() {
    account new_account;
    printf("Enter account name: ");
    fgets(new_account.name, NAME_LENGTH, stdin);
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter account balance: ");
    scanf("%lf", &new_account.balance);
    getchar(); // clear input buffer
    accounts[num_accounts] = new_account;
    num_accounts++;
}

void display_accounts() {
    printf("Account Name\tAccount Number\tBalance\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s\t%d\t%.2lf\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }
}

void deposit() {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    double amount;
    scanf("%lf", &amount);
    getchar(); // clear input buffer
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance is %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Invalid account number. Deposit unsuccessful.\n");
}

void withdraw() {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    double amount;
    scanf("%lf", &amount);
    getchar(); // clear input buffer
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance < amount) {
                printf("Insufficient funds. Withdrawal unsuccessful.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful. New balance is %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Invalid account number. Withdrawal unsuccessful.\n");
}

int main() {
    int option;
    do {
        printf("---------BANKING RECORD SYSTEM MENU----------\n");
        printf("1. Add an account\n");
        printf("2. Display accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar(); // clear input buffer
        switch(option) {
            case 1:
                add_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (option != 5);
    return 0;
}