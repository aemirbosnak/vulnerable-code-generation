//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the Coffee Cafe!\n");
    printf("Please select your preferred brew:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Macchiato\n");
    printf("Enter your choice:");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You selected espresso. Please specify your preferred size:\n");
            printf("1. Small\n");
            printf("2. Medium\n");
            printf("3. Large\n");
            printf("Enter your size choice:");

            int size;
            scanf("%d", &size);

            switch (size)
            {
                case 1:
                    printf("Your order: Espresso small\n");
                    printf("Price: $2.50\n");
                    break;
                case 2:
                    printf("Your order: Espresso medium\n");
                    printf("Price: $3.00\n");
                    break;
                case 3:
                    printf("Your order: Espresso large\n");
                    printf("Price: $3.50\n");
                    break;
                default:
                    printf("Invalid size choice. Please try again.\n");
                    break;
            }
            break;
        case 2:
            printf("You selected cappuccino. Please specify your preferred size:\n");
            printf("1. Small\n");
            printf("2. Medium\n");
            printf("3. Large\n");
            printf("Enter your size choice:");

            scanf("%d", &size);

            switch (size)
            {
                case 1:
                    printf("Your order: Cappuccino small\n");
                    printf("Price: $3.00\n");
                    break;
                case 2:
                    printf("Your order: Cappuccino medium\n");
                    printf("Price: $3.50\n");
                    break;
                case 3:
                    printf("Your order: Cappuccino large\n");
                    printf("Price: $4.00\n");
                    break;
                default:
                    printf("Invalid size choice. Please try again.\n");
                    break;
            }
            break;
        case 3:
            printf("You selected latte. Please specify your preferred size:\n");
            printf("1. Small\n");
            printf("2. Medium\n");
            printf("3. Large\n");
            printf("Enter your size choice:");

            scanf("%d", &size);

            switch (size)
            {
                case 1:
                    printf("Your order: Latte small\n");
                    printf("Price: $2.00\n");
                    break;
                case 2:
                    printf("Your order: Latte medium\n");
                    printf("Price: $2.50\n");
                    break;
                case 3:
                    printf("Your order: Latte large\n");
                    printf("Price: $3.00\n");
                    break;
                default:
                    printf("Invalid size choice. Please try again.\n");
                    break;
            }
            break;
        case 4:
            printf("You selected macchiato. Please specify your preferred size:\n");
            printf("1. Small\n");
            printf("2. Medium\n");
            printf("3. Large\n");
            printf("Enter your size choice:");

            scanf("%d", &size);

            switch (size)
            {
                case 1:
                    printf("Your order: Macchiato small\n");
                    printf("Price: $3.00\n");
                    break;
                case 2:
                    printf("Your order: Macchiato medium\n");
                    printf("Price: $3.50\n");
                    break;
                case 3:
                    printf("Your order: Macchiato large\n");
                    printf("Price: $4.00\n");
                    break;
                default:
                    printf("Invalid size choice. Please try again.\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    system("pause");
    return 0;
}