//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    // System Variables
    char username[20];
    int item_num;
    float total_cost = 0.0f;
    char item_name[50];
    int quantity;

    // Menu Display
    printf("\nWelcome to the Neon Brew Cafe!\n");
    printf("--------------------\n");
    printf("Menu:\n");
    printf("1. Cyber Brew - $5.00\n");
    printf("2. Electric Brew - $6.00\n");
    printf("3. Quantum Brew - $7.00\n");
    printf("4. Quantum Fusion - $8.00\n");
    printf("Enter item number:");

    // User Input
    scanf("%d", &item_num);

    // Item Selection
    switch (item_num)
    {
        case 1:
            strcpy(item_name, "Cyber Brew");
            quantity = 1;
            total_cost += 5.00f;
            break;
        case 2:
            strcpy(item_name, "Electric Brew");
            quantity = 1;
            total_cost += 6.00f;
            break;
        case 3:
            strcpy(item_name, "Quantum Brew");
            quantity = 1;
            total_cost += 7.00f;
            break;
        case 4:
            strcpy(item_name, "Quantum Fusion");
            quantity = 1;
            total_cost += 8.00f;
            break;
        default:
            printf("Invalid item number.\n");
            exit(1);
    }

    // Order Confirmation
    printf("\nOrder Confirmation:");
    printf("\nItem name: %s", item_name);
    printf("\nQuantity: %d", quantity);
    printf("\nTotal cost: $%.2f", total_cost);

    // Payment Processing
    printf("\nPlease pay the total cost to the bartender.");

    // System Exit
    printf("\nThank you for visiting the Neon Brew Cafe! See you next time!");
    exit(0);
}