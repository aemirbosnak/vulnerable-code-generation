//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[20];
    int account_no;
    double balance;
} Record;

Record records[MAX_RECORDS];

void add_record() {
    int i = 0;
    for (i = 0; records[i].account_no != -1 && i < MAX_RECORDS; i++) {}
    records[i].account_no = i + 1;
    printf("Enter name: ");
    scanf("%s", records[i].name);
    printf("Enter account number: ");
    scanf("%d", &records[i].account_no);
    printf("Enter balance: ");
    scanf("%lf", &records[i].balance);
}

void print_records() {
    int i = 0;
    for (i = 0; records[i].account_no != -1 && i < MAX_RECORDS; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_no);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("\n");
    }
}

int main() {
    int choice = 0;

    records[0].account_no = -1;

    while (choice != 3) {
        printf("Enter 1 to add a record, 2 to print records, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                print_records();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}