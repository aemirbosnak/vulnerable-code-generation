//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
    int choice, room_num, num_days, total_cost = 0, available = 1;
    char name[20];

    // Hotel Management System Menu
    printf("Welcome to the Grand Hotel!\n");
    printf("Please select an option:\n");
    printf("1. Make a reservation\n");
    printf("2. Check room availability\n");
    printf("3. View your reservation\n");
    printf("4. Cancel your reservation\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            // Make a reservation
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter the room number you want: ");
            scanf("%d", &room_num);
            printf("Enter the number of days you will be staying: ");
            scanf("%d", &num_days);

            total_cost = num_days * 50;
            available = 0;

            // Confirmation message
            printf("Your reservation has been made. Your room number is %d and the total cost is $%d.\n", room_num, total_cost);
            break;

        case 2:
            // Check room availability
            printf("Enter the room number you want to check: ");
            scanf("%d", &room_num);

            if (available)
            {
                printf("The room is available.\n");
            }
            else
            {
                printf("The room is not available.\n");
            }
            break;

        case 3:
            // View your reservation
            printf("Enter your name: ");
            scanf("%s", name);

            printf("Your reservation information:\n");
            printf("Name: %s\n", name);
            printf("Room number: %d\n", room_num);
            printf("Number of days: %d\n", num_days);
            printf("Total cost: $%d\n", total_cost);
            break;

        case 4:
            // Cancel your reservation
            printf("Enter your name: ");
            scanf("%s", name);

            // Confirmation message
            printf("Your reservation has been canceled.\n");
            available = 1;
            break;

        default:
            // Invalid input
            printf("Invalid input. Please try again.\n");
    }

    return 0;
}