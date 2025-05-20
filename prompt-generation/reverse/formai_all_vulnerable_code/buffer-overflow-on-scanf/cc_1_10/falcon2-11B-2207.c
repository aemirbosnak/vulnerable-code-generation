//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ACCOUNT 10
#define MAX_NAME 50
#define MAX_ACCOUNT_NO 20
#define MAX_BALANCE 10

int main()
{
    int account[MAX_ACCOUNT], balance[MAX_ACCOUNT];
    char name[MAX_NAME];
    char account_no[MAX_ACCOUNT_NO];
    int i, j, k, choice;

    printf("Welcome to the Bank Record System!\n");
    printf("Enter the number of accounts you want to create: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("Enter the account number of the %dth account: ", j+1);
        scanf("%s", &account_no);

        printf("Enter the name of the account holder: ");
        scanf("%s", &name);

        printf("Enter the initial balance of the account: ");
        scanf("%d", &balance[j]);

        printf("\n");
    }

    printf("Account Number\t\t\tName\t\tBalance\n");
    printf("------------------------------\n");
    for (j = 0; j < i; j++) {
        printf("%s\t\t\t%s\t\t%d\n", account_no, name, balance[j]);
    }

    printf("\n");

    while (1) {
        printf("\n1. Add new account\n2. Add money to an account\n3. Withdraw money from an account\n4. Display account details\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the account number of the new account: ");
                scanf("%s", &account_no);

                printf("Enter the name of the new account holder: ");
                scanf("%s", &name);

                printf("Enter the initial balance of the new account: ");
                scanf("%d", &balance[j]);

                printf("\n");
                break;
            case 2:
                printf("Enter the account number of the account you want to add money to: ");
                scanf("%s", &account_no);

                printf("Enter the amount of money you want to add: ");
                scanf("%d", &balance[j]);

                printf("\n");
                break;
            case 3:
                printf("Enter the account number of the account you want to withdraw money from: ");
                scanf("%s", &account_no);

                printf("Enter the amount of money you want to withdraw: ");
                scanf("%d", &balance[j]);

                printf("\n");
                break;
            case 4:
                for (j = 0; j < i; j++) {
                    printf("%s\t\t\t%s\t\t%d\n", account_no, name, balance[j]);
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}