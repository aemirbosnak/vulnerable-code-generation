//FormAI DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored

// Structure to hold banking records
struct BankingRecord {
    char name[100];
    char accountNumber[50];
    float balance;
};

// Function to add a new record
int addRecord(struct BankingRecord records[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Maximum number of records reached\n");
        return count;
    }

    printf("Enter Name: ");
    scanf("%s", records[count].name);

    printf("Enter Account Number: ");
    scanf("%s", records[count].accountNumber);

    printf("Enter Balance: ");
    scanf("%f", &records[count].balance);

    count++;

    printf("Record added successfully\n");

    return count;
}

// Function to search for a record by name
void searchRecord(struct BankingRecord records[], int count)
{
    char name[100];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %s\n", records[i].accountNumber);
            printf("Balance: %.2f\n", records[i].balance);
            return;
        }
    }

    printf("Record not found\n");
}

// Function to display all records
void displayRecords(struct BankingRecord records[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %s\n", records[i].accountNumber);
        printf("Balance: %.2f\n", records[i].balance);
        printf("--------------\n");
    }
}

int main()
{
    struct BankingRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    printf("Welcome to Banking Record System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addRecord(records, count);
                break;
            case 2:
                searchRecord(records, count);
                break;
            case 3:
                displayRecords(records, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}