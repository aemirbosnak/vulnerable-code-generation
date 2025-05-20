//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int rooms_available = 100;
    int current_bookings = 0;

    struct Room
    {
        int room_number;
        char status;
    } room;

    room.room_number = 1;
    room.status = 'O';

    room.room_number = 2;
    room.status = 'A';

    room.room_number = 3;
    room.status = 'O';

    room.room_number = 4;
    room.status = 'A';

    room.room_number = 5;
    room.status = 'O';

    printf("Welcome to the Hotel Management System!\n");
    printf("------------------------\n");
    printf("Rooms Available: %d\n", rooms_available - current_bookings);
    printf("Current Bookings: %d\n", current_bookings);

    printf("Please select an option:\n");
    printf("1. Book a room\n");
    printf("2. Cancel a booking\n");
    printf("3. Check room status\n");

    int option = 0;
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            if (rooms_available - current_bookings > 0)
            {
                printf("Enter your name: ");
                char name[20];
                scanf("%s", name);

                printf("Enter the number of rooms you want to book: ");
                int num_rooms;
                scanf("%d", &num_rooms);

                current_bookings += num_rooms;
                rooms_available -= num_rooms;

                printf("Your booking has been confirmed.\n");
                printf("Your name: %s\n", name);
                printf("Number of rooms booked: %d\n", num_rooms);
                printf("Total cost: $%d\n", num_rooms * 50);
            }
            else
            {
                printf("Sorry, no rooms are available.");
            }
            break;

        case 2:
            printf("Enter your name: ");
            char name[20];
            scanf("%s", name);

            printf("Enter the number of rooms you want to cancel: ");
            int num_rooms;
            scanf("%d", &num_rooms);

            current_bookings -= num_rooms;
            rooms_available += num_rooms;

            printf("Your booking has been cancelled.\n");
            printf("Your name: %s\n", name);
            printf("Number of rooms cancelled: %d\n", num_rooms);
            break;

        case 3:
            printf("Enter the room number you want to check: ");
            int room_number;
            scanf("%d", &room_number);

            for (int i = 0; i < 5; i++)
            {
                if (room.room_number == room_number)
                {
                    printf("Room number: %d\n", room.room_number);
                    printf("Status: %c\n", room.status);
                }
            }
            break;

        default:
            printf("Invalid option.");
    }

    return 0;
}