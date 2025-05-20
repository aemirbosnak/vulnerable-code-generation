//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define a structure to store bank record information
typedef struct BankRecord
{
    char name[50];
    int accountNo;
    double balance;
    char accountType;
} BankRecord;

// Function to add a new bank record
void addRecord(BankRecord *record)
{
    printf("Enter your name: ");
    scanf("%s", record->name);

    printf("Enter your account number: ");
    scanf("%d", &record->accountNo);

    printf("Enter your initial balance: ");
    scanf("%lf", &record->balance);

    printf("Enter your account type (S/C/D): ");
    scanf(" %c", &record->accountType);
}

// Function to display bank records
void displayRecords(BankRecord *records, int numRecords)
{
    for (int i = 0; i < numRecords; i++)
    {
        printf("Name: %s\n", records[i].name);
        printf("Account No: %d\n", records[i].accountNo);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("Account Type: %c\n", records[i].accountType);
        printf("\n");
    }
}

// Main function
int main()
{
    // Create an array of bank records
    BankRecord *records = NULL;

    // Initialize the number of records to 0
    int numRecords = 0;

    // Add a new bank record
    addRecord(records);

    // Add another new bank record
    addRecord(records);

    // Display the bank records
    displayRecords(records, numRecords);

    return 0;
}