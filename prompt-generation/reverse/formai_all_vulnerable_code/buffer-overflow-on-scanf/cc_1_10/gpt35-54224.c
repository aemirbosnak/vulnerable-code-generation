//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct {
    int account_no;
    char name[30];
    float balance;
} Account;

void showMenu()
{
    printf("\n[1] Add Account");
    printf("\n[2] View Account Details");
    printf("\n[3] Search Account");
    printf("\n[4] Update Account");
    printf("\n[5] Delete Account");
    printf("\n[6] Exit");
    printf("\nEnter your choice : ");
}

void addAccount(Account *acc, int *count)
{
    printf("\nEnter account number : ");
    scanf("%d", &acc[*count].account_no);
    printf("\nEnter account holder name : ");
    scanf("%s", acc[*count].name);
    printf("\nEnter account balance : ");
    scanf("%f", &acc[*count].balance);
    (*count)++;
    printf("\nAccount added successfully!");
}

void viewDetails(Account *acc, int count)
{
    int accountNo, i, flag=0;
    printf("\nEnter account number to view details : ");
    scanf("%d", &accountNo);
    for(i=0;i<count;i++)
    {
        if(acc[i].account_no==accountNo)
        {
            printf("\n=======================================");
            printf("\nAccount Number : %d", acc[i].account_no);
            printf("\nAccount Holder Name : %s", acc[i].name);
            printf("\nAccount Balance : %.2f", acc[i].balance);
            printf("\n=======================================");
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nAccount not found!");
}

void searchAccount(Account *acc, int count)
{
    char searchName[30];
    int i, flag=0;
    printf("\nEnter name to search account : ");
    scanf("%s", searchName);
    for(i=0;i<count;i++)
    {
        if(strcmp(acc[i].name, searchName)==0)
        {
            printf("\n=======================================");
            printf("\nAccount Number : %d", acc[i].account_no);
            printf("\nAccount Holder Name : %s", acc[i].name);
            printf("\nAccount Balance : %.2f", acc[i].balance);
            printf("\n=======================================");
            flag=1;
        }
    }
    if(flag==0)
        printf("\nSearch result not found!");
}

void updateAccount(Account *acc, int count)
{
    int accountNo, i, flag=0;
    printf("\nEnter account number to update details : ");
    scanf("%d", &accountNo);
    for(i=0;i<count;i++)
    {
        if(acc[i].account_no==accountNo)
        {
            printf("\nEnter account holder name : ");
            scanf("%s", acc[i].name);
            printf("\nEnter account balance : ");
            scanf("%f", &acc[i].balance);
            flag=1;
            printf("\nAccount details updated successfully!");
            break;
        }
    }
    if(flag==0)
        printf("\nAccount not found!");
}

void deleteAccount(Account *acc, int *count)
{
    int accountNo, i, flag=0;
    printf("\nEnter account number to delete account : ");
    scanf("%d", &accountNo);
    for(i=0;i<*count;i++)
    {
        if(acc[i].account_no==accountNo)
        {
            acc[i] = acc[*count-1];
            (*count)--;
            flag=1;
            printf("\nAccount deleted successfully!");
            break;
        }
    }
    if(flag==0)
        printf("\nAccount not found!");
}

int main()
{
    int choice, count=0;
    Account acc[MAX];
    do
    {
        showMenu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addAccount(acc, &count);
                break;
            case 2:
                viewDetails(acc, count);
                break;
            case 3:
                searchAccount(acc, count);
                break;
            case 4:
                updateAccount(acc, count);
                break;
            case 5:
                deleteAccount(acc, &count);
                break;
            case 6:
                break;
            default:
                printf("\nInvalid Choice!");
        }
    }while(choice!=6);
    return 0;
}