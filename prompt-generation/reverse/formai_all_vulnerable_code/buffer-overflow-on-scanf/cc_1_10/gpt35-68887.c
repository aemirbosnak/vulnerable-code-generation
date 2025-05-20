//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("*SURPRISED VOICE* Welcome to the C Banking Record System! \n");

    int numAccounts, i = 0;

    printf("How many bank accounts would you like to create? ");
    scanf("%d", &numAccounts);

    // Dynamically allocate space for the bank accounts
    char **accountNames = (char **)malloc(numAccounts * sizeof(char *));
    double *accountBalances = (double *)calloc(numAccounts, sizeof(double));

    // Loop through each account to get user input for account name and initial balance
    for (i = 0; i < numAccounts; i++)
    {
        char *tempName = (char *)malloc(50 * sizeof(char)); // Assume 50 character limit per account name

        printf("Enter account name for account %d: ", i + 1);
        scanf("%s", tempName);

        accountNames[i] = tempName;

        printf("Enter initial balance for account %d: ", i + 1);
        scanf("%lf", &accountBalances[i]);

        printf("New account %s with balance %.2lf created!\n", accountNames[i], accountBalances[i]);
    }

    // Prompt user for action in bank record system
    int menuChoice;
    do
    {
        printf("\nWhat would you like to do?\n");
        printf("1. View account balances\n");
        printf("2. Deposit into account\n");
        printf("3. Withdraw from account\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        int accountChoice;
        double transactionAmount;
        switch (menuChoice)
        {
        case 1:
            printf("\nAccount balances:\n");
            for (i = 0; i < numAccounts; i++)
            {
                printf("%d. %s: %.2lf\n", i + 1, accountNames[i], accountBalances[i]);
            }
            break;

        case 2:
            printf("\nEnter account number to deposit into: ");
            scanf("%d", &accountChoice);
            printf("Enter transaction amount: ");
            scanf("%lf", &transactionAmount);
            accountBalances[accountChoice - 1] += transactionAmount;

            printf("\n%.2lf deposited into account %s.\n", transactionAmount, accountNames[accountChoice - 1]);
            printf("New balance for account %s is %.2lf.\n", accountNames[accountChoice - 1], accountBalances[accountChoice - 1]);
            break;

        case 3:
            printf("\nEnter account number to withdraw from: ");
            scanf("%d", &accountChoice);
            printf("Enter transaction amount: ");
            scanf("%lf", &transactionAmount);

            if (transactionAmount > accountBalances[accountChoice - 1])
            {
                printf("\nError: Transaction amount greater than account balance.\n");
            }
            else
            {
                accountBalances[accountChoice - 1] -= transactionAmount;
                printf("\n%.2lf withdrawn from account %s.\n", transactionAmount, accountNames[accountChoice - 1]);
                printf("New balance for account %s is %.2lf.\n", accountNames[accountChoice - 1], accountBalances[accountChoice - 1]);
            }
            break;

        case 4:
            printf("\nThank you for using the C Banking Record System!\n");
            break;

        default:
            printf("\nInvalid input, please try again.\n");
            break;
        }
    } while (menuChoice != 4);

    // Free dynamically allocated memory
    for (i = 0; i < numAccounts; i++)
    {
        free(accountNames[i]);
    }
    free(accountNames);
    free(accountBalances);

    return 0;
}