//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    int nights;
    int isBooked;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int totalRooms;
} Hotel;

void initializeHotel(Hotel *hotel, int totalRooms) {
    hotel->totalRooms = totalRooms;
    for (int i = 0; i < totalRooms; i++) {
        hotel->rooms[i].roomNumber = i + 1;
        hotel->rooms[i].isBooked = 0; 
        strcpy(hotel->rooms[i].guestName, ""); 
        hotel->rooms[i].nights = 0;
    }
}

void displayRooms(const Hotel *hotel) {
    printf("Room Number | Guest Name      | Nights | Status\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < hotel->totalRooms; i++) {
        if (hotel->rooms[i].isBooked) {
            printf("%11d | %-15s | %6d | Booked\n", 
                  hotel->rooms[i].roomNumber, 
                  hotel->rooms[i].guestName, 
                  hotel->rooms[i].nights);
        } else {
            printf("%11d | %-15s | %6s | Available\n", 
                  hotel->rooms[i].roomNumber, 
                  "None", 
                  "N/A");
        }
    }
}

void bookRoom(Hotel *hotel) {
    int roomNumber;
    char guestName[50];
    int nights;

    printf("Enter Room Number to Book: ");
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > hotel->totalRooms) {
        printf("Invalid Room Number.\n");
        return;
    }
    
    roomNumber -= 1; // Adjust for 0-based index

    if (hotel->rooms[roomNumber].isBooked) {
        printf("Room is already booked!\n");
        return;
    }

    printf("Enter Guest Name: ");
    scanf(" %[^\n]", guestName);
    printf("Enter Number of Nights: ");
    scanf("%d", &nights);

    hotel->rooms[roomNumber].isBooked = 1;
    strcpy(hotel->rooms[roomNumber].guestName, guestName);
    hotel->rooms[roomNumber].nights = nights;

    printf("Room %d successfully booked for %s for %d nights.\n", 
           hotel->rooms[roomNumber].roomNumber, 
           hotel->rooms[roomNumber].guestName, 
           hotel->rooms[roomNumber].nights);
}

void checkoutRoom(Hotel *hotel) {
    int roomNumber;

    printf("Enter Room Number to Checkout: ");
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > hotel->totalRooms) {
        printf("Invalid Room Number.\n");
        return;
    }

    roomNumber -= 1; // Adjust for 0-based index

    if (!hotel->rooms[roomNumber].isBooked) {
        printf("Room is not booked!\n");
        return;
    }

    hotel->rooms[roomNumber].isBooked = 0;
    strcpy(hotel->rooms[roomNumber].guestName, "");
    hotel->rooms[roomNumber].nights = 0;

    printf("Room %d has been successfully checked out.\n", hotel->rooms[roomNumber].roomNumber);
}

int main() {
    Hotel hotel;
    int totalRooms;

    printf("Enter Total Number of Rooms in Hotel: ");
    scanf("%d", &totalRooms);
    
    if (totalRooms > MAX_ROOMS) {
        printf("Exceeds maximum room limit of %d.\n", MAX_ROOMS);
        return 1;
    }

    initializeHotel(&hotel, totalRooms);

    int choice;
    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Display Rooms\n");
        printf("2. Book Room\n");
        printf("3. Checkout Room\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(&hotel);
                break;
            case 2:
                bookRoom(&hotel);
                break;
            case 3:
                checkoutRoom(&hotel);
                break;
            case 4:
                printf("Exiting the Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}