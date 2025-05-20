//FormAI DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 30
#define MAX_NAME_LENGTH 50

struct Room {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int isBooked;
};

struct Room hotelRooms[MAX_ROOMS];

int findEmptyRoom()
{
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(!hotelRooms[i].isBooked) {
            return i;
        }
    }
    return -1;
}

void bookRoom(int roomNumber, char* guestName)
{
    int roomIndex = roomNumber - 1;
    if(roomIndex < 0 || roomIndex >= MAX_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }
    if(hotelRooms[roomIndex].isBooked) {
        printf("This room is already booked!\n");
        return;
    }
    strcpy(hotelRooms[roomIndex].guestName, guestName);
    hotelRooms[roomIndex].isBooked = 1;
    printf("Room %d has been booked for %s.\n", roomNumber, guestName);
}

void printRoomStatus()
{
    printf("Room Status\n-----------\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d - %s\n", hotelRooms[i].roomNumber, hotelRooms[i].isBooked ? hotelRooms[i].guestName : "Empty Room");
    }
}

int main()
{
    int choice = 0;
    do {
        printf("\n\nHotel Management System\n=======================\n1. Book Room\n2. Room Status\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char guestName[MAX_NAME_LENGTH];
                int roomNumber;
                printf("Enter guest name: ");
                scanf("%s", guestName);
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                bookRoom(roomNumber, guestName);
                break;
            }
            case 2: {
                printRoomStatus();
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while(choice != 3);
    return 0;
}