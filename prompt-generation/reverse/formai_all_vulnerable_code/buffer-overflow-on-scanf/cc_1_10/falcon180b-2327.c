//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//struct for account
struct account{
    int acc_no;
    char name[20];
    char address[50];
    float balance;
};

struct account account[MAX];
int count=0;

//function to add account
void add_account(){
    int i;
    char ch;
    printf("\nEnter details of account holder:\n");
    printf("Name: ");
    scanf("%s",&account[count].name);
    printf("Address: ");
    scanf("%s",&account[count].address);
    printf("Initial Balance: ");
    scanf("%f",&account[count].balance);
    account[count].acc_no=count+1;
    printf("\nAccount added successfully.\n");
    count++;
}

//function to search account
void search_account(){
    int i,ch;
    printf("\nEnter account number to search: ");
    scanf("%d",&ch);
    for(i=0;i<count;i++){
        if(account[i].acc_no==ch){
            printf("\nAccount found.\n");
            printf("Name: %s\n",account[i].name);
            printf("Address: %s\n",account[i].address);
            printf("Balance: %f\n",account[i].balance);
        }
    }
}

//function to deposit money
void deposit_money(){
    int i,ch;
    float amt;
    printf("\nEnter account number to deposit: ");
    scanf("%d",&ch);
    for(i=0;i<count;i++){
        if(account[i].acc_no==ch){
            printf("\nEnter amount to deposit: ");
            scanf("%f",&amt);
            account[i].balance+=amt;
            printf("\nDeposit successful.\n");
            break;
        }
    }
}

//function to withdraw money
void withdraw_money(){
    int i,ch;
    float amt;
    printf("\nEnter account number to withdraw: ");
    scanf("%d",&ch);
    for(i=0;i<count;i++){
        if(account[i].acc_no==ch){
            printf("\nEnter amount to withdraw: ");
            scanf("%f",&amt);
            if(account[i].balance>=amt){
                account[i].balance-=amt;
                printf("\nWithdrawal successful.\n");
            }
            else{
                printf("\nInsufficient balance.\n");
            }
            break;
        }
    }
}

//function to check balance
void check_balance(){
    int i,ch;
    printf("\nEnter account number to check balance: ");
    scanf("%d",&ch);
    for(i=0;i<count;i++){
        if(account[i].acc_no==ch){
            printf("\nBalance: %f\n",account[i].balance);
            break;
        }
    }
}

int main(){
    int ch;
    while(1){
        printf("\n1. Add account\n2. Search account\n3. Deposit money\n4. Withdraw money\n5. Check balance\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                add_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                check_balance();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}