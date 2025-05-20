//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room details
typedef struct room {
    int room_number;
    char room_type[20];
    int availability;
    float price;
} room;

// Structure to store guest details
typedef struct guest {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    int room_number;
    int check_in_date;
    int check_out_date;
} guest;

// Function to add a new room
void add_room(room *rooms, int *num_rooms) {
    // Get room details from user
    printf("Enter room number: ");
    scanf("%d", &rooms[*num_rooms].room_number);
    printf("Enter room type: ");
    scanf("%s", rooms[*num_rooms].room_type);
    printf("Enter room price: ");
    scanf("%f", &rooms[*num_rooms].price);

    // Set room availability to 1 (available)
    rooms[*num_rooms].availability = 1;

    // Increment number of rooms
    (*num_rooms)++;
}

// Function to display all rooms
void display_rooms(room *rooms, int num_rooms) {
    printf("\n%-10s%-20s%-15s%-10s\n", "Room No.", "Room Type", "Availability", "Price");
    for (int i = 0; i < num_rooms; i++) {
        printf("%-10d%-20s%-15s%-10.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].availability ? "Available" : "Occupied", rooms[i].price);
    }
}

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
    // Get guest details from user
    printf("\nEnter guest name: ");
    scanf(" %[^\n]%*c", guests[*num_guests].name);
    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guests[*num_guests].address);
    printf("Enter guest phone: ");
    scanf("%s", guests[*num_guests].phone);
    printf("Enter guest email: ");
    scanf("%s", guests[*num_guests].email);
    printf("Enter room number: ");
    scanf("%d", &guests[*num_guests].room_number);
    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &guests[*num_guests].check_in_date, &guests[*num_guests].check_in_date, &guests[*num_guests].check_in_date);
    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &guests[*num_guests].check_out_date, &guests[*num_guests].check_out_date, &guests[*num_guests].check_out_date);

    // Increment number of guests
    (*num_guests)++;
}

// Function to display all guests
void display_guests(guest *guests, int num_guests) {
    printf("\n%-20s%-20s%-15s%-15s%-10s%-10s%-10s\n", "Guest Name", "Guest Address", "Guest Phone", "Guest Email", "Room No.", "Check-In", "Check-Out");
    for (int i = 0; i < num_guests; i++) {
        printf("%-20s%-20s%-15s%-15s%-10d%-10d%-10d\n", guests[i].name, guests[i].address, guests[i].phone, guests[i].email, guests[i].room_number, guests[i].check_in_date, guests[i].check_out_date);
    }
}

// Main function
int main() {
    // Initialize hotel rooms and guests
    room rooms[100];
    int num_rooms = 0;
    guest guests[100];
    int num_guests = 0;

    // Main menu loop
    int choice;
    do {
        // Display menu options
        printf("\n\n***** Hotel Management System *****\n");
        printf("1. Add a new room\n");
        printf("2. Display all rooms\n");
        printf("3. Add a new guest\n");
        printf("4. Display all guests\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_room(rooms, &num_rooms);
                break;
            case 2:
                display_rooms(rooms, num_rooms);
                break;
            case 3:
                add_guest(guests, &num_guests);
                break;
            case 4:
                display_guests(guests, num_guests);
                break;
            case 5:
                printf("Thank you for using the Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid number (1-5).\n");
        }
    } while (choice != 5);

    return 0;
}