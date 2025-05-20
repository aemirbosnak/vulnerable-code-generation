//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int account_no;
    float balance;
} Account;

int main() {
    Account accounts[100];
    int i, j, num_accounts;
    float deposit, withdrawal;

    printf("Enter number of accounts: ");
    scanf("%d", &num_accounts);
    for (i = 0; i < num_accounts; i++) {
        printf("Enter account details for account %d:\n", i+1);
        printf("Name: ");
        fgets(accounts[i].name, sizeof(accounts[i].name), stdin);
        accounts[i].account_no = i+1;
        printf("Balance: ");
        scanf("%f", &accounts[i].balance);
        printf("\n");
    }

    printf("Select operation: \n1. Deposit\n2. Withdrawal\n3. Show balance\n4. Exit\n");
    scanf("%d", &j);
    switch (j) {
        case 1:
            printf("Enter deposit amount: ");
            scanf("%f", &deposit);
            for (i = 0; i < num_accounts; i++) {
                accounts[i].balance += deposit;
            }
            break;
        case 2:
            printf("Enter withdrawal amount: ");
            scanf("%f", &withdrawal);
            for (i = 0; i < num_accounts; i++) {
                if (accounts[i].balance >= withdrawal) {
                    accounts[i].balance -= withdrawal;
                    printf("Withdrawal successful.\n");
                } else {
                    printf("Insufficient funds.\n");
                }
            }
            break;
        case 3:
            for (i = 0; i < num_accounts; i++) {
                printf("%d. Account %s has balance of %.2f.\n", i+1, accounts[i].name, accounts[i].balance);
            }
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid option. Please select a valid option.\n");
            break;
    }

    return 0;
}