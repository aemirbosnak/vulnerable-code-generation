//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_number;
    char room_type[20];
    float room_price;
    int room_availability;
};

struct guest {
    char guest_name[50];
    char guest_address[100];
    char guest_phone[20];
    char guest_email[50];
    int guest_id;
};

struct reservation {
    int reservation_id;
    char reservation_date[20];
    char reservation_time[20];
    int room_number;
    int guest_id;
};

void add_room(struct room *rooms, int *num_rooms) {
    printf("Enter room number: ");
    scanf("%d", &rooms[*num_rooms].room_number);

    printf("Enter room type: ");
    scanf("%s", rooms[*num_rooms].room_type);

    printf("Enter room price: ");
    scanf("%f", &rooms[*num_rooms].room_price);

    rooms[*num_rooms].room_availability = 1;

    (*num_rooms)++;
}

void view_rooms(struct room *rooms, int num_rooms) {
    printf("\n%-10s %-20s %-10s %-15s\n", "Room No.", "Room Type", "Room Price", "Availability");

    for (int i = 0; i < num_rooms; i++) {
        printf("%-10d %-20s %-10.2f %-15s\n", rooms[i].room_number, rooms[i].room_type, rooms[i].room_price, rooms[i].room_availability ? "Available" : "Occupied");
    }
}

void add_guest(struct guest *guests, int *num_guests) {
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].guest_name);

    printf("Enter guest address: ");
    scanf("%s", guests[*num_guests].guest_address);

    printf("Enter guest phone: ");
    scanf("%s", guests[*num_guests].guest_phone);

    printf("Enter guest email: ");
    scanf("%s", guests[*num_guests].guest_email);

    guests[*num_guests].guest_id = (*num_guests) + 1;

    (*num_guests)++;
}

void view_guests(struct guest *guests, int num_guests) {
    printf("\n%-10s %-20s %-15s %-20s %-10s\n", "Guest ID", "Guest Name", "Guest Address", "Guest Phone", "Guest Email");

    for (int i = 0; i < num_guests; i++) {
        printf("%-10d %-20s %-15s %-20s %-10s\n", guests[i].guest_id, guests[i].guest_name, guests[i].guest_address, guests[i].guest_phone, guests[i].guest_email);
    }
}

void make_reservation(struct room *rooms, int num_rooms, struct guest *guests, int num_guests, struct reservation *reservations, int *num_reservations) {
    int room_number, guest_id;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter guest ID: ");
    scanf("%d", &guest_id);

    if (room_number > num_rooms || room_number < 1) {
        printf("Invalid room number.\n");
        return;
    }

    if (guest_id > num_guests || guest_id < 1) {
        printf("Invalid guest ID.\n");
        return;
    }

    if (!rooms[room_number - 1].room_availability) {
        printf("Room is not available.\n");
        return;
    }

    reservations[*num_reservations].reservation_id = (*num_reservations) + 1;
    strcpy(reservations[*num_reservations].reservation_date, "2023-03-08");
    strcpy(reservations[*num_reservations].reservation_time, "12:00 PM");
    reservations[*num_reservations].room_number = room_number;
    reservations[*num_reservations].guest_id = guest_id;

    rooms[room_number - 1].room_availability = 0;

    (*num_reservations)++;
}

void view_reservations(struct reservation *reservations, int num_reservations) {
    printf("\n%-10s %-20s %-15s %-10s %-10s\n", "Reservation ID", "Reservation Date", "Reservation Time", "Room Number", "Guest ID");

    for (int i = 0; i < num_reservations; i++) {
        printf("%-10d %-20s %-15s %-10d %-10d\n", reservations[i].reservation_id, reservations[i].reservation_date, reservations[i].reservation_time, reservations[i].room_number, reservations[i].guest_id);
    }
}

int main() {
    struct room rooms[10];
    int num_rooms = 0;

    struct guest guests[10];
    int num_guests = 0;

    struct reservation reservations[10];
    int num_reservations = 0;

    int choice;

    while (1) {
        printf("\n1. Add Room\n2. View Rooms\n3. Add Guest\n4. View Guests\n5. Make Reservation\n6. View Reservations\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room(rooms, &num_rooms);
                break;
            case 2:
                view_rooms(rooms, num_rooms);
                break;
            case 3:
                add_guest(guests, &num_guests);
                break;
            case 4:
                view_guests(guests, num_guests);
                break;
            case 5:
                make_reservation(rooms, num_rooms, guests, num_guests, reservations, &num_reservations);
                break;
            case 6:
                view_reservations(reservations, num_reservations);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}