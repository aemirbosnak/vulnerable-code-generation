//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankingRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a new record at the end
void insert_record(BankingRecord* head)
{
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        new_record->next = head;
        head = new_record;
    }
}

// Function to print all records
void print_records(BankingRecord* head)
{
    BankingRecord* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Account number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    BankingRecord* head = NULL;
    int choice;

    printf("Enter 1 to insert a new record, 2 to print all records: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insert_record(head);
            break;
        case 2:
            print_records(head);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}