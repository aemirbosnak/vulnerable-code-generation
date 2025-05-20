//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char accountNumber[20];
    char accountHolderName[100];
    float accountBalance;
} BankRecord;

void addNewRecord(BankRecord *record, int size)
{
    printf("\nEnter account number: ");
    scanf("%s", record[size].accountNumber);
    printf("\nEnter account holder name: ");
    scanf("%s", record[size].accountHolderName);
    printf("\nEnter account balance: ");
    scanf("%f", &record[size].accountBalance);
}

void deleteRecord(BankRecord *record, char *accountNumber, int *size)
{
    int i, j;
    for(i = 0; i < *size; i++)
    {
        if(strcmp(accountNumber, record[i].accountNumber) == 0)
        {
            for(j = i; j < *size-1; j++)
            {
                strcpy(record[j].accountNumber, record[j+1].accountNumber);
                strcpy(record[j].accountHolderName, record[j+1].accountHolderName);
                record[j].accountBalance = record[j+1].accountBalance;
            }
            (*size)--;
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void printRecords(BankRecord *record, int size)
{
    int i;
    printf("\nAccount\t\tName\t\tBalance\n");
    for(i = 0; i < size; i++)
    {
        printf("%s\t\t%s\t\t$%.2f\n", record[i].accountNumber, record[i].accountHolderName, record[i].accountBalance);
    }
}

void sortRecords(BankRecord *record, int size)
{
    int i, j;
    BankRecord temp;
    for(i = 0; i < size-1; i++)
    {
        for(j = i+1; j < size; j++)
        {
            if(record[i].accountBalance < record[j].accountBalance)
            {
                temp = record[i];
                record[i] = record[j];
                record[j] = temp;
            }
        }
    }
}

void menu()
{
    printf("\n1. Add new record");
    printf("\n2. Delete a record");
    printf("\n3. Print all records");
    printf("\n4. Sort by account balance");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

int main()
{
    BankRecord *record;
    int size = 0, choice;
    record = malloc(sizeof(BankRecord));
    do
    {
        menu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                size++;
                record = realloc(record, sizeof(BankRecord) * (size+1));
                addNewRecord(record, size-1);
                break;
            case 2:
                if(size == 0)
                {
                    printf("\nNo records available!\n");
                }
                else
                {
                    char accountNumber[20];
                    printf("\nEnter account number to delete: ");
                    scanf("%s", accountNumber);
                    deleteRecord(record, accountNumber, &size);
                    record = realloc(record, sizeof(BankRecord) * (size+1));
                }
                break;
            case 3:
                if(size == 0)
                {
                    printf("\nNo records available!\n");
                }
                else
                {
                    printRecords(record, size);
                }
                break;
            case 4:
                if(size == 0)
                {
                    printf("\nNo records available!\n");
                }
                else
                {
                    sortRecords(record, size);
                }
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 5);
    free(record);
    return 0;
}