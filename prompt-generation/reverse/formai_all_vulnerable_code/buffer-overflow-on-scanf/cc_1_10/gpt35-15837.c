//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int accNo;
    char name[50];
    float balance;
};

void create_account(struct account*);
void deposit_money(struct account*, int);
void withdraw_money(struct account*, int);
void display_account(struct account);

int main(){
    struct account cust1;
    create_account(&cust1);
    printf("\n");
    deposit_money(&cust1, 1000);
    printf("\n");
    withdraw_money(&cust1, 500);
    printf("\n");
    display_account(cust1);

    return 0;
}

void create_account(struct account *cust){
    printf("Enter Account Number: ");
    scanf("%d", &cust->accNo);
    fflush(stdin);
    printf("Enter Name: ");
    fgets(cust->name, 50, stdin);
    printf("Enter Balance: ");
    scanf("%f", &cust->balance);
}

void deposit_money(struct account *cust, int amount){
    cust->balance += amount;
    printf("%d deposited successfully. Current balance: %.2f", amount, cust->balance);
}

void withdraw_money(struct account *cust, int amount){
    if(cust->balance < amount){
        printf("Insufficient funds!");
        return;
    }
    cust->balance -= amount;
    printf("%d withdrawn successfully. Current balance: %.2f", amount, cust->balance);
}

void display_account(struct account cust){
    printf("\nAccount Details:");
    printf("\nAccount Number: %d", cust.accNo);
    printf("\nName: %s", cust.name);
    printf("Balance: %.2f", cust.balance);
}