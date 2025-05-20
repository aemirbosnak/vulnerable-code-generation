//FormAI DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100 // maximum number of rooms in the hotel

// hotel room structure
typedef struct Room {
    int roomNumber;
    char guestName[100];
    double ratePerNight;
    int numNights;
    double totalCost;
} Room;

Room hotelRooms[MAX_ROOMS];
int numRooms = 0; // current number of rooms in the hotel

// function to add a new room to the hotel
void addRoom(int roomNumber, char *guestName, double ratePerNight, int numNights) {
    if (numRooms >= MAX_ROOMS) {
        printf("Sorry, the hotel is full and cannot accommodate any more guests.\n");
        return;
    }

    Room newRoom;
    newRoom.roomNumber = roomNumber;
    strcpy(newRoom.guestName, guestName);
    newRoom.ratePerNight = ratePerNight;
    newRoom.numNights = numNights;
    newRoom.totalCost = ratePerNight * numNights;
    
    hotelRooms[numRooms++] = newRoom;
    
    printf("Room #%d has been added to the hotel.\n", roomNumber);
}

// function to print all rooms and their details
void printAllRooms() {
    printf("List of all rooms:\n");
    printf("Room Number\tGuest Name\tRate per night\tNumber of Nights\tTotal Cost\n");
    for (int i=0; i<numRooms; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f\n", hotelRooms[i].roomNumber,
               hotelRooms[i].guestName, hotelRooms[i].ratePerNight,
               hotelRooms[i].numNights, hotelRooms[i].totalCost);
    }
}

int main() {
    int input;
    do {
        printf("\n");
        printf("Welcome to the Hotel Management System.\n");
        printf("Please select an option:\n");
        printf("1. Add a new room\n");
        printf("2. Print all rooms\n");
        printf("3. Exit\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                {
                    int roomNumber;
                    char guestName[100];
                    double ratePerNight;
                    int numNights;

                    printf("Enter room number: ");
                    scanf("%d", &roomNumber);
                    printf("Enter guest name: ");
                    scanf("%s", guestName);
                    printf("Enter rate per night: ");
                    scanf("%lf", &ratePerNight);
                    printf("Enter number of nights: ");
                    scanf("%d", &numNights);

                    addRoom(roomNumber, guestName, ratePerNight, numNights);
                    break;
                }
            case 2:
                printAllRooms();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (input != 3);
    
    return 0;
}