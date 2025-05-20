//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateBill()
{
    system("cls");
    printf("-----------------------------------------------------------------------\n");
    printf("                         Grateful Cafe Billing System\n");
    printf("-----------------------------------------------------------------------\n");

    // Get customer name
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Get number of items ordered
    int numItems = 0;
    printf("Enter the number of items you ordered: ");
    scanf("%d", &numItems);

    // Create an array of item names
    char items[numItems][20];

    // Get item names
    for (int i = 0; i < numItems; i++)
    {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i]);
    }

    // Get item prices
    double prices[numItems];

    // Get item prices
    for (int i = 0; i < numItems; i++)
    {
        printf("Enter the price of item %d: ", i + 1);
        scanf("%lf", &prices[i]);
    }

    // Calculate total cost
    double totalCost = 0.0;
    for (int i = 0; i < numItems; i++)
    {
        totalCost += prices[i] * items[i][0];
    }

    // Print bill
    printf("-----------------------------------------------------------------------\n");
    printf("Customer Name: %s\n", name);
    printf("Number of Items: %d\n", numItems);
    printf("Items:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - %lf\n", items[i], prices[i]);
    }
    printf("Total Cost: %.2lf\n", totalCost);
    printf("Thank you for visiting the Grateful Cafe!\n");
    printf("-----------------------------------------------------------------------\n");

    // Pause
    system("pause");
}

int main()
{
    generateBill();
    return 0;
}