//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    int room_number;
    int floor;
    int price;
    char guest_name[MAX_NAME_LENGTH];
} Room;

Room rooms[MAX_ROOMS]; // array of all rooms in the hotel
int num_rooms = 0; // number of rooms currently in use

void main_menu();
void add_room();
void list_rooms();
void book_room();
void unbook_room();

int main() {
    main_menu();
    return 0;
}

void clear_screen() {
    system("clear||cls");
}

void pause() {
    printf("\nPress enter to continue...");
    getchar();
}

void main_menu() {
    clear_screen();
    printf("Welcome to the Hotel Management System!\n\n");
    printf("Please choose an option:\n");
    printf("1. Add a room\n");
    printf("2. List all rooms\n");
    printf("3. Book a room\n");
    printf("4. Unbook a room\n");
    printf("5. Exit\n");
    printf("\n");

    int choice;
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
            book_room();
            break;
        case 4:
            unbook_room();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
            pause();
            main_menu();
    }
}

void add_room() {
    clear_screen();
    printf("Adding a room...\n\n");

    if (num_rooms >= MAX_ROOMS) {
        printf("Cannot add more rooms - maximum capacity reached.\n");
        pause();
        main_menu();
    }

    int room_number, floor, price;
    char guest_name[MAX_NAME_LENGTH];
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    printf("Enter the floor number: ");
    scanf("%d", &floor);
    printf("Enter the price: ");
    scanf("%d", &price);

    // check if room number already exists
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            printf("A room with this number already exists! Please choose a different number.\n");
            pause();
            add_room();
            return;
        }
    }

    // add room to list
    rooms[num_rooms].room_number = room_number;
    rooms[num_rooms].floor = floor;
    rooms[num_rooms].price = price;
    strcpy(rooms[num_rooms].guest_name, "");
    num_rooms++;

    printf("Room added successfully!\n");
    pause();
    main_menu();
}

void list_rooms() {
    clear_screen();
    printf("Listing all rooms...\n\n");

    if (num_rooms == 0) {
        printf("No rooms to display!\n");
        pause();
        main_menu();
    }

    printf("Room #\tFloor\tPrice\tGuest Name\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%d\t%d\t%d\t%s\n", rooms[i].room_number, rooms[i].floor, rooms[i].price, rooms[i].guest_name);
    }

    pause();
    main_menu();
}

void book_room() {
    clear_screen();
    printf("Booking a room...\n\n");

    if (num_rooms == 0) {
        printf("No rooms to book! Please add a room first.\n");
        pause();
        main_menu();
    }

    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);

    // check if room exists and is unbooked
    int found_room = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            found_room = 1;
            if (strlen(rooms[i].guest_name) > 0) {
                printf("This room is already booked by %s! Please choose another room.\n", rooms[i].guest_name);
                pause();
                book_room();
                return;
            } else {
                printf("Enter guest name: ");
                scanf("%s", rooms[i].guest_name);
                printf("Room %d has been booked by %s!\n", room_number, rooms[i].guest_name);
                pause();
                main_menu();
                return;
            }
        }
    }

    if (!found_room) {
        printf("This room does not exist! Please enter a valid room number.\n");
        pause();
        book_room();
        return;
    }
}

void unbook_room() {
    clear_screen();
    printf("Unbooking a room...\n\n");

    if (num_rooms == 0) {
        printf("No rooms to unbook! Please add a room first.\n");
        pause();
        main_menu();
    }

    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);

    // check if room exists and is booked
    int found_room = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            found_room = 1;
            if (strlen(rooms[i].guest_name) == 0) {
                printf("This room is not booked by anyone!\n");
                pause();
                main_menu();
                return;
            } else {
                strcpy(rooms[i].guest_name, "");
                printf("Room %d has been unbooked!\n", room_number);
                pause();
                main_menu();
                return;
            }
        }
    }

    if (!found_room) {
        printf("This room does not exist! Please enter a valid room number.\n");
        pause();
        unbook_room();
        return;
    }
}