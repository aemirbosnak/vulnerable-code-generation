//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel {
    char name[50];
    int capacity;
    char address[100];
    char phone[20];
} Hotel;

typedef struct room {
    int room_id;
    int room_type;
    int beds;
    int guests;
} Room;

void create_hotel(Hotel* hotel) {
    printf("Enter hotel name: ");
    scanf("%s", hotel->name);

    printf("Enter hotel capacity: ");
    scanf("%d", &hotel->capacity);

    printf("Enter hotel address: ");
    scanf("%s", hotel->address);

    printf("Enter hotel phone number: ");
    scanf("%s", hotel->phone);
}

void create_room(Room* room, Hotel* hotel) {
    printf("Enter room type: ");
    scanf("%d", &room->room_type);

    printf("Enter number of beds: ");
    scanf("%d", &room->beds);

    printf("Enter number of guests: ");
    scanf("%d", &room->guests);
}

void display_hotel(Hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Hotel Capacity: %d\n", hotel->capacity);
    printf("Hotel Address: %s\n", hotel->address);
    printf("Hotel Phone Number: %s\n", hotel->phone);
}

void display_room(Room* room, Hotel* hotel) {
    printf("Room Type: %d\n", room->room_type);
    printf("Number of Beds: %d\n", room->beds);
    printf("Number of Guests: %d\n", room->guests);
}

int main() {
    Hotel hotel;
    create_hotel(&hotel);
    display_hotel(&hotel);

    Room room;
    create_room(&room, &hotel);
    display_room(&room, &hotel);

    return 0;
}