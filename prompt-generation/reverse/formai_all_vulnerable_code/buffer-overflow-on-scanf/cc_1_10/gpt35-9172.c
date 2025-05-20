//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_ROOM_NUM 999

typedef struct Room {
    int roomNum;
    int numOfBeds;
    char roomType[20];
    char guestName[50];
    int guestLengthOfStay;
    int roomIsEmpty;
    int costPerNight;
} Room;

/* Function Prototypes */
void addRoom(Room* hotelRooms, int* numOfRooms);
void removeRoom(Room* hotelRooms, int* numOfRooms);
void bookRoom(Room* hotelRooms, int* numOfRooms);
void checkOutGuest(Room* hotelRooms, int* numOfRooms);
void printHotel(Room* hotelRooms, int numOfRooms);

int main() {
    int numOfRooms = 0;

    Room hotelRooms[MAX_ROOMS];

    while (1) {
        int choice;

        printf("Hotel Management System:\n");
        printf("1. Add a Room\n");
        printf("2. Remove a Room\n");
        printf("3. Book a Room\n");
        printf("4. Check Out a Guest\n");
        printf("5. Print Hotel Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom(hotelRooms, &numOfRooms);
                break;
            case 2:
                removeRoom(hotelRooms, &numOfRooms);
                break;
            case 3:
                bookRoom(hotelRooms, &numOfRooms);
                break;
            case 4:
                checkOutGuest(hotelRooms, &numOfRooms);
                break;
            case 5:
                printHotel(hotelRooms, numOfRooms);
                break;
            case 6:
                printf("Exiting Hotel Management System...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

/* Function Definitions */

void addRoom(Room* hotelRooms, int* numOfRooms) {
    if (*numOfRooms == MAX_ROOMS) {
        printf("Maximum number of rooms reached. Cannot add more rooms.\n");
        return;
    }

    int roomNum;
    while (1) {
        printf("Enter room number (between 100 and 999): ");
        scanf("%d", &roomNum);
        if (roomNum < 100 || roomNum > MAX_ROOM_NUM) {
            printf("Invalid room number. Try again.\n");
        } else {
            break;
        }
    }

    for (int i = 0; i < *numOfRooms; i++) {
        if (hotelRooms[i].roomNum == roomNum) {
            printf("Room already exists.\n");
            return;
        }
    }

    int numOfBeds;
    printf("Enter number of beds: ");
    scanf("%d", &numOfBeds);

    char roomType[20];
    printf("Enter room type (e.g. Single, Double): ");
    scanf("%s", roomType);

    int costPerNight;
    printf("Enter cost per night: ");
    scanf("%d", &costPerNight);

    hotelRooms[*numOfRooms].roomNum = roomNum;
    hotelRooms[*numOfRooms].numOfBeds = numOfBeds;
    strcpy(hotelRooms[*numOfRooms].roomType, roomType);
    hotelRooms[*numOfRooms].roomIsEmpty = 1;
    hotelRooms[*numOfRooms].costPerNight = costPerNight;

    (*numOfRooms)++;
}

void removeRoom(Room* hotelRooms, int* numOfRooms) {
    if (*numOfRooms == 0) {
        printf("Hotel has no rooms to remove.\n");
        return;
    }

    int roomNum;
    while (1) {
        printf("Enter room number to remove: ");
        scanf("%d", &roomNum);
        if (roomNum < 100 || roomNum > MAX_ROOM_NUM) {
            printf("Invalid room number. Try again.\n");
        } else {
            break;
        }
    }

    int found = 0;
    for (int i = 0; i < *numOfRooms; i++) {
        if (hotelRooms[i].roomNum == roomNum) {
            found = 1;
            if (hotelRooms[i].roomIsEmpty == 0) {
                printf("Room is occupied. Cannot remove.\n");
                return;
            }
            for (int j = i; j < *numOfRooms - 1; j++) {
                hotelRooms[j] = hotelRooms[j+1];
            }
            (*numOfRooms)--;
            printf("Room removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Room does not exist.\n");
        return;
    }
}

void bookRoom(Room* hotelRooms, int* numOfRooms) {
    if (*numOfRooms == 0) {
        printf("Hotel has no rooms to book.\n");
        return;
    }

    int roomNum;
    while (1) {
        printf("Enter room number to book: ");
        scanf("%d", &roomNum);
        if (roomNum < 100 || roomNum > MAX_ROOM_NUM) {
            printf("Invalid room number. Try again.\n");
        } else {
            break;
        }
    }

    for (int i = 0; i < *numOfRooms; i++) {
        if (hotelRooms[i].roomNum == roomNum) {
            if (hotelRooms[i].roomIsEmpty == 0) {
                printf("Room is already occupied.\n");
                return;
            }
            char guestName[50];
            printf("Enter guest name: ");
            scanf("%s", guestName);

            int guestLengthOfStay;
            printf("Enter length of stay (in days): ");
            scanf("%d", &guestLengthOfStay);

            hotelRooms[i].roomIsEmpty = 0;
            strcpy(hotelRooms[i].guestName, guestName);
            hotelRooms[i].guestLengthOfStay = guestLengthOfStay;
            printf("Room booked successfully.\n");
            return;
        }
    }

    printf("Room does not exist.\n");
}

void checkOutGuest(Room* hotelRooms, int* numOfRooms) {
    if (*numOfRooms == 0) {
        printf("Hotel has no guests to check out.\n");
        return;
    }

    int roomNum;
    while (1) {
        printf("Enter room number to check out: ");
        scanf("%d", &roomNum);
        if (roomNum < 100 || roomNum > MAX_ROOM_NUM) {
            printf("Invalid room number. Try again.\n");
        } else {
            break;
        }
    }

    for (int i = 0; i < *numOfRooms; i++) {
        if (hotelRooms[i].roomNum == roomNum) {
            if (hotelRooms[i].roomIsEmpty == 1) {
                printf("Room is not occupied.\n");
                return;
            }
            printf("Guest %s checked out of room %d.\n", hotelRooms[i].guestName, hotelRooms[i].roomNum);
            strcpy(hotelRooms[i].guestName, "");
            hotelRooms[i].guestLengthOfStay = 0;
            hotelRooms[i].roomIsEmpty = 1;
            return;
        }
    }

    printf("Room does not exist.\n");
}

void printHotel(Room* hotelRooms, int numOfRooms) {
    printf("Room Number\tNumber of Beds\tRoom Type\tCost Per Night\tGuest Name\t\tLength of Stay\n");
    printf("===================================================================================================\n");
    for (int i = 0; i < numOfRooms; i++) {
        printf("%d\t\t%d\t\t%s\t%d\t\t", hotelRooms[i].roomNum, hotelRooms[i].numOfBeds, hotelRooms[i].roomType, hotelRooms[i].costPerNight);
        if (hotelRooms[i].roomIsEmpty == 1) {
            printf("EMPTY\n");
        } else {
            printf("%s\t\t%d\n", hotelRooms[i].guestName, hotelRooms[i].guestLengthOfStay);
        }
    }
}