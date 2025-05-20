//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bankRecords
{
    int accountNumber;
    char name[50];
    float balance;
}bankRecord;

void displayRecords(bankRecord *records, int size)
{
    printf("\nBANK RECORDS:");
    printf("\n----------------------------------------------------------");
    printf("\nAccount Number\t\tName\t\t\tBalance");
    printf("\n----------------------------------------------------------");
    for(int i=0; i<size; i++)
    {
        printf("\n%d\t\t\t%s\t\t\t%f", records[i].accountNumber, records[i].name, records[i].balance);
    }
    printf("\n----------------------------------------------------------");
}

void searchRecord(bankRecord *records, int size)
{
    int accNo, flag=0;
    printf("\nEnter account number to search: ");
    scanf("%d", &accNo);
    for(int i=0; i<size; i++)
    {
        if(records[i].accountNumber == accNo)
        {
            printf("\n%s's balance is %f.", records[i].name, records[i].balance);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nRecord not found.");
    }
}

void addRecord(bankRecord *records, int *size)
{
    (*size)++;
    records = (bankRecord*)realloc(records, (*size)*sizeof(bankRecord));
    printf("\nEnter details of new record:\n");
    printf("Account Number: ");
    scanf("%d", &records[*size-1].accountNumber);
    printf("Name: ");
    scanf("%s", records[*size-1].name);
    printf("Balance: ");
    scanf("%f", &records[*size-1].balance);
    printf("\nRecord added successfully!");
}

void deleteRecord(bankRecord *records, int *size)
{
    int accNo, flag=0;
    printf("\nEnter account number to delete record: ");
    scanf("%d", &accNo);
    for(int i=0; i<*size; i++)
    {
        if(records[i].accountNumber == accNo)
        {
            for(int j=i; j<*size-1; j++)
            {
                records[j] = records[j+1];
            }
            (*size)--;
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("\nRecord deleted successfully!");
    }
    else
    {
        printf("\nRecord not found.");
    }
}

int main()
{
    bankRecord *records;
    int size = 0, option;
    printf("\t\tWelcome to the Funny Bank!");
    printf("\n==========================================================\n");
    while(1)
    {
        printf("\nMENU:");
        printf("\n1. View bank records");
        printf("\n2. Search for a record");
        printf("\n3. Add a new record");
        printf("\n4. Delete a record");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                if(size == 0)
                {
                    printf("\nNo records found.");
                }
                else
                {
                    displayRecords(records, size);
                }
                break;
            case 2:
                if(size == 0)
                {
                    printf("\nNo records found.");
                }
                else
                {
                    searchRecord(records, size);
                }
                break;
            case 3:
                addRecord(records, &size);
                break;
            case 4:
                if(size == 0)
                {
                    printf("\nNo records found.");
                }
                else
                {
                    deleteRecord(records, &size);
                }
                break;
            case 5:
                printf("\nHope you enjoyed your funny banking experience!");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.");
        }
    }
    return 0;
}