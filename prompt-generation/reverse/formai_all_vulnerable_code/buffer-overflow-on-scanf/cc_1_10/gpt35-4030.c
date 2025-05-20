//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer{
    int account_no;
    char name[50];
    char address[100];
    float balance;
};

void display(struct customer c[], int n){
    printf("\nAccount No.\tName\t\tAddress\t\t\tBalance\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%s\t\t%s\t\t%.2f\n",c[i].account_no,c[i].name,c[i].address,c[i].balance);
    }
}

void deposit(struct customer *c,float amt){
    c->balance+=amt;
}

void withdraw(struct customer *c,float amt){
    if(c->balance>=amt){
        c->balance-=amt;
    }
    else{
        printf("\nInsufficient balance!\n");
    }
}

void add_account(struct customer c[],int *n){
    printf("Enter details for new account:\n");
    printf("Name: ");
    scanf(" %[^\n]s",c[*n].name);
    printf("Address: ");
    scanf(" %[^\n]s",c[*n].address);
    printf("Starting balance: ");
    scanf("%f",&c[*n].balance);

    c[*n].account_no=(*n)+1;
    (*n)++;
}

int search_account(struct customer c[],int n,int account_no){
    for(int i=0;i<n;i++){
        if(c[i].account_no==account_no){
            return i;
        }
    }
    return -1;
}

int main(){
    struct customer c[100];
    int choice,account_no,n=0;
    float amt;

    while(1){
        printf("\nWelcome to Banking Record System\n");
        printf("\n1. Display all accounts\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Add account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                display(c,n);
                break;
            case 2:
                printf("Enter account no.: ");
                scanf("%d",&account_no);
                int index=search_account(c,n,account_no);
                if(index==-1){
                    printf("\nAccount not found!\n");
                }
                else{
                    printf("Enter amount to deposit: ");
                    scanf("%f",&amt);
                    deposit(&c[index],amt);
                    printf("\nDeposit successful!\n");
                }
                break;
            case 3:
                printf("Enter account no.: ");
                scanf("%d",&account_no);
                int idx=search_account(c,n,account_no);
                if(idx==-1){
                    printf("\nAccount not found!\n");
                }
                else{
                    printf("Enter amount to withdraw: ");
                    scanf("%f",&amt);
                    withdraw(&c[idx],amt);
                    printf("\nWithdrawal successful!\n");
                }
                break;
            case 4:
                add_account(c,&n);
                printf("\nAccount added successfully!\n");
                break;
            case 5:
                printf("\nThank you for using Banking Record System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}