//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

//Define account structure
typedef struct account{
    //define properties
    char name[50];
    int account_number;
    double balance;
}account;
// create an array of accounts
account accounts[100];
int num_accounts = 0;


// function to create a new account
void create_account(){
    //Get the account details from the user
    printf("Enter your name: ");
    gets(accounts[num_accounts].name);
    printf("Enter your account number: ");
    scanf("%d", &accounts[num_accounts].account_number);
    printf("Enter your initial balance: ");
    scanf("%lf", &accounts[num_accounts].balance);
    //Increment the number of accounts
    num_accounts++;
}
// function to display account details
void display_account_details(int account_number){
    //find the account based on account number
    int index = -1;
    for(int i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        printf("Account not found.\n");
        return;
    }
    
    //printf account details
    printf("Name: %s \n", accounts[index].name);
    printf("Account Number: %d \n", accounts[index].account_number);
    printf("Balance: %0.2lf \n", accounts[index].balance);
}

// function to deposit money
void deposit_money(int account_number, double amount){
    //find the account based on account number
    int index = -1;
    for(int i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        printf("Account not found.\n");
        return;
    }
    
    //deposit the amount
    accounts[index].balance += amount;
    printf("amount deposited successfully.\n");
    
}

// function to withdraw money
void withdraw_money(int account_number, double amount){
    //find the account based on account number
    int index = -1;
    for(int i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        printf("Account not found.\n");
        return;
    }
    
    //withdraw the amount
    if(accounts[index].balance >= amount){
        accounts[index].balance -= amount;
        printf("Amount withdrawn successfully.\n");
    } else {
        printf("Insufficient balance.\n");
    }
    
}

int main(){
    printf("\t\t\t\t\t\t\t\t\t\tWelcome to the Banking Record System\n");
    printf("\t\t\t\t\t\t\t\t\t\t------------------------\n");
    int choice;
    
    do{
        
        printf("\nPlease select an option from the following:\n");
        printf("1. Create a new account\n");
        printf("2. Display account details\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                printf("Enter your account number: ");
                int acc_num;
                scanf("%d", &acc_num);
                display_account_details(acc_num);
                break;
            case 3:
                printf("Enter your account number: ");
                int acc_num1;
                scanf("%d", &acc_num1);
                printf("Enter the amount to deposit: ");
                double amount;
                scanf("%lf", &amount);
                deposit_money(acc_num1, amount);
                break;
            case 4:
                printf("Enter your account number: ");
                int acc_num2;
                scanf("%d", &acc_num2);
                printf("Enter the amount to withdraw: ");
                double amount2;
                scanf("%lf", &amount2);
                withdraw_money(acc_num2, amount2);
                break;
            case 5:
                printf("Thank you for using Banking Record System. Exiting now...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        
    }while(choice != 5);
    
    return 0;
}