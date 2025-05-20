//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int hotel_capacity = 100;
int current_occupancy = 0;
char hotel_name[50];
int room_numbers[100];
int guests[100];

// Function to check if a room is available
int is_room_available(int room_number) {
    int i;
    for (i = 0; i < hotel_capacity; i++) {
        if (room_numbers[i] == room_number) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the hotel is full
int is_hotel_full() {
    int i;
    for (i = 0; i < hotel_capacity; i++) {
        if (guests[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to add a guest to a room
void add_guest(int room_number, int guest_id) {
    int i;
    for (i = 0; i < hotel_capacity; i++) {
        if (room_numbers[i] == room_number) {
            guests[i] = guest_id;
            return;
        }
    }
    printf("Room %d is not available.\n", room_number);
}

// Function to remove a guest from a room
void remove_guest(int room_number, int guest_id) {
    int i;
    for (i = 0; i < hotel_capacity; i++) {
        if (room_numbers[i] == room_number) {
            guests[i] = 0;
            return;
        }
    }
    printf("Guest %d is not in this room.\n", guest_id);
}

// Function to display hotel information
void display_hotel_info() {
    printf("Hotel Name: %s\n", hotel_name);
    printf("Room Numbers: ");
    for (int i = 0; i < hotel_capacity; i++) {
        printf("%d ", room_numbers[i]);
    }
    printf("\n");
    printf("Current Occupancy: %d/%d\n", current_occupancy, hotel_capacity);
    printf("Guests in Room 1: %d\n", guests[1]);
    printf("Guests in Room 2: %d\n", guests[2]);
    // Add more rooms here
}

// Function to handle user input
void handle_input() {
    int option, room_number, guest_id;
    char command[20];
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            printf("Enter room number: ");
            scanf("%d", &room_number);
            if (is_room_available(room_number)) {
                printf("Enter guest ID: ");
                scanf("%d", &guest_id);
                add_guest(room_number, guest_id);
            } else {
                printf("Room %d is not available.\n", room_number);
            }
            break;
        case 2:
            printf("Enter room number: ");
            scanf("%d", &room_number);
            if (is_room_available(room_number)) {
                printf("Enter guest ID: ");
                scanf("%d", &guest_id);
                remove_guest(room_number, guest_id);
            } else {
                printf("Room %d is not available.\n", room_number);
            }
            break;
        case 3:
            display_hotel_info();
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

// Main function
int main() {
    char input[50];
    printf("Enter hotel name: ");
    scanf("%s", hotel_name);
    printf("Enter hotel capacity: ");
    scanf("%d", &hotel_capacity);
    printf("Enter room numbers: ");
    for (int i = 0; i < hotel_capacity; i++) {
        scanf("%d", &room_numbers[i]);
    }
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        handle_input();
    }
    return 0;
}