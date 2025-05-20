//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

int main() {
    int choice;
    Account account;

    do {
        printf("\nBANKING RECORD SYSTEM\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter account holder's name: ");
                scanf("%s", account.name);
                printf("Enter account number: ");
                scanf("%d", &account.account_number);
                printf("Account created successfully with account number %d\n", account.account_number);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account.account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &account.balance);
                printf("Deposit successful\n");
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account.account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &account.balance);
                if(account.balance >= account.balance) {
                    account.balance -= account.balance;
                    printf("Withdrawal successful\n");
                }
                else {
                    printf("Insufficient balance\n");
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account.account_number);
                printf("Current balance: %.2f\n", account.balance);
                break;
            case 5:
                printf("Thank you for using our services\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 5);

    return 0;
}