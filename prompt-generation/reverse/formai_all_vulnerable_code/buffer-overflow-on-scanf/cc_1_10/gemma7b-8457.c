//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int room_number;
    char room_type;
    double price;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a room into the hotel management system
void insertRoom(HotelManagementSystem** head) {
    // Allocate memory for the new room
    HotelManagementSystem* newRoom = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));

    // Get the room name, number, type, and price
    printf("Enter the room name: ");
    scanf("%s", newRoom->name);

    printf("Enter the room number: ");
    scanf("%d", &newRoom->room_number);

    printf("Enter the room type: ");
    scanf("%c", &newRoom->room_type);

    printf("Enter the room price: ");
    scanf("%lf", &newRoom->price);

    // Insert the new room into the system
    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Function to search for a room in the hotel management system
void searchRoom(HotelManagementSystem* head) {
    // Get the room number
    int roomNumber;
    printf("Enter the room number: ");
    scanf("%d", &roomNumber);

    // Search for the room
    HotelManagementSystem* currentRoom = head;
    while (currentRoom) {
        if (currentRoom->room_number == roomNumber) {
            // Display the room information
            printf("Name: %s\n", currentRoom->name);
            printf("Room Number: %d\n", currentRoom->room_number);
            printf("Room Type: %c\n", currentRoom->room_type);
            printf("Price: %.2lf\n", currentRoom->price);
            break;
        }
        currentRoom = currentRoom->next;
    }

    // If the room is not found, display an error message
    if (currentRoom == NULL) {
        printf("Room not found.\n");
    }
}

// Function to delete a room from the hotel management system
void deleteRoom(HotelManagementSystem* head) {
    // Get the room number
    int roomNumber;
    printf("Enter the room number: ");
    scanf("%d", &roomNumber);

    // Search for the room
    HotelManagementSystem* currentRoom = head;
    HotelManagementSystem* previousRoom = NULL;
    while (currentRoom) {
        if (currentRoom->room_number == roomNumber) {
            // Delete the room
            if (previousRoom) {
                previousRoom->next = currentRoom->next;
            } else {
                head = currentRoom->next;
            }
            free(currentRoom);
            break;
        }
        previousRoom = currentRoom;
        currentRoom = currentRoom->next;
    }

    // If the room is not found, display an error message
    if (currentRoom == NULL) {
        printf("Room not found.\n");
    }
}

// Main function
int main() {
    // Create a head of the hotel management system
    HotelManagementSystem* head = NULL;

    // Insert some rooms into the system
    insertRoom(&head);
    insertRoom(&head);
    insertRoom(&head);

    // Search for a room
    searchRoom(head);

    // Delete a room
    deleteRoom(head);

    // Search for the room after deletion
    searchRoom(head);

    return 0;
}