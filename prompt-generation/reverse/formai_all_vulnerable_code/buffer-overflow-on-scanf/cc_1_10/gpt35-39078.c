//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account
{
    int accountId;
    char accountName[20];
    int balance;
};

void printAccountInfo(struct account acc)
{
    printf("Account ID: %d\n", acc.accountId);
    printf("Account Name: %s\n", acc.accountName);
    printf("Balance: %d\n\n", acc.balance);
}

void searchByAccountId(int accountId, struct account *acc, int numAccounts)
{
    int index=-1;
    for(int i=0;i<numAccounts;i++)
    {
        if(acc[i].accountId==accountId)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        printf("Account ID %d does not exist\n\n", accountId);
        return;
    }
    printf("Account Found!\n");
    printf("------------------\n");
    printAccountInfo(acc[index]);
}

void searchByAccountName(char accountName[], struct account *acc, int numAccounts)
{
    int index=-1;
    for(int i=0;i<numAccounts;i++)
    {
        if(strcmp(acc[i].accountName, accountName)==0)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        printf("Account Name %s does not exist\n\n", accountName);
        return;
    }
    printf("Account Found!\n");
    printf("------------------\n");
    printAccountInfo(acc[index]);
}

int main()
{
    struct account acc[10];
    int numAccounts=0;
    int option, accountId, balance, searchOption;
    char accountName[20];
    
    while(1)
    {
        printf("Hello, Welcome to the Banking Record System.\n\n");
        printf("1. Add Account\n");
        printf("2. Search Account by ID\n");
        printf("3. Search Account by Name\n");
        printf("4. Exit\n\n");
        
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter Account ID: ");
                scanf("%d", &acc[numAccounts].accountId);
                
                printf("Enter Account Name: ");
                scanf("%s", acc[numAccounts].accountName);
                
                printf("Enter Balance: ");
                scanf("%d", &acc[numAccounts].balance);
                
                printf("Account created successfully!\n\n");
                numAccounts++;
                break;
                
            case 2:
                printf("Enter Account ID: ");
                scanf("%d", &accountId);
                searchByAccountId(accountId, acc, numAccounts);
                break;
            
            case 3:
                printf("Enter Account Name: ");
                scanf("%s", accountName);
                searchByAccountName(accountName, acc, numAccounts);
                break;
                
            case 4:
                printf("Thank you for using the Banking Record System\n");
                exit(0);
                break;
                
            default:
                printf("Invalid Option, please try again.\n\n");
                break;
        }
    }
    return 0;
}