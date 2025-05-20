//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_BALANCE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    char balance[MAX_BALANCE_LENGTH];
} account_t;

int main() {
    int option;
    account_t account;

    do {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", account.name);
                printf("Enter your account number: ");
                scanf("%s", account.account_number);
                account.balance[0] = '\0';
                break;
            case 2:
                printf("Enter your account number: ");
                scanf("%s", account.account_number);
                printf("Enter the amount to deposit: ");
                scanf("%s", account.balance);
                break;
            case 3:
                printf("Enter your account number: ");
                scanf("%s", account.account_number);
                printf("Enter the amount to withdraw: ");
                scanf("%s", account.balance);
                break;
            case 4:
                printf("Enter your account number: ");
                scanf("%s", account.account_number);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option!= 5);

    return 0;
}