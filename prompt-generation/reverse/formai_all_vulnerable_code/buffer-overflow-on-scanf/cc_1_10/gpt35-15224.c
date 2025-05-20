//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

struct account{
    int acc_no;
    char name[50];
    float balance;
};

typedef struct account Account;

int num_accounts;

void menu(){
    printf("\n1. Add new account\n2. Show account details\n3. Deposit\n4. Withdraw\n5. Exit\n");
}

int find_account(int acc_no, Account accounts[]){
    for(int i=0;i<num_accounts;i++){
        if(accounts[i].acc_no==acc_no){
            return i;
        }
    }
    return -1;
}

void add_account(Account accounts[]){
    printf("\nEnter account number: ");
    scanf("%d",&accounts[num_accounts].acc_no);
    printf("Enter name: ");
    scanf("%s",accounts[num_accounts].name);
    printf("Enter opening balance: ");
    scanf("%f",&accounts[num_accounts].balance);
    num_accounts++;
    printf("\nAccount added successfully!\n");
}

void show_account(int acc_no, Account accounts[]){
    int index=find_account(acc_no,accounts);
    if(index==-1){
        printf("\nAccount not found!\n");
    }
    else{
        printf("\nAccount number: %d\nName: %s\nBalance: %.2f\n",accounts[index].acc_no,accounts[index].name,accounts[index].balance);
    }
}

void deposit(int acc_no, Account accounts[]){
    int index=find_account(acc_no,accounts);
    if(index==-1){
        printf("\nAccount not found!\n");
    }
    else{
        float amt;
        printf("\nEnter amount to deposit: ");
        scanf("%f",&amt);
        accounts[index].balance+=amt;
        printf("\nDeposit successful! Current balance: %.2f\n",accounts[index].balance);
    }
}

void withdraw(int acc_no, Account accounts[]){
    int index=find_account(acc_no,accounts);
    if(index==-1){
        printf("\nAccount not found!\n");
    }
    else{
        float amt;
        printf("\nEnter amount to withdraw: ");
        scanf("%f",&amt);
        if(accounts[index].balance<amt){
            printf("\nInsufficient balance!\n");
        }
        else{
            accounts[index].balance-=amt;
            printf("\nWithdrawal successful! Current balance: %.2f\n",accounts[index].balance);
        }
    }
}

int main(){
    num_accounts=0;
    Account accounts[100];
    int choice=0;
    while(choice!=5){
        menu();
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_account(accounts); break;
            case 2: {
                int acc_no;
                printf("\nEnter account number: ");
                scanf("%d",&acc_no);
                show_account(acc_no,accounts); 
                break;
            }
            case 3: {
                int acc_no;
                printf("\nEnter account number: ");
                scanf("%d",&acc_no);
                deposit(acc_no,accounts); 
                break;
            }
            case 4: {
                int acc_no;
                printf("\nEnter account number: ");
                scanf("%d",&acc_no);
                withdraw(acc_no,accounts); 
                break;
            }
            case 5: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}