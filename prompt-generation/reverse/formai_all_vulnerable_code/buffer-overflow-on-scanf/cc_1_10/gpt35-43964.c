//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <string.h>
#define MAX_TRANS 100

int main()
{
    int gold_balance = 1000; // Starting balance
    int num_transactions = 0; // Number of transactions
    int i;
    char type[10], desc[50]; // Type and description of transaction
    int amount; // Amount of gold spent/earned
    struct Transaction {
        char type[10];
        char desc[50];
        int amount;
    } transactions[MAX_TRANS]; // Array to store transactions
    
    printf("Welcome to the Medieval Expense Tracker!\n\n");
    printf("Starting gold balance: %d\n\n", gold_balance);
    
    while(1)
    {
        printf("Enter transaction type (spend/earn): ");
        scanf("%s", type);
        if(strcmp(type, "spend") == 0)
        {
            printf("Enter amount spent: ");
            scanf("%d", &amount);
            if(amount > gold_balance)
            {
                printf("You cannot spend more gold than you have!\n");
                continue;
            }
            printf("Enter description: ");
            scanf(" %[^\n]s", desc);
            gold_balance -= amount;
            strcpy(transactions[num_transactions].type, type);
            strcpy(transactions[num_transactions].desc, desc);
            transactions[num_transactions].amount = amount;
            num_transactions++;
        }
        else if(strcmp(type, "earn") == 0)
        {
            printf("Enter amount earned: ");
            scanf("%d", &amount);
            printf("Enter description: ");
            scanf(" %[^\n]s", desc);
            gold_balance += amount;
            strcpy(transactions[num_transactions].type, type);
            strcpy(transactions[num_transactions].desc, desc);
            transactions[num_transactions].amount = amount;
            num_transactions++;
        }
        else if(strcmp(type, "quit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid transaction type.\n");
        }
        printf("Current gold balance: %d\n\n", gold_balance);
    }
    
    // Print transaction history
    printf("Transaction history:\n");
    for(i = 0; i < num_transactions; i++)
    {
        printf("%s %d gold - %s\n", transactions[i].type, transactions[i].amount, transactions[i].desc);
    }
    printf("\nFinal gold balance: %d\n", gold_balance);
    
    return 0;
}