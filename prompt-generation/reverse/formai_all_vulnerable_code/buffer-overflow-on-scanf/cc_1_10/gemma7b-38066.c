//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record
{
    char name[20];
    int account_number;
    double balance;
} Record;

Record records[MAX_RECORDS];

void add_record()
{
    int i = 0;
    for (i = 0; records[i].account_number != -1; i++)
    {
        ;
    }

    records[i].account_number = rand() % 100000;
    printf("Enter name: ");
    scanf("%s", records[i].name);
    printf("Enter initial balance: ");
    scanf("%lf", &records[i].balance);
    records[i].balance = records[i].balance;
}

void view_records()
{
    int i = 0;
    for (i = 0; records[i].account_number != -1; i++)
    {
        printf("Account Number: %d\n", records[i].account_number);
        printf("Name: %s\n", records[i].name);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("\n");
    }
}

void update_balance(int acc_no, double new_balance)
{
    int i = 0;
    for (i = 0; records[i].account_number != -1; i++)
    {
        if (records[i].account_number == acc_no)
        {
            records[i].balance = new_balance;
            return;
        }
    }

    printf("No record found for account number: %d\n", acc_no);
}

void main()
{
    int choice = 0;

    records[0].account_number = -1;

    while (choice != 3)
    {
        printf("Enter 1 to add a record, 2 to view records, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return;
}