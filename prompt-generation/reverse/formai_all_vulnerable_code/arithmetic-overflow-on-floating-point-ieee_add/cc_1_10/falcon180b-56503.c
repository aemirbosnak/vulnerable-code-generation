//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct account{
    int acc_no;
    char name[50];
    char address[100];
    float balance;
};

struct account create_account(int acc_no, char name[50], char address[100], float balance){
    struct account account;
    account.acc_no = acc_no;
    strcpy(account.name, name);
    strcpy(account.address, address);
    account.balance = balance;
    return account;
}

void display_account(struct account account){
    printf("\nAccount No: %d\n", account.acc_no);
    printf("Name: %s\n", account.name);
    printf("Address: %s\n", account.address);
    printf("Balance: %.2f\n", account.balance);
}

void deposit_money(struct account *account, float amount){
    account->balance += amount;
    printf("\nAmount Deposited Successfully!\n");
}

void withdraw_money(struct account *account, float amount){
    if(amount > account->balance){
        printf("\nInsufficient Balance!");
    }
    else{
        account->balance -= amount;
        printf("\nAmount Withdrawn Successfully!");
    }
}

int main(){
    int choice, acc_no;
    char name[50], address[100];
    float balance, amount;

    struct account account;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);

    printf("\nEnter Account Holder's Name: ");
    scanf("%s", name);

    printf("\nEnter Account Holder's Address: ");
    scanf("%s", address);

    printf("\nEnter Initial Balance: ");
    scanf("%f", &balance);

    account = create_account(acc_no, name, address, balance);
    display_account(account);

    do{
        printf("\n\nEnter your choice:\n");
        printf("1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Amount to Deposit: ");
                scanf("%f", &amount);
                deposit_money(&account, amount);
                break;

            case 2:
                printf("\nEnter Amount to Withdraw: ");
                scanf("%f", &amount);
                withdraw_money(&account, amount);
                break;

            case 3:
                display_account(account);
                break;

            case 4:
                printf("\nThank You!");
                break;

            default:
                printf("\nInvalid Choice!");
        }
    }while(choice!= 4);

    return 0;
}