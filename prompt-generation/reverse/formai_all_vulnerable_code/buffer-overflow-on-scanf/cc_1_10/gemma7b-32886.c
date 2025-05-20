//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

// Function to insert a new record at the end
void insert_record(Record** head) {
    // Allocate memory for the new record
    Record* new_record = (Record*)malloc(sizeof(Record));

    // Get the record details from the user
    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    // If the head is NULL, then this is the first record
    if (*head == NULL) {
        *head = new_record;
    } else {
        // Traverse the linked list until we reach the last record
        Record* current_record = *head;
        while (current_record->next != NULL) {
            current_record = current_record->next;
        }

        // Insert the new record at the end of the list
        current_record->next = new_record;
    }
}

// Function to search for a record
void search_record(Record* head, int account_number) {
    // Traverse the linked list until we find the record or reach the end of the list
    while (head) {
        if (head->account_number == account_number) {
            // Print the record details
            printf("Name: %s\n", head->name);
            printf("Account number: %d\n", head->account_number);
            printf("Balance: %.2lf\n", head->balance);
            break;
        } else {
            head = head->next;
        }
    }

    // If the record is not found, print an error message
    if (head == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a record
void delete_record(Record* head, int account_number) {
    // Traverse the linked list until we find the record or reach the end of the list
    Record* previous_record = NULL;
    Record* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            // If the previous record is not NULL, then update the previous record to point to the current record
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                // Otherwise, update the head of the list
                head = current_record->next;
            }

            // Free the memory occupied by the current record
            free(current_record);
            break;
        } else {
            previous_record = current_record;
            current_record = current_record->next;
        }
    }

    // If the record is not found, print an error message
    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    // Create a linked list of records
    Record* head = NULL;

    // Insert some records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a record
    search_record(head, 123);

    // Delete a record
    delete_record(head, 456);

    return 0;
}