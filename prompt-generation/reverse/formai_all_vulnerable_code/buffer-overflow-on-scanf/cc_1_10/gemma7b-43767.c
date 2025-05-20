//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Banking Record System structure
typedef struct BankingRecordSystem
{
    struct BankingRecordSystem *next;
    char account_number[10];
    char account_name[50];
    double account_balance;
    double transaction_amount;
    char transaction_type;
    char transaction_date[20];
} BankingRecordSystem;

// Function to insert a new record into the Banking Record System
void insert_record(BankingRecordSystem **head)
{
    BankingRecordSystem *new_record = (BankingRecordSystem *)malloc(sizeof(BankingRecordSystem));

    printf("Enter account number: ");
    scanf("%s", new_record->account_number);

    printf("Enter account name: ");
    scanf("%s", new_record->account_name);

    printf("Enter account balance: ");
    scanf("%lf", &new_record->account_balance);

    printf("Enter transaction amount: ");
    scanf("%lf", &new_record->transaction_amount);

    printf("Enter transaction type: ");
    scanf(" %c", &new_record->transaction_type);

    printf("Enter transaction date: ");
    scanf("%s", new_record->transaction_date);

    new_record->next = NULL;

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }
}

// Function to display all records in the Banking Record System
void display_records(BankingRecordSystem *head)
{
    while (head)
    {
        printf("Account number: %s\n", head->account_number);
        printf("Account name: %s\n", head->account_name);
        printf("Account balance: %.2lf\n", head->account_balance);
        printf("Transaction amount: %.2lf\n", head->transaction_amount);
        printf("Transaction type: %c\n", head->transaction_type);
        printf("Transaction date: %s\n", head->transaction_date);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    BankingRecordSystem *head = NULL;

    // Insert some records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Display all records
    display_records(head);

    return 0;
}