//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define MAX_BALANCE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    double balance;
} Record;

int main() {
    FILE *bank_file;
    Record records[MAX_RECORDS];
    int num_records = 0;
    char choice;

    // Open the bank file
    bank_file = fopen("bank.txt", "r");
    if (bank_file == NULL) {
        printf("Error opening bank file.\n");
        return 1;
    }

    // Read records from the bank file
    while (fscanf(bank_file, "%s %s %lf\n", records[num_records].name, records[num_records].account_number, &records[num_records].balance)!= EOF) {
        num_records++;
    }
    fclose(bank_file);

    // Main menu loop
    while (choice!= '4') {
        printf("\nBanking Record System\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("\nAdd Record\n");
                printf("Enter name: ");
                scanf("%s", records[num_records].name);
                printf("Enter account number: ");
                scanf("%s", records[num_records].account_number);
                printf("Enter balance: ");
                scanf("%lf", &records[num_records].balance);
                num_records++;
                break;

            case '2':
                printf("\nDelete Record\n");
                printf("Enter name: ");
                scanf("%s", records[num_records - 1].name);
                num_records--;
                break;

            case '3':
                printf("\nSearch Record\n");
                printf("Enter name: ");
                scanf("%s", records[num_records - 1].name);
                break;

            case '4':
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    // Save the records to the bank file
    bank_file = fopen("bank.txt", "w");
    if (bank_file == NULL) {
        printf("Error opening bank file.\n");
        return 1;
    }

    for (int i = 0; i < num_records; i++) {
        fprintf(bank_file, "%s %s %lf\n", records[i].name, records[i].account_number, records[i].balance);
    }

    fclose(bank_file);
    printf("\nProgram ended successfully.\n");

    return 0;
}