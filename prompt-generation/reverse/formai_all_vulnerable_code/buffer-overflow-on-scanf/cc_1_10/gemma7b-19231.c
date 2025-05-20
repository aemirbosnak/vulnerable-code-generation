//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct BankRecord
{
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert_record(BankRecord** head)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
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

void search_record(BankRecord* head)
{
    char search_name[20];
    int search_account_no;

    printf("Enter name: ");
    scanf("%s", search_name);

    printf("Enter account number: ");
    scanf("%d", &search_account_no);

    BankRecord* current_record = head;

    while (current_record)
    {
        if (strcmp(current_record->name, search_name) == 0 && current_record->account_no == search_account_no)
        {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_no);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Record not found.\n");
    }
}

int main()
{
    BankRecord* head = NULL;

    while (1)
    {
        int choice;

        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_record(&head);
                break;
            case 2:
                search_record(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    return 0;
}