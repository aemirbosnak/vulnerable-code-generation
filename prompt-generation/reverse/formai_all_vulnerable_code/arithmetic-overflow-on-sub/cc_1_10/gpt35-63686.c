//FormAI DATASET v1.0 Category: Banking Record System ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct Bank_Record{
    char name[50];
    int acc_no;
    int balance;
};

void create_account(struct Bank_Record *record);
void deposit_amount(struct Bank_Record *record, int amount);
void withdraw_amount(struct Bank_Record *record, int amount);
void display_details(struct Bank_Record *record);

int main(){
    int option, amount;
    struct Bank_Record record;
    do{
        printf("\n\n::::: MENU :::::");
        printf("\n1. Create Account");
        printf("\n2. Deposit Amount");
        printf("\n3. Withdraw Amount");
        printf("\n4. Display Account Details");
        printf("\n5. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                create_account(&record);
                break;
            case 2:
                printf("\nEnter Amount to Deposit: ");
                scanf("%d", &amount);
                deposit_amount(&record, amount);
                break;
            case 3:
                printf("\nEnter Amount to Withdraw: ");
                scanf("%d", &amount);
                withdraw_amount(&record, amount);
                break;
            case 4:
                display_details(&record);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice! Please Try Again.");
        }
    }while(option!=5);
    return 0;
}

void create_account(struct Bank_Record *record){
    printf("\nEnter Name: ");
    scanf("%s", record->name);
    printf("Enter Account Number: ");
    scanf("%d", &record->acc_no);
    printf("Enter Opening Balance: ");
    scanf("%d", &record->balance);
    printf("\nAccount Created Successfully!");
}

void deposit_amount(struct Bank_Record *record, int amount){
    record->balance += amount;
    printf("\nAmount Deposited Successfully!");
}

void withdraw_amount(struct Bank_Record *record, int amount){
    if(record->balance<amount)
        printf("\nInsufficient Balance!");
    else{
        record->balance -= amount;
        printf("\nAmount Withdrawn Successfully!");
    }
}

void display_details(struct Bank_Record *record){
    printf("\n-------------------");
    printf("\nName: %s", record->name);
    printf("\nAccount Number: %d", record->acc_no);
    printf("\nBalance: %d", record->balance);
    printf("\n-------------------");
}