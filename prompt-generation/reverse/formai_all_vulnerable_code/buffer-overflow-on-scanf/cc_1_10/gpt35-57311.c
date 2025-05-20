//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, quantity;
    float price, total_bill = 0;
    char menu_item[20], order[100] = "";

    printf("Welcome to the post-apocalyptic C Cafe!\n");
    printf("------------------------------\n");

    printf("\nMENU:\n");
    printf("1. Coffee\n");
    printf("2. Sandwiches\n");
    printf("3. Burgers\n");
    printf("4. Fries\n");
    printf("5. Nachos\n\n");

    while (1)
    {
        printf("Enter your choice (0 to end): ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("\nYou have ordered:\n%s", order);
            printf("Total bill = $%.2f\n", total_bill);
            printf("------------------------------\n");
            printf("Thank you for visiting the post-apocalyptic C Cafe!\n");
            break;
        }

        switch (choice)
        {
            case 1:
                strcpy(menu_item, "Coffee");
                price = 2.5;
                break;
            case 2:
                strcpy(menu_item, "Sandwiches");
                price = 4.0;
                break;
            case 3:
                strcpy(menu_item, "Burgers");
                price = 5.0;
                break;
            case 4:
                strcpy(menu_item, "Fries");
                price = 3.0;
                break;
            case 5:
                strcpy(menu_item, "Nachos");
                price = 3.5;
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if (quantity <= 0)
        {
            printf("Invalid quantity!\n");
            continue;
        }

        total_bill += price * quantity;
        sprintf(order, "%s%d %s\n", order, quantity, menu_item);
    }

    return 0;
}