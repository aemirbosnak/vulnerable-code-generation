//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char room_type[20];
    int num_guests;
    float price;
} Room;

typedef struct {
    Room rooms[100];
    int num_rooms;
} Hotel;

void init_hotel(Hotel* hotel) {
    hotel->num_rooms = 0;
}

int find_room(Hotel* hotel, char* room_type) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (strcmp(hotel->rooms[i].room_type, room_type) == 0) {
            return i;
        }
    }
    return -1;
}

void add_guest(Hotel* hotel, int room_index, int num_guests) {
    hotel->rooms[room_index].num_guests += num_guests;
}

void print_bill(Hotel* hotel, int room_index) {
    Room room = hotel->rooms[room_index];
    printf("Room Type: %s\n", room.room_type);
    printf("Number of Guests: %d\n", room.num_guests);
    printf("Price per Night: $%.2f\n", room.price);
    printf("Total Price: $%.2f\n", room.price * room.num_guests);
}

int main(void) {
    Hotel my_hotel;
    init_hotel(&my_hotel);

    Room new_room = {"King", "Deluxe", 2, 50.0};
    my_hotel.rooms[my_hotel.num_rooms++] = new_room;

    int room_index = find_room(&my_hotel, "Deluxe");
    add_guest(&my_hotel, room_index, 3);

    room_index = find_room(&my_hotel, "King");
    add_guest(&my_hotel, room_index, 4);

    print_bill(&my_hotel, room_index);

    return 0;
}