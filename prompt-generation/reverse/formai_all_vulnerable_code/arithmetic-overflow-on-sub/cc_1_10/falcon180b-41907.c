//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
    int roomNumber;
    char guestName[50];
    int reservationDate;
    int checkInDate;
    int checkOutDate;
    int totalNights;
    float totalCost;
} Reservation;

Reservation reservations[MAX_ROOMS];
int numReservations = 0;

void makeReservation() {
    char guestName[50];
    int roomNumber, reservationDate, checkInDate, checkOutDate;
    float totalCost;

    printf("Enter guest name: ");
    scanf("%s", guestName);

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    printf("Enter reservation date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &reservationDate, &checkInDate, &checkOutDate);

    totalCost = (checkOutDate - checkInDate + 1) * 100;

    strcpy(reservations[numReservations].guestName, guestName);
    reservations[numReservations].roomNumber = roomNumber;
    reservations[numReservations].reservationDate = reservationDate;
    reservations[numReservations].checkInDate = checkInDate;
    reservations[numReservations].checkOutDate = checkOutDate;
    reservations[numReservations].totalNights = checkOutDate - checkInDate + 1;
    reservations[numReservations].totalCost = totalCost;

    numReservations++;
}

void displayReservations() {
    int i;

    for (i = 0; i < numReservations; i++) {
        printf("Guest Name: %s\n", reservations[i].guestName);
        printf("Room Number: %d\n", reservations[i].roomNumber);
        printf("Reservation Date: %d-%d-%d\n", reservations[i].reservationDate, reservations[i].checkInDate, reservations[i].checkOutDate);
        printf("Total Nights: %d\n", reservations[i].totalNights);
        printf("Total Cost: $%.2f\n\n", reservations[i].totalCost);
    }
}

void main() {
    int choice;

    while (1) {
        printf("Hotel Management System\n");
        printf("1. Make Reservation\n");
        printf("2. Display Reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}