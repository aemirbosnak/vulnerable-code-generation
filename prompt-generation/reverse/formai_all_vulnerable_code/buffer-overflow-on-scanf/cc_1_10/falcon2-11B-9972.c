//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_id;
    char room_type[20];
    int num_of_beds;
    int num_of_guests;
    int price_per_night;
};

struct guest {
    int guest_id;
    char first_name[20];
    char last_name[20];
    int arrival_date;
    int departure_date;
};

struct hotel {
    int hotel_id;
    char hotel_name[20];
    struct room rooms[10];
    struct guest guests[10];
};

int main() {
    struct hotel hotel;

    printf("Enter the hotel id: ");
    scanf("%d", &hotel.hotel_id);

    printf("Enter the hotel name: ");
    scanf("%s", hotel.hotel_name);

    int num_rooms = 0;
    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    for(int i = 0; i < num_rooms; i++) {
        struct room room;

        printf("Enter the room id: ");
        scanf("%d", &room.room_id);

        printf("Enter the room type: ");
        scanf(" %s", room.room_type);

        printf("Enter the number of beds: ");
        scanf("%d", &room.num_of_beds);

        printf("Enter the number of guests: ");
        scanf("%d", &room.num_of_guests);

        printf("Enter the price per night: ");
        scanf("%d", &room.price_per_night);

        hotel.rooms[i] = room;
    }

    int num_guests = 0;
    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);

    for(int i = 0; i < num_guests; i++) {
        struct guest guest;

        printf("Enter the guest id: ");
        scanf("%d", &guest.guest_id);

        printf("Enter the first name: ");
        scanf(" %s", guest.first_name);

        printf("Enter the last name: ");
        scanf(" %s", guest.last_name);

        printf("Enter the arrival date: ");
        scanf("%d", &guest.arrival_date);

        printf("Enter the departure date: ");
        scanf("%d", &guest.departure_date);

        hotel.guests[i] = guest;
    }

    printf("Hotel ID: %d\n", hotel.hotel_id);
    printf("Hotel Name: %s\n", hotel.hotel_name);

    for(int i = 0; i < num_rooms; i++) {
        struct room room = hotel.rooms[i];
        printf("Room %d: %s, %d beds, %d guests, $%.2f per night\n",
               room.room_id,
               room.room_type,
               room.num_of_beds,
               room.num_of_guests,
               room.price_per_night);
    }

    for(int i = 0; i < num_guests; i++) {
        struct guest guest = hotel.guests[i];
        printf("Guest %d: %s %s, arriving on %d, leaving on %d\n",
               guest.guest_id,
               guest.first_name,
               guest.last_name,
               guest.arrival_date,
               guest.departure_date);
    }

    return 0;
}