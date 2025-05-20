//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of guests
#define MAX_GUESTS 100

// Define the guest structure
typedef struct Guest {
    char name[50];
    int room_number;
    int num_of_days;
    char status;
} Guest;

// Define the room structure
typedef struct Room {
    int room_number;
    int occupancy;
    char type;
} Room;

// Create an array of guests
Guest guests[MAX_GUESTS];

// Create an array of rooms
Room rooms[MAX_GUESTS];

// Function to add a guest to the system
void add_guest() {
    // Get the guest's name, room number, and number of days
    printf("Enter your name: ");
    scanf("%s", guests[MAX_GUESTS - 1].name);

    printf("Enter your room number: ");
    scanf("%d", &guests[MAX_GUESTS - 1].room_number);

    printf("Enter the number of days you will be staying: ");
    scanf("%d", &guests[MAX_GUESTS - 1].num_of_days);

    // Set the guest's status to "confirmed"
    guests[MAX_GUESTS - 1].status = 'C';
}

// Function to check in a guest
void check_in() {
    // Get the guest's name
    printf("Enter your name: ");
    scanf("%s", guests[MAX_GUESTS - 1].name);

    // Check if the guest is confirmed
    if (guests[MAX_GUESTS - 1].status == 'C') {
        // Assign the guest to their room
        rooms[guests[MAX_GUESTS - 1].room_number].occupancy = guests[MAX_GUESTS - 1].num_of_days;

        // Print a welcome message
        printf("Welcome to the hotel, %s! Enjoy your stay!", guests[MAX_GUESTS - 1].name);
    } else {
        // Print an error message
        printf("Sorry, your reservation has not been confirmed.");
    }
}

// Function to check out a guest
void check_out() {
    // Get the guest's name
    printf("Enter your name: ");
    scanf("%s", guests[MAX_GUESTS - 1].name);

    // Check if the guest is checked in
    if (guests[MAX_GUESTS - 1].status == 'I') {
        // Calculate the guest's total cost
        int total_cost = rooms[guests[MAX_GUESTS - 1].room_number].occupancy * guests[MAX_GUESTS - 1].num_of_days;

        // Print the guest's total cost
        printf("Your total cost is $%d.", total_cost);

        // Set the guest's status to "checked out"
        guests[MAX_GUESTS - 1].status = 'O';
    } else {
        // Print an error message
        printf("Sorry, you are not checked in.");
    }
}

// Main function
int main() {
    // Add a guest to the system
    add_guest();

    // Check in a guest
    check_in();

    // Check out a guest
    check_out();

    return 0;
}