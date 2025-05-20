//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
// hotel_management_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 50

// Room structure
typedef struct {
    int room_number;
    int guests[MAX_GUESTS];
} Room;

// Guest structure
typedef struct {
    char name[20];
    char address[50];
    int phone_number;
} Guest;

// Function to add a new guest
void add_guest(Guest *guest, int guest_count) {
    printf("Enter the guest's name: ");
    scanf("%s", guest->name);
    printf("Enter the guest's address: ");
    scanf("%s", guest->address);
    printf("Enter the guest's phone number: ");
    scanf("%d", &guest->phone_number);
    guest_count++;
}

// Function to display all guests
void display_guests(Guest guests[], int guest_count) {
    int i;
    for (i = 0; i < guest_count; i++) {
        printf("%s\n", guests[i].name);
        printf("%s\n", guests[i].address);
        printf("%d\n", guests[i].phone_number);
    }
}

// Function to add a new room
void add_room(Room *room, int room_count) {
    printf("Enter the room number: ");
    scanf("%d", &room->room_number);
    room_count++;
}

// Function to display all rooms
void display_rooms(Room rooms[], int room_count) {
    int i;
    for (i = 0; i < room_count; i++) {
        printf("%d\n", rooms[i].room_number);
    }
}

int main() {
    // Initialize guest and room variables
    Guest guests[MAX_GUESTS];
    Room rooms[MAX_ROOMS];
    int guest_count = 0;
    int room_count = 0;

    // Add guests and rooms
    add_guest(&guests[guest_count], guest_count);
    add_room(&rooms[room_count], room_count);

    // Display guests and rooms
    display_guests(guests, guest_count);
    display_rooms(rooms, room_count);

    return 0;
}