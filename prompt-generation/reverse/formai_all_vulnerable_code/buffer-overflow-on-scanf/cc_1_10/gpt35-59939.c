//FormAI DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    int numberOfBeds;
    float pricePerNight;
    int isBooked;
};

struct Guest {
    char name[50];
    int numberOfGuests;
    int roomNumber;
    int nightsStaying;
};

struct Room rooms[50];
struct Guest guests[50];
int numberOfRooms = 0, numberOfGuests = 0;

void addRoom() {
    int roomNumber, numberOfBeds, isBooked;
    float pricePerNight;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    printf("Enter number of beds: ");
    scanf("%d", &numberOfBeds);
    printf("Enter price per night: ");
    scanf("%f", &pricePerNight);
    isBooked = 0;
    struct Room newRoom = {roomNumber, numberOfBeds, pricePerNight, isBooked};
    rooms[numberOfRooms] = newRoom;
    numberOfRooms++;
    printf("Room added successfully!\n");
}

void displayRooms() {
    printf("Room Number\tNumber of Beds\tPrice Per Night\n");
    for (int i = 0; i < numberOfRooms; i++) {
        printf("%d\t\t%d\t\t%.2f\t\t%s\n", rooms[i].roomNumber, rooms[i].numberOfBeds, rooms[i].pricePerNight, (rooms[i].isBooked == 1 ? "Booked" : "Available"));
    }
}

void bookRoom() {
    int roomNumber, numberOfGuests, nightsStaying;
    char name[50];
    int roomIndex = -1, guestIndex = -1;
    printf("Enter your name: ");
    scanf(" %[^\n]s", name);
    printf("Enter number of guests: ");
    scanf("%d", &numberOfGuests);
    printf("Enter number of nights to stay: ");
    scanf("%d", &nightsStaying);
    printf("Available Rooms:\n");
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i].isBooked == 0) {
            printf("%d\t\t%d\t\t%.2f\n", rooms[i].roomNumber, rooms[i].numberOfBeds, rooms[i].pricePerNight);
        }
    }
    printf("Enter room number you want to book: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            roomIndex = i;
            break;
        }
    }
    if (roomIndex == -1) {
        printf("Invalid Room Number!\n");
        return;
    }
    rooms[roomIndex].isBooked = 1;
    printf("Booking Confirmed!\n");
    guests[numberOfGuests] = (struct Guest) {name, numberOfGuests, roomNumber, nightsStaying};
    numberOfGuests++;
}

void displayGuests() {
    printf("Name\t\tNumber of Guests\tRoom Number\tNights Staying\n");
    for (int i = 0; i < numberOfGuests; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", guests[i].name, guests[i].numberOfGuests, guests[i].roomNumber, guests[i].nightsStaying);
    }
}

int main() {
    int choice;
    do {
        printf("\n\nMenu:\n");
        printf("1. Add Room\n");
        printf("2. Display Rooms\n");
        printf("3. Book Room\n");
        printf("4. Display Guests\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                displayGuests();
                break;
            case 5:
                printf("Thank you for using our Hotel Management System!");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while (1);
    return 0;
}