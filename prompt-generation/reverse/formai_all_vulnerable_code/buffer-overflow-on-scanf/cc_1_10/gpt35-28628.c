//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <string.h>

// structure for storing hotel room information
struct Room
{
    int room_number;
    char room_type[20];
    float room_price;
    int room_occupied;
};

// function prototypes
void add_room(struct Room rooms[], int *num_of_rooms);
void display_rooms(struct Room rooms[], int num_of_rooms);
void check_in(struct Room rooms[], int num_of_rooms);
void check_out(struct Room rooms[], int num_of_rooms);

int main()
{
    struct Room rooms[50];  // array to store hotel rooms
    int num_of_rooms = 0;
    int choice;

    do
    {
        printf("\n----- HOTEL MANAGEMENT SYSTEM -----");
        printf("\n1. Add Room");
        printf("\n2. Display Rooms");
        printf("\n3. Check In");
        printf("\n4. Check Out");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_room(rooms, &num_of_rooms);
                break;
            case 2:
                display_rooms(rooms, num_of_rooms);
                break;
            case 3:
                check_in(rooms, num_of_rooms);
                break;
            case 4:
                check_out(rooms, num_of_rooms);
                break;
            case 5:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 5);

    return 0;
}

// function to add a new room to the system
void add_room(struct Room rooms[], int *num_of_rooms)
{
    printf("\nEnter room number: ");
    scanf("%d", &rooms[*num_of_rooms].room_number);

    printf("Enter room type: ");
    scanf("%s", rooms[*num_of_rooms].room_type);

    printf("Enter room price per night: ");
    scanf("%f", &rooms[*num_of_rooms].room_price);

    rooms[*num_of_rooms].room_occupied = 0;

    *num_of_rooms += 1;

    printf("\nRoom added successfully.");
}

// function to display all rooms in the system
void display_rooms(struct Room rooms[], int num_of_rooms)
{
    if (num_of_rooms == 0)
    {
        printf("\nNo rooms added yet.");
    }
    else
    {
        printf("\n----- LIST OF ROOMS -----");
        for (int i = 0; i < num_of_rooms; i++)
        {
            printf("\nRoom Number: %d", rooms[i].room_number);
            printf("\nRoom Type: %s", rooms[i].room_type);
            printf("\nRoom Price per Night: %.2f", rooms[i].room_price);
            if (rooms[i].room_occupied)
            {
                printf("\nRoom Status: OCCUPIED");
            }
            else
            {
                printf("\nRoom Status: AVAILABLE");
            }
            printf("\n");
        }
    }
}

// function for checking a guest into a room
void check_in(struct Room rooms[], int num_of_rooms)
{
    int room_number;

    printf("\nEnter room number to check-in: ");
    scanf("%d", &room_number);

    for (int i = 0; i < num_of_rooms; i++)
    {
        if (rooms[i].room_number == room_number)
        {
            if (rooms[i].room_occupied)
            {
                printf("\nRoom is already occupied.");
            }
            else
            {
                printf("\nEnter guest name: ");
                char guest_name[20];
                scanf("%s", guest_name);

                strcpy(rooms[i].room_type, guest_name);
                rooms[i].room_occupied = 1;

                printf("\nGuest checked in successfully.");
            }
            return;
        }
    }

    printf("\nRoom not found.");
}

// function for checking a guest out of a room
void check_out(struct Room rooms[], int num_of_rooms)
{
    int room_number;

    printf("\nEnter room number to check-out: ");
    scanf("%d", &room_number);

    for (int i = 0; i < num_of_rooms; i++)
    {
        if (rooms[i].room_number == room_number)
        {
            if (!rooms[i].room_occupied)
            {
                printf("\nRoom is already vacant.");
            }
            else
            {
                printf("\nGuest %s checked out of room %d.", rooms[i].room_type, room_number);
                rooms[i].room_occupied = 0;
                strcpy(rooms[i].room_type, "");
            }
            return;
        }
    }

    printf("\nRoom not found.");
}