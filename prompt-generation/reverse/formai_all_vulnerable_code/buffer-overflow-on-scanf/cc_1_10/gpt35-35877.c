//FormAI DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_ACCOUNTS 100

typedef struct{
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int account_number;
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS]; // array to store all bank accounts
int num_accounts = 0; // number of bank accounts currently stored in the array

// function prototypes
void addAccount();
void printAccount(int account_number);
void printAllAccounts();
void deposit(int account_number, float amount);
void withdraw(int account_number, float amount);
void deleteAccount(int account_number);

int main(){
    int choice, account_number;
    float amount;
    do{
        printf("\n\n========= Bank Record System =========");
        printf("\n1. Add Account");
        printf("\n2. Print Account");
        printf("\n3. Print All Accounts");
        printf("\n4. Deposit");
        printf("\n5. Withdraw");
        printf("\n6. Delete Account");
        printf("\nEnter your choice (0 to quit): ");
        scanf("%d", &choice);
        switch(choice){
            case 0: // quit the program
                printf("\nThank you for using the Bank Record System!");
                exit(0);
            case 1: // add account
                addAccount();
                break;
            case 2: // print account
                printf("\nEnter account number: ");
                scanf("%d", &account_number);
                printAccount(account_number);
                break;
            case 3: // print all accounts
                printAllAccounts();
                break;
            case 4: // deposit
                printf("\nEnter account number: ");
                scanf("%d", &account_number);
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 5: // withdraw
                printf("\nEnter account number: ");
                scanf("%d", &account_number);
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 6: // delete account
                printf("\nEnter account number: ");
                scanf("%d", &account_number);
                deleteAccount(account_number);
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    }while(1);
    return 0;
}

void addAccount(){
    BankAccount account;
    printf("\nEnter name: ");
    scanf(" %[^\n]s", account.name);
    printf("\nEnter address: ");
    scanf(" %[^\n]s", account.address);
    account.account_number = num_accounts + 1;
    account.balance = 0;
    accounts[num_accounts] = account;
    num_accounts++;
    printf("\nAccount added successfully!");
}

void printAccount(int account_number){
    int i;
    for(i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            printf("\nAccount Number: %d", accounts[i].account_number);
            printf("\nName: %s", accounts[i].name);
            printf("\nAddress: %s", accounts[i].address);
            printf("\nBalance: %.2f", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found. Please try again.");
}

void printAllAccounts(){
    int i;
    if(num_accounts == 0){
        printf("\nNo accounts added yet.");
        return;
    }
    printf("\n===================================================================");
    printf("\n%-10s %-20s %-50s %-10s", "Acc. No.", "Name", "Address", "Balance");
    printf("\n===================================================================");
    for(i = 0; i < num_accounts; i++){
        printf("\n%-10d %-20s %-50s %-10.2f", accounts[i].account_number, accounts[i].name, accounts[i].address, accounts[i].balance);
    }
}

void deposit(int account_number, float amount){
    int i;
    for(i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            accounts[i].balance += amount;
            printf("\nDeposit successful!");
            printf("\nNew balance: %.2f", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found. Please try again.");
}

void withdraw(int account_number, float amount){
    int i;
    for(i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            if(accounts[i].balance >= amount){
                accounts[i].balance -= amount;
                printf("\nWithdrawal successful!");
                printf("\nNew balance: %.2f", accounts[i].balance);
            }
            else{
                printf("\nInsufficient balance. Please try again.");
            }
            return;
        }
    }
    printf("\nAccount not found. Please try again.");
}

void deleteAccount(int account_number){
    int i, j;
    for(i = 0; i < num_accounts; i++){
        if(accounts[i].account_number == account_number){
            for(j = i+1; j < num_accounts; j++){
                accounts[j-1] = accounts[j];
            }
            num_accounts--;
            printf("\nAccount deleted successfully!");
            return;
        }
    }
    printf("\nAccount not found. Please try again.");
}