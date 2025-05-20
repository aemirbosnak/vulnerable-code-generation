//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
#define SIZE 50

struct account{
    int acc_no;
    char name[SIZE];
    char address[SIZE];
    float balance;
};

struct account acc[MAX];
int curr_acc=0;

void create_account(){
    int i;
    printf("Enter the number of accounts you want to create: ");
    scanf("%d",&i);
    for(int j=0;j<i;j++){
        printf("\nEnter account number: ");
        scanf("%d",&acc[curr_acc].acc_no);
        printf("Enter account holder's name: ");
        scanf("%s",acc[curr_acc].name);
        printf("Enter account holder's address: ");
        scanf("%s",acc[curr_acc].address);
        printf("Enter initial balance: ");
        scanf("%f",&acc[curr_acc].balance);
        curr_acc++;
    }
}

void display_accounts(){
    int i;
    printf("\nAccount Number\tName\tAddress\tBalance");
    for(i=0;i<curr_acc;i++){
        printf("\n%d\t%s\t%s\t%.2f",acc[i].acc_no,acc[i].name,acc[i].address,acc[i].balance);
    }
}

void deposit(){
    int acc_no;
    float amt;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<curr_acc;i++){
        if(acc[i].acc_no==acc_no){
            printf("\nEnter amount to deposit: ");
            scanf("%f",&amt);
            acc[i].balance+=amt;
            printf("\nAmount deposited successfully.");
            break;
        }
        else{
            printf("\nAccount not found.");
        }
    }
}

void withdraw(){
    int acc_no;
    float amt;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<curr_acc;i++){
        if(acc[i].acc_no==acc_no){
            printf("\nEnter amount to withdraw: ");
            scanf("%f",&amt);
            if(amt>acc[i].balance){
                printf("\nInsufficient balance.");
            }
            else{
                acc[i].balance-=amt;
                printf("\nAmount withdrawn successfully.");
            }
            break;
        }
        else{
            printf("\nAccount not found.");
        }
    }
}

void main(){
    int choice;
    while(1){
        printf("\n1.Create Account\n2.Display Accounts\n3.Deposit\n4.Withdraw\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    }
}