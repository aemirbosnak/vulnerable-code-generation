//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 100

// Structure for a room
struct Room {
    int roomNumber;
    int numberOfBeds;
    float pricePerNight;
    char isAvailable[3];
};

// Global array to hold all rooms in the hotel
struct Room roomList[MAX_ROOMS];

// Function to get user input for a new room
struct Room getNewRoomData() {
    struct Room newRoom;
    printf("Enter Room Number: ");
    scanf("%d", &newRoom.roomNumber);
    printf("Enter Number of Beds: ");
    scanf("%d", &newRoom.numberOfBeds);
    printf("Enter Price per Night: ");
    scanf("%f", &newRoom.pricePerNight);
    strcpy(newRoom.isAvailable, "Yes");
    return newRoom;
}

// Function to add a new room to the hotel
void addNewRoom() {
    struct Room newRoom = getNewRoomData();
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (roomList[i].roomNumber == 0) {
            roomList[i] = newRoom;
            printf("New Room Added Successfully!\n");
            return;
        }
    }
    printf("Hotel is Full! Room Could not be Created.\n");
}

// Function to display the information of all rooms in the hotel
void displayAllRooms() {
    printf("Room Number\tNo. of Beds\tPrice per Night\tAvailable\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (roomList[i].roomNumber != 0) {
            printf("%d\t\t%d\t\t%.2f\t\t%s\n", roomList[i].roomNumber, roomList[i].numberOfBeds, roomList[i].pricePerNight, roomList[i].isAvailable);
        }
    }
}

// Function to update the availability of a room
void updateRoomAvailability(int roomNumber, char *availability) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (roomList[i].roomNumber == roomNumber) {
            strcpy(roomList[i].isAvailable, availability);
            printf("Room Availability Updated Successfully!\n");
            return;
        }
    }
    printf("Room with this Room Number does not exist!\n");
}

// Function to get user input for a room number and availability status
void updateRoomAvailabilityUI() {
    int roomNumber;
    char availability[3];
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);
    printf("Enter Availability (Yes/No): ");
    scanf("%s", availability);
    updateRoomAvailability(roomNumber, availability);
}

int main() {
    while(1) {
        printf("\n\nWelcome to C Hotel Management System\n");
        printf("1. Add New Room\n");
        printf("2. Display All Rooms Information\n");
        printf("3. Update Room Availability\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addNewRoom();
                break;
            case 2:
                displayAllRooms();
                break;
            case 3:
                updateRoomAvailabilityUI();
                break;
            case 4:
                printf("Thank You for Using C Hotel Management System\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}