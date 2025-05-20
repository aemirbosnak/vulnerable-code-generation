//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define NAME_LEN 50
#define BOOKED 'Y'
#define VACANT 'N'

typedef struct {
    int roomNumber;
    char guestName[NAME_LEN];
    char status; // 'Y' for booked, 'N' for vacant
} Room;

Room hotel[MAX_ROOMS];
int totalRooms = 0;

void addRoom(int roomNumber) {
    if (totalRooms >= MAX_ROOMS) {
        printf("Maximum room capacity reached.\n");
        return;
    }
    hotel[totalRooms].roomNumber = roomNumber;
    strcpy(hotel[totalRooms].guestName, "");
    hotel[totalRooms].status = VACANT;
    totalRooms++;
    printf("Room number %d added successfully.\n", roomNumber);
}

void bookRoom(int roomNumber, const char* guestName) {
    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == roomNumber) {
            if (hotel[i].status == VACANT) {
                strcpy(hotel[i].guestName, guestName);
                hotel[i].status = BOOKED;
                printf("Room number %d booked successfully for %s.\n", roomNumber, guestName);
                return;
            } else {
                printf("Room number %d is already booked.\n", roomNumber);
                return;
            }
        }
    }
    printf("Room number %d not found.\n", roomNumber);
}

void vacateRoom(int roomNumber) {
    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == roomNumber) {
            if (hotel[i].status == BOOKED) {
                printf("Room number %d is vacated by %s.\n", roomNumber, hotel[i].guestName);
                hotel[i].status = VACANT;
                strcpy(hotel[i].guestName, "");
                return;
            } else {
                printf("Room number %d is already vacant.\n", roomNumber);
                return;
            }
        }
    }
    printf("Room number %d not found.\n", roomNumber);
}

void displayRooms() {
    printf("Room Number\tGuest Name\tStatus\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < totalRooms; i++) {
        printf("%d\t\t%s\t\t%c\n", hotel[i].roomNumber, hotel[i].guestName[0] ? hotel[i].guestName : "None", hotel[i].status);
    }
}

int main() {
    int choice;
    int roomNumber;
    char guestName[NAME_LEN];

    do {
        printf("\nHotel Management System\n");
        printf("1. Add Room\n");
        printf("2. Book Room\n");
        printf("3. Vacate Room\n");
        printf("4. Display Rooms\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter room number to add: ");
                scanf("%d", &roomNumber);
                addRoom(roomNumber);
                break;
            case 2:
                printf("Enter room number to book: ");
                scanf("%d", &roomNumber);
                printf("Enter guest name: ");
                scanf("%s", guestName);
                bookRoom(roomNumber, guestName);
                break;
            case 3:
                printf("Enter room number to vacate: ");
                scanf("%d", &roomNumber);
                vacateRoom(roomNumber);
                break;
            case 4:
                displayRooms();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}