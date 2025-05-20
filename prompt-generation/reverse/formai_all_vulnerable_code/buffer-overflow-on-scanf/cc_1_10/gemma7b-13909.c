//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

void insert_record(Record** head) {
    Record* new_record = malloc(sizeof(Record));
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

void print_records(Record* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_no);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Record* head = NULL;
    int choice;

    printf("Welcome to the C Banking Record System!\n");

    while (1) {
        printf("Enter 1 to insert a new record, 2 to print records, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record(&head);
                break;
            case 2:
                print_records(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}