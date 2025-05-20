//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double balance;
    int account_number;
} Account;

typedef struct {
    char description[100];
    double amount;
    int account_number;
    int transaction_number;
} Transaction;

int main() {
    int num_accounts, num_transactions;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];
    char choice;

    do {
        system("clear");
        printf("Personal Finance Planner\n");
        printf("------------------------\n");
        printf("A - Add account\n");
        printf("B - View accounts\n");
        printf("C - Add transaction\n");
        printf("D - View transactions\n");
        printf("E - Exit\n");
        printf("------------------------\n");
        scanf("%c", &choice);

        switch(choice) {
        case 'A':
            printf("Enter account name: ");
            scanf("%s", accounts[num_accounts].name);
            printf("Enter account number: ");
            scanf("%d", &accounts[num_accounts].account_number);
            accounts[num_accounts].balance = 0;
            num_accounts++;
            break;
        case 'B':
            printf("Accounts:\n");
            for(int i=0; i<num_accounts; i++) {
                printf("%d. %s - $%.2f\n", i+1, accounts[i].name, accounts[i].balance);
            }
            break;
        case 'C':
            printf("Enter transaction description: ");
            scanf("%s", transactions[num_transactions].description);
            printf("Enter amount: ");
            scanf("%lf", &transactions[num_transactions].amount);
            printf("Enter account number: ");
            scanf("%d", &transactions[num_transactions].account_number);
            transactions[num_transactions].transaction_number = num_transactions+1;
            num_transactions++;
            break;
        case 'D':
            printf("Transactions:\n");
            for(int i=0; i<num_transactions; i++) {
                printf("%d. %s - $%.2f - Account %d\n", i+1, transactions[i].description, transactions[i].amount, transactions[i].account_number);
            }
            break;
        case 'E':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}