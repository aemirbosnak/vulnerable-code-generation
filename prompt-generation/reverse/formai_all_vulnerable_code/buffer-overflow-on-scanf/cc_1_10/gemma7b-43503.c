//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank record data
typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insert_record(BankRecord* head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
}

// Function to search for a bank record
void search_record(BankRecord* head) {
    int account_no;
    printf("Enter account number: ");
    scanf("%d", &account_no);

    BankRecord* current_record = head;
    while (current_record) {
        if (current_record->account_no == account_no) {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_no);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a bank record
void delete_record(BankRecord* head) {
    int account_no;
    printf("Enter account number: ");
    scanf("%d", &account_no);

    BankRecord* current_record = head;
    BankRecord* previous_record = NULL;

    while (current_record) {
        if (current_record->account_no == account_no) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            break;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    BankRecord* head = NULL;

    // Insert a few bank records
    insert_record(head);
    insert_record(head);
    insert_record(head);

    // Search for a bank record
    search_record(head);

    // Delete a bank record
    delete_record(head);

    return 0;
}