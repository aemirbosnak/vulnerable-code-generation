//FormAI DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankRecord {
    int account_number;
    char name[30];
    float balance;
};

void add_record(struct BankRecord *records, int *size) {
    struct BankRecord new_record;
    printf("Enter account number: ");
    scanf("%d", &new_record.account_number);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter balance: ");
    scanf("%f", &new_record.balance);
    *(records + *size) = new_record;
    (*size)++;
}

void display_records(struct BankRecord *records, int size) {
    printf("Account Number\tName\t\tBalance\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t\t%s\t\t%.2f\n", (records+i)->account_number,
               (records+i)->name, (records+i)->balance);
    }
}

void search_record(struct BankRecord *records, int size) {
    int account_number;
    printf("Enter account number to search: ");
    scanf("%d", &account_number);
    for (int i = 0; i < size; i++) {
        if ((records+i)->account_number == account_number) {
            printf("Record found:\n");
            printf("Account Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%.2f\n", (records+i)->account_number,
                   (records+i)->name, (records+i)->balance);
            return;
        }
    }
    printf("Record not found.\n");
}

void del_record(struct BankRecord *records, int *size) {
    int account_number;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);
    for (int i = 0; i < *size; i++) {
        if ((records+i)->account_number == account_number) {
            for (int j = i; j < *size-1; j++) {
                *(records+j) = *(records+j+1);
            }
            (*size)--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    int size = 0;
    struct BankRecord *records = (struct BankRecord*) malloc(10 * sizeof(struct BankRecord));
    int choice;
    do {
        printf("\nBank Record System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (size == 10) {
                    printf("Database is full.\n");
                } else {
                    add_record(records, &size);
                }
                break;
            case 2:
                if (size == 0) {
                    printf("Database is empty.\n");
                } else {
                    display_records(records, size);
                }
                break;
            case 3:
                if (size == 0) {
                    printf("Database is empty.\n");
                } else {
                    search_record(records, size);
                }
                break;
            case 4:
                if (size == 0) {
                    printf("Database is empty.\n");
                } else {
                    del_record(records, &size);
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    free(records);
    return 0;
}