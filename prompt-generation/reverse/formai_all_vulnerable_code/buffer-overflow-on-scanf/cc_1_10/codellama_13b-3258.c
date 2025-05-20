//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Hotel {
    int id;
    char name[50];
    int capacity;
    int price;
};

struct Room {
    int id;
    int hotel_id;
    int room_type;
    int price;
};

struct Guest {
    int id;
    char name[50];
    int age;
    char address[50];
    int phone;
    int hotel_id;
    int room_id;
    int check_in_date;
    int check_out_date;
};

void add_hotel(struct Hotel *hotel) {
    hotel->id = rand() % 100;
    printf("Enter the name of the hotel: ");
    scanf("%s", hotel->name);
    printf("Enter the capacity of the hotel: ");
    scanf("%d", &hotel->capacity);
    printf("Enter the price of the hotel: ");
    scanf("%d", &hotel->price);
}

void add_room(struct Room *room, struct Hotel *hotel) {
    room->id = rand() % 100;
    room->hotel_id = hotel->id;
    printf("Enter the room type (1 for single, 2 for double, 3 for suite): ");
    scanf("%d", &room->room_type);
    printf("Enter the price of the room: ");
    scanf("%d", &room->price);
}

void add_guest(struct Guest *guest, struct Hotel *hotel, struct Room *room) {
    guest->id = rand() % 100;
    printf("Enter the name of the guest: ");
    scanf("%s", guest->name);
    printf("Enter the age of the guest: ");
    scanf("%d", &guest->age);
    printf("Enter the address of the guest: ");
    scanf("%s", guest->address);
    printf("Enter the phone number of the guest: ");
    scanf("%d", &guest->phone);
    guest->hotel_id = hotel->id;
    guest->room_id = room->id;
    printf("Enter the check-in date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &guest->check_in_date, &guest->check_in_date, &guest->check_in_date);
    printf("Enter the check-out date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &guest->check_out_date, &guest->check_out_date, &guest->check_out_date);
}

void print_hotel(struct Hotel *hotel) {
    printf("Hotel ID: %d\n", hotel->id);
    printf("Hotel Name: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Price: %d\n", hotel->price);
}

void print_room(struct Room *room) {
    printf("Room ID: %d\n", room->id);
    printf("Hotel ID: %d\n", room->hotel_id);
    printf("Room Type: ");
    switch (room->room_type) {
        case 1:
            printf("Single");
            break;
        case 2:
            printf("Double");
            break;
        case 3:
            printf("Suite");
            break;
        default:
            printf("Invalid");
    }
    printf("\n");
    printf("Price: %d\n", room->price);
}

void print_guest(struct Guest *guest) {
    printf("Guest ID: %d\n", guest->id);
    printf("Name: %s\n", guest->name);
    printf("Age: %d\n", guest->age);
    printf("Address: %s\n", guest->address);
    printf("Phone: %d\n", guest->phone);
    printf("Hotel ID: %d\n", guest->hotel_id);
    printf("Room ID: %d\n", guest->room_id);
    printf("Check-in Date: %d-%d-%d\n", guest->check_in_date, guest->check_in_date, guest->check_in_date);
    printf("Check-out Date: %d-%d-%d\n", guest->check_out_date, guest->check_out_date, guest->check_out_date);
}

int main() {
    struct Hotel hotel;
    struct Room room;
    struct Guest guest;

    add_hotel(&hotel);
    add_room(&room, &hotel);
    add_guest(&guest, &hotel, &room);

    print_hotel(&hotel);
    print_room(&room);
    print_guest(&guest);

    return 0;
}