//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define ROOM_TYPE_COUNT 3
#define NAME_MAX 100

typedef struct {
    int room_number;
    char room_type[20];
    float price;
    int is_occupied;
    char guest_name[NAME_MAX];
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void initialize_rooms() {
    strcpy(rooms[0].room_type, "Single");
    rooms[0].room_number = 101;
    rooms[0].price = 50.0;
    rooms[0].is_occupied = 0;

    strcpy(rooms[1].room_type, "Double");
    rooms[1].room_number = 102;
    rooms[1].price = 80.0;
    rooms[1].is_occupied = 0;

    strcpy(rooms[2].room_type, "Suite");
    rooms[2].room_number = 103;
    rooms[2].price = 150.0;
    rooms[2].is_occupied = 0;

    room_count = 3;  // We have initialized 3 rooms
}

void display_rooms() {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < room_count; i++) {
        if (!rooms[i].is_occupied) {
            printf("Room Number: %d, Type: %s, Price: $%.2f\n",
                   rooms[i].room_number, rooms[i].room_type, rooms[i].price);
        }
    }
}

void book_room() {
    int room_number;
    char guest_name[NAME_MAX];

    printf("\nEnter room number to book: ");
    scanf("%d", &room_number);
    getchar();  // Consume newline
    printf("Enter guest name: ");
    fgets(guest_name, NAME_MAX, stdin);
    guest_name[strcspn(guest_name, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < room_count; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].is_occupied) {
                printf("Sorry, room %d is already occupied.\n", room_number);
            } else {
                rooms[i].is_occupied = 1;
                strcpy(rooms[i].guest_name, guest_name);
                printf("Room %d booked successfully for %s.\n", room_number, guest_name);
            }
            return;
        }
    }
    printf("Room number %d does not exist.\n", room_number);
}

void checkout_room() {
    int room_number;

    printf("\nEnter room number to checkout: ");
    scanf("%d", &room_number);

    for (int i = 0; i < room_count; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].is_occupied) {
                rooms[i].is_occupied = 0;
                printf("Room %d checked out successfully.\n", room_number);
            } else {
                printf("Room %d is already empty.\n", room_number);
            }
            return;
        }
    }
    printf("Room number %d does not exist.\n", room_number);
}

void display_menu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. View Available Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Checkout a Room\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

int main() {
    initialize_rooms();
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_rooms();
                break;
            case 2:
                book_room();
                break;
            case 3:
                checkout_room();
                break;
            case 4:
                printf("Exiting the hotel management system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}