//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_RESERVATIONS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[15];
} Guest;

typedef struct {
    int room_number;
    int guest_id;
    char checkin_date[20];
    char checkout_date[20];
} Reservation;

int num_rooms = 0;
int num_guests = 0;
int num_reservations = 0;

Guest guests[MAX_GUESTS];
Reservation reservations[MAX_RESERVATIONS];

void add_room() {
    num_rooms++;
}

void add_guest() {
    num_guests++;
}

void add_reservation() {
    num_reservations++;
}

void display_rooms() {
    printf("Number of rooms: %d\n", num_rooms);
}

void display_guests() {
    printf("Number of guests: %d\n", num_guests);
}

void display_reservations() {
    printf("Number of reservations: %d\n", num_reservations);
}

int main() {
    char choice;
    int id;

    do {
        printf("\nHotel Management System\n");
        printf("1. Add room\n");
        printf("2. Add guest\n");
        printf("3. Add reservation\n");
        printf("4. Display rooms\n");
        printf("5. Display guests\n");
        printf("6. Display reservations\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_room();
                break;
            case '2':
                add_guest();
                break;
            case '3':
                add_reservation();
                break;
            case '4':
                display_rooms();
                break;
            case '5':
                display_guests();
                break;
            case '6':
                display_reservations();
                break;
            case '7':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    } while (1);

    return 0;
}