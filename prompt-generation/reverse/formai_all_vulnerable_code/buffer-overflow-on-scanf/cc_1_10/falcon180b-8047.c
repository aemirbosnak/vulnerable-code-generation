//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT 100

typedef struct {
    int account_number;
    char name[50];
    char address[100];
    float balance;
} BankAccount;

int main() {
    BankAccount accounts[MAX_ACCOUNT];
    int num_accounts = 0;
    char choice = 'y';

    while(choice == 'y') {
        printf("\nEnter your choice:\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter address: ");
                scanf("%s", accounts[num_accounts].address);
                accounts[num_accounts].balance = 0.0;
                printf("Account created successfully.\n");
                num_accounts++;
                break;

            case '2':
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts - 1].account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &accounts[num_accounts - 1].balance);
                printf("Deposit successful.\n");
                break;

            case '3':
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts - 1].account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &accounts[num_accounts - 1].balance);
                if(accounts[num_accounts - 1].balance >= accounts[num_accounts - 1].balance - 0.0) {
                    accounts[num_accounts - 1].balance -= accounts[num_accounts - 1].balance - 0.0;
                    printf("Withdrawal successful.\n");
                } else {
                    printf("Insufficient balance.\n");
                }
                break;

            case '4':
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts - 1].account_number);
                printf("Current balance: $%.2f\n", accounts[num_accounts - 1].balance);
                break;

            case '5':
                printf("Thank you for using our banking system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}