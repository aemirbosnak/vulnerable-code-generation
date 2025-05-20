//FormAI DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define structures for Banking Record System
struct Account_Info {
    int account_no;
    char name[20];
    float balance;
};

typedef struct Account_Info account;

// Function Prototypes
void addAccount(account*, int*);
void printAllAccounts(account*, int);
void searchByAccount(account*, int);
void deleteAccount(account*, int*);

int main()
{
    account accounts[50];  // Define an array of accounts
    int n = 0, choice;
    char menu[] = "\n\nBanking Record System\n1. Add Account\n2. Print All Accounts\n3. Search by Account No.\n4. Delete Account\n0. Exit\nEnter Choice:";
    
    do {
        printf("%s", menu);
        scanf("%d", &choice);   // Take choice as input from the user
        
        switch(choice) {
            case 1: addAccount(accounts, &n); break;
            case 2: printAllAccounts(accounts, n); break;
            case 3: searchByAccount(accounts, n); break;
            case 4: deleteAccount(accounts, &n); break;
            case 0: printf("\nExiting...\n"); exit(0);  // Exit the program
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    } while(choice != 0);
    
    return 0;
}

// Function to add an account
void addAccount(account* accounts, int* n)
{
    account acc;
    printf("\nEnter Account No: "); scanf("%d", &acc.account_no);
    printf("Enter Name: "); scanf("%s", acc.name);
    printf("Enter Balance: "); scanf("%f", &acc.balance);
    
    accounts[*n] = acc;
    *n = *n + 1;    // Increment the number of accounts
    printf("\nAccount Added Successfully.\n");
}

// Function to print all accounts
void printAllAccounts(account* accounts, int n)
{
    printf("\n\nAll Accounts:\n");
    printf("================================================\n");
    printf("Account No.\t\tName\t\tBalance\n");
    printf("================================================\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d\t\t\t%s\t\t%.2f\n", accounts[i].account_no,accounts[i].name, accounts[i].balance);
    }
}

// Function to search for an account by account no.
void searchByAccount(account* accounts, int n)
{
    int acc_no;
    printf("\nEnter Account No to search: "); 
    scanf("%d", &acc_no);
    
    for(int i = 0; i < n; i++) {
        if(accounts[i].account_no == acc_no) {
            printf("Account Found:\n");
            printf("================================================\n");
            printf("Account No.\t\tName\t\tBalance\n");
            printf("================================================\n");
            printf("%d\t\t\t%s\t\t%.2f\n", accounts[i].account_no,accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account Not Found.\n");
}

// Function to delete an account
void deleteAccount(account* accounts, int* n) 
{
    int acc_no;
    printf("\nEnter Account No to delete: "); 
    scanf("%d", &acc_no);
    
    for(int i = 0; i < *n; i++) {
        if(accounts[i].account_no == acc_no) {
            for(int j = i; j < *n-1; j++) {
                accounts[j] = accounts[j+1];    // Shift all accounts left
            }
            *n = *n - 1;    // Decrement the number of accounts
            printf("Account Deleted Successfully.\n");
            return;
        }
    }
    printf("Account Not Found.\n");
}