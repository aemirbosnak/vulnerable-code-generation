//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int account_no;
    char name[50];
    float balance;
};

void new_record(struct Record *records, int *num_records) {
    int account_no;
    char name[50];
    float balance;

    printf("Enter account number: ");
    scanf("%d", &account_no);

    printf("Enter name: ");
    scanf(" %[^\n]s", name);

    printf("Enter balance: ");
    scanf("%f", &balance);

    records[*num_records].account_no = account_no;
    strcpy(records[*num_records].name, name);
    records[*num_records].balance = balance;

    (*num_records)++;
}

void delete_record(struct Record *records, int *num_records, int account_no) {
    int i;
    int found = 0;

    for (i = 0; i < *num_records; i++) {
        if (records[i].account_no == account_no) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < *num_records - 1; i++) {
            records[i] = records[i + 1];
        }

        (*num_records)--;
        printf("Record with account number %d deleted successfully.\n", account_no);
    } else {
        printf("Record with account number %d not found.\n", account_no);
    }
}

void display_records(struct Record *records, int num_records) {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }

    printf("%-15s%-50s%s\n", "Account No", "Name", "Balance");
    for (int i = 0; i < 65; i++) {
        putchar('-');
    }
    putchar('\n');

    for (int i = 0; i < num_records; i++) {
        printf("%-15d%-50s%.2f\n", records[i].account_no, records[i].name, records[i].balance);
    }
}

int main() {
    struct Record records[100];
    int num_records = 0;
    int choice;
    int account_no;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Add new record\n");
        printf("2. Delete record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                new_record(records, &num_records);
                break;

            case 2:
                printf("Enter account number to delete: ");
                scanf("%d", &account_no);
                delete_record(records, &num_records, account_no);
                break;

            case 3:
                display_records(records, num_records);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}