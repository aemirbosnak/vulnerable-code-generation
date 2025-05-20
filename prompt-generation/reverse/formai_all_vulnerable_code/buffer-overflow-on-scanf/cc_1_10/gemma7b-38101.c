//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the Banking Record structure
typedef struct BankingRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a Banking Record at the end
void insert_at_end(BankingRecord** head)
{
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));

    // Get the name, account number, and balance from the user
    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    // If the head is NULL, then this is the first record
    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }

    // Print the confirmation message
    printf("Record inserted successfully!\n");
}

// Function to search for a Banking Record by account number
BankingRecord* search_by_account_number(BankingRecord* head, int account_number)
{
    while (head)
    {
        if (head->account_number == account_number)
        {
            return head;
        }
        else
        {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a Banking Record
void update_balance(BankingRecord* head, int account_number, double new_balance)
{
    BankingRecord* record = search_by_account_number(head, account_number);

    if (record)
    {
        record->balance = new_balance;

        printf("Balance updated successfully!\n");
    }
    else
    {
        printf("Record not found.\n");
    }
}

// Function to delete a Banking Record by account number
void delete_record(BankingRecord* head, int account_number)
{
    BankingRecord* previous = NULL;
    BankingRecord* current = head;

    while (current)
    {
        if (current->account_number == account_number)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }

            free(current);

            printf("Record deleted successfully!\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Record not found.\n");
}

int main()
{
    BankingRecord* head = NULL;

    // Insert some records
    insert_at_end(&head);
    insert_at_end(&head);
    insert_at_end(&head);

    // Search for a record
    BankingRecord* record = search_by_account_number(head, 123);

    // Update the balance of a record
    update_balance(head, 123, 1000);

    // Delete a record
    delete_record(head, 456);

    return 0;
}