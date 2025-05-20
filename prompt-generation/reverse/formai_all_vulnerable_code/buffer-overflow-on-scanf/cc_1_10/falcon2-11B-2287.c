//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
    int transactions[10];
} Account;

void print_account(Account *a) {
    printf("Name: %s\n", a->name);
    printf("Account Number: %d\n", a->account_number);
    printf("Balance: $%.2f\n", a->balance);
    printf("Transactions:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: $%.2f\n", i + 1, a->transactions[i]);
    }
}

int main() {
    Account accounts[5];
    int num_accounts = 5;
    int num_transactions = 10;

    int choice = 0;
    do {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account details:\n");
                scanf("%s%d%f", accounts[choice].name, &accounts[choice].account_number, &accounts[choice].balance);
                break;
            case 2:
                printf("Enter amount to deposit:\n");
                scanf("%f", &accounts[choice].balance);
                break;
            case 3:
                printf("Enter amount to withdraw:\n");
                scanf("%f", &accounts[choice].balance);
                break;
            case 4:
                print_account(accounts + choice);
                break;
            case 5:
                exit(0);
        }
    } while (choice!= 5);

    return 0;
}