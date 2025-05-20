//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct{
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_RECORDS];

int numAccounts = 0;

void addAccount(){
    if(numAccounts < MAX_RECORDS){
        Account acct;
        printf("\nEnter account number: ");
        scanf("%d", &acct.accountNumber);
        printf("Enter name: ");
        scanf(" %[^\n]", acct.name);
        printf("Enter balance: ");
        scanf("%f", &acct.balance);
        accounts[numAccounts] = acct;
        numAccounts++;
        printf("\nAccount added successfully!\n");
    } else{
        printf("\nSorry, maximum number of accounts reached.\n");
    }
}

void printAccount(Account acct){
    printf("\nAccount Number: %d", acct.accountNumber);
    printf("\nName: %s", acct.name);
    printf("\nBalance: $%.2f\n", acct.balance);
}

void displayAccounts(){
    printf("\n--- All accounts ---\n");
    if(numAccounts == 0){
        printf("\nNo accounts to display.\n");   
    } else{
        for(int i=0; i<numAccounts; i++){
            printf("\n%d. ", i+1);
            printAccount(accounts[i]);
        }
    }
}

void search(){
    int accountNumber;
    printf("\nEnter account number to search: ");
    scanf("%d", &accountNumber);
    int found = 0;
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            found = 1;
            printf("\nAccount found!\n");
            printAccount(accounts[i]);
            break;
        }
    }
    if(!found){
        printf("\nSorry, account not found.\n");
    }
}

void deposit(){
    int accountNumber;
    printf("\nEnter account number to deposit into: ");
    scanf("%d", &accountNumber);
    int found = 0;
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            printf("\nEnter amount to deposit: ");
            float amt;
            scanf("%f", &amt);
            accounts[i].balance += amt;
            found = 1;
            printf("\nDeposit successful!\n");
            break;
        }
    }
    if(!found){
        printf("\nSorry, account not found.\n");
    }
}

void withdraw(){
    int accountNumber;
    printf("\nEnter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    int found = 0;
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            printf("\nEnter amount to withdraw: ");
            float amt;
            scanf("%f", &amt);
            if(amt > accounts[i].balance){
                printf("\nSorry, insufficient balance.\n");
            } else{
                accounts[i].balance -= amt;
                found = 1;
                printf("\nWithdrawal successful!\n");
            }
            break;
        }
    }
    if(!found){
        printf("\nSorry, account not found.\n");
    }
}

void saveToFile(){
    FILE *fptr;
    fptr = fopen("accounts.txt", "w");
    for(int i=0; i<numAccounts; i++){
        fprintf(fptr, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    fclose(fptr);
    printf("\nAccounts saved to file.\n");
}

void loadFromFile(){
    FILE *fptr;
    fptr = fopen("accounts.txt", "r");
    if(fptr == NULL){
        printf("\nFile not found.\n");
    } else{
        int count = 0;
        while(!feof(fptr)){
            Account acct;
            fscanf(fptr, "%d %s %f", &acct.accountNumber, acct.name, &acct.balance);
            if(acct.accountNumber != 0){
                accounts[count] = acct;
                count++;
            }
        }
        numAccounts = count;
        printf("\nAccounts loaded from file.\n");
        fclose(fptr);
    }
}

int main(){
    int choice;
    printf("\nWelcome to the Banking Record System!\n");
    while(1){
        printf("\nPlease select an option:\n");
        printf("\n1. Add An Account");
        printf("\n2. Display All Accounts");
        printf("\n3. Search An Account");
        printf("\n4. Deposit Into An Account");
        printf("\n5. Withdraw From An Account");
        printf("\n6. Save To File");
        printf("\n7. Load From File");
        printf("\n8. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                search();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid choice entered. Please try again.\n");
        }
    }
    return 0;
}