//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNT 100

typedef struct {
    char name[50];
    int balance;
    char type[50];
} Account;

Account accounts[MAX_ACCOUNT];
int account_count = 0;

int main() {
    int choice, account_num;

    printf("Welcome to the Banking Record System!\n");
    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Create a new account\n");
        printf("2. Deposit funds to an account\n");
        printf("3. Withdraw funds from an account\n");
        printf("4. View account details\n");
        printf("5. View all accounts\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Create a new account:\n");
                printf("Name: ");
                fgets(accounts[account_count].name, sizeof(accounts[account_count].name), stdin);
                printf("Account Type: ");
                fgets(accounts[account_count].type, sizeof(accounts[account_count].type), stdin);
                accounts[account_count].balance = 0;
                account_count++;
                break;
            case 2:
                printf("Deposit funds to an account:\n");
                printf("Account Number: ");
                scanf("%d", &account_num);
                if (account_num < 0 || account_num >= account_count) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Amount: ");
                scanf("%d", &accounts[account_num].balance);
                break;
            case 3:
                printf("Withdraw funds from an account:\n");
                printf("Account Number: ");
                scanf("%d", &account_num);
                if (account_num < 0 || account_num >= account_count) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Amount: ");
                scanf("%d", &accounts[account_num].balance);
                break;
            case 4:
                printf("View account details:\n");
                printf("Account Number: ");
                scanf("%d", &account_num);
                if (account_num < 0 || account_num >= account_count) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Name: %s\n", accounts[account_num].name);
                printf("Type: %s\n", accounts[account_num].type);
                printf("Balance: %d\n", accounts[account_num].balance);
                break;
            case 5:
                printf("View all accounts:\n");
                for (int i = 0; i < account_count; i++) {
                    printf("Account %d:\n", i + 1);
                    printf("Name: %s\n", accounts[i].name);
                    printf("Type: %s\n", accounts[i].type);
                    printf("Balance: %d\n", accounts[i].balance);
                }
                break;
            case 6:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}