//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct {
    int roomNumber;
    char type[20]; // e.g., Single, Double, Suite
    float price;
    int isBooked; // 0 for available, 1 for booked
} Room;

typedef struct {
    int bookingId;
    int roomNumber;
    char guestName[50];
    char checkInDate[11]; // format: YYYY-MM-DD
    char checkOutDate[11];
} Booking;

Room rooms[MAX_ROOMS];
Booking bookings[MAX_ROOMS];
int roomCount = 0;
int bookingCount = 0;

void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Cannot add more rooms. Maximum limit reached.\n");
        return;
    }
    Room newRoom;
    newRoom.roomNumber = roomCount + 101; // Room numbers start from 101
    printf("Enter room type (Single/Double/Suite): ");
    scanf("%s", newRoom.type);
    printf("Enter room price: ");
    scanf("%f", &newRoom.price);
    newRoom.isBooked = 0; // Mark as available
    rooms[roomCount++] = newRoom;
    printf("Room added successfully. Room Number: %d\n", newRoom.roomNumber);
}

void bookRoom() {
    if (bookingCount >= MAX_ROOMS) {
        printf("Cannot book more rooms. Maximum booking limit reached.\n");
        return;
    }
    int roomNum;
    printf("Enter room number to book: ");
    scanf("%d", &roomNum);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNum) {
            if (rooms[i].isBooked) {
                printf("Room %d is already booked.\n", roomNum);
                return;
            }
            Booking newBooking;
            newBooking.bookingId = bookingCount + 1; // Booking IDs start from 1
            newBooking.roomNumber = roomNum;
            printf("Enter guest name: ");
            scanf("%s", newBooking.guestName);
            printf("Enter check-in date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkInDate);
            printf("Enter check-out date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkOutDate);
            bookings[bookingCount++] = newBooking;

            rooms[i].isBooked = 1; // Mark room as booked
            printf("Room %d booked successfully. Booking ID: %d\n", roomNum, newBooking.bookingId);
            return;
        }
    }
    printf("Room %d not found.\n", roomNum);
}

void cancelBooking() {
    int bookingId;
    printf("Enter booking ID to cancel: ");
    scanf("%d", &bookingId);

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == bookingId) {
            for (int j = 0; j < roomCount; j++) {
                if (rooms[j].roomNumber == bookings[i].roomNumber) {
                    rooms[j].isBooked = 0; // Mark room as available
                    break;
                }
            }
            for (int j = i; j < bookingCount - 1; j++) {
                bookings[j] = bookings[j + 1]; // Shift bookings
            }
            bookingCount--;
            printf("Booking ID %d canceled successfully.\n", bookingId);
            return;
        }
    }
    printf("Booking ID %d not found.\n", bookingId);
}

void viewRooms() {
    printf("Room Number\tType\tPrice\tStatus\n");
    for (int i = 0; i < roomCount; i++) {
        printf("%d\t\t%s\t%.2f\t%s\n", rooms[i].roomNumber, rooms[i].type,
               rooms[i].price, rooms[i].isBooked ? "Booked" : "Available");
    }
}

void viewBookings() {
    printf("Booking ID\tRoom Number\tGuest Name\tCheck-in\tCheck-out\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("%d\t\t%d\t\t%s\t%s\t%s\n", bookings[i].bookingId,
               bookings[i].roomNumber, bookings[i].guestName,
               bookings[i].checkInDate, bookings[i].checkOutDate);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Room\n");
        printf("2. Book Room\n");
        printf("3. Cancel Booking\n");
        printf("4. View Rooms\n");
        printf("5. View Bookings\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addRoom(); break;
            case 2: bookRoom(); break;
            case 3: cancelBooking(); break;
            case 4: viewRooms(); break;
            case 5: viewBookings(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}