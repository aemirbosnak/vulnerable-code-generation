//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Define a structure to store banking record information
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record at the end
void insert_record(bank_record** head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Function to search for a bank record by account number
bank_record* search_record(bank_record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* head, int account_number, double new_balance) {
    bank_record* record = search_record(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record by account number
void delete_record(bank_record* head, int account_number) {
    bank_record* previous = NULL;
    bank_record* current = head;

    while (current) {
        if (current->account_number == account_number) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return;
}

int main() {
    bank_record* head = NULL;

    // Insert some bank records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a bank record by account number
    bank_record* record = search_record(head, 12345);

    // Update the balance of a bank record
    update_balance(head, 12345, 1000);

    // Delete a bank record by account number
    delete_record(head, 12345);

    // Print the bank records
    bank_record* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }

    return 0;
}