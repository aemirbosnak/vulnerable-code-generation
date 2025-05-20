//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare a structure for account holders for the bank record system
struct account {
    int accNo;
    char accName[50];
    float accBal;
};

//Function prototypes
void displayMenu();
void addAccount();
void viewAccount();
void deleteAccount();
void updateAccount();
void searchAccount();

int main()
{
    int choice;
    while(1)
    {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                updateAccount();
                break;
            case 5:
                searchAccount();
                break;
            case 6:
                printf("\nThank you for using the Banking Record System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please choose a valid option.\n");
                break;
        }
    }
    return 0;
}

//Function definition for displaying menu for bank record system options
void displayMenu()
{
    printf("\n========= BANKING RECORD SYSTEM =========\n");
    printf("\n1. Add an account\n");
    printf("2. View all accounts\n");
    printf("3. Delete an account\n");
    printf("4. Update an account\n");
    printf("5. Search an account\n");
    printf("6. Exit\n");
}

//Function definition for adding a new account to the bank record system
void addAccount()
{
    struct account acc;
    FILE *fp;
    fp = fopen("bank_records.txt", "ab");
    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }
    printf("\nEnter account number: ");
    scanf("%d", &acc.accNo);
    printf("\nEnter account name: ");
    scanf("%s", &acc.accName);
    printf("\nEnter account balance: ");
    scanf("%f", &acc.accBal);
    fwrite(&acc, sizeof(struct account), 1, fp);
    fclose(fp);
    printf("\nAccount added successfully!\n");
}

//Function definition for viewing all accounts in the bank record system
void viewAccount()
{
    struct account acc;
    FILE *fp;
    fp = fopen("bank_records.txt", "rb");
    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }
    printf("\n=========================================\n");
    printf("%-15s%-30s%-15s\n","ACC NO.","ACC NAME","ACC BALANCE");
    printf("=========================================\n");
    while(fread(&acc, sizeof(struct account), 1, fp))
    {
        printf("%-15d%-30s%-15.2f\n",acc.accNo,acc.accName,acc.accBal);
    }
    printf("=========================================\n");
    fclose(fp);
}

//Function definition for deleting an account from the bank record system
void deleteAccount()
{
    struct account acc;
    int accNo;
    FILE *fp, *fpTemp;
    fp = fopen("bank_records.txt", "rb");
    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }
    printf("\nEnter account number to delete: ");
    scanf("%d", &accNo);
    fpTemp = fopen("temp.txt", "wb");
    while(fread(&acc, sizeof(struct account), 1, fp))
    {
        if(acc.accNo != accNo)
        {
            fwrite(&acc, sizeof(struct account), 1, fpTemp);
        }
    }
    fclose(fp);
    fclose(fpTemp);
    remove("bank_records.txt");
    rename("temp.txt", "bank_records.txt");
    printf("\nAccount deleted successfully!\n");
}

//Function definition for updating an account in the bank record system
void updateAccount()
{
    struct account acc;
    int accNo, found=0;
    FILE *fp;
    fp = fopen("bank_records.txt", "r+b");
    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }
    printf("\nEnter account number to update: ");
    scanf("%d", &accNo);
    while(fread(&acc, sizeof(struct account), 1, fp))
    {
        if(acc.accNo == accNo)
        {
            printf("\nEnter updated account name: ");
            scanf("%s", &acc.accName);
            printf("\nEnter updated account balance: ");
            scanf("%f", &acc.accBal);
            fseek(fp, -sizeof(struct account), SEEK_CUR);
            fwrite(&acc, sizeof(struct account), 1, fp);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("\nAccount not found!\n");
    }
    else
    {
        printf("\nAccount updated successfully!\n");
    }
    fclose(fp);
}

//Function definition for searching an account in the bank record system
void searchAccount()
{
    struct account acc;
    int accNo, found=0;
    FILE *fp;
    fp = fopen("bank_records.txt", "rb");
    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }
    printf("\nEnter account number to search: ");
    scanf("%d", &accNo);
    while(fread(&acc, sizeof(struct account), 1, fp))
    {
        if(acc.accNo == accNo)
        {
            printf("\n=========================================\n");
            printf("%-15s%-30s%-15s\n","ACC NO.","ACC NAME","ACC BALANCE");
            printf("=========================================\n");
            printf("%-15d%-30s%-15.2f\n",acc.accNo,acc.accName,acc.accBal);
            printf("=========================================\n");
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("\nAccount not found!\n");
    }
    fclose(fp);
}