//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 10

// Define the record structure
typedef struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

// Function to insert a new record
void insert_record(Record** head) {
    // Allocate memory for the new record
    Record* new_record = (Record*)malloc(sizeof(Record));

    // Get the record details from the user
    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    // Insert the new record into the linked list
    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }

    // Print a confirmation message
    printf("Record inserted successfully!\n");
}

// Function to search for a record
void search_record(Record* head, int account_no) {
    // Traverse the linked list until the record is found or the end of the list is reached
    while (head) {
        if (head->account_no == account_no) {
            // Print the record details
            printf("Name: %s\n", head->name);
            printf("Account number: %d\n", head->account_no);
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

// Function to update a record
void update_record(Record* head, int account_no) {
    // Traverse the linked list until the record is found or the end of the list is reached
    while (head) {
        if (head->account_no == account_no) {
            // Get the updated record details from the user
            printf("Enter new name: ");
            scanf("%s", head->name);

            printf("Enter new account number: ");
            scanf("%d", &head->account_no);

            printf("Enter new balance: ");
            scanf("%lf", &head->balance);

            // Print a confirmation message
            printf("Record updated successfully!\n");
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
void delete_record(Record* head, int account_no) {
    // Traverse the linked list until the record is found or the end of the list is reached
    Record* prev = NULL;
    while (head) {
        if (head->account_no == account_no) {
            // If the record is the first record, update the head of the list
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = head->next;
            }

            // Print a confirmation message
            printf("Record deleted successfully!\n");
            break;
        } else {
            prev = head;
            head = head->next;
        }
    }

    // If the record is not found, print an error message
    if (head == NULL) {
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

    // Update a record
    update_record(head, 456);

    // Delete a record
    delete_record(head, 789);

    return 0;
}