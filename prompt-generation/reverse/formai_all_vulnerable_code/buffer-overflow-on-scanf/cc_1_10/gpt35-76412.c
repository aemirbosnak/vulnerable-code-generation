//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Reservation {
    int roomNumber;
    char guestName[50];
    int checkInMonth;
    int checkInDay;
    int checkInYear;
    int checkOutMonth;
    int checkOutDay;
    int checkOutYear;
};

struct Reservation reservations[100];
int reservationCount = 0;

void makeReservation() {
    struct Reservation reservation;
    printf("\nEnter room number: ");
    scanf("%d", &reservation.roomNumber);
    printf("Enter guest name: ");
    scanf(" %[^\n]s", reservation.guestName);
    printf("Enter check-in date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &reservation.checkInMonth, &reservation.checkInDay, &reservation.checkInYear);
    printf("Enter check-out date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &reservation.checkOutMonth, &reservation.checkOutDay, &reservation.checkOutYear);
    reservations[reservationCount++] = reservation;    
}

void listReservations() {
    printf("\nRoom\tGuest Name\tCheck-In\tCheck-Out\n");
    for(int i = 0; i < reservationCount; i++) {
        printf("%d\t%s\t%d/%d/%d\t%d/%d/%d\n", reservations[i].roomNumber, reservations[i].guestName,
        reservations[i].checkInMonth, reservations[i].checkInDay, reservations[i].checkInYear,
        reservations[i].checkOutMonth, reservations[i].checkOutDay, reservations[i].checkOutYear);
    }
}

void menu() {
    char choice;
    do {
        printf("\n\nC Hotel Management System\n");
        printf("1. Make a reservation\n");
        printf("2. List all reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': makeReservation(); break;
            case '2': listReservations(); break;
            case '3': exit(0); 
            default: printf("Invalid choice. Try again.");
        }

    } while(choice != '3');
}

int main() {
    menu();
    return 0;
}