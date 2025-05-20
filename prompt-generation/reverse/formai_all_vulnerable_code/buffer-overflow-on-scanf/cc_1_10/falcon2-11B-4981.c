//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a hotel booking
struct Booking {
    char name[50];
    char phone[20];
    int days;
    float price;
};

// Define a structure to represent a hotel
struct Hotel {
    char name[50];
    int capacity;
    struct Booking bookings[50];
};

// Function to initialize a hotel with a given name and capacity
void initHotel(struct Hotel* hotel, char* name, int capacity) {
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        hotel->bookings[i].days = 0;
        hotel->bookings[i].price = 0.0f;
    }
}

// Function to check if a room is available in the hotel
int isRoomAvailable(struct Hotel* hotel, char* name) {
    for (int i = 0; i < hotel->capacity; i++) {
        if (strcmp(hotel->bookings[i].name, name) == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to add a booking to the hotel
void addBooking(struct Hotel* hotel, char* name, char* phone, int days, float price) {
    for (int i = 0; i < hotel->capacity; i++) {
        if (strcmp(hotel->bookings[i].name, name) == 0) {
            hotel->bookings[i].days = days;
            hotel->bookings[i].price = price;
            return;
        }
    }
    printf("Error: Room is not available\n");
}

// Function to remove a booking from the hotel
void removeBooking(struct Hotel* hotel, char* name) {
    for (int i = 0; i < hotel->capacity; i++) {
        if (strcmp(hotel->bookings[i].name, name) == 0) {
            hotel->bookings[i].days = 0;
            hotel->bookings[i].price = 0.0f;
            return;
        }
    }
    printf("Error: Room is not available\n");
}

// Function to print the hotel's availability and bookings
void printHotel(struct Hotel* hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Available Rooms: %d\n", hotel->capacity - sizeof(hotel->bookings) / sizeof(struct Booking));
    for (int i = 0; i < hotel->capacity; i++) {
        printf("Room %d: %s (%d days, %.2f)\n", i + 1, hotel->bookings[i].name, hotel->bookings[i].days, hotel->bookings[i].price);
    }
}

// Function to check-in a guest to the hotel
void checkIn(struct Hotel* hotel, char* name) {
    if (isRoomAvailable(hotel, name)) {
        printf("Checking in: %s\n", name);
        addBooking(hotel, name, "", 1, 100.0f);
        printHotel(hotel);
    } else {
        printf("Error: Room is not available\n");
    }
}

// Function to check-out a guest from the hotel
void checkOut(struct Hotel* hotel, char* name) {
    if (isRoomAvailable(hotel, name)) {
        removeBooking(hotel, name);
        printHotel(hotel);
    } else {
        printf("Error: Room is not available\n");
    }
}

int main() {
    struct Hotel hotel;
    char hotelName[50];
    int capacity;
    char name[50];
    char phone[20];
    int days;
    float price;

    // Get user input
    printf("Enter hotel name: ");
    fgets(hotelName, sizeof(hotelName), stdin);
    printf("Enter hotel capacity: ");
    scanf("%d", &capacity);
    printf("Enter guest name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter guest phone number: ");
    fgets(phone, sizeof(phone), stdin);
    printf("Enter number of days: ");
    scanf("%d", &days);
    printf("Enter price per day: ");
    scanf("%f", &price);

    // Initialize the hotel
    initHotel(&hotel, hotelName, capacity);

    // Check-in the guest
    checkIn(&hotel, name);

    // Check-out the guest
    checkOut(&hotel, name);

    // Print the updated availability and bookings
    printHotel(&hotel);

    return 0;
}