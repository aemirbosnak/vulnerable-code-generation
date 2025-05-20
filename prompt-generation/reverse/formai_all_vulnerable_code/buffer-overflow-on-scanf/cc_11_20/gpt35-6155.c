//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankRecord {
    char name[50];
    int accountNumber;
    float balance;
};

int main() {
    int numRecords;
    printf("Enter number of records: ");
    scanf("%d", &numRecords);
    struct bankRecord records[numRecords];
    for (int i = 0; i < numRecords; i++) {
        printf("\nEnter name for record %d: ", i+1);
        scanf("%s", records[i].name);
        printf("Enter account number for record %d: ", i+1);
        scanf("%d", &records[i].accountNumber);
        printf("Enter balance for record %d: ", i+1);
        scanf("%f", &records[i].balance);
    }

    int choice;
    do {
        printf("\nBank Record System\n1. Search by name\n2. Search by account number\n3. Delete record\n4. View all records\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            
            case 1: {
                char searchName[50];
                printf("Enter name to search: ");
                scanf("%s", searchName);
                int found = 0;
                for (int i = 0; i<numRecords; i++) {
                    if (strcmp(records[i].name, searchName) == 0) {
                        printf("Record found:\nName: %s\nAccount Number: %d\nBalance: %.2f\n", records[i].name, records[i].accountNumber, records[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("Record not found for %s\n", searchName);
                }
                break;
            }

            case 2: {
                int searchAccNum;
                printf("Enter account number to search: ");
                scanf("%d", &searchAccNum);
                int found = 0;
                for (int i = 0; i<numRecords; i++) {
                    if (records[i].accountNumber == searchAccNum) {
                        printf("Record found:\nName: %s\nAccount Number: %d\nBalance: %.2f\n", records[i].name, records[i].accountNumber, records[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("Record not found for %d\n", searchAccNum);
                }
                break;
            }

            case 3: {
                int deleteIndex = -1;
                int deleteAccNum;
                printf("Enter account number to delete: ");
                scanf("%d", &deleteAccNum);
                for (int i = 0; i<numRecords; i++) {
                    if (records[i].accountNumber == deleteAccNum) {
                        deleteIndex = i;
                        break;
                    }
                }
                if (deleteIndex != -1) {
                    for (int i = deleteIndex; i<numRecords-1; i++) {
                        records[i] = records[i+1];
                    }
                    numRecords--;
                    printf("Record deleted successfully\n");
                }
                else {
                    printf("Record not found for %d\n", deleteAccNum);
                }
                break;
            }

            case 4: {
                printf("\nBank Records: \n");
                for (int i = 0; i<numRecords; i++) {
                    printf("Record %d:\nName: %s\nAccount Number: %d\nBalance: %.2f\n", i+1, records[i].name, records[i].accountNumber, records[i].balance);
                }
                break;
            }

            case 5: {
                printf("\nExiting Bank Record System...\n");
                break;
            }

            default: {
                printf("\nInvalid choice\n");
            }
        }
    } while(choice != 5);

    return 0;
}