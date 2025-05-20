//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int room_number;
    int guest_id;
    char name[50];
    char address[100];
    int phone_number;
    int checkin_date;
    int checkout_date;
} Guest;

void create_guest(Guest *guest) {
    printf("Enter guest name: ");
    scanf("%s", guest->name);
    printf("Enter guest address: ");
    scanf("%s", guest->address);
    printf("Enter guest phone number: ");
    scanf("%d", &guest->phone_number);
}

void display_guest(Guest guest) {
    printf("Guest Name: %s\n", guest.name);
    printf("Guest Address: %s\n", guest.address);
    printf("Guest Phone Number: %d\n", guest.phone_number);
}

void create_room(int *room_number) {
    *room_number = rand() % 100 + 1;
}

void display_room(int room_number) {
    printf("Room Number: %d\n", room_number);
}

void check_in(Guest *guest, int room_number) {
    guest->room_number = room_number;
    guest->checkin_date = time(NULL);
}

void check_out(Guest *guest) {
    guest->room_number = 0;
    guest->checkout_date = time(NULL);
}

int main() {
    srand(time(NULL));
    Guest guest;
    int room_number;

    create_guest(&guest);
    create_room(&room_number);

    check_in(&guest, room_number);

    printf("Guest checked in successfully!\n");

    display_guest(guest);
    display_room(room_number);

    sleep(5);

    check_out(&guest);

    printf("Guest checked out successfully!\n");

    display_guest(guest);
    display_room(room_number);

    return 0;
}