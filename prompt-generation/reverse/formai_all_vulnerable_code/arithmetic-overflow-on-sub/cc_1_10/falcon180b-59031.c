//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_RESERVATIONS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    int checkInDate;
    int checkOutDate;
} Reservation;

Reservation reservations[MAX_RESERVATIONS];

int numReservations = 0;

void addReservation() {
    numReservations++;
}

void removeReservation(int index) {
    numReservations--;
}

void displayReservations() {
    printf("\nReservations:\n");
    for (int i = 0; i < numReservations; i++) {
        printf("Room Number: %d\nGuest Name: %s\nCheck-in Date: %d\nCheck-out Date: %d\n", reservations[i].roomNumber, reservations[i].guestName, reservations[i].checkInDate, reservations[i].checkOutDate);
    }
}

int main() {

    int choice;
    while (1) {
        printf("\nC Hotel Management System\n");
        printf("1. Add Reservation\n2. Remove Reservation\n3. Display Reservations\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReservation();
                printf("\nReservation added successfully!\n");
                break;
            case 2:
                printf("\nEnter the reservation number you want to remove: ");
                int reservationNumber;
                scanf("%d", &reservationNumber);
                removeReservation(reservationNumber - 1);
                printf("\nReservation removed successfully!\n");
                break;
            case 3:
                displayReservations();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}