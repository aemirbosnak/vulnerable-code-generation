//FormAI DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30], address[100], phone[11];
    int account_num, balance;
} BankRecord;

FILE* filePointer;

void createRecord() {
    BankRecord record;
    printf("Enter name: ");
    scanf("%s", record.name);

    printf("Enter address: ");
    scanf("%s", record.address);

    printf("Enter phone number: ");
    scanf("%s", record.phone);

    printf("Enter account number: ");
    scanf("%d", &record.account_num);

    printf("Enter initial balance: ");
    scanf("%d", &record.balance);

    fwrite(&record, sizeof(record), 1, filePointer);
    printf("Record added successfully!\n");
}

void searchRecord() {
    int accountNum;
    printf("Enter account number: ");
    scanf("%d", &accountNum);

    BankRecord record;
    int found = 0;
    while(fread(&record, sizeof(record), 1, filePointer)) {
        if(record.account_num == accountNum) {
            printf("Name: %s\n", record.name);
            printf("Address: %s\n", record.address);
            printf("Phone: %s\n", record.phone);
            printf("Account Number: %d\n", record.account_num);
            printf("Balance: %d\n", record.balance);
            found = 1;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
}

void updateRecord() {
    int accountNum;
    printf("Enter account number: ");
    scanf("%d", &accountNum);

    BankRecord record;
    int found = 0;
    while(fread(&record, sizeof(record), 1, filePointer)) {
        if(record.account_num == accountNum) {
            printf("Current name: %s\n", record.name);
            printf("Enter new name: ");
            scanf("%s", record.name);

            printf("Current address: %s\n", record.address);
            printf("Enter new address: ");
            scanf("%s", record.address);

            printf("Current phone: %s\n", record.phone);
            printf("Enter new phone: ");
            scanf("%s", record.phone);

            printf("Current balance: %d\n", record.balance);
            printf("Enter new balance: ");
            scanf("%d", &record.balance);

            fseek(filePointer, ftell(filePointer) - sizeof(record), SEEK_SET);
            fwrite(&record, sizeof(record), 1, filePointer);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
}

void deleteRecord() {
    int accountNum;
    printf("Enter account number: ");
    scanf("%d", &accountNum);

    BankRecord record;
    int found = 0;
    while(fread(&record, sizeof(record), 1, filePointer)) {
        if(record.account_num == accountNum) {
            printf("Do you want to delete the following record? (y/n)\n");
            printf("Name: %s\n", record.name);
            printf("Address: %s\n", record.address);
            printf("Phone: %s\n", record.phone);
            printf("Account Number: %d\n", record.account_num);
            printf("Balance: %d\n", record.balance);

            char choice;
            scanf("%s", &choice);
            if(choice == 'y') {
                fseek(filePointer, -sizeof(record), SEEK_CUR);
                BankRecord blankRecord = {0, "", "", 0, 0};
                fwrite(&blankRecord, sizeof(blankRecord), 1, filePointer);
                printf("Record deleted successfully!\n");
            }
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
}

int main() {
    char filename[] = "bankRecords.dat";
    filePointer = fopen(filename, "ab+");

    int choice;
    do {
        printf("\n\nBanking Record System\n");
        printf("1. Create Record\n");
        printf("2. Search Record\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createRecord();
                break;
            case 2:
                rewind(filePointer);
                searchRecord();
                break;
            case 3:
                rewind(filePointer);
                updateRecord();
                break;
            case 4:
                rewind(filePointer);
                deleteRecord();
                break;
            case 5:
                fclose(filePointer);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}