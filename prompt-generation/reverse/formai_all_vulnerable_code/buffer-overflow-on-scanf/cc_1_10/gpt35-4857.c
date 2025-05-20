//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
/* C Banking Record System Example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000

struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

void print_menu() {
    printf("------ Banking Record System ------\n");
    printf("1. Add New Record\n");
    printf("2. View Record\n");
    printf("3. Edit Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("-----------------------------------\n");
    printf("Enter your choice: ");
}

void add_record(struct bank_record records[], int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
    } else {
        struct bank_record new_record;
        printf("- Add New Record -\n");
        printf("Name: ");
        scanf("%s", new_record.name);
        printf("Account Number: ");
        scanf("%d", &new_record.account_number);
        printf("Balance: ");
        scanf("%f", &new_record.balance);
        records[*num_records] = new_record;
        (*num_records)++;
        printf("Record added successfully.\n");
    }
}

void view_record(struct bank_record records[], int num_records) {
    if (num_records == 0) {
        printf("No records found.\n");
    } else {
        int account_number;
        printf("- View Record -\n");
        printf("Enter account number: ");
        scanf("%d", &account_number);
        for (int i = 0; i < num_records; i++) {
            if (records[i].account_number == account_number) {
                printf("Name: %s\n", records[i].name);
                printf("Account Number: %d\n", records[i].account_number);
                printf("Balance: %.2f\n", records[i].balance);
                return;
            }
        }
        printf("Record not found.\n");
    }
}

void edit_record(struct bank_record records[], int num_records) {
    if (num_records == 0) {
        printf("No records found.\n");
    } else {
        int account_number;
        printf("- Edit Record -\n");
        printf("Enter account number: ");
        scanf("%d", &account_number);
        for (int i = 0; i < num_records; i++) {
            if (records[i].account_number == account_number) {
                printf("Name (%s): ", records[i].name);
                scanf("%s", records[i].name);
                printf("Account Number (%d): ", records[i].account_number);
                scanf("%d", &records[i].account_number);
                printf("Balance (%.2f): ", records[i].balance);
                scanf("%f", &records[i].balance);
                printf("Record edited successfully.\n");
                return;
            }
        }
        printf("Record not found.\n");
    }
}

void delete_record(struct bank_record records[], int *num_records) {
    if (*num_records == 0) {
        printf("No records found.\n");
    } else {
        int account_number;
        printf("- Delete Record -\n");
        printf("Enter account number: ");
        scanf("%d", &account_number);
        for (int i = 0; i < *num_records; i++) {
            if (records[i].account_number == account_number) {
                for (int j = i; j < *num_records; j++) {
                    records[j] = records[j+1];
                }
                (*num_records)--;
                printf("Record deleted successfully.\n");
                return;
            }
        }
        printf("Record not found.\n");
    }
}

int main() {
    struct bank_record records[MAX_RECORDS];
    int num_records = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                view_record(records, num_records);
                break;
            case 3:
                edit_record(records, num_records);
                break;
            case 4:
                delete_record(records, &num_records);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}