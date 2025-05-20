//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeader() {
    printf("\n-------------------------------\n");
    printf("--- HOTEL MANAGEMENT SYSTEM ---\n");
    printf("-------------------------------\n\n");
}

int main() {
    printHeader();

    // Creating surreal objects
    char guests[20][50] = {"Lucifer", "Rebecca", "Gandalf", "Mickey Mouse", "Squidward", "Einstein",
                           "Patrick Star", "Iron Man", "Nemo", "Batman", "Wonder Woman", "Dumbledore",
                           "Frankenstein", "Shrek", "Harry Potter", "Jack Skellington", "Neo", "Yoda",
                           "Mickey Mouse", "Minnie Mouse"};
    int rooms[20] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210};
    int reservations[20] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0};

    // Printing out surreal objects
    printf("CURRENT GUESTS:\n");
    for(int i=0; i<20; i++) {
        printf("%d. %s\n", i+1, guests[i]);
    }

    printf("\n\nAVAILABLE ROOMS:\n");
    for(int i=0; i<20; i++) {
        if(reservations[i] == 0) {
            printf("%d\n", rooms[i]);
        }
    }

    // Taking surreal inputs
    char newGuest[50];
    int roomNumber;

    printf("\nEnter new guest name: ");
    scanf("%s", newGuest);

    printf("Enter the room number for %s (available rooms are above): ", newGuest);
    scanf("%d", &roomNumber);

    // Surreal logic to reserve room
    int roomIndex = -1;

    for(int i=0; i<20; i++) {
        if(roomNumber == rooms[i] && reservations[i] == 0) {
            roomIndex = i;
            break;
        }
    }

    if(roomIndex == -1) {
        printf("Room %d is not available. Please choose another room.\n", roomNumber);
    } else {
        strcpy(guests[roomIndex], newGuest);
        reservations[roomIndex] = 1;
        printf("Room %d has been reserved for %s.\n", rooms[roomIndex], guests[roomIndex]);
    }

    // Surreal logic to checkout
    printf("\nEnter room number to checkout: ");
    int checkOutRoomNumber;
    scanf("%d", &checkOutRoomNumber);

    int checkOutIndex = -1;

    for(int i=0; i<20; i++) {
        if(checkOutRoomNumber == rooms[i] && reservations[i] == 1) {
            checkOutIndex = i;
            break;
        }
    }

    if(checkOutIndex == -1) {
        printf("Room %d is not occupied.\n", checkOutRoomNumber);
    } else {
        printf("%s has successfully checked out of room %d.\n", guests[checkOutIndex], checkOutRoomNumber);
        reservations[checkOutIndex] = 0;
        guests[checkOutIndex][0] = '\0';
    }

    return 0;
}