//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the Banking Record System structure
typedef struct BankingRecordSystem {
    int account_number;
    char account_holder_name[50];
    double account_balance;
    struct BankingRecordSystem* next;
} BankingRecordSystem;

// Function to insert a new record into the Banking Record System
void insert_record(BankingRecordSystem** head) {
    BankingRecordSystem* new_record = (BankingRecordSystem*)malloc(sizeof(BankingRecordSystem));

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter account holder name: ");
    scanf("%s", new_record->account_holder_name);

    printf("Enter account balance: ");
    scanf("%lf", &new_record->account_balance);

    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Function to search for a record in the Banking Record System
void search_record(BankingRecordSystem* head) {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    BankingRecordSystem* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            printf("Account holder name: %s\n", current_record->account_holder_name);
            printf("Account balance: %.2lf\n", current_record->account_balance);
            break;
        } else {
            current_record = current_record->next;
        }
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a record from the Banking Record System
void delete_record(BankingRecordSystem* head) {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    BankingRecordSystem* current_record = head;
    BankingRecordSystem* previous_record = NULL;

    while (current_record) {
        if (current_record->account_number == account_number) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            break;
        } else {
            previous_record = current_record;
            current_record = current_record->next;
        }
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    BankingRecordSystem* head = NULL;

    // Insert a new record
    insert_record(&head);

    // Search for a record
    search_record(head);

    // Delete a record
    delete_record(head);

    return 0;
}