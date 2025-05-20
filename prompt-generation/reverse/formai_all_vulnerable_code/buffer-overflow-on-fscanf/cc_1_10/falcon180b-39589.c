//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_NUMBER_LEN 20
#define MAX_AMOUNT_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char accountNumber[MAX_ACCOUNT_NUMBER_LEN];
    char amount[MAX_AMOUNT_LEN];
} Record;

int main() {
    FILE *fp;
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int choice;

    fp = fopen("banking_records.txt", "r+");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in existing records
    while (fscanf(fp, "%s %s %s\n", records[numRecords].name, records[numRecords].accountNumber, records[numRecords].amount)!= EOF) {
        numRecords++;
    }

    // Main loop
    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Add a new record\n");
        printf("2. View records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add a new record
            printf("Enter name: ");
            scanf("%s", records[numRecords].name);
            printf("Enter account number: ");
            scanf("%s", records[numRecords].accountNumber);
            printf("Enter amount: ");
            scanf("%s", records[numRecords].amount);
            numRecords++;
            break;

        case 2:
            // View records
            printf("\nRecords:\n");
            for (int i = 0; i < numRecords; i++) {
                printf("%s %s %s\n", records[i].name, records[i].accountNumber, records[i].amount);
            }
            break;

        case 3:
            // Exit
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

        // Write records to file
        rewind(fp);
        for (int i = 0; i < numRecords; i++) {
            fprintf(fp, "%s %s %s\n", records[i].name, records[i].accountNumber, records[i].amount);
        }
        fclose(fp);
    }

    return 0;
}