//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} account;

void create_account(account *a) {
    printf("Enter account number: ");
    scanf("%d", &a->account_number);
    printf("Enter account holder name: ");
    scanf("%s", a->name);
    a->balance = 0;
}

void deposit(account *a, float amount) {
    a->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", a->balance);
}

void withdraw(account *a, float amount) {
    if(a->balance >= amount) {
        a->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", a->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(account *a) {
    printf("Current balance: %.2f\n", a->balance);
}

int main() {
    account a;
    int choice;

    create_account(&a);

    do {
        printf("\nBanking Record System\n");
        printf("1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &a.balance);
                deposit(&a, a.balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &a.balance);
                withdraw(&a, a.balance);
                break;
            case 3:
                check_balance(&a);
                break;
            case 4:
                printf("Thank you for using our services.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}