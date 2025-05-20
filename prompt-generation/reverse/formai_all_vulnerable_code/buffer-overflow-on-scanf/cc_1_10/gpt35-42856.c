//FormAI DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    int account_number;
    char account_holder[50];
    float account_balance;
} records[10];

int num_records = 0;

void add_record() {
    if (num_records == 10) {
        printf("Maximum number of records reached.\n");
        return;
    }
    
    struct bank_record record;
    printf("Enter account number: ");
    scanf("%d", &record.account_number);
    printf("Enter account holder name: ");
    scanf("%s", record.account_holder);
    printf("Enter account balance: ");
    scanf("%f", &record.account_balance);
    
    records[num_records++] = record;
    printf("Record added successfully.\n");
}

void read_record() {
    int account_number;
    printf("Enter account number to read: ");
    scanf("%d", &account_number);
    
    for (int i=0; i<num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("Account Holder: %s\n", records[i].account_holder);
            printf("Account Balance: %f\n", records[i].account_balance);
            return;
        }
    }
    
    printf("Record not found.\n");
}

void menu() {
    printf("**** Retro Banking Record System ****\n");
    printf("[1] Add Record\n");
    printf("[2] Read Record\n");
    printf("[3] Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                read_record();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    
    return 0;
}