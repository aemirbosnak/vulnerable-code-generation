//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define data structures to store hotel information
typedef struct Room {
    int number;
    int capacity;
    int available;
    float price;
} Room;

typedef struct Reservation {
    int room_number;
    char guest_name[50];
    int start_day;
    int end_day;
} Reservation;

// Declare global variables
int num_rooms;
Room* rooms;
int num_reservations;
Reservation* reservations;

// Declare function prototypes
void print_menu();
void add_room();
void list_rooms();
void reserve_room();
void list_reservations();

// Main program loop
int main() {
    int choice;

    // Initialize variables
    num_rooms = 0;
    rooms = NULL;
    num_reservations = 0;
    reservations = NULL;

    // Main menu loop
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                list_rooms();
                break;
            case 3:
                reserve_room();
                break;
            case 4:
                list_reservations();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 5);

    // Clean up memory
    free(rooms);
    free(reservations);

    return 0;
}

// Function to print main menu
void print_menu() {
    printf("Welcome to the Hotel Management System\n");
    printf("--------------------------------------\n");
    printf("1) Add a new room\n");
    printf("2) List all rooms\n");
    printf("3) Reserve a room\n");
    printf("4) List all reservations\n");
    printf("5) Exit program\n");
}

// Function to add a new room
void add_room() {
    // Increment number of rooms
    num_rooms++;

    // Resize rooms array
    rooms = realloc(rooms, num_rooms * sizeof(Room));

    // Get room information from user
    printf("Enter room number: ");
    scanf("%d", &rooms[num_rooms-1].number);
    printf("Enter room capacity: ");
    scanf("%d", &rooms[num_rooms-1].capacity);
    printf("Enter room price: ");
    scanf("%f", &rooms[num_rooms-1].price);

    // Mark room as available
    rooms[num_rooms-1].available = 1;

    // Print confirmation message
    printf("Room %d has been added\n", rooms[num_rooms-1].number);
}

// Function to list all rooms
void list_rooms() {
    printf("List of available rooms\n");
    printf("-----------------------\n");
    for (int i=0; i<num_rooms; i++) {
        if (rooms[i].available) {
            printf("Room %d, capacity %d, price %.2f\n",
                rooms[i].number, rooms[i].capacity, rooms[i].price);
        }
    }
}

// Function to reserve a room
void reserve_room() {
    // Get reservation information from user
    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);
    printf("Enter start day of reservation: ");
    int start_day;
    scanf("%d", &start_day);
    printf("Enter end day of reservation: ");
    int end_day;
    scanf("%d", &end_day);

    // Display list of available rooms
    list_rooms();

    // Get user's choice of room number
    int room_number;
    do {
        printf("Enter room number to reserve: ");
        scanf("%d", &room_number);
        // Check if room is available
        if (!rooms[room_number-1].available) {
            printf("Room is not available, please choose another one\n");
        }
    } while (!rooms[room_number-1].available);

    // Mark room as unavailable
    rooms[room_number-1].available = 0;

    // Add reservation to list
    num_reservations++;
    reservations = realloc(reservations, num_reservations * sizeof(Reservation));
    reservations[num_reservations-1].room_number = room_number;
    strcpy(reservations[num_reservations-1].guest_name, guest_name);
    reservations[num_reservations-1].start_day = start_day;
    reservations[num_reservations-1].end_day = end_day;

    // Print confirmation message
    printf("%s has reserved room %d from day %d to %d\n",
        guest_name, room_number, start_day, end_day);
}

// Function to list all reservations
void list_reservations() {
    printf("List of all reservations\n");
    printf("------------------------\n");
    for (int i=0; i<num_reservations; i++) {
        printf("%s has reserved room %d from day %d to %d\n",
            reservations[i].guest_name, reservations[i].room_number,
            reservations[i].start_day, reservations[i].end_day);
    }
}