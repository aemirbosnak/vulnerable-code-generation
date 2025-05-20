//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, quantity, i, total = 0;
    char item[20];

    // Coffee Menu
    printf("Welcome to the Coffee Cafe!\n");
    printf("Please select an item from the menu:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Milkshake\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            strcpy(item, "Coffee");
            printf("You selected: %s\n", item);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total += quantity * 50;
            break;
        case 2:
            strcpy(item, "Tea");
            printf("You selected: %s\n", item);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total += quantity * 30;
            break;
        case 3:
            strcpy(item, "Juice");
            printf("You selected: %s\n", item);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total += quantity * 20;
            break;
        case 4:
            strcpy(item, "Milkshake");
            printf("You selected: %s\n", item);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total += quantity * 40;
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    // Calculate Total Cost
    printf("Total cost: $%d\n", total);

    // Receipt
    printf("-----------------------------------\n");
    printf("Item: %s\n", item);
    printf("Quantity: %d\n", quantity);
    printf("Total Cost: $%d\n", total);
    printf("-----------------------------------\n");

    return 0;
}