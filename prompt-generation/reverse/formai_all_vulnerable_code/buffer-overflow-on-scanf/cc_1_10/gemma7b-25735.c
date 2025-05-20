//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_no);

    newGuest->next = head;
    head = newGuest;

    return head;
}

Room* insertRoom(Room* head) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%d", &newRoom->room_no);
    printf("Enter occupancy: ");
    scanf("%d", &newRoom->occupancy);

    newRoom->next = head;
    head = newRoom;

    return head;
}

void checkIn(Guest* head, Room* headRoom) {
    printf("Enter guest name: ");
    char guestName[50];
    scanf("%s", guestName);

    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(currentGuest->name, guestName) == 0) {
            int roomNo = currentGuest->room_no;
            Room* currentRoom = headRoom;
            while (currentRoom) {
                if (currentRoom->room_no == roomNo) {
                    if (currentRoom->occupancy == 0) {
                        currentRoom->occupancy = 1;
                        printf("Guest %s has checked in to room %d.\n", currentGuest->name, roomNo);
                        break;
                    } else {
                        printf("Room %d is already occupied.\n", roomNo);
                    }
                }
                currentRoom = currentRoom->next;
            }
        }
        currentGuest = currentGuest->next;
    }

    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

void checkOut(Guest* head, Room* headRoom) {
    printf("Enter guest name: ");
    char guestName[50];
    scanf("%s", guestName);

    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(currentGuest->name, guestName) == 0) {
            int roomNo = currentGuest->room_no;
            Room* currentRoom = headRoom;
            while (currentRoom) {
                if (currentRoom->room_no == roomNo) {
                    if (currentRoom->occupancy == 1) {
                        currentRoom->occupancy = 0;
                        printf("Guest %s has checked out of room %d.\n", currentGuest->name, roomNo);
                        break;
                    } else {
                        printf("Room %d is not occupied.\n", roomNo);
                    }
                }
                currentRoom = currentRoom->next;
            }
        }
        currentGuest = currentGuest->next;
    }

    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    insertGuest(headGuest);
    insertGuest(headGuest);
    insertRoom(headRoom);
    insertRoom(headRoom);

    checkOut(headGuest, headRoom);
    checkOut(headGuest, headRoom);

    return 0;
}