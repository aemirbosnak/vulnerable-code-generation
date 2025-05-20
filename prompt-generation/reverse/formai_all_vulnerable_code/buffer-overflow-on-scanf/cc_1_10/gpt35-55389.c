//FormAI DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char account_num[25];
    char name[100];
    float balance;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Error: Maximum number of records reached\n");
        return;
    }

    Record new_record;
    printf("Enter account number: ");
    scanf("%s", new_record.account_num);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter balance: ");
    scanf("%f", &new_record.balance);

    records[num_records++] = new_record;
}

void view_records() {
    printf("-------------\n");
    printf("| Records   |\n");
    printf("-------------\n");
    printf("| Account # | Name          | Balance  |\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < num_records; i++) {
        printf("| %-9s| %-14s| %-9.2f|\n", records[i].account_num, records[i].name, records[i].balance);
    }
}

void search_record() {
    char search_account_num[25];
    printf("Enter account number to search: ");
    scanf("%s", search_account_num);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_num, search_account_num) == 0) {
            printf("------------------------------------------------\n");
            printf("| Account # | Name          | Balance            |\n");
            printf("------------------------------------------------\n");
            printf("| %-9s| %-14s| %-19.2f|\n", records[i].account_num, records[i].name, records[i].balance);
            return;
        }
    }

    printf("Record with account number %s not found.\n", search_account_num);
}

void delete_record() {
    char delete_account_num[25];
    printf("Enter account number to delete: ");
    scanf("%s", delete_account_num);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_num, delete_account_num) == 0) {
            for (int j = i; j < num_records-1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record with account number %s deleted.\n", delete_account_num);
            return;
        }
    }

    printf("Record with account number %s not found.\n", delete_account_num);
}

int main() {
    int choice = 0;

    while (choice != 5) {
        printf("\n\nBanking Record System\n");
        printf("----------------------------------------------\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("----------------------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}