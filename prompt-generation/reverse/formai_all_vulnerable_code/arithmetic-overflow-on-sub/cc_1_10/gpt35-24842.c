//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum size of name and address strings
#define MAX_NAME_SIZE 50
#define MAX_ADDR_SIZE 100

// define struct for room information
typedef struct {
    int number;
    char type[MAX_NAME_SIZE];
    float price;
} Room;

// define struct for guest information
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    char address[MAX_ADDR_SIZE];
    int room_number;
} Guest;

// function prototypes
void display_menu();
void display_rooms(Room *rooms, int num_rooms);
void search_rooms(Room *rooms, int num_rooms, char *type);
int find_room_index(Room *rooms, int num_rooms, int room_num);
void book_room(Room *rooms, int num_rooms, Guest *guests, int num_guests);
void view_guests(Guest *guests, int num_guests);
void check_out(Guest *guests, int num_guests);

int main() {
    // define initial variables
    int num_rooms = 5;
    int num_guests = 0;
    Room rooms[5] = {{101, "Single", 50.0},
                     {102, "Single", 50.0},
                     {201, "Double", 75.0},
                     {202, "Double", 75.0},
                     {203, "Double", 75.0}};
    Guest guests[10];
    int choice;

    // main program loop
    do {
        // display menu and get user input
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_rooms(rooms, num_rooms);
                break;
            case 2:
                printf("Enter room type: ");
                char type[MAX_NAME_SIZE];
                scanf("%s", type);
                search_rooms(rooms, num_rooms, type);
                break;
            case 3:
                book_room(rooms, num_rooms, guests, num_guests);
                num_guests++;
                break;
            case 4:
                view_guests(guests, num_guests);
                break;
            case 5:
                check_out(guests, num_guests);
                num_guests--;
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("\nWelcome to C Hotel Management System!\n");
    printf("-------------------------------------\n");
    printf("1. View available rooms\n");
    printf("2. Search for rooms by type\n");
    printf("3. Book a room\n");
    printf("4. View guests\n");
    printf("5. Check out a guest\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void display_rooms(Room *rooms, int num_rooms) {
    printf("\nAvailable Rooms:\n");
    printf("----------------\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("Room number: %d\n", rooms[i].number);
        printf("Room type: %s\n", rooms[i].type);
        printf("Price per night: %.2f\n", rooms[i].price);
        printf("----------------\n");
    }
}

void search_rooms(Room *rooms, int num_rooms, char *type) {
    printf("\nAvailable %s Rooms:\n", type);
    printf("---------------------\n");
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].type, type) == 0) {
            printf("Room number: %d\n", rooms[i].number);
            printf("Price per night: %.2f\n", rooms[i].price);
            printf("----------------\n");
        }
    }
}

int find_room_index(Room *rooms, int num_rooms, int room_num) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].number == room_num) {
            return i;
        }
    }
    return -1;  // room number not found
}

void book_room(Room *rooms, int num_rooms, Guest *guests, int num_guests) {
    printf("Enter guest name: ");
    char name[MAX_NAME_SIZE];
    scanf("%s", name);

    printf("Enter guest address: ");
    char address[MAX_ADDR_SIZE];
    scanf("%s", address);

    printf("Enter room number: ");
    int room_num;
    scanf("%d", &room_num);
    int room_index = find_room_index(rooms, num_rooms, room_num);
    if (room_index == -1) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    // update room status as booked
    rooms[room_index].price *= 1.2;  // increase price by 20%
    printf("Room %d booked successfully!\n", room_num);

    // create guest record
    Guest guest;
    guest.id = num_guests + 1;
    strcpy(guest.name, name);
    strcpy(guest.address, address);
    guest.room_number = room_num;
    guests[num_guests] = guest;
}

void view_guests(Guest *guests, int num_guests) {
    printf("\nGuest List:\n");
    printf("-----------\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Guest ID: %d\n", guests[i].id);
        printf("Guest name: %s\n", guests[i].name);
        printf("Guest address: %s\n", guests[i].address);
        printf("Room number: %d\n", guests[i].room_number);
        printf("----------------\n");
    }
}

void check_out(Guest *guests, int num_guests) {
    printf("Enter guest ID: ");
    int guest_id;
    scanf("%d", &guest_id);
    int guest_index = guest_id - 1;
    if (guest_index < 0 || guest_index >= num_guests) {
        printf("Invalid guest ID. Please try again.\n");
        return;
    }

    // update room status as available
    int room_num = guests[guest_index].room_number;
    printf("Room %d is now available.\n", room_num);

    // remove guest record
    for (int i = guest_index; i < num_guests - 1; i++) {
        guests[i] = guests[i+1];
    }
}