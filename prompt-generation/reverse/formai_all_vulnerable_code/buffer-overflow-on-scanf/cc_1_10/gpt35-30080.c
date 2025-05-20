//FormAI DATASET v1.0 Category: Banking Record System ; Style: calm
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure for keeping banking records
typedef struct{
    char accountNo[25];
    char accountName[50];
    float balance;
} BankRecord;

int main(){
    //initialize the variables
    int i, j, numAccounts;
    float maxBalance=0, minBalance=999999999;
    char temp[50];
    BankRecord bankAccounts[100];
    
    printf("Welcome to the Banking Record System.\n");
    printf("Please enter the number of accounts you want to create (maximum 100): ");
    scanf("%d", &numAccounts);
    
    //create accounts
    for(i=0; i<numAccounts; i++){
        printf("\nCreating Account No.%d\n", i+1);
        printf("Please enter the account number (up to 25 characters): ");
        scanf("%s", bankAccounts[i].accountNo);
        printf("Please enter the account holder name (up to 50 characters): ");
        scanf("%s", bankAccounts[i].accountName);
        printf("Please enter the balance for the account: ");
        scanf("%f", &bankAccounts[i].balance);
        
        if(bankAccounts[i].balance > maxBalance){
            maxBalance = bankAccounts[i].balance;
            strcpy(temp, bankAccounts[i].accountNo);
        }
        if(bankAccounts[i].balance < minBalance){
            minBalance = bankAccounts[i].balance;
        }
    }
    
    //display the banking records
    printf("\nBanking Records\n");
    printf("-------------------------------------------------------------\n");
    for(i=0; i<numAccounts; i++){
        printf("Account No.%d\n", i+1);
        printf("Account Number: %s\n", bankAccounts[i].accountNo);
        printf("Account Holder Name: %s\n", bankAccounts[i].accountName);
        printf("Account Balance: $%.2f\n", bankAccounts[i].balance);
        printf("-------------------------------------------------------------\n");
    }
    
    //display the account with the highest balance
    printf("\nAccount with the highest balance\n");
    printf("Account Number: %s\n", temp);
    printf("Account Balance: $%.2f\n", maxBalance);
    
    //display the account with the lowest balance
    printf("\nAccount with the lowest balance\n");
    for(i=0; i<numAccounts; i++){
        if(bankAccounts[i].balance == minBalance){
            printf("Account Number: %s\n", bankAccounts[i].accountNo);
            printf("Account Balance: $%.2f\n", minBalance);
            break;
        }
    }
    
    return 0;
}