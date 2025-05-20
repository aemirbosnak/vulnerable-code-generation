//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} BankRecord;

#define MAX_RECORDS 100

BankRecord records[MAX_RECORDS];
int num_records = 0;

void create_record(int account_number, const char *name, float balance) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    records[num_records].account_number = account_number;
    strcpy(records[num_records].name, name);
    records[num_records].balance = balance;
    num_records++;
}

void display_records() {
    if (num_records == 0) {
        printf("Error: No records found.\n");
        return;
    }

    printf("\nAccount Number\tName\tBalance\n");

    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

int main() {
    int account_number, choice;
    char name[50];
    float balance;

    while (1) {
        printf("\n1. Create Record\n2. Display Records\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%f", &balance);

                create_record(account_number, name, balance);
                printf("Record created successfully.\n");
                break;

            case 2:
                display_records();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}