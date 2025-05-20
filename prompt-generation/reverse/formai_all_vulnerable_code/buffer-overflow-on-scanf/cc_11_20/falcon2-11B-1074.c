//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT_NUM 1000
#define MAX_BALANCE 1000000

typedef struct Account {
    int account_num;
    char account_holder[30];
    int balance;
} Account;

Account accounts[MAX_ACCOUNT_NUM];
int num_accounts = 0;

int main() {
    int choice;
    int account_num;
    char account_holder[30];
    int balance;

    while (1) {
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (num_accounts == MAX_ACCOUNT_NUM) {
                    printf("Account limit reached. Cannot create new account.\n");
                } else {
                    strcpy(accounts[num_accounts].account_holder, "");
                    accounts[num_accounts].account_num = account_num;
                    accounts[num_accounts].balance = 0;
                    num_accounts++;
                    printf("Account created successfully.\n");
                }
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (num_accounts > 0 && account_num < num_accounts) {
                    printf("Enter deposit amount: ");
                    scanf("%d", &balance);
                    accounts[account_num].balance += balance;
                    printf("Deposit successful.\n");
                } else {
                    printf("Invalid account number.\n");
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (num_accounts > 0 && account_num < num_accounts) {
                    printf("Enter withdrawal amount: ");
                    scanf("%d", &balance);

                    if (accounts[account_num].balance >= balance) {
                        accounts[account_num].balance -= balance;
                        printf("Withdrawal successful.\n");
                    } else {
                        printf("Insufficient balance.\n");
                    }
                } else {
                    printf("Invalid account number.\n");
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (num_accounts > 0 && account_num < num_accounts) {
                    printf("Account balance: %d\n", accounts[account_num].balance);
                } else {
                    printf("Invalid account number.\n");
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}