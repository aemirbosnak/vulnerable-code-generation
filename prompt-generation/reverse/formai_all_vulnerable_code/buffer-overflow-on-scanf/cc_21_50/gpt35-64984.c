//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNo;
    char firstName[20];
    char lastName[20];
    float balance;
} bankRecord;

int main() {
    int choice;
    bankRecord* record;
    int numRecords = 0;
    FILE* fp;

    fp = fopen("bank_records.txt", "r");

    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        exit(1);
    }

    // Count the number of bank records in the file
    while (fscanf(fp, "%*[^\n]"), fscanf(fp, "%*c"), !feof(fp)) {
        numRecords++;
    }

    fclose(fp);

    // Initialize the bank record array
    record = (bankRecord*) malloc(numRecords * sizeof(bankRecord));
    fp = fopen("bank_records.txt", "r");

    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        exit(1);
    }

    // Load the bank records from the file into the array
    for (int i = 0; i < numRecords; i++) {
        fscanf(fp, "%d %s %s %f", &record[i].accountNo, record[i].firstName, record[i].lastName, &record[i].balance);
    }

    fclose(fp);

    // Main menu loop
    while (1) {
        printf("\nBank Record System\n");
        printf("-------------------\n");
        printf("1. View All Records\n");
        printf("2. Add New Record\n");
        printf("3. Edit Record\n");
        printf("4. Delete Record\n");
        printf("5. Search Record\n");
        printf("6. Save Records\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // View all records
                printf("\nAccount No.\tFirst Name\tLast Name\tBalance\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("%d\t\t%s\t\t%s\t\t%.2f\n", record[i].accountNo, record[i].firstName, record[i].lastName, record[i].balance);
                }
                break;
            case 2:
                // Add new record
                record = (bankRecord*) realloc(record, (numRecords + 1) * sizeof(bankRecord));
                printf("\nEnter Account No.: ");
                scanf("%d", &record[numRecords].accountNo);
                printf("Enter First Name: ");
                scanf("%s", &record[numRecords].firstName);
                printf("Enter Last Name: ");
                scanf("%s", &record[numRecords].lastName);
                printf("Enter Balance: ");
                scanf("%f", &record[numRecords].balance);
                numRecords++;
                printf("\nRecord added successfully.\n");
                break;
            case 3:
                // Edit record
                printf("\nEnter Account No. of record to edit: ");
                int editAccountNo;
                scanf("%d", &editAccountNo);
                int editRecordIndex = -1;
                for (int i = 0; i < numRecords; i++) {
                    if (record[i].accountNo == editAccountNo) {
                        editRecordIndex = i;
                        break;
                    }
                }
                if (editRecordIndex == -1) {
                    printf("\nRecord not found.\n");
                    break;
                }
                printf("\nEnter new First Name: ");
                scanf("%s", &record[editRecordIndex].firstName);
                printf("Enter new Last Name: ");
                scanf("%s", &record[editRecordIndex].lastName);
                printf("Enter new Balance: ");
                scanf("%f", &record[editRecordIndex].balance);
                printf("\nRecord edited successfully.\n");
                break;
            case 4:
                // Delete record
                printf("\nEnter Account No. of record to delete: ");
                int deleteAccountNo;
                scanf("%d", &deleteAccountNo);
                int deleteRecordIndex = -1;
                for (int i = 0; i < numRecords; i++) {
                    if (record[i].accountNo == deleteAccountNo) {
                        deleteRecordIndex = i;
                        break;
                    }
                }
                if (deleteRecordIndex == -1) {
                    printf("\nRecord not found.\n");
                    break;
                }
                for (int i = deleteRecordIndex; i < numRecords - 1; i++) {
                    record[i] = record[i + 1];
                }
                record = (bankRecord*) realloc(record, (numRecords - 1) * sizeof(bankRecord));
                numRecords--;
                printf("\nRecord deleted successfully.\n");
                break;
            case 5:
                // Search record
                printf("\nEnter Account No. to search: ");
                int searchAccountNo;
                scanf("%d", &searchAccountNo);
                int searchRecordIndex = -1;
                for (int i = 0; i < numRecords; i++) {
                    if (record[i].accountNo == searchAccountNo) {
                        searchRecordIndex = i;
                        break;
                    }
                }
                if (searchRecordIndex == -1) {
                    printf("\nRecord not found.\n");
                    break;
                }
                printf("\nAccount No.\tFirst Name\tLast Name\tBalance\n");
                printf("--------------------------------------------------\n");
                printf("%d\t\t%s\t\t%s\t\t%.2f\n", record[searchRecordIndex].accountNo, record[searchRecordIndex].firstName, record[searchRecordIndex].lastName, record[searchRecordIndex].balance);
                break;
            case 6:
                // Save records to file
                fp = fopen("bank_records.txt", "w");
                if (fp == NULL) {
                    printf("Error: File cannot be opened.\n");
                    exit(1);
                }
                for (int i = 0; i < numRecords; i++) {
                    fprintf(fp, "%d %s %s %.2f\n", record[i].accountNo, record[i].firstName, record[i].lastName, record[i].balance);
                }
                fclose(fp);
                printf("\nRecords saved successfully.\n");
                break;
            case 8:
                // Exit
                return 0;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}