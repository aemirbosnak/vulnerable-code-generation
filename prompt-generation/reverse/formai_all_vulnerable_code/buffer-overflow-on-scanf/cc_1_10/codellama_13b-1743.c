//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: configurable
/*
 * Hotel Management System Example Program
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_GUESTS 100
#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 30

// Define data types
typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
    int arrival_date;
    int departure_date;
} Guest;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
    int status;
} Room;

// Define functions
void get_input(Guest guests[], int *num_guests);
void print_guests(Guest guests[], int num_guests);
void print_rooms(Room rooms[], int num_rooms);

// Main function
int main() {
    // Declare variables
    Guest guests[MAX_GUESTS];
    Room rooms[MAX_ROOMS];
    int num_guests = 0;
    int num_rooms = 0;

    // Get input from user
    get_input(guests, &num_guests);

    // Print guests
    print_guests(guests, num_guests);

    // Print rooms
    print_rooms(rooms, num_rooms);

    // Return success
    return 0;
}

// Get input from user
void get_input(Guest guests[], int *num_guests) {
    int i;

    // Ask for number of guests
    printf("Enter the number of guests: ");
    scanf("%d", num_guests);

    // Ask for guest details
    for (i = 0; i < *num_guests; i++) {
        printf("Enter guest %d's name: ", i + 1);
        scanf("%s", guests[i].name);
        printf("Enter guest %d's room number: ", i + 1);
        scanf("%d", &guests[i].room_number);
        printf("Enter guest %d's arrival date: ", i + 1);
        scanf("%d", &guests[i].arrival_date);
        printf("Enter guest %d's departure date: ", i + 1);
        scanf("%d", &guests[i].departure_date);
    }
}

// Print guests
void print_guests(Guest guests[], int num_guests) {
    int i;

    // Print guests
    for (i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Arrival date: %d\n", guests[i].arrival_date);
        printf("Departure date: %d\n", guests[i].departure_date);
    }
}

// Print rooms
void print_rooms(Room rooms[], int num_rooms) {
    int i;

    // Print rooms
    for (i = 0; i < num_rooms; i++) {
        printf("Room %d:\n", i + 1);
        printf("Name: %s\n", rooms[i].name);
        printf("Room number: %d\n", rooms[i].room_number);
        printf("Status: %d\n", rooms[i].status);
    }
}