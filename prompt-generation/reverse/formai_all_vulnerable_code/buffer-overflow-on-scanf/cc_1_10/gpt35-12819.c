//FormAI DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME 50
#define MAX_ACCOUNT_NUM 10

struct BankRecord {
    char name[MAX_NAME];
    char account_num[MAX_ACCOUNT_NUM];
    double balance;
};

int num_records = 0;
struct BankRecord records[MAX_RECORDS];

void add_record() {
    struct BankRecord new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%s", new_record.account_num);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    records[num_records] = new_record;
    num_records++;

    printf("Record added successfully.\n");
}

void display_record(struct BankRecord record) {
    printf("%-20s%-15s$%.2f\n", record.name, record.account_num, record.balance);
}

void display_records() {
    printf("%-20s%-15s%s\n", "Name", "Account #", "Balance");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        display_record(records[i]);
    }
}

void search_records() {
    char search_term[MAX_NAME];
    printf("Enter search term: ");
    scanf("%s", search_term);

    printf("%-20s%-15s%s\n", "Name", "Account #", "Balance");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < num_records; i++) {
        if (strstr(records[i].name, search_term) != NULL) {
            display_record(records[i]);
        }
    }
}

void menu() {
    printf("\n");
    printf("Choose an option:\n");
    printf("1. Add a record\n");
    printf("2. Display all records\n");
    printf("3. Search records by name\n");
    printf("4. Exit\n");
    printf("\n");
}

int main() {
    int option;

    do {
        menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_records();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 4);

    return 0;
}