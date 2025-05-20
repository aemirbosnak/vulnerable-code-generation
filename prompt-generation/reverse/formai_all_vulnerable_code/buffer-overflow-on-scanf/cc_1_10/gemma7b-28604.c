//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Define a structure to store financial data
    typedef struct FinancialData
    {
        char name[50];
        double income;
        double expenses;
        double savings;
        double investments;
    } FinancialData;

    // Create an array of financial data structures
    FinancialData data[100];

    // Get the number of financial data entries
    int numEntries = 0;

    // Loop over the entries and get their data
    while (1)
    {
        printf("Enter name: ");
        scanf("%s", data[numEntries].name);

        printf("Enter income: ");
        scanf("%lf", &data[numEntries].income);

        printf("Enter expenses: ");
        scanf("%lf", &data[numEntries].expenses);

        printf("Enter savings: ");
        scanf("%lf", &data[numEntries].savings);

        printf("Enter investments: ");
        scanf("%lf", &data[numEntries].investments);

        numEntries++;

        // Check if the user wants to continue
        char continueInput;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continueInput);

        if (continueInput == 'N')
        {
            break;
        }
    }

    // Calculate the total assets and liabilities
    double totalAssets = 0;
    double totalLiabilities = 0;
    for (int i = 0; i < numEntries; i++)
    {
        totalAssets += data[i].savings + data[i].investments;
        totalLiabilities += data[i].expenses;
    }

    // Calculate the net worth
    double netWorth = totalAssets - totalLiabilities;

    // Print the results
    printf("Total Assets: $%.2lf\n", totalAssets);
    printf("Total Liabilities: $%.2lf\n", totalLiabilities);
    printf("Net Worth: $%.2lf\n", netWorth);

    return 0;
}