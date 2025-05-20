//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void Banking_Record_System()
{
    system("clear");
    printf("Welcome to the C Banking Record System!\n");

    int account_number, amount, choice;
    char name[20];

    printf("Please enter your account number:");
    scanf("%d", &account_number);

    printf("Please enter your name:");
    scanf("%s", name);

    printf("Please select an option:");
    printf("\n1. Deposit\n2. Withdraw\n3. Transfer\n4. View Account Statement\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the amount you want to deposit:");
            scanf("%d", &amount);
            printf("Deposit successful!\n");
            break;
        case 2:
            printf("Enter the amount you want to withdraw:");
            scanf("%d", &amount);
            printf("Withdrawal successful!\n");
            break;
        case 3:
            printf("Enter the account number of the recipient:");
            scanf("%d", &account_number);
            printf("Enter the amount you want to transfer:");
            scanf("%d", &amount);
            printf("Transfer successful!\n");
            break;
        case 4:
            printf("Account statement:\n");
            printf("Account Number: %d\n", account_number);
            printf("Name: %s\n", name);
            printf("Balance: $%d\n", amount);
            break;
        default:
            printf("Invalid choice.\n");
    }

    Banking_Record_System();
}

int main()
{
    Banking_Record_System();

    return 0;
}