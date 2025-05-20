//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_RESERVATIONS 1000

typedef struct {
    int roomNumber;
    int numGuests;
    char guestName[50];
    int reservationID;
} Reservation;

Reservation reservations[MAX_RESERVATIONS];
int numReservations = 0;

void addReservation() {
    if (numReservations >= MAX_RESERVATIONS) {
        printf("Sorry, the hotel is fully booked.\n");
        return;
    }

    int roomNumber, numGuests;
    char guestName[50];
    int reservationID = numReservations + 1;

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    printf("Enter number of guests: ");
    scanf("%d", &numGuests);

    printf("Enter guest name: ");
    scanf("%s", guestName);

    reservations[numReservations].roomNumber = roomNumber;
    reservations[numReservations].numGuests = numGuests;
    strcpy(reservations[numReservations].guestName, guestName);
    reservations[numReservations].reservationID = reservationID;

    numReservations++;

    printf("Reservation added successfully! Reservation ID: %d\n", reservationID);
}

void viewReservations() {
    if (numReservations == 0) {
        printf("No reservations found.\n");
        return;
    }

    printf("Reservation ID | Room Number | Number of Guests | Guest Name\n");
    for (int i = 0; i < numReservations; i++) {
        printf("%d | %d | %d | %s\n", reservations[i].reservationID, reservations[i].roomNumber, reservations[i].numGuests, reservations[i].guestName);
    }
}

void cancelReservation() {
    int reservationID;

    printf("Enter reservation ID to cancel: ");
    scanf("%d", &reservationID);

    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].reservationID == reservationID) {
            reservations[i].roomNumber = -1;
            reservations[i].numGuests = 0;
            strcpy(reservations[i].guestName, "");
            printf("Reservation cancelled successfully! Reservation ID: %d\n", reservationID);
            return;
        }
    }

    printf("Reservation not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nHotel Management System\n");
        printf("1. Add reservation\n2. View reservations\n3. Cancel reservation\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                printf("Thank you for using our Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}