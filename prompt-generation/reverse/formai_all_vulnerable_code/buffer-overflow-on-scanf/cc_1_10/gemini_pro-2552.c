//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int room_number;
    char room_type;
    int capacity;
    float price;
    int availability;
} room;

typedef struct reservation {
    int reservation_id;
    char guest_name[50];
    char check_in_date[11];
    char check_out_date[11];
    int room_number;
    int num_guests;
} reservation;

room rooms[] = {
    {101, 'S', 1, 100.0, 1},
    {102, 'S', 1, 100.0, 1},
    {103, 'D', 2, 150.0, 1},
    {104, 'D', 2, 150.0, 1},
    {105, 'Q', 4, 200.0, 1},
    {106, 'Q', 4, 200.0, 1}
};

reservation reservations[] = {};

int num_rooms = sizeof(rooms) / sizeof(rooms[0]);
int num_reservations = 0;

void print_rooms() {
    printf("Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d: %c, Capacity: %d, Price: $%.2f, Availability: %d\n", rooms[i].room_number, rooms[i].room_type, rooms[i].capacity, rooms[i].price, rooms[i].availability);
    }
}

void print_reservations() {
    printf("Reservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("Reservation %d: Guest Name: %s, Check-In Date: %s, Check-Out Date: %s, Room Number: %d, Number of Guests: %d\n", reservations[i].reservation_id, reservations[i].guest_name, reservations[i].check_in_date, reservations[i].check_out_date, reservations[i].room_number, reservations[i].num_guests);
    }
}

void make_reservation() {
    char guest_name[50];
    char check_in_date[11];
    char check_out_date[11];
    int room_number;
    int num_guests;

    printf("Enter guest name: ");
    scanf("%s", guest_name);

    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", check_in_date);

    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", check_out_date);

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter number of guests: ");
    scanf("%d", &num_guests);

    reservation new_reservation = {num_reservations + 1, guest_name, check_in_date, check_out_date, room_number, num_guests};

    reservations[num_reservations] = new_reservation;

    num_reservations++;

    printf("Reservation made successfully.\n");
}

void cancel_reservation() {
    int reservation_id;

    printf("Enter reservation ID: ");
    scanf("%d", &reservation_id);

    for (int i = 0; i < num_reservations; i++) {
        if (reservations[i].reservation_id == reservation_id) {
            reservations[i] = reservations[num_reservations - 1];

            num_reservations--;

            printf("Reservation canceled successfully.\n");

            return;
        }
    }

    printf("Reservation not found.\n");
}

void check_availability() {
    char check_in_date[11];
    char check_out_date[11];

    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", check_in_date);

    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", check_out_date);

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].availability == 1) {
            printf("Room %d is available.\n", rooms[i].room_number);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Print Rooms\n");
        printf("2. Print Reservations\n");
        printf("3. Make Reservation\n");
        printf("4. Cancel Reservation\n");
        printf("5. Check Availability\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_rooms();
                break;
            case 2:
                print_reservations();
                break;
            case 3:
                make_reservation();
                break;
            case 4:
                cancel_reservation();
                break;
            case 5:
                check_availability();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}