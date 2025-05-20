//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* head = NULL;

void add_record() {
    Record* new_record = malloc(sizeof(Record));

    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    new_record->next = head;
    head = new_record;
}

void print_records() {
    Record* current_record = head;

    while (current_record) {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_number);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }
}

int main() {
    char choice;

    while (1) {
        printf("Enter 'a' to add a record, 'p' to print records, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_record();
                break;
            case 'p':
                print_records();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}