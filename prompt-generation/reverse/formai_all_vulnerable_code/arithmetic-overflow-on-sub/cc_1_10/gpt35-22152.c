//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Structure to hold guest information
typedef struct {
    int guest_id;
    char guest_name[50];
    int room_number;
} Guest;

// Structure to hold room information
typedef struct {
    int room_number;
    bool is_available;
    pthread_mutex_t lock;
} Room;

// Global variables
int num_of_guests;
int num_of_rooms;
Guest *guests;
Room *rooms;

// Function declarations
void init_guests();
void init_rooms();
void print_menu();
int get_room_number();
bool is_room_available(int room_number);
void book_room(int guest_id, char *guest_name, int room_number);
void checkout_room(int room_number);

// Main function
int main() {
    init_guests();
    init_rooms();
    bool is_running = true;
    while (is_running) {
        print_menu();
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Search for available room and book it
                printf("\nWelcome to the hotel booking system!\n\n");
                char guest_name[50];
                printf("Enter your name: ");
                scanf("%s", guest_name);
                int room_number = get_room_number();
                if (room_number != -1) {
                    // Book the room and print confirmation message
                    int guest_id = num_of_guests;
                    book_room(guest_id, guest_name, room_number);
                    printf("\nThank you %s, your booking is confirmed!\nYour room number is %d.\n\n", guest_name, room_number);
                } else {
                    printf("\nSorry, all rooms are currently booked. Please try again later.\n\n");
                }
                break;
            case 2:
                // Checkout from the room
                printf("\nWelcome to the checkout system!\n\n");
                int checkout_room_num;
                printf("Enter your room number: ");
                scanf("%d", &checkout_room_num);
                checkout_room(checkout_room_num);
                break;
            case 3:
                // Quit the program
                printf("\nThank you for using the hotel management system!\n\n");
                is_running = false;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
    // Free heap memory and destroy locks
    free(guests);
    free(rooms);
    for (int i = 0; i < num_of_rooms; i++) {
        pthread_mutex_destroy(&rooms[i].lock);
    }
    return 0;
}

// Function to initialize guests array
void init_guests() {
    printf("Enter the number of guests: ");
    scanf("%d", &num_of_guests);
    guests = (Guest *) malloc(num_of_guests * sizeof(Guest));
}

// Function to initialize rooms array
void init_rooms() {
    printf("Enter the number of rooms: ");
    scanf("%d", &num_of_rooms);
    rooms = (Room *) malloc(num_of_rooms * sizeof(Room));
    // Initialize each room with room number and availability
    for (int i = 0; i < num_of_rooms; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].is_available = true;
        pthread_mutex_init(&rooms[i].lock, NULL);
    }
}

// Function to print the menu
void print_menu() {
    printf("========= HOTEL MANAGEMENT SYSTEM =========\n");
    printf("1. Book a room\n");
    printf("2. Checkout\n");
    printf("3. Quit\n");
}

// Function to get available room number
int get_room_number() {
    int room_number = -1;
    for (int i = 0; i < num_of_rooms; i++) {
        if (is_room_available(i)) {
            room_number = i + 1;
            break;
        }
    }
    return room_number;
}

// Function to check if room is available
bool is_room_available(int room_number) {
    bool result = false;
    pthread_mutex_lock(&rooms[room_number].lock);
    if (rooms[room_number].is_available) {
        result = true;
    }
    pthread_mutex_unlock(&rooms[room_number].lock);
    return result;
}

// Function to book a room
void book_room(int guest_id, char *guest_name, int room_number) {
    pthread_mutex_lock(&rooms[room_number-1].lock);
    rooms[room_number-1].is_available = false;
    pthread_mutex_unlock(&rooms[room_number-1].lock);
    guests[guest_id].guest_id = guest_id;
    strcpy(guests[guest_id].guest_name, guest_name);
    guests[guest_id].room_number = room_number;
}

// Function to checkout from a room
void checkout_room(int room_number) {
    pthread_mutex_lock(&rooms[room_number-1].lock);
    rooms[room_number-1].is_available = true;
    pthread_mutex_unlock(&rooms[room_number-1].lock);
    for (int i = 0; i < num_of_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("\nThank you %s for staying with us!\n", guests[i].guest_name);
            guests[i].room_number = -1;
            break;
        }
    }
}