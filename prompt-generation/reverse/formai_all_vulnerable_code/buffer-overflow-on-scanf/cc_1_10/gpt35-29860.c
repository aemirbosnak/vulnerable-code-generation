//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct bank_record {
    char name[50];
    char address[100];
    int account_number;
    double balance;
};

struct bank_record records[MAX_SIZE];
int record_count = 0;

void add_record() {
    printf("\nAdding new record\n");
    printf("------------------\n");
    struct bank_record record;
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter address: ");
    scanf("%s", record.address);
    printf("Enter account number: ");
    scanf("%d", &record.account_number);
    printf("Enter balance: ");
    scanf("%lf", &record.balance);
    records[record_count++] = record;
    printf("Record added successfully!\n");
}

void display_records() {
    printf("\nDisplaying all records\n");
    printf("-----------------------\n");
    if (record_count == 0) {
        printf("No records found.\n");
    } else {
        for (int i = 0; i < record_count; i++) {
            struct bank_record record = records[i];
            printf("Name: %s\n", record.name);
            printf("Address: %s\n", record.address);
            printf("Account number: %d\n", record.account_number);
            printf("Balance: $%.2lf\n", record.balance);
            printf("\n");
        }
    }
}

void search_record() {
    printf("\nSearching record\n");
    printf("-----------------\n");
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    bool found_record = false;
    for (int i = 0; i < record_count; i++) {
        struct bank_record record = records[i];
        if (record.account_number == account_number) {
            printf("Name: %s\n", record.name);
            printf("Address: %s\n", record.address);
            printf("Account number: %d\n", record.account_number);
            printf("Balance: $%.2lf\n", record.balance);
            printf("\n");
            found_record = true;
        }
    }
    if (!found_record) {
        printf("Record not found.\n");
    }
}

void update_record() {
    printf("\nUpdating record\n");
    printf("----------------\n");
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    bool found_record = false;
    for (int i = 0; i < record_count; i++) {
        struct bank_record* record = &records[i];
        if (record->account_number == account_number) {
            found_record = true;
            printf("Enter new name (leave blank if no change): ");
            char new_name[50];
            scanf("%s", new_name);
            if (strlen(new_name) > 0) {
                strcpy(record->name, new_name);
            }
            printf("Enter new address (leave blank if no change): ");
            char new_address[100];
            scanf("%s", new_address);
            if (strlen(new_address) > 0) {
                strcpy(record->address, new_address);
            }
            printf("Enter new balance (leave blank if no change): ");
            char new_balance_str[50];
            scanf("%s", new_balance_str);
            if (strlen(new_balance_str) > 0) {
                double new_balance = atof(new_balance_str);
                record->balance = new_balance;
            }
            printf("Record updated successfully!\n");
        }
    }
    if (!found_record) {
        printf("Record not found.\n");
    }
}

void delete_record() {
    printf("\nDeleting record\n");
    printf("----------------\n");
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    bool found_record = false;
    for (int i = 0; i < record_count; i++) {
        struct bank_record* record = &records[i];
        if (record->account_number == account_number) {
            found_record = true;
            for (int j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count--;
            printf("Record deleted successfully!\n");
        }
    }
    if (!found_record) {
        printf("Record not found.\n");
    }
}

int main() {
    printf("-------------------------\n");
    printf("Welcome to C Bank\n");
    printf("-------------------------\n");
    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Update a record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                printf("Thank you for using C Bank!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}