//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    double rate;
    int status;
} Guest;

typedef struct {
    char name[50];
    int check_in_date;
    int check_out_date;
} Reservation;

void create_guest(Guest *guest) {
    printf("Enter guest name: ");
    scanf("%s", guest->name);
    printf("Enter room number: ");
    scanf("%d", &guest->room_number);
    printf("Enter rate: ");
    scanf("%lf", &guest->rate);
    printf("Enter status: ");
    scanf("%d", &guest->status);
}

void display_guest(Guest guest) {
    printf("Guest name: %s\n", guest.name);
    printf("Room number: %d\n", guest.room_number);
    printf("Rate: %.2lf\n", guest.rate);
    printf("Status: %d\n", guest.status);
}

void create_reservation(Reservation *reservation) {
    printf("Enter guest name: ");
    scanf("%s", reservation->name);
    printf("Enter check-in date: ");
    scanf("%d", &reservation->check_in_date);
    printf("Enter check-out date: ");
    scanf("%d", &reservation->check_out_date);
}

void display_reservation(Reservation reservation) {
    printf("Guest name: %s\n", reservation.name);
    printf("Check-in date: %d\n", reservation.check_in_date);
    printf("Check-out date: %d\n", reservation.check_out_date);
}

int main() {
    Guest guest1;
    Guest guest2;
    Reservation reservation1;
    Reservation reservation2;

    create_guest(&guest1);
    display_guest(guest1);

    create_guest(&guest2);
    display_guest(guest2);

    create_reservation(&reservation1);
    display_reservation(reservation1);

    create_reservation(&reservation2);
    display_reservation(reservation2);

    return 0;
}