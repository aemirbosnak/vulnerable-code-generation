//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
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

Guest* insertGuest(Guest* head, char* name, int room_no) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

Room* insertRoom(Room* head, int room_no, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

void checkIn(Guest* head, Room* headRoom) {
    char name[50];
    int room_no;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the room number: ");
    scanf("%d", &room_no);

    Guest* tempGuest = head;
    Room* tempRoom = headRoom;

    while (tempGuest) {
        if (strcmp(tempGuest->name, name) == 0) {
            while (tempRoom) {
                if (tempRoom->room_no == room_no && tempRoom->occupancy == 0) {
                    tempRoom->occupancy = 1;
                    tempGuest->room_no = room_no;
                    printf("Welcome to room %d, %s!", room_no, tempGuest->name);
                    break;
                }
                tempRoom = tempRoom->next;
            }
        }
        tempGuest = tempGuest->next;
    }

    if (tempGuest == NULL) {
        printf("Sorry, the guest does not exist.");
    }
}

void checkOut(Guest* head, Room* headRoom) {
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    Guest* tempGuest = head;

    while (tempGuest) {
        if (strcmp(tempGuest->name, name) == 0) {
            tempGuest->room_no = 0;
            printf("Thank you for staying at the hotel, %s!", tempGuest->name);
            break;
        }
        tempGuest = tempGuest->next;
    }

    if (tempGuest == NULL) {
        printf("Sorry, the guest does not exist.");
    }
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    int choice;

    while (1) {
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkOut(headGuest, headRoom);
                break;
            case 2:
                checkIn(headGuest, headRoom);
                break;
            default:
                printf("Invalid choice.");
                break;
        }

        printf("\n");
    }

    return 0;
}