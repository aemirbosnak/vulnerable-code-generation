//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hotel Struct
struct hotel {
    int roomNumber;
    char roomType[50];
    bool isAvailable;
    int checkInDate[3];
    int checkOutDate[3];
    float roomPrice;
};

// Global variables
int numRooms = 5;
struct hotel rooms[5];

// Function prototypes
void initRooms();
void displayRooms();
void bookRoom();
void viewBookedRooms();

// Main function
int main() {
    initRooms();
    char choice;
    do {
        system("clear");
        printf("******************* Welcome to C Hotel *******************\n");
        printf("1. View available rooms\n");
        printf("2. Book a room\n");
        printf("3. View booked rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                displayRooms();
                break;
            case '2':
                bookRoom();
                break;
            case '3':
                viewBookedRooms();
                break;
            case '4':
                printf("Thank you for using C Hotel Management System.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("Press enter to continue.");
        getchar();
        getchar();
    } while (choice != '4');
    return 0;
}

// Initialize rooms
void initRooms() {
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].roomType, "Standard");
        rooms[i].isAvailable = true;
        rooms[i].checkInDate[0] = rooms[i].checkOutDate[0] = 0;
        rooms[i].checkInDate[1] = rooms[i].checkOutDate[1] = 0;
        rooms[i].checkInDate[2] = rooms[i].checkOutDate[2] = 0;
        rooms[i].roomPrice = 50.0;
    }
}

// Display available rooms
void displayRooms() {
    printf("Room Number\tRoom Type\tAvailability\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t%s\t", rooms[i].roomNumber, rooms[i].roomType);
        if (rooms[i].isAvailable) {
            printf("Available\n");
        } else {
            printf("Not available\n");
        }
    }
}

// Book a room
void bookRoom() {
    int roomNum;
    printf("Enter the room number you want to book: ");
    scanf("%d", &roomNum);
    if (roomNum > 0 && roomNum <= numRooms) {
        if (rooms[roomNum - 1].isAvailable) {
            rooms[roomNum - 1].isAvailable = false;
            printf("Room number %d has been booked.\n", roomNum);
            int checkInd, checkInm, checkIny, checkOutd, checkOutm, checkOuty;
            printf("Enter the check-in date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &checkInd, &checkInm, &checkIny);
            printf("Enter the check-out date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &checkOutd, &checkOutm, &checkOuty);
            rooms[roomNum - 1].checkInDate[0] = checkInd;
            rooms[roomNum - 1].checkInDate[1] = checkInm;
            rooms[roomNum - 1].checkInDate[2] = checkIny;
            rooms[roomNum - 1].checkOutDate[0] = checkOutd;
            rooms[roomNum - 1].checkOutDate[1] = checkOutm;
            rooms[roomNum - 1].checkOutDate[2] = checkOuty;
        } else {
            printf("The room is not available.\n");
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// View booked rooms
void viewBookedRooms() {
    printf("Room Number\tRoom Type\tCheck-in Date\tCheck-out Date\tPrice\n");
    float totalSales = 0.0;
    for (int i = 0; i < numRooms; i++) {
        if (!rooms[i].isAvailable) {
            printf("%d\t%s\t%d/%d/%d\t%d/%d/%d\t%.2f\n", rooms[i].roomNumber, rooms[i].roomType, 
                                                        rooms[i].checkInDate[0], rooms[i].checkInDate[1], 
                                                        rooms[i].checkInDate[2], rooms[i].checkOutDate[0], 
                                                        rooms[i].checkOutDate[1], rooms[i].checkOutDate[2], 
                                                        rooms[i].roomPrice);
            totalSales += rooms[i].roomPrice;
        }
    }
    printf("Total sales: %.2f\n", totalSales);
}