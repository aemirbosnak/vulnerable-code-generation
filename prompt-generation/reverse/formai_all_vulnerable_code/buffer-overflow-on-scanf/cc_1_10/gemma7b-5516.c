//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: retro
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

void display_records()
{
    int i = 0;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (records[i].balance > 0)
        {
            printf("%s, %d, %.2lf\n", records[i].name, records[i].account_number, records[i].balance);
        }
    }
}

void add_record()
{
    int i = 0;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (records[i].balance == 0)
        {
            printf("Enter name: ");
            scanf("%s", records[i].name);

            printf("Enter account number: ");
            scanf("%d", &records[i].account_number);

            printf("Enter balance: ");
            scanf("%lf", &records[i].balance);

            break;
        }
    }

    if (i == MAX_RECORDS)
    {
        printf("Error: No space for new record.\n");
    }
}

int main()
{
    int choice = 0;

    while (choice != 3)
    {
        printf("\nWelcome to the C Banking Record System!\n");
        printf("1. Display Records\n");
        printf("2. Add Record\n");
        printf("3. Exit\n");

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
            case 3:
                printf("Thank you for using the C Banking Record System.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}