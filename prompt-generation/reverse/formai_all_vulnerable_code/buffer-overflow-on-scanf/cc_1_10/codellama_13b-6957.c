//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_BOOKINGS 100

// Structure to represent a booking
typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
    int duration;
    int total_cost;
} Booking;

// Function to calculate the total cost of a booking
int calculate_total_cost(int duration) {
    return duration * 100;
}

// Function to print the bookings
void print_bookings(Booking bookings[], int num_bookings) {
    for (int i = 0; i < num_bookings; i++) {
        printf("Booking %d: %s - Room %d - Duration %d - Total Cost %d\n", i, bookings[i].name, bookings[i].room_number, bookings[i].duration, bookings[i].total_cost);
    }
}

int main() {
    // Create an array of bookings
    Booking bookings[MAX_BOOKINGS];

    // Get the number of bookings
    int num_bookings;
    printf("Enter the number of bookings: ");
    scanf("%d", &num_bookings);

    // Get the booking details for each booking
    for (int i = 0; i < num_bookings; i++) {
        printf("Enter the name of booking %d: ", i);
        scanf("%s", bookings[i].name);
        printf("Enter the room number of booking %d: ", i);
        scanf("%d", &bookings[i].room_number);
        printf("Enter the duration of booking %d: ", i);
        scanf("%d", &bookings[i].duration);
        bookings[i].total_cost = calculate_total_cost(bookings[i].duration);
    }

    // Print the bookings
    print_bookings(bookings, num_bookings);

    return 0;
}