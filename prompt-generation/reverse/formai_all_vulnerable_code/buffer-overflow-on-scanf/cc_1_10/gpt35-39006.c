//FormAI DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int accountNum;
    char name[50];
    double balance;
} Record;

void displayMenu();
void addRecord(Record records[], int *numRecords);
void viewRecords(Record records[], int numRecords);
void saveRecords(Record records[], int numRecords);

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    char option;

    do {
        displayMenu();
        printf("Enter your option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
            addRecord(records, &numRecords);
            break;
            case '2':
            viewRecords(records, numRecords);
            break;
            case '3':
            saveRecords(records, numRecords);
            break;
            case '4':
            printf("Exiting program...");
            break;
            default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    } while(option != '4');

    return 0;
}

void displayMenu() {
    printf("\n---Banking Record System---\n");
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Save records to file\n");
    printf("4. Exit\n");
}

void addRecord(Record records[], int *numRecords) {
    if(*numRecords >= MAX_RECORDS) {
        printf("Maximum number of records reached\n");
        return;
    }

    Record newRecord;

    printf("\nEnter account number: ");
    scanf("%d", &newRecord.accountNum);
    getchar(); // consume newline character

    printf("Enter name: ");
    fgets(newRecord.name, 50, stdin);

    char *newline = strchr(newRecord.name, '\n');
    if (newline) {
        *newline = '\0';
    }

    printf("Enter balance: ");
    scanf("%lf", &newRecord.balance);
    records[*numRecords] = newRecord;
    *numRecords += 1;

    printf("\nRecord successfully added!\n");
}

void viewRecords(Record records[], int numRecords) {
    if(numRecords == 0) {
        printf("\nNo records to view\n");
        return;
    }

    printf("\n---Records---\n");

    for(int i = 0; i < numRecords; i++) {
        printf("Account number: %d\n", records[i].accountNum);
        printf("Name: %s\n", records[i].name);
        printf("Balance: %0.2lf\n", records[i].balance);
        printf("\n");
    }
}

void saveRecords(Record records[], int numRecords) {
    if(numRecords == 0) {
        printf("\nNo records to save\n");
        return;
    }

    FILE *fp;
    fp = fopen("bank_records.txt", "w");

    if(fp == NULL) {
        printf("Error opening file");
        return;
    }

    for(int i = 0; i < numRecords; i++) {
        fprintf(fp, "%d,%s,%0.2lf\n", records[i].accountNum, records[i].name, records[i].balance);
    }

    fclose(fp);
    printf("\nRecords successfully saved to file!\n");
}