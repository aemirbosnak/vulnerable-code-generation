//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
typedef struct Room {
    char room_number[10];
    char room_type[20];
    int number_of_beds;
    float room_rate;
    char amenities[100];
} Room;

// Define the structure of a guest
typedef struct Guest {
    char guest_name[50];
    char guest_address[100];
    char guest_phone_number[20];
    char guest_email[50];
    char guest_room_number[10];
} Guest;

// Function to add a room
void add_room(Room *room) {
    printf("Enter the room number: ");
    scanf("%s", room->room_number);

    printf("Enter the room type: ");
    scanf("%s", room->room_type);

    printf("Enter the number of beds: ");
    scanf("%d", &room->number_of_beds);

    printf("Enter the room rate: ");
    scanf("%f", &room->room_rate);

    printf("Enter the amenities: ");
    scanf("%s", room->amenities);
}

// Function to add a guest
void add_guest(Guest *guest) {
    printf("Enter the guest name: ");
    scanf("%s", guest->guest_name);

    printf("Enter the guest address: ");
    scanf("%s", guest->guest_address);

    printf("Enter the guest phone number: ");
    scanf("%s", guest->guest_phone_number);

    printf("Enter the guest email: ");
    scanf("%s", guest->guest_email);

    printf("Enter the guest room number: ");
    scanf("%s", guest->guest_room_number);
}

// Function to display the list of rooms
void display_rooms(Room *rooms, int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        printf("Room Number: %s\n", rooms[i].room_number);
        printf("Room Type: %s\n", rooms[i].room_type);
        printf("Number of Beds: %d\n", rooms[i].number_of_beds);
        printf("Room Rate: %.2f\n", rooms[i].room_rate);
        printf("Amenities: %s\n", rooms[i].amenities);
        printf("\n");
    }
}

// Function to display the list of guests
void display_guests(Guest *guests, int num_guests) {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest Name: %s\n", guests[i].guest_name);
        printf("Guest Address: %s\n", guests[i].guest_address);
        printf("Guest Phone Number: %s\n", guests[i].guest_phone_number);
        printf("Guest Email: %s\n", guests[i].guest_email);
        printf("Guest Room Number: %s\n", guests[i].guest_room_number);
        printf("\n");
    }
}

int main() {
    // Create an array of rooms
    Room rooms[10];

    // Add some rooms
    add_room(&rooms[0]);
    add_room(&rooms[1]);
    add_room(&rooms[2]);

    // Create an array of guests
    Guest guests[5];

    // Add some guests
    add_guest(&guests[0]);
    add_guest(&guests[1]);
    add_guest(&guests[2]);

    // Display the list of rooms
    display_rooms(rooms, 3);

    // Display the list of guests
    display_guests(guests, 3);

    return 0;
}