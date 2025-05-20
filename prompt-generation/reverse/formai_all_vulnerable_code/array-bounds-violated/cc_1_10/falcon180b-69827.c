//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_BALANCE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    double balance;
} Account;

int main() {
    int choice, accountNumber;
    char name[MAX_NAME_LENGTH];
    Account accounts[MAX_ACCOUNTS];

    printf("Welcome to the Capulet and Montague Bank\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].name, "") == 0) {
            strcpy(accounts[i].name, name);
            accounts[i].accountNumber = i + 1;
            accounts[i].balance = 0.0;
            printf("Your account number is %d\n", accounts[i].accountNumber);
            break;
        }
    }

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &accounts[accountNumber - 1].balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &accounts[accountNumber - 1].balance);
                break;
            case 3:
                printf("Your current balance is %.2lf\n", accounts[accountNumber - 1].balance);
                break;
            case 4:
                printf("Thank you for using the Capulet and Montague Bank\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (choice!= 4);

    return 0;
}