//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct record {
    char account_no[20];
    char name[50];
    double balance;
};

typedef struct record Record;

void add_record(Record* records, int* num_records);
void display_records(Record* records, int num_records);
void update_record(Record* records, int num_records);
void delete_record(Record* records, int* num_records);

int main() {
    int num_records = 0;
    Record* records = malloc(100 * sizeof(Record)); // allocate space for 100 records

    int choice = 0;
    while (choice != 5) {
        printf("\nBanking Record System\n");
        printf("----------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                update_record(records, num_records);
                break;
            case 4:
                delete_record(records, &num_records);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    free(records); // free dynamically allocated memory
    return 0;
}

void add_record(Record* records, int* num_records) {
    if (*num_records == 100) {
        printf("\nCannot add record. Maximum capacity reached.\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%s", records[*num_records].account_no);

    printf("Enter name: ");
    scanf("%s", records[*num_records].name);

    printf("Enter balance: ");
    scanf("%lf", &records[*num_records].balance);

    (*num_records)++;
    printf("\nRecord added!\n");
}

void display_records(Record* records, int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nRecords:\n");

    for (int i = 0; i < num_records; i++) {
        printf("%d. Account Number: %s, Name: %s, Balance: %.2lf\n", i + 1, records[i].account_no, records[i].name, records[i].balance);
    }
}

void update_record(Record* records, int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    char account_no[20];

    printf("\nEnter account number to update: ");
    scanf("%s", account_no);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_no, account_no) == 0) {
            printf("Enter name: ");
            scanf("%s", records[i].name);

            printf("Enter balance: ");
            scanf("%lf", &records[i].balance);

            printf("\nRecord updated!\n");
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void delete_record(Record* records, int* num_records) {
    if (*num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    char account_no[20];

    printf("\nEnter account number to delete: ");
    scanf("%s", account_no);

    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i].account_no, account_no) == 0) {
            for (int j = i; j < *num_records - 1; j++) {
                records[j] = records[j + 1];
            }

            (*num_records)--;
            printf("\nRecord deleted!\n");
            return;
        }
    }

    printf("\nRecord not found.\n");
}