//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100

// Data structure for a room
struct {
    int roomNumber;
    char roomType[20];
    int roomPrice;
    int isAvailable;
} rooms[MAX_ROOMS];

// Data structure for a guest
struct {
    char name[50];
    int age;
    char phoneNumber[15];
    char address[100];
} guests[MAX_GUESTS];

// Function to display available rooms
void displayAvailableRooms() {
    int count = 0;
    printf("Available Rooms:\n");
    for(int i=0; i<MAX_ROOMS; i++) {
        if(rooms[i].isAvailable == 1) {
            printf("%d. %s - $%d\n", i+1, rooms[i].roomType, rooms[i].roomPrice);
            count++;
        }
    }
    if(count == 0) {
        printf("\nNo rooms available.\n");
    }
}

// Function to book a room
void bookRoom(int roomNumber) {
    printf("\nEnter guest details:\n");
    printf("Name: ");
    scanf("%s", guests[0].name);
    printf("Age: ");
    scanf("%d", &guests[0].age);
    printf("Phone Number: ");
    scanf("%s", guests[0].phoneNumber);
    printf("Address: ");
    scanf("%s", guests[0].address);

    rooms[roomNumber-1].isAvailable = 0;
    printf("\nRoom %d booked for %s.\n", roomNumber, guests[0].name);
}

// Function to check out a room
void checkOutRoom(int roomNumber) {
    rooms[roomNumber-1].isAvailable = 1;
    printf("\nRoom %d checked out.\n", roomNumber);
}

int main() {
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Book a room\n2. Check out\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                displayAvailableRooms();
                int roomNumber;
                printf("\nEnter room number: ");
                scanf("%d", &roomNumber);
                bookRoom(roomNumber);
                break;
            }
            case 2: {
                int roomNumber;
                printf("\nEnter room number: ");
                scanf("%d", &roomNumber);
                checkOutRoom(roomNumber);
                break;
            }
            case 3: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice.\n");
            }
        }
    } while(choice!= 3);

    return 0;
}