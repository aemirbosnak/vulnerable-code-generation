//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define MAX_ACCOUNTS 1000
#define MAX_NAME_LEN 50

// Struct to store Bank Account details
struct BankAccount{
    int accountNo;
    char name[MAX_NAME_LEN];
    float balance;
};

// Global Variables
struct BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to add a new account
void addNewAccount(){
    int accountNo;
    char name[MAX_NAME_LEN];
    float balance;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    // Check if account already exists
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            printf("Account %d already exists.\n", accountNo);
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Balance: ");
    scanf("%f", &balance);

    // Add new account to accounts array
    struct BankAccount newAccount;
    newAccount.accountNo = accountNo;
    strcpy(newAccount.name, name);
    newAccount.balance = balance;
    accounts[numAccounts++] = newAccount;

    printf("New Account Added Successfully.\n");
}

// Function to display all accounts
void displayAllAccounts(){
    if(numAccounts == 0){
        printf("No Accounts Found.\n");
        return;
    }
    printf("%-15s %-20s %s\n", "Account No.", "Name", "Balance");
    for(int i=0; i<numAccounts; i++){
        printf("%-15d %-20s $%.2f\n", accounts[i].accountNo, accounts[i].name, accounts[i].balance);
    }
}

// Function to search account by account number
void searchAccount(){
    int accountNo, found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            found = 1;
            printf("%-15s %-20s %s\n", "Account No.", "Name", "Balance");
            printf("%-15d %-20s $%.2f\n", accounts[i].accountNo, accounts[i].name, accounts[i].balance);
            break;
        }
    }
    if(!found){
        printf("Account %d not found.\n", accountNo);
    }
}

// Function to delete an account
void deleteAccount(){
    int accountNo, found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            found = 1;
            // Shift accounts array to delete the element
            for(int j=i; j<numAccounts-1; j++){
                accounts[j] = accounts[j+1];
            }
            numAccounts--;
            printf("Account %d deleted successfully.\n", accountNo);
            break;
        }
    }
    if(!found){
        printf("Account %d not found.\n", accountNo);
    }
}

// Function to update account balance
void updateBalance(){
    int accountNo, found = 0;
    float balance;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);
    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            found = 1;
            printf("Enter new Balance: ");
            scanf("%f", &balance);
            accounts[i].balance = balance;
            printf("Balance updated for Account %d.\n", accountNo);
            break;
        }
    }
    if(!found){
        printf("Account %d not found.\n", accountNo);
    }
}

// Main function
int main(){
    int option;
    do{
        printf("\n***** C BANKING RECORD SYSTEM *****\n");
        printf("1. Add New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Delete Account\n");
        printf("5. Update Balance\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addNewAccount();
                break;
            case 2:
                displayAllAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                updateBalance();
                break;
            case 6:
                printf("Thank you for using C BANKING RECORD SYSTEM.\n");
                break;
            default:
                printf("Invalid Option.\n");
        }
    } while(option != 6);

    return 0;
}