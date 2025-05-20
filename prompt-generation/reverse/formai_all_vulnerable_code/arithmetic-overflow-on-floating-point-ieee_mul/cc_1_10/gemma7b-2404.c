//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void BankingRecordSystem()
{
    int account_number;
    char name[20];
    double balance;
    char transaction_type;
    double transaction_amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter balance: ");
    scanf("%lf", &balance);

    printf("Enter transaction type (D/W/B): ");
    scanf(" %c", &transaction_type);

    printf("Enter transaction amount: ");
    scanf("%lf", &transaction_amount);

    switch (transaction_type)
    {
        case 'D':
            balance += transaction_amount;
            break;
        case 'W':
            balance -= transaction_amount;
            break;
        case 'B':
            balance *= transaction_amount;
            break;
        default:
            printf("Invalid transaction type.\n");
    }

    printf("Updated balance: $%.2lf\n", balance);
}

int main()
{
    BankingRecordSystem();

    return 0;
}