//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
};

void insert_record(struct BankRecord** head) {
    struct BankRecord* new_record = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void search_record(struct BankRecord* head, int account_no) {
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
    struct BankRecord* head = NULL;

    // Insert some records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a record
    search_record(head, 1234);

    return 0;
}