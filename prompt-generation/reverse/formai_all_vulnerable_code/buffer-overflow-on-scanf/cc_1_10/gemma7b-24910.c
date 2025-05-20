//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store banking records
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record at the end
void insert_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    new_record->next = NULL;

    // Get the user's name, account number, and balance
    printf("Enter your name: ");
    scanf("%s", new_record->name);

    printf("Enter your account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter your balance: ");
    scanf("%lf", &new_record->balance);

    // If the head is NULL, insert the new record as the first record
    if (*head == NULL) {
        *head = new_record;
    } else {
        // Traverse the linked list until the last record is reached
        BankRecord* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new record as the last record
        temp->next = new_record;
    }
}

// Function to search for a record
void search_record(BankRecord** head) {
    // Get the user's account number
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);

    // Search for the record
    BankRecord* temp = *head;
    while (temp) {
        if (temp->account_number == account_number) {
            // Display the record
            printf("Name: %s\n", temp->name);
            printf("Account Number: %d\n", temp->account_number);
            printf("Balance: %.2lf\n", temp->balance);
            break;
        }
        temp = temp->next;
    }

    // If the record is not found, display an error message
    if (temp == NULL) {
        printf("Record not found.\n");
    }
}

// Function to update a record
void update_record(BankRecord** head) {
    // Get the user's account number
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);

    // Search for the record
    BankRecord* temp = *head;
    while (temp) {
        if (temp->account_number == account_number) {
            // Get the user's new balance
            double new_balance;
            printf("Enter your new balance: ");
            scanf("%lf", &new_balance);

            // Update the record
            temp->balance = new_balance;

            // Display the updated record
            printf("Name: %s\n", temp->name);
            printf("Account Number: %d\n", temp->account_number);
            printf("Balance: %.2lf\n", temp->balance);
            break;
        }
        temp = temp->next;
    }

    // If the record is not found, display an error message
    if (temp == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a record
void delete_record(BankRecord** head) {
    // Get the user's account number
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);

    // Search for the record
    BankRecord* temp = *head;
    BankRecord* prev = NULL;
    while (temp) {
        if (temp->account_number == account_number) {
            // If the record is the first record, update the head
            if (prev == NULL) {
                *head = temp->next;
            } else {
                // Otherwise, update the previous record to point to the next record
                prev->next = temp->next;
            }

            // Free the memory occupied by the record
            free(temp);

            // Display the updated list
            printf("Updated list:\n");
            temp = *head;
            while (temp) {
                printf("Name: %s\n", temp->name);
                printf("Account Number: %d\n", temp->account_number);
                printf("Balance: %.2lf\n", temp->balance);
                printf("\n");
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the record is not found, display an error message
    if (temp == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    // Create a linked list of banking records
    BankRecord* head = NULL;

    // Insert some records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a record
    search_record(&head);

    // Update a record
    update_record(&head);

    // Delete a record
    delete_record(&head);

    return 0;
}