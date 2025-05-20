//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
// A unique C Hotel Management System example program in a shape shifting style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a hotel room
struct Room {
    int id;
    char name[50];
    char description[200];
    int capacity;
    int price;
};

// Define a structure to represent a hotel
struct Hotel {
    char name[50];
    char address[100];
    int num_rooms;
    struct Room *rooms;
};

// Function to print a hotel
void print_hotel(struct Hotel *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d: %s\n", hotel->rooms[i].id, hotel->rooms[i].name);
        printf("Description: %s\n", hotel->rooms[i].description);
        printf("Capacity: %d\n", hotel->rooms[i].capacity);
        printf("Price: %d\n", hotel->rooms[i].price);
    }
}

// Function to create a new hotel
struct Hotel *create_hotel(char *name, char *address, int num_rooms) {
    struct Hotel *hotel = malloc(sizeof(struct Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->rooms = malloc(num_rooms * sizeof(struct Room));
    return hotel;
}

// Function to create a new room
struct Room *create_room(int id, char *name, char *description, int capacity, int price) {
    struct Room *room = malloc(sizeof(struct Room));
    room->id = id;
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->capacity = capacity;
    room->price = price;
    return room;
}

// Function to add a room to a hotel
void add_room(struct Hotel *hotel, struct Room *room) {
    hotel->rooms[hotel->num_rooms] = *room;
    hotel->num_rooms++;
}

// Function to print a list of hotels
void print_hotels(struct Hotel **hotels, int num_hotels) {
    for (int i = 0; i < num_hotels; i++) {
        print_hotel(hotels[i]);
    }
}

int main() {
    // Create a new hotel
    struct Hotel *hotel = create_hotel("Grand Hotel", "123 Main St", 5);

    // Create some rooms
    struct Room *room1 = create_room(1, "Standard Room", "A comfortable room with a single bed", 1, 100);
    struct Room *room2 = create_room(2, "Deluxe Room", "A larger room with a double bed", 2, 200);
    struct Room *room3 = create_room(3, "Suite", "A luxurious suite with a king-sized bed", 4, 300);

    // Add the rooms to the hotel
    add_room(hotel, room1);
    add_room(hotel, room2);
    add_room(hotel, room3);

    // Print the hotel
    print_hotel(hotel);

    // Create another hotel
    struct Hotel *hotel2 = create_hotel("Little Hotel", "456 Elm St", 3);

    // Create some rooms
    struct Room *room4 = create_room(4, "Tiny Room", "A small room with a single bed", 1, 50);
    struct Room *room5 = create_room(5, "Small Room", "A cozy room with a double bed", 2, 100);
    struct Room *room6 = create_room(6, "Medium Room", "A comfortable room with a double bed", 3, 150);

    // Add the rooms to the hotel
    add_room(hotel2, room4);
    add_room(hotel2, room5);
    add_room(hotel2, room6);

    // Print the hotel
    print_hotel(hotel2);

    // Create an array of hotels
    struct Hotel **hotels = malloc(2 * sizeof(struct Hotel *));
    hotels[0] = hotel;
    hotels[1] = hotel2;

    // Print the list of hotels
    print_hotels(hotels, 2);

    return 0;
}