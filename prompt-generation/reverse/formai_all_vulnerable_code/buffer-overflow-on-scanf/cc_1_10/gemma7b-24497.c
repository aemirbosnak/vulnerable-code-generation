//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem
{
    char name[50];
    int room_no;
    char type[50];
    int available;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a new room into the hotel management system
void insertRoom(HotelManagementSystem* head)
{
    // Allocate memory for a new room
    HotelManagementSystem* newRoom = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));

    // Get the room number, type, and availability
    printf("Enter the room number: ");
    scanf("%d", &newRoom->room_no);

    printf("Enter the room type: ");
    scanf("%s", newRoom->type);

    printf("Enter the availability: ");
    scanf("%d", &newRoom->available);

    // Link the new room to the head of the system
    newRoom->next = head;
    head = newRoom;
}

// Function to search for a room in the hotel management system
void searchRoom(HotelManagementSystem* head)
{
    // Get the room number
    int roomNo;
    printf("Enter the room number: ");
    scanf("%d", &roomNo);

    // Search for the room
    HotelManagementSystem* currentRoom = head;
    while (currentRoom)
    {
        if (currentRoom->room_no == roomNo)
        {
            // Display the room information
            printf("Room name: %s\n", currentRoom->name);
            printf("Room type: %s\n", currentRoom->type);
            printf("Availability: %d\n", currentRoom->available);
            break;
        }
        currentRoom = currentRoom->next;
    }

    // If the room is not found, display an error message
    if (currentRoom == NULL)
    {
        printf("Room not found.\n");
    }
}

// Function to delete a room from the hotel management system
void deleteRoom(HotelManagementSystem* head)
{
    // Get the room number
    int roomNo;
    printf("Enter the room number: ");
    scanf("%d", &roomNo);

    // Search for the room
    HotelManagementSystem* previousRoom = NULL;
    HotelManagementSystem* currentRoom = head;
    while (currentRoom)
    {
        if (currentRoom->room_no == roomNo)
        {
            // If the room is the first room in the system, update the head of the system
            if (previousRoom == NULL)
            {
                head = currentRoom->next;
            }
            // Otherwise, delete the room from the linked list
            else
            {
                previousRoom->next = currentRoom->next;
            }
            free(currentRoom);
            break;
        }
        previousRoom = currentRoom;
        currentRoom = currentRoom->next;
    }

    // If the room is not found, display an error message
    if (currentRoom == NULL)
    {
        printf("Room not found.\n");
    }
}

int main()
{
    // Create a new hotel management system
    HotelManagementSystem* head = NULL;

    // Insert some rooms into the system
    insertRoom(head);
    insertRoom(head);
    insertRoom(head);

    // Search for a room in the system
    searchRoom(head);

    // Delete a room from the system
    deleteRoom(head);

    // Search for the room after deletion
    searchRoom(head);

    return 0;
}