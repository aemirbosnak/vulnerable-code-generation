//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a guest's name
#define MAX_NAME_LENGTH 50

// Define the maximum number of nights a guest can stay
#define MAX_NIGHTS 7

// Define the room rates
#define SINGLE_ROOM_RATE 100
#define DOUBLE_ROOM_RATE 150
#define SUITE_ROOM_RATE 200

// Define the data structure for a guest
typedef struct guest {
    char name[MAX_NAME_LENGTH];
    int room_number;
    int nights;
    float total_cost;
} guest;

// Define the data structure for the hotel
typedef struct hotel {
    guest guests[MAX_ROOMS];
    int num_guests;
} hotel;

// Function to initialize the hotel
void initialize_hotel(hotel *h) {
    h->num_guests = 0;
}

// Function to add a guest to the hotel
void add_guest(hotel *h, guest *g) {
    h->guests[h->num_guests] = *g;
    h->num_guests++;
}

// Function to remove a guest from the hotel
void remove_guest(hotel *h, int room_number) {
    int i;
    for (i = 0; i < h->num_guests; i++) {
        if (h->guests[i].room_number == room_number) {
            break;
        }
    }

    if (i < h->num_guests) {
        for (i; i < h->num_guests - 1; i++) {
            h->guests[i] = h->guests[i + 1];
        }
        h->num_guests--;
    }
}

// Function to calculate the total cost of a guest's stay
float calculate_total_cost(guest *g) {
    float cost = 0;

    switch (g->room_number) {
        case 1:
            cost = g->nights * SINGLE_ROOM_RATE;
            break;
        case 2:
            cost = g->nights * DOUBLE_ROOM_RATE;
            break;
        case 3:
            cost = g->nights * SUITE_ROOM_RATE;
            break;
    }

    return cost;
}

// Function to print the hotel's guest list
void print_guest_list(hotel *h) {
    int i;
    for (i = 0; i < h->num_guests; i++) {
        printf("%s, Room %d, %d nights, $%.2f\n", h->guests[i].name, h->guests[i].room_number, h->guests[i].nights, h->guests[i].total_cost);
    }
}

// Function to main
int main() {
    // Initialize the hotel
    hotel h;
    initialize_hotel(&h);

    // Add some guests to the hotel
    guest g1 = {"John Smith", 1, 3, 0};
    guest g2 = {"Jane Doe", 2, 5, 0};
    guest g3 = {"Bill Jones", 3, 7, 0};
    add_guest(&h, &g1);
    add_guest(&h, &g2);
    add_guest(&h, &g3);

    // Calculate the total cost for each guest
    int i;
    for (i = 0; i < h.num_guests; i++) {
        h.guests[i].total_cost = calculate_total_cost(&h.guests[i]);
    }

    // Print the hotel's guest list
    print_guest_list(&h);

    // Remove a guest from the hotel
    remove_guest(&h, 2);

    // Print the hotel's guest list again
    print_guest_list(&h);

    return 0;
}