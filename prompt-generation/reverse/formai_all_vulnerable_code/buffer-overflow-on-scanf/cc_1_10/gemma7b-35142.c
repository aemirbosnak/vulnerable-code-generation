//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem
{
    char name[50];
    int room_number;
    double room_price;
    char room_type;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a room into the hotel management system
void insertRoom(HotelManagementSystem** head)
{
    // Allocate memory for the new room
    HotelManagementSystem* newRoom = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));

    // Get the room details from the user
    printf("Enter the room name: ");
    scanf("%s", newRoom->name);

    printf("Enter the room number: ");
    scanf("%d", &newRoom->room_number);

    printf("Enter the room price: ");
    scanf("%lf", &newRoom->room_price);

    printf("Enter the room type: ");
    scanf("%c", &newRoom->room_type);

    // Insert the new room into the linked list
    if (*head == NULL)
    {
        *head = newRoom;
    }
    else
    {
        (*head)->next = newRoom;
        *head = newRoom;
    }
}

// Function to search for a room in the hotel management system
void searchRoom(HotelManagementSystem* head)
{
    // Get the room number from the user
    int roomNumber;
    printf("Enter the room number: ");
    scanf("%d", &roomNumber);

    // Search for the room
    HotelManagementSystem* currentRoom = head;
    while (currentRoom)
    {
        if (currentRoom->room_number == roomNumber)
        {
            // Display the room details
            printf("Room name: %s\n", currentRoom->name);
            printf("Room number: %d\n", currentRoom->room_number);
            printf("Room price: %.2lf\n", currentRoom->room_price);
            printf("Room type: %c\n", currentRoom->room_type);
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

int main()
{
    // Create a linked list of rooms
    HotelManagementSystem* head = NULL;

    // Insert some rooms into the linked list
    insertRoom(&head);
    insertRoom(&head);
    insertRoom(&head);

    // Search for a room in the linked list
    searchRoom(head);

    return 0;
}