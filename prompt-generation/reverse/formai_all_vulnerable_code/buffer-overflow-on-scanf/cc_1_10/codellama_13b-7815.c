//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
// Hotel Management System in a Sherlock Holmes style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_NAME_LENGTH 20
#define MAX_ROOMS 100

// Define data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
} Guest;

typedef struct {
    int room_number;
    int guests;
    int beds;
} Room;

// Define functions
void welcome_message();
void menu();
void create_guest();
void check_in();
void check_out();
void view_guests();
void view_rooms();
void book_room();

// Global variables
Guest guests[MAX_ROOMS];
Room rooms[MAX_ROOMS];
int num_guests;
int num_rooms;

int main() {
    welcome_message();
    menu();
    return 0;
}

void welcome_message() {
    printf("Welcome to the Hotel Management System!\n");
    printf("I am your trusty sidekick, Watson.\n");
}

void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Create a new guest\n");
        printf("2. Check in a guest\n");
        printf("3. Check out a guest\n");
        printf("4. View guests\n");
        printf("5. View rooms\n");
        printf("6. Book a room\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_guest();
                break;
            case 2:
                check_in();
                break;
            case 3:
                check_out();
                break;
            case 4:
                view_guests();
                break;
            case 5:
                view_rooms();
                break;
            case 6:
                book_room();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 7);
}

void create_guest() {
    printf("Enter the guest's name: ");
    scanf("%s", &guests[num_guests].name);
    guests[num_guests].room_number = -1;
    num_guests++;
}

void check_in() {
    int guest_number;
    printf("Enter the guest number: ");
    scanf("%d", &guest_number);
    if (guest_number >= 0 && guest_number < num_guests) {
        if (rooms[guests[guest_number].room_number].guests < rooms[guests[guest_number].room_number].beds) {
            rooms[guests[guest_number].room_number].guests++;
            guests[guest_number].room_number = rooms[guests[guest_number].room_number].room_number;
            printf("Guest checked in successfully.\n");
        } else {
            printf("No available rooms.\n");
        }
    } else {
        printf("Invalid guest number.\n");
    }
}

void check_out() {
    int guest_number;
    printf("Enter the guest number: ");
    scanf("%d", &guest_number);
    if (guest_number >= 0 && guest_number < num_guests) {
        if (guests[guest_number].room_number != -1) {
            rooms[guests[guest_number].room_number].guests--;
            guests[guest_number].room_number = -1;
            printf("Guest checked out successfully.\n");
        } else {
            printf("Guest is not checked in.\n");
        }
    } else {
        printf("Invalid guest number.\n");
    }
}

void view_guests() {
    int i;
    printf("Guest List:\n");
    for (i = 0; i < num_guests; i++) {
        printf("%d. %s\n", i, guests[i].name);
    }
}

void view_rooms() {
    int i;
    printf("Room List:\n");
    for (i = 0; i < num_rooms; i++) {
        printf("%d. Room %d: %d guests, %d beds\n", i, rooms[i].room_number, rooms[i].guests, rooms[i].beds);
    }
}

void book_room() {
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    if (room_number >= 0 && room_number < num_rooms) {
        if (rooms[room_number].guests < rooms[room_number].beds) {
            rooms[room_number].guests++;
            printf("Room booked successfully.\n");
        } else {
            printf("No available rooms.\n");
        }
    } else {
        printf("Invalid room number.\n");
    }
}