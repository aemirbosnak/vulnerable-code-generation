//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200
#define MAX_RESERVATIONS 500

typedef struct {
    int roomNumber;
    char guestName[50];
    int daysStayed;
} Reservation;

Reservation reservations[MAX_RESERVATIONS];
int numReservations = 0;

void makeReservation(int roomNumber, char guestName[], int daysStayed) {
    if (numReservations >= MAX_RESERVATIONS) {
        printf("Sorry, we are fully booked.\n");
        return;
    }

    reservations[numReservations].roomNumber = roomNumber;
    strcpy(reservations[numReservations].guestName, guestName);
    reservations[numReservations].daysStayed = daysStayed;

    numReservations++;

    printf("Reservation made for %s in room %d for %d days.\n", guestName, roomNumber, daysStayed);
}

void checkOut(int roomNumber) {
    int i;

    for (i = 0; i < numReservations; i++) {
        if (reservations[i].roomNumber == roomNumber) {
            printf("Guest %s has checked out of room %d.\n", reservations[i].guestName, roomNumber);
            numReservations--;
            break;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("The Game is Afoot!\n");
        printf("1. Make a reservation\n");
        printf("2. Check out\n");
        printf("3. View reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter room number: ");
            int roomNumber;
            scanf("%d", &roomNumber);

            printf("Enter guest name: ");
            char guestName[50];
            scanf("%s", guestName);

            printf("Enter number of days staying: ");
            int daysStayed;
            scanf("%d", &daysStayed);

            makeReservation(roomNumber, guestName, daysStayed);
            break;

        case 2:
            printf("Enter room number: ");
            int roomNumberCheckout;
            scanf("%d", &roomNumberCheckout);

            checkOut(roomNumberCheckout);
            break;

        case 3:
            printf("Current reservations:\n");
            for (int i = 0; i < numReservations; i++) {
                printf("Room %d: %s (%d days)\n", reservations[i].roomNumber, reservations[i].guestName, reservations[i].daysStayed);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}