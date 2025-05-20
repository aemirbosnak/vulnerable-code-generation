//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record at the end of the linked list
void insert_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
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
    *head = new_record;
}

// Function to search for a record by account number
BankRecord* search_record(BankRecord* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a record
void update_balance(BankRecord* head, int account_number, double new_balance) {
    BankRecord* record = search_record(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a record from the list
void delete_record(BankRecord* head, int account_number) {
    BankRecord* previous = NULL;
    BankRecord* current = head;
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
    return;
}

int main() {
    BankRecord* head = NULL;
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    search_record(head, 1234);

    update_balance(head, 1234, 1000);

    delete_record(head, 1234);

    return 0;
}