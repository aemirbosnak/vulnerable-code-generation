//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[20];
    int account_number;
    double balance;
    struct Record* next;
} Record;

void insert_record(Record** head) {
    Record* new_record = malloc(sizeof(Record));
    new_record->next = NULL;

    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void search_record(Record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_number);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }
    printf("Record not found.\n");
}

void update_record(Record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            printf("Enter new name: ");
            scanf("%s", head->name);

            printf("Enter new account number: ");
            scanf("%d", &head->account_number);

            printf("Enter new balance: ");
            scanf("%lf", &head->balance);

            return;
        }
        head = head->next;
    }
    printf("Record not found.\n");
}

void delete_record(Record* head, int account_number) {
    Record* previous = NULL;
    Record* current = head;

    while (current) {
        if (current->account_number == account_number) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("Enter choice: ");

        int choice = scanf(" %d ", &choice);

        switch (choice) {
            case 1:
                insert_record(&head);
                break;
            case 2:
                search_record(head, atoi("account number"));
                break;
            case 3:
                update_record(head, atoi("account number"));
                break;
            case 4:
                delete_record(head, atoi("account number"));
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}