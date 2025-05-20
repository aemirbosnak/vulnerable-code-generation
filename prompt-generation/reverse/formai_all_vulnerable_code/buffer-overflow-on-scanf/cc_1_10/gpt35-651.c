//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
    int account_number;
    float balance;
}account;

void display(account acc){
    printf("\n*************************\n");
    printf("Name: %s\n",acc.name);
    printf("Account Number: %d\n",acc.account_number);
    printf("Balance: %.2f\n",acc.balance);
    printf("*************************\n");
}

int main(){
    account accounts[10];
    int i=0,n=0;
    printf("\nHi there! Welcome to our Bank.");
    while(1){
        int choice;
        printf("\n\nWhat would you like to do? Please choose the option\n");
        printf("1.Open a new bank account\n2.Deposit money to an account\n3.Withdraw money from an account\n4.Check account information\n5.Exit\n\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:{//Opening a new account
                account acc;
                printf("Please enter your name: ");
                scanf(" %[^\n]s",acc.name);
                printf("Please enter your account number: ");
                scanf("%d",&acc.account_number);
                printf("Please enter the initial deposit amount: ");
                scanf("%f",&acc.balance);
                accounts[n]=acc;
                printf("\nAccount created successfully! Your account number is %d.\n",acc.account_number);
                n++;
                break;
            }

            case 2:{//Depositing money to an account
                int acc_no;
                float amount;
                printf("Please enter your account number: ");
                scanf("%d",&acc_no);
                for(i=0;i<n;i++){
                    if(accounts[i].account_number==acc_no){
                        printf("Please enter the amount you want to deposit: ");
                        scanf("%f",&amount);
                        accounts[i].balance+=amount;
                        printf("\nDeposit Successful! Your current balance is %.2f",accounts[i].balance);
                        break;
                    }
                }
                if(i==n){
                    printf("\nSorry, no account found with the given account number.\n");
                }
                break;
            }

            case 3:{//Withdrawing money from an account
                int acc_no;
                float amount;
                printf("Please enter your account number: ");
                scanf("%d",&acc_no);
                for(i=0;i<n;i++){
                    if(accounts[i].account_number==acc_no){
                        printf("Please enter the amount you want to withdraw: ");
                        scanf("%f",&amount);
                        if(amount<=accounts[i].balance){
                            accounts[i].balance-=amount;
                            printf("\nWithdrawal Successful! Your current balance is %.2f",accounts[i].balance);
                        }
                        else{
                            printf("\nSorry, you do not have sufficient balance to make this transaction.\n");
                        }
                        break;
                    }
                }
                if(i==n){
                    printf("\nSorry, no account found with the given account number.\n");
                }
                break;
            }

            case 4:{//Checking account information
                int acc_no;
                printf("Please enter your account number: ");
                scanf("%d",&acc_no);
                for(i=0;i<n;i++){
                    if(accounts[i].account_number==acc_no){
                        display(accounts[i]);
                        break;
                    }
                }
                if(i==n){
                    printf("\nSorry, no account found with the given account number.\n");
                }
                break;
            }

            case 5://Quitting the program
                printf("\n\nThank you for banking with us!\n\n");
                exit(0);

            default://Invalid choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}