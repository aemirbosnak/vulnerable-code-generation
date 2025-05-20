//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Define the Hotel Management System structure
typedef struct HotelManagementSystem
{
    char name[50];
    int room_number;
    char room_type[50];
    int available;
    double price;
} HotelManagementSystem;

// Create a function to add a room to the hotel management system
void add_room(HotelManagementSystem *hms)
{
    printf("Enter the room name: ");
    scanf("%s", hms->name);

    printf("Enter the room number: ");
    scanf("%d", &hms->room_number);

    printf("Enter the room type: ");
    scanf("%s", hms->room_type);

    printf("Enter the availability: ");
    scanf("%d", &hms->available);

    printf("Enter the price: ");
    scanf("%lf", &hms->price);
}

// Create a function to list all rooms in the hotel management system
void list_rooms(HotelManagementSystem *hms)
{
    for (int i = 0; i < hms->available; i++)
    {
        printf("Name: %s\n", hms->name);
        printf("Room Number: %d\n", hms->room_number);
        printf("Room Type: %s\n", hms->room_type);
        printf("Available: %d\n", hms->available);
        printf("Price: %.2lf\n", hms->price);
        printf("\n");
    }
}

int main()
{
    // Create an instance of the hotel management system
    HotelManagementSystem hms;

    // Add a room to the hotel management system
    add_room(&hms);

    // List all rooms in the hotel management system
    list_rooms(&hms);

    return 0;
}