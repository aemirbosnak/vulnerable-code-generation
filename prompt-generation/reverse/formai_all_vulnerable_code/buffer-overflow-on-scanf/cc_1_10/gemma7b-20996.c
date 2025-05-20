//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[20];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }

    return head;
}

void search_record(Record* head, int account_no) {
    while (head) {
        if (head->account_no == account_no) {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_no);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    // Insert records
    insert_record(head);
    insert_record(head);
    insert_record(head);

    // Search for a record
    search_record(head, 123);

    return 0;
}