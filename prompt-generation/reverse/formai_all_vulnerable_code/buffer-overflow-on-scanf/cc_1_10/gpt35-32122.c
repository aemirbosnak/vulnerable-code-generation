//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
struct guest {
    char name[50];
    int age;
    char address[100];
    int roomNumber;
};

// Structure to store room information
struct room {
    int roomNumber;
    char type[20];
    int capacity;
    int availability;
};

// Function to display available rooms
void displayRooms(struct room rooms[10], int n) {
    printf("\nRoom Number\tType\tCapacity\tAvailability\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%s\t%d\t\t", rooms[i].roomNumber, rooms[i].type, rooms[i].capacity);
        if(rooms[i].availability == 1) {
            printf("Available\n");
        }
        else {
            printf("Occupied\n");
        }
    }
}

// Function to check room availability
int checkAvailableRoom(struct room rooms[10], int n, int roomNumber) {
    for(int i=0; i<n; i++) {
        if(rooms[i].roomNumber == roomNumber && rooms[i].availability == 1) {
            return 1;
        }
    }
    return 0;
}

// Function to show guest details
void showGuestDetails(struct guest guest) {
    printf("\nGuest Details\n");
    printf("Name: %s\n", guest.name);
    printf("Age: %d\n", guest.age);
    printf("Address: %s\n", guest.address);
    printf("Room Number: %d\n", guest.roomNumber);
}

int main() {
    struct room rooms[10];
    int n;
    printf("Enter the number of rooms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("\nEnter the details of Room %d\n", (i+1));
        printf("Room Number: ");
        scanf("%d", &rooms[i].roomNumber);
        printf("Room Type: ");
        scanf("%s", rooms[i].type);
        printf("Capacity: ");
        scanf("%d", &rooms[i].capacity);
        rooms[i].availability = 1;
    }

    while(1) {
        printf("\n1. Book Room\n");
        printf("2. Display Available Rooms\n");
        printf("3. Exit\n");
        int choice;
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Book Room
                {
                    struct guest guest;
                    printf("\nEnter Guest Details\n");
                    printf("Name: ");
                    scanf("%s", guest.name);
                    printf("Age: ");
                    scanf("%d", &guest.age);
                    printf("Address: ");
                    scanf("%s", guest.address);
                    printf("Enter Room Number: ");
                    scanf("%d", &guest.roomNumber);
                    if(checkAvailableRoom(rooms, n, guest.roomNumber)) {
                        printf("Room is available. Booking confirmed.\n");
                        for(int i=0; i<n; i++) {
                            if(rooms[i].roomNumber == guest.roomNumber) {
                                rooms[i].availability = 0;
                                break;
                            }
                        }
                        showGuestDetails(guest);
                    }
                    else {
                        printf("Room is not available.\n");
                    }
                }
                break;
            case 2:
                // Display Available Rooms
                displayRooms(rooms, n);
                break;
            case 3:
                // Exit
                exit(0);
            default:
                printf("Invalid Choice. Try Again.\n");
        }
    }
    return 0;
}