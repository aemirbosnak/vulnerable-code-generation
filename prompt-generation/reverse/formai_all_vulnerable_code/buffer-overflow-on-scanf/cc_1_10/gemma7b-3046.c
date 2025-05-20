//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void search_record(BankRecord* head, int account_no) {
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
    BankRecord* head = NULL;
    int choice, account_no;

    printf("Enter 1 to insert a record, 2 to search a record: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert_record(&head);
            break;
        case 2:
            printf("Enter account number: ");
            scanf("%d", &account_no);
            search_record(head, account_no);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}