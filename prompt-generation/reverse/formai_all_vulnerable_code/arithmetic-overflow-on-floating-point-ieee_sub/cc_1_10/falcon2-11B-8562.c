//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct account
{
    int account_no;
    char name[100];
    float balance;
};

void create_account()
{
    int n;
    struct account acc;
    printf("Enter Account No: ");
    scanf("%d", &n);
    printf("Enter Account Holder Name: ");
    scanf("%s", acc.name);
    printf("Enter Opening Balance: ");
    scanf("%f", &acc.balance);
    printf("Account Created Successfully\n");
}

void deposit(struct account *acc)
{
    float amount;
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    acc->balance += amount;
    printf("Deposit Successful\n");
}

void withdraw(struct account *acc)
{
    float amount;
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    if (acc->balance >= amount)
    {
        acc->balance -= amount;
        printf("Withdrawal Successful\n");
    }
    else
    {
        printf("Insufficient Balance\n");
    }
}

void display_account(struct account acc)
{
    printf("Account No: %d\n", acc.account_no);
    printf("Account Holder Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

int main()
{
    struct account acc;
    create_account();
    deposit(&acc);
    withdraw(&acc);
    display_account(acc);
    return 0;
}