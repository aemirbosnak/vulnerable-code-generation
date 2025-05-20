//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 100

// Structure to hold banking record data
typedef struct {
    int account_number;
    char first_name[25];
    char last_name[25];
    double balance;
} BankingRecord;

// Functions declarations
void addRecord(BankingRecord records[], int* num_records);
void printRecords(BankingRecord records[], int num_records);
void saveRecords(BankingRecord records[], int num_records);
int loadRecords(BankingRecord records[]);

int main(void) {
    int num_records = 0;
    BankingRecord records[MAX_NUM_RECORDS];

    num_records = loadRecords(records);

    printf("Welcome to the Banking Record System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new record\n");
        printf("2. Print all records\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                addRecord(records, &num_records);
                break;
            }
            case 2: {
                printRecords(records, num_records);
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                saveRecords(records, num_records);
                exit(0);
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    }

    return 0;
}

void addRecord(BankingRecord records[], int* num_records) {
    if (*num_records == MAX_NUM_RECORDS) {
        printf("The maximum number of records have been reached.\n");
        return;
    }

    BankingRecord newRecord;

    printf("Please enter the account number: ");
    scanf("%d", &newRecord.account_number);

    printf("Please enter the first name: ");
    scanf("%s", newRecord.first_name);

    printf("Please enter the last name: ");
    scanf("%s", newRecord.last_name);

    printf("Please enter the balance: ");
    scanf("%lf", &newRecord.balance);

    records[*num_records] = newRecord;

    (*num_records)++;

    printf("Record added successfully.\n");
}

void printRecords(BankingRecord records[], int num_records) {
    if (num_records == 0) {
        printf("No records to print.\n");
        return;
    }

    printf("%-15s %-15s %-15s %-15s\n", "Account #", "First Name", "Last Name", "Balance");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < num_records; i++) {
        printf("%-15d %-15s %-15s %-15.2f\n",
               records[i].account_number,
               records[i].first_name,
               records[i].last_name,
               records[i].balance);
    }
}

void saveRecords(BankingRecord records[], int num_records) {
    FILE* fp = fopen("records.dat", "wb");

    fwrite(records, sizeof(BankingRecord), num_records, fp);

    fclose(fp);
}

int loadRecords(BankingRecord records[]) {
    FILE* fp = fopen("records.dat", "rb");

    if (fp == NULL) {
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long num_bytes = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int num_records = num_bytes / sizeof(BankingRecord);

    fread(records, sizeof(BankingRecord), num_records, fp);

    fclose(fp);

    return num_records;
}