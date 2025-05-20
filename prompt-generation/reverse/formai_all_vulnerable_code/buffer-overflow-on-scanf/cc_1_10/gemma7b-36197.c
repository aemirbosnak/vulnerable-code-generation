//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest *next;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    struct Room *next;
} Room;

Guest *insertGuest(Guest *head) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_no);
    newGuest->next = head;
    head = newGuest;
    return head;
}

Room *insertRoom(Room *head) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    printf("Enter the room number: ");
    scanf("%d", &newRoom->room_no);
    printf("Enter the occupancy: ");
    scanf("%d", &newRoom->occupancy);
    newRoom->next = head;
    head = newRoom;
    return head;
}

void checkIn(Guest *head) {
    printf("Enter your name: ");
    char guestName[50];
    scanf("%s", guestName);
    Guest *guest = head;
    while (guest) {
        if (strcmp(guest->name, guestName) == 0) {
            printf("Welcome, %s! Your room number is %d.", guest->name, guest->room_no);
            break;
        }
        guest = guest->next;
    }
    if (guest == NULL) {
        printf("Guest not found.");
    }
}

void checkOut(Guest *head) {
    printf("Enter your name: ");
    char guestName[50];
    scanf("%s", guestName);
    Guest *guest = head;
    while (guest) {
        if (strcmp(guest->name, guestName) == 0) {
            printf("Thank you for your stay, %s. Have a nice day.", guest->name);
            free(guest);
            guest = NULL;
            break;
        }
        guest = guest->next;
    }
    if (guest == NULL) {
        printf("Guest not found.");
    }
}

int main() {
    Guest *headGuest = NULL;
    Room *headRoom = NULL;

    int choice;

    printf("Welcome to the Grand Hotel!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                headGuest = insertGuest(headGuest);
                break;
            case 2:
                checkOut(headGuest);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.");
        }
    }

    return 0;
}