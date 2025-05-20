//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

struct account{
    int acc_no;
    char name[20];
    float balance;
};

struct account account[MAX];
int count=0;

void create(){
    int i;
    for(i=0;i<MAX;i++){
        if(account[i].acc_no==0){
            count++;
            printf("\nEnter account number: ");
            scanf("%d",&account[i].acc_no);
            printf("\nEnter name: ");
            scanf("%s",account[i].name);
            account[i].balance=0;
            printf("\nAccount created successfully\n");
            return;
        }
    }
    printf("\nSorry! All accounts are full\n");
}

void deposit(){
    int acc_no,i;
    float amt;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(i=0;i<MAX;i++){
        if(account[i].acc_no==acc_no){
            printf("\nEnter amount to be deposited: ");
            scanf("%f",&amt);
            account[i].balance+=amt;
            printf("\nAmount deposited successfully\n");
            return;
        }
    }
    printf("\nAccount not found\n");
}

void withdraw(){
    int acc_no,i;
    float amt;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(i=0;i<MAX;i++){
        if(account[i].acc_no==acc_no){
            printf("\nEnter amount to be withdrawn: ");
            scanf("%f",&amt);
            if(account[i].balance>=amt){
                account[i].balance-=amt;
                printf("\nAmount withdrawn successfully\n");
            }
            else{
                printf("\nInsufficient balance\n");
            }
            return;
        }
    }
    printf("\nAccount not found\n");
}

void display(){
    int i;
    for(i=0;i<MAX;i++){
        if(account[i].acc_no!=0){
            printf("\nAccount number: %d\n",account[i].acc_no);
            printf("Name: %s\n",account[i].name);
            printf("Balance: %.2f\n",account[i].balance);
        }
    }
}

int main(){
    int ch;
    while(1){
        printf("\n\n1.Create account\n2.Deposit\n3.Withdraw\n4.Display\n5.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();break;
            case 2:deposit();break;
            case 3:withdraw();break;
            case 4:display();break;
            case 5:exit(0);
            default:printf("\nInvalid choice\n");
        }
    }
    return 0;
}