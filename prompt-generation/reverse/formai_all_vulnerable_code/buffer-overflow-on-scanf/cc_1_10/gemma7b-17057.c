//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[20];
    int account_no;
    double balance;
} Record;

Record records[MAX_RECORDS];

void insert_record() {
    Record new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%d", &new_record.account_no);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    int i = 0;
    for (; i < MAX_RECORDS && records[i].account_no != 0; i++) {}

    records[i] = new_record;
}

void search_record() {
    char search_name[20];

    printf("Enter name: ");
    scanf("%s", search_name);

    int i = 0;
    for (; i < MAX_RECORDS && records[i].account_no != 0; i++) {
        if (strcmp(records[i].name, search_name) == 0) {
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].account_no);
            printf("Balance: %.2lf\n", records[i].balance);
        }
    }
}

int main() {
    int choice;

    printf("Enter 1 to insert a record, 2 to search a record: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert_record();
            break;
        case 2:
            search_record();
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}