//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord {
    int account_number;
    char name[30];
    float balance;
};

void addRecord(struct BankRecord **records, int *numRecords) {
    int account_number;
    char name[30];
    float balance;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Balance: ");
    scanf("%f", &balance);
    // Creating a new BankRecord
    struct BankRecord *newRecord = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    newRecord->account_number = account_number;
    strcpy(newRecord->name, name);
    newRecord->balance = balance;
    // Updating the records array
    (*numRecords)++;
    *records = (struct BankRecord*)realloc(*records, (*numRecords)*sizeof(struct BankRecord));
    (*records)[*numRecords - 1] = *newRecord;
    printf("\nRecord Added Successfully\n");
}

void displayRecords(struct BankRecord *records, int numRecords) {
    if(numRecords == 0) {
        printf("\nNo Records Found!\n");
        return;
    }
    printf("\nAccount Number\tName\t\tBalance\n");
    for(int i=0;i<numRecords;i++) {
        printf("%d\t\t%s\t\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

void searchRecord(struct BankRecord *records, int numRecords) {
    if(numRecords == 0) {
        printf("\nNo Records Found!\n");
        return;
    }
    int account_number;
    printf("\nEnter Account Number to Search: ");
    scanf("%d", &account_number);
    for(int i=0;i<numRecords;i++) {
        if(records[i].account_number == account_number) {
            printf("\nRecord Found!\nAccount Number: %d\nName: %s\nBalance: %.2f\n", records[i].account_number, records[i].name, records[i].balance);
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

void deleteRecord(struct BankRecord **records, int *numRecords) {
    if(*numRecords == 0) {
        printf("\nNo Records Found!\n");
        return;
    }
    int account_number, index = -1;
    printf("\nEnter Account Number to Delete: ");
    scanf("%d", &account_number);
    for(int i=0;i<*numRecords;i++) {
        if((*records)[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nRecord Not Found!\n");
        return;
    }
    // Shifting the elements of records array
    for(int i=index;i<(*numRecords)-1;i++) {
        (*records)[i] = (*records)[i+1];
    }
    // Updating the records array
    (*numRecords)--;
    *records = (struct BankRecord*)realloc(*records, (*numRecords)*sizeof(struct BankRecord));
    printf("\nRecord Deleted Successfully\n");
}

int main() {
    // Initializing the records array
    struct BankRecord *records = NULL;
    int numRecords = 0;
    int choice;
    while(1) {
        printf("\n---------------------\n");
        printf("\nBank Record System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addRecord(&records, &numRecords);
                    break;
            case 2: displayRecords(records, numRecords);
                    break;
            case 3: searchRecord(records, numRecords);
                    break;
            case 4: deleteRecord(&records, &numRecords);
                    break;
            case 5: printf("\nThank You for using Bank Record System!\n");
                    exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}