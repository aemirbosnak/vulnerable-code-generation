//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct Record
{
    int account_number;
    char name[50];
    double balance;
    struct Record* next;
} Record;

void insert_record(Record** head)
{
    Record* new_record = malloc(sizeof(Record));
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }
}

void display_records(Record* head)
{
    while (head)
    {
        printf("Account number: %d\n", head->account_number);
        printf("Name: %s\n", head->name);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Record* head = NULL;

    // Insert records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Display records
    display_records(head);

    return 0;
}