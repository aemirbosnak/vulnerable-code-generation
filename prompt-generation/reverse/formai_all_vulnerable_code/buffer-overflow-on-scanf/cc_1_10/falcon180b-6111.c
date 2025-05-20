//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100
#define MAX_STAFF 50

typedef struct {
    int room_number;
    char room_type[20];
    int rate;
    char status;
} Room;

typedef struct {
    char name[50];
    char address[100];
    int phone_number;
    char email[50];
} Guest;

typedef struct {
    int booking_id;
    int guest_id;
    int room_number;
    char checkin_date[20];
    char checkout_date[20];
    int duration;
    int total_cost;
} Booking;

typedef struct {
    int staff_id;
    char name[50];
    char designation[50];
    int salary;
} Staff;

int main() {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_GUESTS];
    Booking bookings[MAX_BOOKINGS];
    Staff staff[MAX_STAFF];

    int num_rooms, num_guests, num_bookings, num_staff;
    
    printf("Enter number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter number of guests: ");
    scanf("%d", &num_guests);

    printf("Enter number of bookings: ");
    scanf("%d", &num_bookings);

    printf("Enter number of staff: ");
    scanf("%d", &num_staff);

    for(int i=0; i<num_rooms; i++) {
        printf("Enter room details for room %d:\n", i+1);
        printf("Room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Room type: ");
        scanf("%s", rooms[i].room_type);
        printf("Rate: ");
        scanf("%d", &rooms[i].rate);
        printf("Status: ");
        scanf(" %c", &rooms[i].status);
    }

    for(int i=0; i<num_guests; i++) {
        printf("Enter guest details for guest %d:\n", i+1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Address: ");
        scanf("%s", guests[i].address);
        printf("Phone number: ");
        scanf("%d", &guests[i].phone_number);
        printf("Email: ");
        scanf("%s", guests[i].email);
    }

    for(int i=0; i<num_bookings; i++) {
        printf("Enter booking details for booking %d:\n", i+1);
        printf("Guest ID: ");
        scanf("%d", &bookings[i].guest_id);
        printf("Room number: ");
        scanf("%d", &bookings[i].room_number);
        printf("Checkin date: ");
        scanf("%s", bookings[i].checkin_date);
        printf("Checkout date: ");
        scanf("%s", bookings[i].checkout_date);
        bookings[i].duration = atoi(bookings[i].checkout_date) - atoi(bookings[i].checkin_date) + 1;
        bookings[i].total_cost = rooms[bookings[i].room_number-1].rate * bookings[i].duration;
    }

    for(int i=0; i<num_staff; i++) {
        printf("Enter staff details for staff %d:\n", i+1);
        printf("Name: ");
        scanf("%s", staff[i].name);
        printf("Designation: ");
        scanf("%s", staff[i].designation);
        printf("Salary: ");
        scanf("%d", &staff[i].salary);
    }

    return 0;
}