//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record
{
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head)
{
    Record* new_record = malloc(sizeof(Record));
    new_record->next = NULL;

    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }

    return head;
}

void display_records(Record* head)
{
    Record* current_record = head;

    printf("List of records:\n");
    while (current_record)
    {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_no);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }
}

int main()
{
    Record* head = NULL;

    // Insert some records
    head = insert_record(head);
    insert_record(head);
    insert_record(head);

    // Display the records
    display_records(head);

    return 0;
}