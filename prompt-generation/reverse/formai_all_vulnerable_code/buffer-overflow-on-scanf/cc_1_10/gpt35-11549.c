//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold room information
typedef struct Room {
    int number;
    char type[20];
    char status[10];
    float price;
    struct Room *next;
} Room;

// Functions to manipulate room data
void addRoom(Room **rooms, int number, char type[], char status[], float price);
void editRoom(Room *rooms, int number);
void deleteRoom(Room **rooms, int number);
void displayRooms(Room *rooms);

int main() {
    // Initialize empty list of rooms
    Room *rooms = NULL;
    printf("Welcome to the C Hotel Management System!\n\n");

    // Main loop for system functionalities
    while (1) {
        int choice;
        printf("Please choose an option:\n");
        printf("1. Add a room\n");
        printf("2. Edit a room\n");
        printf("3. Delete a room\n");
        printf("4. Display all rooms\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new room to the list
                printf("\nAdding a new room:\n");
                int number;
                char type[20], status[10];
                float price;
                printf("Room number: ");
                scanf("%d", &number);
                printf("Room type: ");
                scanf("%s", type);
                printf("Room status: ");
                scanf("%s", status);
                printf("Room price per night: ");
                scanf("%f", &price);
                addRoom(&rooms, number, type, status, price);
                printf("\nRoom added successfully!\n");
                break;
            case 2:
                // Edit an existing room in the list
                printf("\nEditing a room:\n");
                printf("Enter the room number to edit: ");
                scanf("%d", &number);
                editRoom(rooms, number);
                break;
            case 3:
                // Delete an existing room from the list
                printf("\nDeleting a room:\n");
                printf("Enter the room number to delete: ");
                scanf("%d", &number);
                deleteRoom(&rooms, number);
                break;
            case 4:
                // Display all rooms in the list
                printf("\nDisplaying all rooms:\n");
                displayRooms(rooms);
                break;
            case 5:
                // Exit the program
                printf("\nExiting C Hotel Management System...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

// Function to add a new room to the list
void addRoom(Room **rooms, int number, char type[], char status[], float price) {
    Room *newRoom = (Room*) malloc(sizeof(Room));
    newRoom->number = number;
    strcpy(newRoom->type, type);
    strcpy(newRoom->status, status);
    newRoom->price = price;
    newRoom->next = (*rooms);
    (*rooms) = newRoom;
}

// Function to edit an existing room in the list
void editRoom(Room *rooms, int number) {
    while (rooms != NULL) {
        if (rooms->number == number) {
            printf("Current room type: %s\n", rooms->type);
            printf("Enter new room type: ");
            scanf("%s", rooms->type);
            printf("Current room status: %s\n", rooms->status);
            printf("Enter new room status: ");
            scanf("%s", rooms->status);
            printf("Current room price per night: %.2f\n", rooms->price);
            printf("Enter new room price per night: ");
            scanf("%f", &rooms->price);
            printf("\nRoom updated successfully!\n");
            return;
        }
        rooms = rooms->next;
    }
    printf("\nRoom not found.\n");
}

// Function to delete an existing room from the list
void deleteRoom(Room **rooms, int number) {
    Room *temp = *rooms, *prev;

    // If room to be deleted is the first node
    if (temp != NULL && temp->number == number) {
        *rooms = temp->next;
        free(temp);
        printf("\nRoom deleted successfully!\n");
        return;
    }

    // Traverse the list to find the room to be deleted
    while (temp != NULL && temp->number != number) {
        prev = temp;
        temp = temp->next;
    }

    // If room was not found
    if (temp == NULL) {
        printf("\nRoom not found.\n");
        return;
    }

    // Remove the room from the list
    prev->next = temp->next;
    free(temp);
    printf("\nRoom deleted successfully!\n");
}

// Function to display all rooms in the list
void displayRooms(Room *rooms) {
    if (rooms == NULL) {
        printf("No rooms to display.\n");
        return;
    }

    printf("%-15s %-20s %-10s %s\n", "Room Number", "Room Type", "Status", "Price per Night");
    while (rooms != NULL) {
        printf("%-15d %-20s %-10s %.2f\n", rooms->number, rooms->type, rooms->status, rooms->price);
        rooms = rooms->next;
    }
}