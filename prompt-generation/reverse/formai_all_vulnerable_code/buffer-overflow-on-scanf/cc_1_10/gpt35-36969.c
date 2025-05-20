//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing hotel room details
typedef struct {
    int roomNumber;
    char roomType[10];
    char guestName[30];
    int days;
    float price;
} Room;

// Function to create new room
Room createNewRoom(int roomNumber) {
    Room newRoom;
    newRoom.roomNumber = roomNumber;
    printf("Enter room type (Single/Double): ");
    scanf("%s", newRoom.roomType);
    printf("Enter guest name: ");
    scanf("%s", newRoom.guestName);
    printf("Enter number of days: ");
    scanf("%d", &newRoom.days);
    if(strcmp(newRoom.roomType, "Single") == 0) {
        newRoom.price = 100 * newRoom.days;
    } else if(strcmp(newRoom.roomType, "Double") == 0) {
        newRoom.price = 150 * newRoom.days;
    }
    printf("New room with room number %d created.\n", roomNumber);
    return newRoom;
}

// Function to display room info
void displayRoomInfo(Room room) {
    printf("Room Number: %d\n", room.roomNumber);
    printf("Room Type: %s\n", room.roomType);
    printf("Guest Name: %s\n", room.guestName);
    printf("Number of Days: %d\n", room.days);
    printf("Price: %.2f\n\n", room.price);
}

// Main function
int main() {
    Room hotelRooms[50];
    int choice, i, roomNumber, numRooms=0;
    do {
        printf("\nHotel Management System Menu\n");
        printf("1. Add New Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Display Room Info\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                hotelRooms[numRooms] = createNewRoom(roomNumber);
                numRooms++;
                break;
            case 2:
                if(numRooms == 0) {
                    printf("No rooms added yet.\n");
                } else {
                    printf("List of all rooms:\n");
                    for(i=0; i<numRooms; i++) {
                        displayRoomInfo(hotelRooms[i]);
                    }
                }
                break;
            case 3:
                if(numRooms == 0) {
                    printf("No rooms added yet.\n");
                } else {
                    printf("Enter room number: ");
                    scanf("%d", &roomNumber);
                    for(i=0; i<numRooms; i++) {
                        if(hotelRooms[i].roomNumber == roomNumber) {
                            displayRoomInfo(hotelRooms[i]);
                            break;
                        }
                        if(i == numRooms-1) {
                            printf("Room not found.\n");
                        }
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}