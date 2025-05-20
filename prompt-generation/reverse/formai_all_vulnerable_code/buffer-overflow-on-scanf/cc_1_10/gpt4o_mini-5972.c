//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME 50

typedef struct {
    int roomNumber;
    char type[MAX_NAME];
    float price;
    int isBooked; // boolean (1 for true, 0 for false)
} Room;

typedef struct {
    char guestName[MAX_NAME];
    int roomNumber;
} Booking;

Room rooms[MAX_ROOMS];
Booking bookings[MAX_ROOMS];
int roomCount = 0;
int bookingCount = 0;

void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Room limit reached. Cannot add more rooms.\n");
        return;
    }
    
    Room newRoom;
    printf("Enter room number: ");
    scanf("%d", &newRoom.roomNumber);
    printf("Enter room type (Single/Double/Suite): ");
    scanf("%s", newRoom.type);
    printf("Enter room price: ");
    scanf("%f", &newRoom.price);
    newRoom.isBooked = 0; // Room is not booked
    
    rooms[roomCount++] = newRoom;
    printf("Room added successfully!\n");
}

void viewRooms() {
    printf("\nAvailable Rooms:\n");
    printf("Room No | Type    | Price  | Status\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < roomCount; i++) {
        printf("%7d | %-7s | %5.2f | %s\n", 
                rooms[i].roomNumber, 
                rooms[i].type, 
                rooms[i].price, 
                rooms[i].isBooked ? "Booked" : "Available");
    }
}

void bookRoom() {
    int roomNumber;
    char guestName[MAX_NAME];
    int found = 0;

    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);
    
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked == 0) {
            printf("Enter guest name: ");
            scanf("%s", guestName);

            rooms[i].isBooked = 1; // Mark room as booked
            strcpy(bookings[bookingCount].guestName, guestName);
            bookings[bookingCount].roomNumber = roomNumber;
            bookingCount++;
            found = 1;
            printf("Room %d booked for %s successfully!\n", roomNumber, guestName);
            break;
        }
    }
    if (!found) {
        printf("Room is either not found or already booked.\n");
    }
}

void cancelBooking() {
    int roomNumber;
    int found = 0;

    printf("Enter room number to cancel booking: ");
    scanf("%d", &roomNumber);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked == 1) {
            rooms[i].isBooked = 0; // Mark room as available
            found = 1;

            // Remove booking entry (optional - keeping it simple here)
            for (int j = 0; j < bookingCount; j++) {
                if (bookings[j].roomNumber == roomNumber) {
                    for (int k = j; k < bookingCount - 1; k++) {
                        bookings[k] = bookings[k + 1];
                    }
                    bookingCount--;
                    break;
                }
            }

            printf("Booking for room %d canceled successfully!\n", roomNumber);
            break;
        }
    }
    if (!found) {
        printf("No booking found for the given room number.\n");
    }
}

void displayMenu() {
    printf("\nHotel Management System\n");
    printf("1. Add Room\n");
    printf("2. View Rooms\n");
    printf("3. Book Room\n");
    printf("4. Cancel Booking\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                viewRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                cancelBooking();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}