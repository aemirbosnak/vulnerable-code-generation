//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int accountNum;
    float balance;
} Account;

int main() {
    int numAccounts, choice, i, accNum;
    float deposit, withdraw;
    char name[50];
    Account *accounts;

    printf("*** Welcome to the Banking Record System! ***\n");
    printf("Please enter the number of accounts to create: ");
    scanf("%d", &numAccounts);

    accounts = (Account*) malloc(numAccounts * sizeof(Account));

    for(i=0; i<numAccounts; i++) {
        printf("*** Please create account #%d ***\n", i+1);
        printf("Name: ");
        scanf("%s", &accounts[i].name);
        printf("Account Number: ");
        scanf("%d", &accounts[i].accountNum);
        printf("Balance: ");
        scanf("%f", &accounts[i].balance);
    }

    do {
        printf("\n *** Banking Record System Menu ***\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View Records\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nAccount Number: ");
                scanf("%d", &accNum);
                for(i=0; i<numAccounts; i++) {
                    if(accounts[i].accountNum == accNum) {
                        printf("Deposit Amount: ");
                        scanf("%f", &deposit);
                        accounts[i].balance += deposit;
                        printf("Deposit successful!\n");
                        break;
                    }
                }
                if(i == numAccounts) printf("Account not found!\n");
                break;
            case 2:
                printf("\nAccount Number: ");
                scanf("%d", &accNum);
                for(i=0; i<numAccounts; i++) {
                    if(accounts[i].accountNum == accNum) {
                        printf("Withdraw Amount: ");
                        scanf("%f", &withdraw);
                        if(withdraw > accounts[i].balance) {
                            printf("Not enough balance!\n");
                        } else {
                            accounts[i].balance -= withdraw;
                            printf("Withdrawal successful!\n");
                        }
                        break;
                    }
                }
                if(i == numAccounts) printf("Account not found!\n");
                break;
            case 3:
                printf("\n*** Banking Records ***\n");
                for(i=0; i<numAccounts; i++) {
                    printf("Name: %s\n", accounts[i].name);
                    printf("Account Number: %d\n", accounts[i].accountNum);
                    printf("Balance: $%.2f\n", accounts[i].balance);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    free(accounts);
    return 0;
}