//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct record {
    char name[MAX_SIZE];
    char account_num[MAX_SIZE];
    float balance;
} Record;

int main() {
    Record *records;
    int num_records;

    printf("Welcome to Genius Banking Record System!\n");
    printf("How many records would you like to create?\n");
    scanf("%d", &num_records);

    records = (Record *) malloc(num_records * sizeof(Record));

    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", records[i].name);
        printf("Enter account number: ");
        scanf("%s", records[i].account_num);
        printf("Enter balance: ");
        scanf("%f", &records[i].balance);
    }

    printf("\nRecord(s) created successfully!\n\n");

    while (1) {
        int option;
        printf("Please select an option:\n");
        printf("1. View record\n");
        printf("2. Deposit or withdraw from record\n");
        printf("3. Update record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        if (option == 1) {
            int index;
            printf("Enter index of record to view: ");
            scanf("%d", &index);

            if (index < 1 || index > num_records) {
                printf("Invalid index!\n\n");
                continue;
            }

            printf("\n%s\n", records[index - 1].name);
            printf("%s\n", records[index - 1].account_num);
            printf("%.2f\n\n", records[index - 1].balance);

        } else if (option == 2) {
            int index;
            float amount;
            char operation[10];

            printf("Enter index of record: ");
            scanf("%d", &index);

            if (index < 1 || index > num_records) {
                printf("Invalid index!\n\n");
                continue;
            }

            printf("Enter deposit or withdraw: ");
            scanf("%s", operation);
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (strcmp(operation, "deposit") == 0) {
                records[index - 1].balance += amount;
                printf("\nDeposit successful!\n");
            } else if (strcmp(operation, "withdraw") == 0) {
                if (records[index - 1].balance >= amount) {
                    records[index - 1].balance -= amount;
                    printf("\nWithdrawal successful!\n");
                } else {
                    printf("\nInsufficient balance!\n");
                }
            } else {
                printf("\nInvalid operation!\n");
                continue;
            }

            printf("%s's new balance: %.2f\n\n", records[index - 1].name, records[index - 1].balance);

        } else if (option == 3) {
            int index;
            printf("Enter index of record to update: ");
            scanf("%d", &index);

            if (index < 1 || index > num_records) {
                printf("Invalid index!\n\n");
                continue;
            }

            printf("\n%s's current information\n", records[index - 1].name);
            printf("%s\n", records[index - 1].account_num);
            printf("%.2f\n", records[index - 1].balance);

            printf("\n%s's updated information\n", records[index - 1].name);
            printf("Enter name: ");
            scanf("%s", records[index - 1].name);
            printf("Enter account number: ");
            scanf("%s", records[index - 1].account_num);
            printf("Enter balance: ");
            scanf("%f", &records[index - 1].balance);

            printf("\nRecord updated successfully!\n\n");

        } else if (option == 4) {
            int index;
            printf("Enter index of record to delete: ");
            scanf("%d", &index);

            if (index < 1 || index > num_records) {
                printf("Invalid index!\n\n");
                continue;
            }

            for (int i = index - 1; i < num_records - 1; i++) {
                strcpy(records[i].name, records[i + 1].name);
                strcpy(records[i].account_num, records[i + 1].account_num);
                records[i].balance = records[i + 1].balance;
            }

            num_records--;
            records = (Record *) realloc(records, num_records * sizeof(Record));

            printf("\nRecord deleted successfully!\n\n");

        } else if (option == 5) {
            printf("Exiting Genius Banking Record System...\n");
            break;
        } else {
            printf("Invalid option!\n\n");
        }
    }

    free(records);

    return 0;
}