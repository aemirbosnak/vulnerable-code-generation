//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct account{
    char name[20];
    char address[50];
    int account_number;
    float balance;
};

void create_account(struct account *a){
    printf("Enter name: ");
    scanf("%s",a->name);
    printf("Enter address: ");
    scanf("%s",a->address);
    printf("Enter account number: ");
    scanf("%d",&a->account_number);
    printf("Enter initial balance: ");
    scanf("%f",&a->balance);
}

void deposit(struct account *a,float amount){
    a->balance+=amount;
    printf("\nDeposit successful!\n");
}

void withdraw(struct account *a,float amount){
    if(a->balance>=amount){
        a->balance-=amount;
        printf("\nWithdrawal successful!\n");
    }
    else{
        printf("\nInsufficient balance!");
    }
}

void check_balance(struct account *a){
    printf("\nCurrent balance: %.2f\n",a->balance);
}

void main(){
    struct account a[MAX];
    int choice,i,num=0;

    do{
        printf("\n\nBanking System\n");
        printf("1. Create account\n2. Deposit\n3. Withdraw\n4. Check balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(num>=MAX){
                    printf("\nMaximum number of accounts reached!");
                }
                else{
                    create_account(&a[num]);
                    num++;
                }
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d",&i);

                for(int j=0;j<num;j++){
                    if(a[j].account_number==i){
                        deposit(&a[j],0);
                        break;
                    }
                }

                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d",&i);

                for(int j=0;j<num;j++){
                    if(a[j].account_number==i){
                        withdraw(&a[j],0);
                        break;
                    }
                }

                break;

            case 4:
                printf("Enter account number: ");
                scanf("%d",&i);

                for(int j=0;j<num;j++){
                    if(a[j].account_number==i){
                        check_balance(&a[j]);
                        break;
                    }
                }

                break;

            case 5:
                printf("\nThank you for using our services!");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=5);
}