//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_BOOKINGS 10000

typedef struct {
    char name[50];
    int age;
    char address[100];
} Guest;

typedef struct {
    int room_number;
    int number_of_guests;
    char guest_name[50];
    int booking_id;
} Booking;

typedef struct {
    int id;
    char name[50];
    int price_per_night;
    int availability;
} Room;

int main() {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_GUESTS];
    Booking bookings[MAX_BOOKINGS];
    int num_rooms, num_guests, num_bookings;
    int i, j, k;

    printf("Enter number of rooms in the hotel: ");
    scanf("%d", &num_rooms);

    for (i = 0; i < num_rooms; i++) {
        printf("Enter details for room %d:\n", i+1);
        printf("Name: ");
        scanf("%s", rooms[i].name);
        printf("Price per night: ");
        scanf("%d", &rooms[i].price_per_night);
        printf("Availability: ");
        scanf("%d", &rooms[i].availability);
    }

    printf("Enter number of guests: ");
    scanf("%d", &num_guests);

    for (i = 0; i < num_guests; i++) {
        printf("Enter details for guest %d:\n", i+1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Age: ");
        scanf("%d", &guests[i].age);
        printf("Address: ");
        scanf("%s", guests[i].address);
    }

    printf("Enter number of bookings: ");
    scanf("%d", &num_bookings);

    for (i = 0; i < num_bookings; i++) {
        printf("Enter details for booking %d:\n", i+1);
        printf("Room number: ");
        scanf("%d", &bookings[i].room_number);
        printf("Number of guests: ");
        scanf("%d", &bookings[i].number_of_guests);
        printf("Guest name: ");
        scanf("%s", bookings[i].guest_name);
    }

    return 0;
}