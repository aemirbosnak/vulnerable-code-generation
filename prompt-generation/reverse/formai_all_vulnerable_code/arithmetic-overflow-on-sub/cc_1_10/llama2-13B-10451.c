//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_GUESTS 100
#define MAX_ROOMS 20

// Define hotel struct
typedef struct {
    int num_guests;    // Number of guests currently staying
    int num_available_rooms; // Number of available rooms
    int *room_occupancy; // Array of room occupancy (0 = unoccupied, 1 = occupied)
    int *guest_arrival_times; // Array of guest arrival times
    int *guest_departure_times; // Array of guest departure times
} hotel;

// Function to initialize hotel
void init_hotel(hotel *h) {
    h->num_guests = 0;
    h->num_available_rooms = MAX_ROOMS;
    h->room_occupancy = calloc(MAX_ROOMS, sizeof(int));
    h->guest_arrival_times = calloc(MAX_GUESTS, sizeof(int));
    h->guest_departure_times = calloc(MAX_GUESTS, sizeof(int));
}

// Function to check availability of rooms
int check_availability(hotel *h) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (h->room_occupancy[i] == 0) {
            return 1; // Room found
        }
    }
    return 0; // No rooms found
}

// Function to check if guest has checked in
int check_in(hotel *h, int guest_id) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (h->guest_arrival_times[i] == guest_id) {
            h->room_occupancy[h->guest_arrival_times[i] - 1] = 1;
            return 1; // Guest has checked in
        }
    }
    return 0; // Guest not found
}

// Function to check if guest has checked out
int check_out(hotel *h, int guest_id) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (h->guest_departure_times[i] == guest_id) {
            h->room_occupancy[h->guest_departure_times[i] - 1] = 0;
            return 1; // Guest has checked out
        }
    }
    return 0; // Guest not found
}

// Function to handle guest arrival
void handle_arrival(hotel *h, int guest_id) {
    if (!check_availability(h)) {
        printf("No rooms available!\n");
        return;
    }
    h->guest_arrival_times[h->num_guests] = guest_id;
    h->num_guests++;
    h->room_occupancy[h->guest_arrival_times[h->num_guests] - 1] = 1;
}

// Function to handle guest departure
void handle_departure(hotel *h, int guest_id) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (h->guest_departure_times[i] == guest_id) {
            h->guest_departure_times[i] = 0; // Mark departure time as 0
            h->room_occupancy[h->guest_arrival_times[i] - 1] = 0; // Mark room as unoccupied
            h->num_guests--;
            return;
        }
    }
    printf("Guest not found\n");
}

int main() {
    hotel h;
    init_hotel(&h);

    // Example usage:
    handle_arrival(&h, 10); // Arrive at 10:00 AM
    handle_arrival(&h, 20); // Arrive at 2:00 PM
    handle_departure(&h, 10); // Depart at 12:00 PM
    handle_departure(&h, 20); // Depart at 4:00 PM

    // Print current status of hotel
    printf("Current status of hotel:\n");
    printf("Number of guests: %d\n", h.num_guests);
    printf("Number of available rooms: %d\n", h.num_available_rooms);
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d: %d\n", i + 1, h.room_occupancy[i]);
    }

    return 0;
}