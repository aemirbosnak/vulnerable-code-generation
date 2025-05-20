//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORD_SIZE 10

typedef struct Record {
    char name[20];
    int account_no;
    double balance;
} Record;

Record records[MAX_RECORD_SIZE];

void add_record() {
    Record new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%d", &new_record.account_no);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    records[0] = new_record;
}

void view_records() {
    for (int i = 0; i < MAX_RECORD_SIZE; i++) {
        if (records[i].account_no != 0) {
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].account_no);
            printf("Balance: %.2lf\n", records[i].balance);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Enter 1 to add a record, 2 to view records: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_record();
            break;
        case 2:
            view_records();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}