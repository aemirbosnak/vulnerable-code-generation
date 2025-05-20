//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of rooms
#define MAX_ROOMS 100

// Room structure
typedef struct
{
    int roomNumber;
    char guestName[50];
    int numOccupants;
    int numNights;
    float rate;
    float bill;
} Room;

// Function prototypes
void addRoom(Room rooms[], int* numRooms);
void removeRoom(Room rooms[], int* numRooms);
void displayRooms(Room rooms[], int numRooms);
void checkIn(Room rooms[], int numRooms);
void checkOut(Room rooms[], int numRooms);

int main()
{
    // Define variables
    Room rooms[MAX_ROOMS];
    int numRooms = 0;
    int choice;
    
    // Main menu
    do
    {
        printf("*** C Hotel Management System ***\n\n");
        printf("1. Add a room\n");
        printf("2. Remove a room\n");
        printf("3. Display all rooms\n");
        printf("4. Check in a guest\n");
        printf("5. Check out a guest\n");
        printf("6. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addRoom(rooms, &numRooms);
                break;
            case 2:
                removeRoom(rooms, &numRooms);
                break;
            case 3:
                displayRooms(rooms, numRooms);
                break;
            case 4:
                checkIn(rooms, numRooms);
                break;
            case 5:
                checkOut(rooms, numRooms);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 6);
    
    return 0;
}

// Function to add a room
void addRoom(Room rooms[], int* numRooms)
{
    // Check if there is still room to add a new room
    if (*numRooms >= MAX_ROOMS)
    {
        printf("Error: Maximum number of rooms reached.\n");
        return;
    }
    
    // Get room info from user
    printf("Enter room number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);
    printf("Enter rate per night: ");
    scanf("%f", &rooms[*numRooms].rate);
    
    // Increment number of rooms
    (*numRooms)++;
    
    printf("Room added successfully.\n");
}

// Function to remove a room
void removeRoom(Room rooms[], int* numRooms)
{
    // Check if there are no rooms to remove
    if (*numRooms == 0)
    {
        printf("Error: No rooms to remove.\n");
        return;
    }
    
    // Get room number from user
    int roomNumber;
    printf("Enter room number to remove: ");
    scanf("%d", &roomNumber);
    
    // Look for room in array
    int i, found = 0;
    for (i = 0; i < *numRooms; i++)
    {
        if (rooms[i].roomNumber == roomNumber)
        {
            found = 1;
            break;
        }
    }
    
    if (found)
    {
        // Shift all rooms after this one back by one
        for (; i < *numRooms - 1; i++)
        {
            rooms[i] = rooms[i+1];
        }
        
        // Decrement number of rooms
        (*numRooms)--;
        
        printf("Room removed successfully.\n");
    }
    else
    {
        printf("Error: Room not found.\n");
    }
}

// Function to display all rooms
void displayRooms(Room rooms[], int numRooms)
{
    // Check if there are no rooms to display
    if (numRooms == 0)
    {
        printf("No rooms to display.\n");
        return;
    }
    
    // Print table header
    printf("%-10s %-20s %-15s %-10s %-10s\n", "Room #", "Guest Name", "Occupants", "Nights", "Bill");
    
    // Print each room
    int i;
    for (i = 0; i < numRooms; i++)
    {
        printf("%-10d %-20s %-15d %-10d $%-10.2f\n", rooms[i].roomNumber, rooms[i].guestName, rooms[i].numOccupants, rooms[i].numNights, rooms[i].bill);
    }
}

// Function to check in a guest
void checkIn(Room rooms[], int numRooms)
{
    // Check if there are no rooms to check in to
    if (numRooms == 0)
    {
        printf("Error: No rooms available.\n");
        return;
    }
    
    // Get room number from user
    int roomNumber;
    printf("Enter room number to check in to: ");
    scanf("%d", &roomNumber);
    
    // Look for room in array
    int i, found = 0;
    for (i = 0; i < numRooms; i++)
    {
        if (rooms[i].roomNumber == roomNumber)
        {
            found = 1;
            break;
        }
    }
    
    if (found)
    {
        // Get guest info from user
        printf("Enter guest name: ");
        scanf("%s", rooms[i].guestName);
        printf("Enter number of occupants: ");
        scanf("%d", &rooms[i].numOccupants);
        printf("Enter number of nights: ");
        scanf("%d", &rooms[i].numNights);
        
        // Calculate and set bill
        rooms[i].bill = rooms[i].numNights * rooms[i].rate;
        
        printf("Guest checked in successfully.\n");
    }
    else
    {
        printf("Error: Room not found.\n");
    }
}

// Function to check out a guest
void checkOut(Room rooms[], int numRooms)
{
    // Check if there are no rooms to check out of
    if (numRooms == 0)
    {
        printf("Error: No rooms occupied.\n");
        return;
    }
    
    // Get room number from user
    int roomNumber;
    printf("Enter room number to check out of: ");
    scanf("%d", &roomNumber);
    
    // Look for room in array
    int i, found = 0;
    for (i = 0; i < numRooms; i++)
    {
        if (rooms[i].roomNumber == roomNumber)
        {
            found = 1;
            break;
        }
    }
    
    if (found)
    {
        // Remove guest info from room
        strcpy(rooms[i].guestName, "");
        rooms[i].numOccupants = 0;
        rooms[i].numNights = 0;
        rooms[i].bill = 0;
        
        printf("Guest checked out successfully.\n");
    }
    else
    {
        printf("Error: Room not found.\n");
    }
}