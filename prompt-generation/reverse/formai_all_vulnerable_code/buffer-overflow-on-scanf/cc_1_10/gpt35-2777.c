//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct bank_record {
    int account_number;
    char name[50];
    float balance;
};
typedef struct bank_record BankRecord;

void addRecord(BankRecord *records, int *num_records) {
    printf("\nEnter account number:\t");
    scanf("%d", &records[*num_records].account_number);
    printf("Enter name:\t");
    scanf("%s", records[*num_records].name);
    printf("Enter balance:\t");
    scanf("%f", &records[*num_records].balance);
    (*num_records)++;
    printf("\nRecord added successfully!\n\n");
}

void deleteRecord(BankRecord *records, int *num_records) {
    int account_number, i, index = -1;
    printf("\nEnter account number to delete:\t");
    scanf("%d", &account_number);
    for (i = 0; i < *num_records; i++) {
        if (records[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        for (i = index; i < *num_records - 1; i++) {
            records[i] = records[i+1];
        }
        (*num_records)--;
        printf("\nRecord deleted successfully!\n\n");
    }
    else {
        printf("\nRecord not found!\n\n");
    }
}

void displayRecords(BankRecord *records, int num_records) {
    int i;
    printf("\n%-20s%-20s%-20s\n\n", "Account Number", "Name", "Balance");
    for (i = 0; i < num_records; i++) {
        printf("%-20d%-20s%-20.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
    printf("\n");
}

int main() {
    int choice, num_records = 0, max_records = 10;
    BankRecord *records = (BankRecord*)malloc(max_records*sizeof(BankRecord));
    do {
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Display record\n");
        printf("4. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (num_records >= max_records) {
                    max_records *= 2;
                    records = (BankRecord*)realloc(records, max_records*sizeof(BankRecord));
                }
                addRecord(records, &num_records);
                break;
            case 2:
                deleteRecord(records, &num_records);
                break;
            case 3:
                displayRecords(records, num_records);
                break;
            case 4:
                printf("\nExiting program...\n\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n\n");
                break;
        }
    } while (choice != 4);
    free(records);
    return 0;
}