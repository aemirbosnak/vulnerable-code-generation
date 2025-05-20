//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank records
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insert_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter your name: ");
    scanf("%s", new_record->name);
    printf("Enter your account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter your initial balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Function to search for a bank record
void search_record(BankRecord* head, int account_number) {
    BankRecord* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_number);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        } else {
            current_record = current_record->next;
        }
    }

    if (current_record == NULL) {
        printf("No record found for account number: %d\n", account_number);
    }
}

// Main function
int main() {
    BankRecord* head = NULL;

    // Insert some bank records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a bank record
    search_record(head, 123456);

    return 0;
}