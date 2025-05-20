//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the room structure
typedef struct Room
{
    char room_number[10];
    char room_type[20];
    int available_beds;
    float room_rate;
} Room;

// Define the guest structure
typedef struct Guest
{
    char guest_name[50];
    char guest_address[100];
    int guest_phone_number;
    char guest_room_number[10];
} Guest;

// Global variables
Room rooms[100];
Guest guests[100];

// Function to add a room
void add_room()
{
    // Get the room number, type, available beds, and rate
    printf("Enter the room number: ");
    scanf("%s", rooms[0].room_number);

    printf("Enter the room type: ");
    scanf("%s", rooms[0].room_type);

    printf("Enter the number of available beds: ");
    scanf("%d", &rooms[0].available_beds);

    printf("Enter the room rate: ");
    scanf("%f", &rooms[0].room_rate);
}

// Function to add a guest
void add_guest()
{
    // Get the guest name, address, phone number, and room number
    printf("Enter the guest name: ");
    scanf("%s", guests[0].guest_name);

    printf("Enter the guest address: ");
    scanf("%s", guests[0].guest_address);

    printf("Enter the guest phone number: ");
    scanf("%d", &guests[0].guest_phone_number);

    printf("Enter the guest room number: ");
    scanf("%s", guests[0].guest_room_number);
}

// Function to check if a room is available
int is_room_available(char *room_number)
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(rooms[i].room_number, room_number) == 0 && rooms[i].available_beds > 0)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check if a guest is registered
int is_guest_registered(char *guest_name)
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(guests[i].guest_name, guest_name) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Main function
int main()
{
    // Add a room
    add_room();

    // Add a guest
    add_guest();

    // Check if the room is available
    if (is_room_available("101"))
    {
        printf("The room is available.");
    } else
    {
        printf("The room is not available.");
    }

    // Check if the guest is registered
    if (is_guest_registered("John Doe"))
    {
        printf("The guest is registered.");
    } else
    {
        printf("The guest is not registered.");
    }

    return 0;
}