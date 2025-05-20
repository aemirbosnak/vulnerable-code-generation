//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank records
typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insert_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Function to print all bank records
void print_records(BankRecord* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_no);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

// Function to search for a bank record
void search_record(BankRecord* head, int account_no) {
    while (head) {
        if (head->account_no == account_no) {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_no);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main() {
    BankRecord* head = NULL;

    // Insert some bank records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Print all bank records
    print_records(head);

    // Search for a bank record
    search_record(head, 123);

    return 0;
}