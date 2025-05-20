//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Record;

Record records[MAX_RECORDS];
int next_record = 0;

void add_record(int account_number, const char *name, float balance) {
    if (next_record >= MAX_RECORDS) {
        printf("Banking record system is full.\n");
        return;
    }

    strcpy(records[next_record].name, name);
    records[next_record].account_number = account_number;
    records[next_record].balance = balance;
    next_record++;
}

void search_record(int account_number) {
    for (int i = 0; i < next_record; i++) {
        if (records[i].account_number == account_number) {
            printf("Account Number: %d\n", records[i].account_number);
            printf("Name: %s\n", records[i].name);
            printf("Balance: %.2f\n", records[i].balance);
            return;
        }
    }

    printf("Record not found.\n");
}

void main() {
    int choice, account_number;
    char name[50];
    float amount;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_record(account_number, name, amount);
                break;
            case 2:
                printf("Enter account number to search: ");
                scanf("%d", &account_number);
                search_record(account_number);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}