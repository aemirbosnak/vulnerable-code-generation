//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account{
    int account_number;
    char name[50];
    float balance;
};

void new_account(struct account acc[], int i){
    int account_number;
    char name[50];
    float balance;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("\nEnter balance: ");
    scanf("%f", &balance);
    acc[i].account_number = account_number;
    strcpy(acc[i].name, name);
    acc[i].balance = balance;
}

int find_account(struct account acc[], int i){
    int account_number;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    for (i=0;i<10;i++){
        if (acc[i].account_number == account_number){
            return i;
        }
    }
    return -1;
}

void deposit(struct account acc[], int i){
    int account_index;
    float amount;
    account_index = find_account(acc,i);
    if (account_index == -1){
        printf("\nAccount not found.\n");
    }
    else{
        printf("\nEnter amount to be deposited: ");
        scanf("%f", &amount);
        acc[account_index].balance += amount;
        printf("\nDeposit successful. New balance is %.2f.\n", acc[account_index].balance);
    }
}

void withdraw(struct account acc[], int i){
    int account_index;
    float amount;
    account_index = find_account(acc,i);
    if (account_index == -1){
        printf("\nAccount not found.\n");
    }
    else{
        printf("\nEnter amount to be withdrawn: ");
        scanf("%f", &amount);
        if (acc[account_index].balance < amount){
            printf("\nInsufficient balance.\n");
        }
        else{
            acc[account_index].balance -= amount;
            printf("\nWithdrawal successful. New balance is %.2f.\n", acc[account_index].balance);
        }
    }
}

void display(struct account acc[], int i){
    int account_index;
    account_index = find_account(acc,i);
    if (account_index == -1){
        printf("\nAccount not found.\n");
    }
    else{
        printf("\nAccount number: %d\n", acc[account_index].account_number);
        printf("Name: %s\n", acc[account_index].name);
        printf("Balance: %.2f\n", acc[account_index].balance);
    }
}

int main(){
    int choice, i=0;
    struct account acc[10];
    while (1){
        printf("\nBanking Record System\n");
        printf("\n1.Create new account\n2.Deposit\n3.Withdraw\n4.Display account details\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if (i<10){
                    new_account(acc, i);
                    i++;
                }
                else{
                    printf("\nMaximum number of accounts reached.\n");
                }
                break;
            case 2:
                deposit(acc, i);
                break;
            case 3:
                withdraw(acc, i);
                break;
            case 4:
                display(acc, i);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}