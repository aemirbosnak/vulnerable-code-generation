//FormAI DATASET v1.0 Category: Banking Record System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining structures
struct customer{
    char name[100];
    int account_number;
    float balance;
};

//function prototype
void display(struct customer[],int);
void add_account(struct customer[],int);
void delete_account(struct customer[],int);
void transaction(struct customer[],int);

int main(){
    int n,i,option;
    printf("Enter the number of customers: ");
    scanf("%d",&n);

    struct customer c[n];

    //initializing the array of structures
    for(i=0;i<n;i++){
        printf("\n\nEnter the name of the customer %d:",i+1);
        scanf("%s",&c[i].name);

        printf("\nEnter the account number of the customer %d:",i+1);
        scanf("%d",&c[i].account_number);

        printf("\nEnter the balance in the account of customer %d:",i+1);
        scanf("%f",&c[i].balance);
    }

    //displaying options
    do{
        printf("\n\n***Banking Record System***");
        printf("\n1. Display all accounts");
        printf("\n2. Add a new account");
        printf("\n3. Delete an existing account");
        printf("\n4. Do a transaction");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                display(c,n);
                break;
            case 2:
                add_account(c,n);
                n++;
                break;
            case 3:
                delete_account(c,n);
                n--;
                break;
            case 4:
                transaction(c,n);
                break;
            case 5:
                exit(0);
            default:
                printf("\nPlease enter a valid option!");
                break;
        }
    }while(option!=5);
    return 0;
}

//function to display all accounts
void display(struct customer c[],int n){
    int i;
    printf("\n\n***All Accounts***\n");
    for(i=0;i<n;i++){
        printf("\nName of the customer %d: %s",i+1,c[i].name);
        printf("\nAccount number of the customer %d: %d",i+1,c[i].account_number);
        printf("\nBalance in the account of customer %d: %.2f\n",i+1,c[i].balance);
    }
}

//function to add a new account
void add_account(struct customer c[],int n){
    printf("\nEnter the name of the customer:");
    scanf("%s",&c[n].name);

    printf("\nEnter the account number of the customer:");
    scanf("%d",&c[n].account_number);

    printf("\nEnter the balance in the account of customer:");
    scanf("%f",&c[n].balance);

    printf("\n\nAccount added successfully!");
}

//function to delete an existing account
void delete_account(struct customer c[],int n){
    int i,account_number,flag=0;

    printf("\nEnter the account number to be deleted:");
    scanf("%d",&account_number);

    //checking if the account exists or not
    for(i=0;i<n;i++){
        if(c[i].account_number==account_number){
            flag=1;
            break;
        }
    }

    if(flag==1){
        //shifting elements to delete the account
        for(i=0;i<n;i++){
            if(c[i].account_number==account_number){
                for(int j=i;j<n-1;j++){
                    strcpy(c[j].name,c[j+1].name);
                    c[j].account_number=c[j+1].account_number;
                    c[j].balance=c[j+1].balance;
                }
                break;
            }
        }
        printf("\n\nAccount deleted successfully!");
    }
    else{
        printf("\n\nAccount not found!");
    }
}

//function to do a transaction
void transaction(struct customer c[],int n){
    int i,account_number,flag=0,option;
    float amount;

    printf("\nEnter the account number:");
    scanf("%d",&account_number);

    //checking if the account exists or not
    for(i=0;i<n;i++){
        if(c[i].account_number==account_number){
            flag=1;
            break;
        }
    }

    if(flag==1){
        //displaying transaction options
        printf("\n\n***Transaction Options***");
        printf("\n1. Deposit");
        printf("\n2. Withdraw");
        printf("\n\nEnter your choice: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("\nEnter the amount to be deposited:");
                scanf("%f",&amount);
                c[i].balance+=amount;
                printf("\n\nAmount deposited successfully! Current balance: %.2f",c[i].balance);
                break;
            case 2:
                printf("\nEnter the amount to be withdrawn:");
                scanf("%f",&amount);
                if(c[i].balance<amount){
                    printf("\n\nInsufficient balance!");
                }
                else{
                    c[i].balance-=amount;
                    printf("\n\nAmount withdrawn successfully! Current balance: %.2f",c[i].balance);
                }
                break;
            default:
                printf("\nPlease enter a valid option!");
                break;
        }
    }
    else{
        printf("\n\nAccount not found!");
    }
}