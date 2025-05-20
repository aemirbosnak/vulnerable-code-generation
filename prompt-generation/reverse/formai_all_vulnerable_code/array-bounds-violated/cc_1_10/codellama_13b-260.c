//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>

struct account {
    int account_number;
    char name[50];
    float balance;
};

struct account accounts[100];

int main() {
    int i;
    char command;
    int account_number;
    char name[50];
    float balance;

    printf("Welcome to the Banking Record System!\n");
    printf("Commands: 'a' to add a new account, 's' to show an account, 'd' to delete an account, 'q' to quit\n");

    while (1) {
        printf("> ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%f", &balance);
                accounts[account_number].account_number = account_number;
                strcpy(accounts[account_number].name, name);
                accounts[account_number].balance = balance;
                break;
            case 's':
                printf("Enter account number: ");
                scanf("%d", &account_number);
                if (accounts[account_number].account_number == 0) {
                    printf("Account not found\n");
                } else {
                    printf("Account: %d\n", accounts[account_number].account_number);
                    printf("Name: %s\n", accounts[account_number].name);
                    printf("Balance: %f\n", accounts[account_number].balance);
                }
                break;
            case 'd':
                printf("Enter account number: ");
                scanf("%d", &account_number);
                if (accounts[account_number].account_number == 0) {
                    printf("Account not found\n");
                } else {
                    accounts[account_number].account_number = 0;
                    strcpy(accounts[account_number].name, "");
                    accounts[account_number].balance = 0.0;
                }
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}