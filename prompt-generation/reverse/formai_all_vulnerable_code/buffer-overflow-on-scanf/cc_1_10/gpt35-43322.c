//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the structure for a bank record
struct BankRecord
{
    char name[50];
    int accountNumber;
    float balance;
};

// function to add a new record to the database
void addRecord(struct BankRecord *record, int numRecords)
{
    printf("\nEnter the details for the new record:");

    printf("\nName: ");
    scanf("%s", record[numRecords].name);

    printf("Account Number: ");
    scanf("%d", &record[numRecords].accountNumber);

    printf("Balance: ");
    scanf("%f", &record[numRecords].balance);

    printf("\nRecord added!\n");
}

// function to display the records in the database
void displayRecords(struct BankRecord *record, int numRecords)
{
    printf("\n----------------- Records -----------------\n");

    for (int i = 0; i < numRecords; i++)
    {
        printf("\nRecord %d: \n", i+1);
        printf("Name: %s\n", record[i].name);
        printf("Account Number: %d\n", record[i].accountNumber);
        printf("Balance: %.2f\n", record[i].balance);
    }
}

// main function
int main()
{
    struct BankRecord *record; // pointer to a bank record
    int numRecords = 0; // initializing the number of records

    printf("Welcome to the Banking Record System!\n");

    while (1)
    {
        printf("\nWhat would you like to do?\n1. Add a record\n2. Display all records\n3. Exit\nChoice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                numRecords++;
                record = (struct BankRecord*) realloc(record, numRecords * sizeof(struct BankRecord));
                addRecord(record, numRecords-1);
                break;

            case 2:
                if (numRecords == 0)
                {
                    printf("\nThere are no records to display!\n");
                }
                else
                {
                    displayRecords(record, numRecords);
                }
                break;

            case 3:
                printf("\nExiting the program...\n");
                free(record);
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}