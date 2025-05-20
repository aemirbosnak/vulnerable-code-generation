//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>

// Function for greeting and welcoming guests
void welcomeGuest(char name[]) {
    printf("Hello %s! Welcome to our hotel.\n", name);
}

// Function for checking room availability 
int checkRoomAvailability(int roomNumber) {
    if(roomNumber >= 101 && roomNumber <= 110) {
        return 1; // room is available
    } else {
        return 0; // room is not available
    }
}

// Function for checking if the room is a suite or standard room
int checkRoomType(int roomNumber) {
    if(roomNumber >= 101 && roomNumber <= 105) {
        return 1; // room is a suite
    } else {
        return 0; // room is a standard room
    }
}

// Function for booking a room
void bookRoom(int roomNumber, char name[], int nights) {
    printf("%s, your booking for room number %d for %d nights has been confirmed.\n", name, roomNumber, nights);
}

// Function for retrieving and printing customer information
void printCustomerDetails(char name[], int roomNumber, int nights) {
    printf("Customer Name: %s\n", name);
    printf("Room Number: %d\n", roomNumber);
    printf("Nights stayed: %d\n", nights);
}

int main() {
    char guestName[20];
    int roomNum, nightsStayed;

    printf("Welcome to C Hotel Management System!\n");
    printf("Please enter your name: ");
    scanf("%s", guestName);

    welcomeGuest(guestName);

    printf("\nPlease enter the room number you wish to check availability of: ");
    scanf("%d", &roomNum);

    if(checkRoomAvailability(roomNum)) {
        printf("Room number %d is available!\n", roomNum);

        if(checkRoomType(roomNum)) {
            printf("This is a Suite room.\n");
        } else {
            printf("This is a Standard room.\n");
        }

        printf("\nHow many nights would you like to stay? ");
        scanf("%d", &nightsStayed);

        bookRoom(roomNum, guestName, nightsStayed);
        printf("Thank you for choosing C Hotel! Here are your booking details:\n");
        printCustomerDetails(guestName, roomNum, nightsStayed);

    } else {
        printf("Room number %d is not available! Please try another room.\n", roomNum);
    }

    return 0;
}