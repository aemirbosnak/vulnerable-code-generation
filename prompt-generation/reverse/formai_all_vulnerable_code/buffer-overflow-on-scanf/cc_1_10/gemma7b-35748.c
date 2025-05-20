//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store banking record data
typedef struct BankingRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a new banking record at the end
void insert_record(BankingRecord** head) {
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
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

// Function to search for a banking record by account number
BankingRecord* search_record(BankingRecord* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a banking record
void update_balance(BankingRecord* head, int account_number, double new_balance) {
    BankingRecord* record = search_record(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a banking record
void delete_record(BankingRecord* head, int account_number) {
    BankingRecord* previous = NULL;
    BankingRecord* current = head;

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
    BankingRecord* head = NULL;

    // Insert some banking records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a banking record by account number
    BankingRecord* record = search_record(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a banking record
    update_balance(head, 1234, 1000.0);
    record = search_record(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Delete a banking record
    delete_record(head, 1234);
    record = search_record(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    return 0;
}