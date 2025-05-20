//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_BALANCE 1000000

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    char choice;

    do {
        printf("\nBanking System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numAccounts >= MAX_ACCOUNTS) {
                    printf("Maximum number of accounts reached.\n");
                } else {
                    printf("Enter account number: ");
                    scanf("%d", &accounts[numAccounts].accountNumber);
                    printf("Enter name: ");
                    scanf("%s", accounts[numAccounts].name);
                    accounts[numAccounts].balance = 0.0;
                    numAccounts++;
                    printf("Account created successfully.\n");
                }
                break;

            case '2':
                printf("Enter account number: ");
                scanf("%d", &choice);
                for(int i=0; i<numAccounts; i++) {
                    if(accounts[i].accountNumber == choice) {
                        printf("Enter amount to deposit: ");
                        scanf("%f", &accounts[i].balance);
                        printf("Deposit successful.\n");
                        break;
                    }
                }
                break;

            case '3':
                printf("Enter account number: ");
                scanf("%d", &choice);
                for(int i=0; i<numAccounts; i++) {
                    if(accounts[i].accountNumber == choice) {
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &accounts[i].balance);
                        if(accounts[i].balance < 0.0) {
                            printf("Insufficient balance.\n");
                        } else {
                            printf("Withdrawal successful.\n");
                        }
                        break;
                    }
                }
                break;

            case '4':
                printf("Enter account number: ");
                scanf("%d", &choice);
                for(int i=0; i<numAccounts; i++) {
                    if(accounts[i].accountNumber == choice) {
                        printf("Account balance: %.2f\n", accounts[i].balance);
                        break;
                    }
                }
                break;

            case '5':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}