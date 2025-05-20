//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

struct Room {
    int room_number;
    char room_type[20];
    float room_price;
};

struct Reservation {
    char guest_name[30];
    int num_of_guests;
    int num_of_nights;
    int room_number;
    float total_price;
};

int num_of_rooms = 0;
struct Room rooms[MAX_ROOMS];
int num_of_reservations = 0;
struct Reservation reservations[MAX_ROOMS];

void add_room() {
    struct Room room;

    printf("Enter room number: ");
    scanf("%d", &room.room_number);
    printf("Enter room type: ");
    scanf("%s", room.room_type);
    printf("Enter room price: ");
    scanf("%f", &room.room_price);

    rooms[num_of_rooms++] = room;
    printf("Room added successfully.\n");
}

void add_reservation() {
    char guest_name[30];
    int num_of_guests;
    int num_of_nights;
    int room_number;

    printf("Enter guest name: ");
    scanf("%s", guest_name);
    printf("Enter number of guests: ");
    scanf("%d", &num_of_guests);
    printf("Enter number of nights: ");
    scanf("%d", &num_of_nights);
    printf("Enter room number: ");
    scanf("%d", &room_number);

    // Find the room
    struct Room *room = NULL;
    for (int i = 0; i < num_of_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            room = &rooms[i];
            break;
        }
    }

    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }

    // Calculate total price
    float total_price = room->room_price * num_of_nights;

    reservations[num_of_reservations].room_number = room_number;
    strcpy(reservations[num_of_reservations].guest_name, guest_name);
    reservations[num_of_reservations].num_of_guests = num_of_guests;
    reservations[num_of_reservations].num_of_nights = num_of_nights;
    reservations[num_of_reservations].total_price = total_price;

    printf("Reservation added successfully.\n");
    num_of_reservations++;
}

void print_rooms() {
    printf("%-10s %-15s %-10s\n", "Room #", "Type", "Price");
    for (int i = 0; i < num_of_rooms; i++) {
        printf("%-10d %-15s %-10.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].room_price);
    }
}

void print_reservations() {
    printf("%-15s %-10s %-15s %-10s %-10s\n", "Guest Name", "# Guests", "Room Type", "# Nights", "Price");
    for (int i = 0; i < num_of_reservations; i++) {
        int room_num = reservations[i].room_number;
        struct Room *room = NULL;
        for (int j = 0; j < num_of_rooms; j++) {
            if (rooms[j].room_number == room_num) {
                room = &rooms[j];
                break;
            }
        }

        printf("%-15s %-10d %-15s %-10d %-10.2f\n", reservations[i].guest_name, reservations[i].num_of_guests, 
            room->room_type, reservations[i].num_of_nights, reservations[i].total_price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Menu\n");
        printf("====\n");
        printf("1. Add room\n");
        printf("2. Add reservation\n");
        printf("3. View rooms\n");
        printf("4. View reservations\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                add_reservation();
                break;
            case 3:
                print_rooms();
                break;
            case 4:
                print_reservations();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}