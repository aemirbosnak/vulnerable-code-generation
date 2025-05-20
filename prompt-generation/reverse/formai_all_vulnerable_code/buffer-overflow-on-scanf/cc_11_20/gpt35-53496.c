//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room_details
{
    int room_no;
    int room_type;
    int room_price;
    char room_status[10];
};

int main()
{
    struct room_details rooms[100];
    int total_rooms, i, room_to_book, user_choice;
    int booked_rooms_count = 0;
    int available_rooms_count = 0;

    printf("Welcome to C Hotel Management System!\n");
    printf("------------------------------------\n");
    printf("Enter the total number of rooms in the hotel: ");
    scanf("%d", &total_rooms);

    for (i = 0; i < total_rooms; i++)
    {
        rooms[i].room_no = i + 1;
        printf("\nEnter the room type of room %d (1 for Single, 2 for Double, 3 for Suite): ", rooms[i].room_no);
        scanf("%d", &rooms[i].room_type);

        if (rooms[i].room_type == 1)
            rooms[i].room_price = 100;
        else if (rooms[i].room_type == 2)
            rooms[i].room_price = 150;
        else if (rooms[i].room_type == 3)
            rooms[i].room_price = 200;

        strcpy(rooms[i].room_status, "Available");

        available_rooms_count++;
    }

    while (1)
    {
        printf("\n---------------------------------------\n");
        printf("1. Book a Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        if (user_choice == 1)
        {
            printf("\nEnter the room number you want to book: ");
            scanf("%d", &room_to_book);

            if (room_to_book < 1 || room_to_book > total_rooms)
            {
                printf("\nInvalid Room Number!\n");
            }
            else
            {
                if (strcmp(rooms[room_to_book - 1].room_status, "Booked") == 0)
                {
                    printf("\nRoom is already booked!\n");
                }
                else
                {
                    printf("\nRoom Booked Successfully!\n");
                    strcpy(rooms[room_to_book - 1].room_status, "Booked");
                    booked_rooms_count++;
                    available_rooms_count--;
                }
            }
        }
        else if (user_choice == 2)
        {
            printf("\nRoom No.\tRoom Type\tPrice\t\tStatus\n");
            printf("--------------------------------------------------------\n");

            for (i = 0; i < total_rooms; i++)
            {
                if (rooms[i].room_type == 1)
                    printf("%d\t\tSingle\t\t$%d\t\t%s\n", rooms[i].room_no, rooms[i].room_price, rooms[i].room_status);
                else if (rooms[i].room_type == 2)
                    printf("%d\t\tDouble\t\t$%d\t\t%s\n", rooms[i].room_no, rooms[i].room_price, rooms[i].room_status);
                else if (rooms[i].room_type == 3)
                    printf("%d\t\tSuite\t\t$%d\t\t%s\n", rooms[i].room_no, rooms[i].room_price, rooms[i].room_status);
            }
            printf("--------------------------------------------------------\n");
            printf("Total Rooms: %d\n", total_rooms);
            printf("Booked Rooms: %d\n", booked_rooms_count);
            printf("Available Rooms: %d\n", available_rooms_count);
        }
        else if (user_choice == 3)
        {
            printf("\nExiting Program. Thank you!\n");
            break;
        }
        else
        {
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}