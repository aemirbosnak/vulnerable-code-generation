//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    double balance;
} BankAccount;

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    char choice;

    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("Please choose an option:\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numAccounts >= MAX_ACCOUNTS) {
                    printf("Sorry, you cannot create any more accounts.\n");
                } else {
                    printf("Enter account holder's name:\n");
                    scanf("%s", accounts[numAccounts].name);
                    printf("Enter account number:\n");
                    scanf("%s", accounts[numAccounts].accountNumber);
                    accounts[numAccounts].balance = 0.0;
                    numAccounts++;
                    printf("Account created successfully!\n");
                }
                break;

            case '2':
                printf("Enter account number:\n");
                scanf("%s", accounts[numAccounts-1].accountNumber);
                printf("Enter amount to deposit:\n");
                scanf("%lf", &accounts[numAccounts-1].balance);
                printf("Deposit successful!\n");
                break;

            case '3':
                printf("Enter account number:\n");
                scanf("%s", accounts[numAccounts-1].accountNumber);
                printf("Enter amount to withdraw:\n");
                scanf("%lf", &accounts[numAccounts-1].balance);
                printf("Withdrawal successful!\n");
                break;

            case '4':
                printf("Enter account number:\n");
                scanf("%s", accounts[numAccounts-1].accountNumber);
                printf("Current balance: $%.2lf\n", accounts[numAccounts-1].balance);
                break;

            case '5':
                printf("Thank you for using the Banking Record System!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(choice!= '5');

    return 0;
}