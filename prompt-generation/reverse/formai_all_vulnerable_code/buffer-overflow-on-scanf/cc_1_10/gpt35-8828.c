//FormAI DATASET v1.0 Category: Banking Record System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaring Global Variables
typedef struct account{
    char name[50];
    int account_number;
    float balance;
}acc;

acc account_list[100]; //The maximum limit for accounts
int num_accounts = 0; //Current number of accounts

//Function prototypes
void addAccount();
void displayAccounts();
void deposit();
void withdraw();
void updateRecord(int account_num, float change);

int main(){
    int choice;
    printf("Welcome to XYZ Bank,\n");
    do{
        printf("\nChoose an option:\n");
        printf("1. Add new account\n");
        printf("2. Display account details\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("\nThank you for using XYZ Banking System.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    }while(1);
}

//Function to add a new account
void addAccount(){
    printf("\nEnter the following details:\n");
    printf("Name: ");
    scanf("%s", account_list[num_accounts].name);
    printf("Account Number: ");
    scanf("%d", &account_list[num_accounts].account_number);
    printf("Balance: ");
    scanf("%f", &account_list[num_accounts].balance);

    num_accounts++;
    printf("\nAccount created successfully.\n");
}

//Function to display all accounts
void displayAccounts(){
    printf("\nAccount List:\n");
    printf("Name\t\tAccount Number\t\tBalance\n");
    for(int i=0; i<num_accounts; i++){
        printf("%s\t\t%d\t\t\t%.2f\n", account_list[i].name, account_list[i].account_number, account_list[i].balance);
    }
}

//Function to deposit an amount to an account
void deposit(){
    int acc_num;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &acc_num);

    for(int i=0; i<num_accounts; i++){
        if(account_list[i].account_number == acc_num){
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            account_list[i].balance += amount;
            updateRecord(acc_num, amount);
            printf("\nDeposit successful. Current balance: %.2f\n", account_list[i].balance);
            return;
        }
    }
    printf("\nAccount not found. Please try again.\n");
}

//Function to withdraw an amount from an account
void withdraw(){
    int acc_num;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &acc_num);

    for(int i=0; i<num_accounts; i++){
        if(account_list[i].account_number == acc_num){
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);
            if(account_list[i].balance >= amount){
                account_list[i].balance -= amount;
                updateRecord(acc_num, -amount);
                printf("\nWithdrawal successful. Current balance: %.2f\n", account_list[i].balance);
                return;
            }
            else{
                printf("\nInsufficient balance. Please try again.\n");
                return;
            }
        }
    }
    printf("\nAccount not found. Please try again.\n");
}

//Function to update record in a file
void updateRecord(int account_num, float change){
    char file_name[] = "record.txt"; //Name of the file
    FILE *fp;
    fp = fopen(file_name, "a"); //Open the file in append mode

    for(int i=0; i<num_accounts; i++){
        if(account_list[i].account_number == account_num){
            fprintf(fp, "%s\t%d\t%.2f\n", account_list[i].name, account_list[i].account_number, account_list[i].balance+change);
        }
    }
    fclose(fp);
}