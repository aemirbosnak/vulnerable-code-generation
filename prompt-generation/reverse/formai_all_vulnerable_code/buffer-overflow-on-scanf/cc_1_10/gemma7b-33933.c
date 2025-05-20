//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record
{
    char name[20];
    int account_no;
    double balance;
} Record;

Record records[MAX_RECORDS];

void display_records()
{
    for (int i = 0; i < MAX_RECORDS; i++)
    {
        if (records[i].balance > 0)
        {
            printf("Name: %s, Account No: %d, Balance: %.2lf\n", records[i].name, records[i].account_no, records[i].balance);
        }
    }
}

void add_record()
{
    Record new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%d", &new_record.account_no);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    for (int i = 0; i < MAX_RECORDS; i++)
    {
        if (records[i].account_no == new_record.account_no)
        {
            printf("Error: Account number already exists.\n");
            return;
        }
    }

    records[MAX_RECORDS - 1] = new_record;
    printf("Record added successfully.\n");
}

int main()
{
    int choice;

    printf("Welcome to the C Banking Record System.\n");

    while (1)
    {
        printf("1. Display Records\n");
        printf("2. Add Record\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display_records();
                break;
            case 2:
                add_record();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}