//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct banking_record {
    int account_num;
    char name[50];
    float balance;
};

struct banking_record records[MAX_RECORDS];
int num_records = 0;

void print_records() {
    int i;
    printf("Account #    Name                    Balance\n");
    printf("--------------------------------------------\n");
    for (i = 0; i < num_records; i++) {
        printf("%-12d%-24s$%.2f\n", records[i].account_num, records[i].name, records[i].balance);
    }
}

void add_record() {
    if (num_records < MAX_RECORDS) {
        struct banking_record record;
        printf("Enter account number: ");
        scanf("%d", &record.account_num);
        printf("Enter name: ");
        getchar(); // consume newline
        fgets(record.name, sizeof record.name, stdin);
        record.name[strcspn(record.name, "\n")] = '\0'; // remove trailing newline
        printf("Enter balance: ");
        scanf("%f", &record.balance);
        records[num_records] = record;
        num_records++;
        printf("Record added successfully.\n");
    } else {
        printf("Error: Maximum number of records reached.\n");
    }
}

void remove_record() {
    int i, account_num;
    printf("Enter account number to remove: ");
    scanf("%d", &account_num);
    for (i = 0; i < num_records; i++) {
        if (records[i].account_num == account_num) {
            int j;
            for (j = i; j < num_records - 1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record removed successfully.\n");
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void update_record() {
    int i, account_num;
    printf("Enter account number to update: ");
    scanf("%d", &account_num);
    for (i = 0; i < num_records; i++) {
        if (records[i].account_num == account_num) {
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void search_record() {
    int i, account_num;
    printf("Enter account number to search: ");
    scanf("%d", &account_num);
    for (i = 0; i < num_records; i++) {
        if (records[i].account_num == account_num) {
            printf("Account #    Name                    Balance\n");
            printf("--------------------------------------------\n");
            printf("%-12d%-24s$%.2f\n", records[i].account_num, records[i].name, records[i].balance);
            return;
        }
    }
    printf("Error: Account not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n");
        printf("1. Print all records\n");
        printf("2. Add a new record\n");
        printf("3. Remove a record\n");
        printf("4. Update a record\n");
        printf("5. Search a record\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_records();
                break;
            case 2:
                add_record();
                break;
            case 3:
                remove_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                search_record();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (1);
    return 0;
}