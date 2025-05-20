//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* insertRecord(Record* head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));

    printf("Enter name: ");
    scanf("%s", newRecord->name);

    printf("Enter account number: ");
    scanf("%d", &newRecord->account_number);

    printf("Enter balance: ");
    scanf("%lf", &newRecord->balance);

    newRecord->next = head;
    head = newRecord;

    return head;
}

void displayRecords(Record* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Record* head = NULL;

    while (1) {
        printf("1. Insert Record\n");
        printf("2. Display Records\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertRecord(head);
                break;
            case 2:
                displayRecords(head);
                break;
            default:
                break;
        }

        printf("\n");
    }

    return 0;
}