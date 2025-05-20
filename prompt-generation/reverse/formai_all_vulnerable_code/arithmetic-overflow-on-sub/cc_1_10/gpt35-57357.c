//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for holding hotel room information
typedef struct {
    int roomNumber;
    int capacity;
    int occupied;
    char occupantName[50];
} Room;

// Define a struct for holding reservation information
typedef struct {
    int roomNumber;
    char occupantName[50];
    char checkInDate[11];
    char checkOutDate[11];
    int days;
} Reservation;

// Define a function to display the menu and get user input
int getMenuChoice() {
    int choice;

    printf("\nWelcome to the C Hotel Management System\n");
    printf("Select an option:\n");
    printf("1. View Room Status\n");
    printf("2. Make Reservation\n");
    printf("3. Update Reservation\n");
    printf("4. Cancel Reservation\n");
    printf("5. Generate Room Report\n");
    printf("6. Exit\n");

    printf("Choice: ");
    scanf("%d", &choice);

    return choice;
}

// Define a function to display the status of all hotel rooms
void viewRoomStatus(Room rooms[], int numRooms) {
    printf("\nRoom Status:\n");

    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].occupied ? "occupied" : "vacant");
        if (rooms[i].occupied) {
            printf("Occupant: %s\n", rooms[i].occupantName);
        }
        printf("\n");
    }
}

// Define a function to make a reservation for a room
void makeReservation(Room rooms[], Reservation reservations[], int numRooms, int numReservations) {
    int roomChoice, numGuests;
    char guestName[50], checkInDate[11], checkOutDate[11];
    int days;

    // Display list of available rooms
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        if (!rooms[i].occupied) {
            printf("Room %d (Capacity: %d)\n", rooms[i].roomNumber, rooms[i].capacity);
        }
    }

    printf("Enter room number: ");
    scanf("%d", &roomChoice);
    getchar(); // remove newline character from buffer

    // Check if room is available
    if (rooms[roomChoice - 1].occupied) {
        printf("Room is already occupied.\n");
        return;
    }

    printf("Enter guest name: ");
    fgets(guestName, 50, stdin);
    guestName[strcspn(guestName, "\n")] = 0; // remove newline character from string

    printf("Enter check-in date (yyyy-mm-dd): ");
    scanf("%s", checkInDate);

    printf("Enter check-out date (yyyy-mm-dd): ");
    scanf("%s", checkOutDate);

    printf("Enter number of days: ");
    scanf("%d", &days);

    // Check if room can accommodate number of guests
    if (rooms[roomChoice - 1].capacity < numGuests) {
        printf("Room cannot accommodate that many guests.\n");
        return;
    }

    // Add room to reservations array
    Reservation reservation = {roomChoice, guestName, checkInDate, checkOutDate, days};
    reservations[numReservations++] = reservation;

    // Update room status
    rooms[roomChoice - 1].occupied = 1;
    strcpy(rooms[roomChoice - 1].occupantName, guestName);

    printf("Reservation made successfully.\n");
}

// Define a function to update a reservation for a room
void updateReservation(Room rooms[], Reservation reservations[], int numRooms, int numReservations, int reservationIndex) {
    int roomChoice, numGuests;
    char guestName[50], checkInDate[11], checkOutDate[11];
    int days;

    Reservation reservation = reservations[reservationIndex];

    // Display current reservation information
    printf("\nCurrent Reservation:\n");
    printf("Room %d\n", reservation.roomNumber);
    printf("Guest Name: %s\n", reservation.occupantName);
    printf("Check-in Date: %s\n", reservation.checkInDate);
    printf("Check-out Date: %s\n", reservation.checkOutDate);
    printf("Number of Days: %d\n", reservation.days);

    // Get updated reservation information
    printf("\nEnter updated reservation information:\n");
    printf("Enter guest name: ");
    fgets(guestName, 50, stdin);
    guestName[strcspn(guestName, "\n")] = 0; // remove newline character from string

    printf("Enter check-in date (yyyy-mm-dd): ");
    scanf("%s", checkInDate);

    printf("Enter check-out date (yyyy-mm-dd): ");
    scanf("%s", checkOutDate);

    printf("Enter number of days: ");
    scanf("%d", &days);

    // Update reservation information
    strcpy(reservation.occupantName, guestName);
    strcpy(reservation.checkInDate, checkInDate);
    strcpy(reservation.checkOutDate, checkOutDate);
    reservation.days = days;

    // Update room status
    rooms[reservation.roomNumber - 1].occupied = 1;
    strcpy(rooms[reservation.roomNumber - 1].occupantName, guestName);

    printf("Reservation updated successfully.\n");
}

// Define a function to cancel a reservation for a room
void cancelReservation(Room rooms[], Reservation reservations[], int numRooms, int numReservations, int reservationIndex) {
    Reservation reservation = reservations[reservationIndex];

    // Remove reservation from reservations array
    for (int i = reservationIndex; i < numReservations - 1; i++) {
        reservations[i] = reservations[i + 1];
    }
    numReservations--;

    // Update room status
    rooms[reservation.roomNumber - 1].occupied = 0;
    strcpy(rooms[reservation.roomNumber - 1].occupantName, "");

    printf("\nReservation canceled successfully.\n");
}

// Define a function to generate a report of room status and reservations
void generateReport(Room rooms[], Reservation reservations[], int numRooms, int numReservations) {
    printf("\nRoom Report:\n");

    printf("Room Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].occupied ? "occupied" : "vacant");
        if (rooms[i].occupied) {
            printf("Occupant: %s\n", rooms[i].occupantName);
        }
        printf("\n");
    }

    printf("Reservations:\n");
    for (int i = 0; i < numReservations; i++) {
        Reservation reservation = reservations[i];
        printf("Reservation %d:\n", i + 1);
        printf("Room %d\n", reservation.roomNumber);
        printf("Guest Name: %s\n", reservation.occupantName);
        printf("Check-in Date: %s\n", reservation.checkInDate);
        printf("Check-out Date: %s\n", reservation.checkOutDate);
        printf("Number of Days: %d\n\n", reservation.days);
    }
}

int main() {
    Room rooms[] = {
        {1, 2, 0, ""},
        {2, 2, 0, ""},
        {3, 4, 0, ""},
        {4, 4, 0, ""},
        {5, 6, 0, ""}
    };
    int numRooms = 5;

    Reservation reservations[100];
    int numReservations = 0;

    int choice, reservationIndex;

    while (1) {
        choice = getMenuChoice();

        switch (choice) {
            case 1: // view room status
                viewRoomStatus(rooms, numRooms);
                break;
            case 2: // make reservation
                makeReservation(rooms, reservations, numRooms, numReservations);
                break;
            case 3: // update reservation
                printf("Enter reservation number: ");
                scanf("%d", &reservationIndex);
                reservationIndex--; // convert from human-readable index to zero-based index

                if (reservationIndex >= 0 && reservationIndex < numReservations) {
                    updateReservation(rooms, reservations, numRooms, numReservations, reservationIndex);
                } else {
                    printf("Invalid reservation number.\n");
                }
                break;
            case 4: // cancel reservation
                printf("Enter reservation number: ");
                scanf("%d", &reservationIndex);
                reservationIndex--; // convert from human-readable index to zero-based index

                if (reservationIndex >= 0 && reservationIndex < numReservations) {
                    cancelReservation(rooms, reservations, numRooms, numReservations, reservationIndex);
                } else {
                    printf("Invalid reservation number.\n");
                }
                break;
            case 5: // generate report
                generateReport(rooms, reservations, numRooms, numReservations);
                break;
            case 6: // exit
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}