//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

struct room {
    char name[20];
    int number;
    float price;
    struct room* next;
};

struct booking {
    char name[20];
    int number;
    struct booking* next;
};

void insertRoom(struct room** head) {
    struct room* newRoom = (struct room*)malloc(sizeof(struct room));
    printf("Enter room name: ");
    scanf("%s", newRoom->name);
    printf("Enter room number: ");
    scanf("%d", &newRoom->number);
    printf("Enter room price: ");
    scanf("%f", &newRoom->price);
    newRoom->next = *head;
    *head = newRoom;
}

void insertBooking(struct booking** head) {
    struct booking* newBooking = (struct booking*)malloc(sizeof(struct booking));
    printf("Enter booking name: ");
    scanf("%s", newBooking->name);
    printf("Enter booking number: ");
    scanf("%d", &newBooking->number);
    newBooking->next = *head;
    *head = newBooking;
}

void displayRooms(struct room* head) {
    struct room* currentRoom = head;
    while (currentRoom) {
        printf("Room name: %s\n", currentRoom->name);
        printf("Room number: %d\n", currentRoom->number);
        printf("Room price: %.2f\n", currentRoom->price);
        printf("\n");
        currentRoom = currentRoom->next;
    }
}

void displayBookings(struct booking* head) {
    struct booking* currentBooking = head;
    while (currentBooking) {
        printf("Booking name: %s\n", currentBooking->name);
        printf("Booking number: %d\n", currentBooking->number);
        printf("\n");
        currentBooking = currentBooking->next;
    }
}

int main() {
    struct room* headRoom = NULL;
    struct booking* headBooking = NULL;

    int choice;

    printf("Enter 1 to insert a room, 2 to insert a booking, 3 to display rooms, or 4 to display bookings: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertRoom(&headRoom);
            break;
        case 2:
            insertBooking(&headBooking);
            break;
        case 3:
            displayRooms(headRoom);
            break;
        case 4:
            displayBookings(headBooking);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}