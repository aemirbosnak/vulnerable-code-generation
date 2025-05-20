//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int account_no;
    int balance;
    char bank[50];
    char branch[50];
} Account;

int main() {
    Account* accounts = (Account*)malloc(10 * sizeof(Account));
    int i;

    printf("Enter bank name: ");
    scanf("%s", accounts[0].bank);
    printf("Enter branch name: ");
    scanf("%s", accounts[0].branch);
    printf("Enter account number: ");
    scanf("%d", &accounts[0].account_no);
    printf("Enter name of account holder: ");
    scanf("%s", accounts[0].name);
    printf("Enter initial balance: ");
    scanf("%d", &accounts[0].balance);

    for (i = 1; i < 10; i++) {
        printf("Enter bank name: ");
        scanf("%s", accounts[i].bank);
        printf("Enter branch name: ");
        scanf("%s", accounts[i].branch);
        printf("Enter account number: ");
        scanf("%d", &accounts[i].account_no);
        printf("Enter name of account holder: ");
        scanf("%s", accounts[i].name);
        printf("Enter initial balance: ");
        scanf("%d", &accounts[i].balance);
    }

    printf("Banking Record System\n");
    printf("Bank Name: %s\n", accounts[0].bank);
    printf("Branch Name: %s\n", accounts[0].branch);
    printf("Account Number: %d\n", accounts[0].account_no);
    printf("Name of Account Holder: %s\n", accounts[0].name);
    printf("Initial Balance: %d\n", accounts[0].balance);

    for (i = 1; i < 10; i++) {
        printf("Account %d:\n", i);
        printf("Bank Name: %s\n", accounts[i].bank);
        printf("Branch Name: %s\n", accounts[i].branch);
        printf("Account Number: %d\n", accounts[i].account_no);
        printf("Name of Account Holder: %s\n", accounts[i].name);
        printf("Initial Balance: %d\n", accounts[i].balance);
    }

    printf("\n");
    free(accounts);
    return 0;
}