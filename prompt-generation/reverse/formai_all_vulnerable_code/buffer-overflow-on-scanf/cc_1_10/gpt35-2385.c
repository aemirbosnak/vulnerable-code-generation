//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Room struct to handle room properties
typedef struct {
    int number;
    bool lights; // true for on, false for off
    bool has_ghost; // true if contains a ghost, false otherwise
    bool locked; // true if door is locked, false otherwise
} Room;

// Function to randomly generate a ghost in a room
void generate_ghost(Room* room) {
    int random_number = rand() % 2; // 50% chance of having a ghost
    if (random_number == 1) {
        room->has_ghost = true;
    }
}

// Function to print room information
void print_room(Room room) {
    char* lights_status = (room.lights) ? "on" : "off";
    char* ghost_status = (room.has_ghost) ? "Yes" : "No";
    char* door_status = (room.locked) ? "locked" : "unlocked";
    printf("Room %d:\n", room.number);
    printf("Lights are %s\n", lights_status);
    printf("Has Ghost? %s\n", ghost_status);
    printf("Door is %s\n\n", door_status);
}

// Function to simulate moving from room to room
void move_to_room(Room* current_room, Room all_rooms[], int num_rooms) {
    int room_number;
    bool valid_input = false;
    while (!valid_input) {
        printf("Enter room number to move to: ");
        scanf("%d", &room_number);
        if (room_number == current_room->number) {
            printf("You are already in that room.\n");
        } else if (room_number < 1 || room_number > num_rooms) {
            printf("Invalid room number.\n");
        } else if (all_rooms[room_number - 1].locked) {
            printf("Door to that room is locked. Find the key!\n");
        } else {
            valid_input = true;
            current_room = &all_rooms[room_number - 1];
            printf("You have entered room %d.\n", current_room->number);
            generate_ghost(current_room);
            print_room(*current_room);
        }
    }
}

// Function to simulate finding the key
void find_key(Room* current_room) {
    current_room->locked = false;
    printf("You have found the key! Door to this room is now unlocked.\n");
}

//Main function
int main() {
    srand(time(NULL)); //Seed random number generator

    int num_rooms = 5;
    Room all_rooms[num_rooms];

    // Initialize all rooms
    for (int i = 0; i < num_rooms; i++) {
        Room room;
        room.number = i + 1;
        room.lights = false;
        room.has_ghost = false;
        room.locked = true;
        all_rooms[i] = room;
    }

    // Turn on lights in first room
    all_rooms[0].lights = true;

    // Generate ghosts randomly in each room
    for (int i = 0; i < num_rooms; i++) {
        generate_ghost(&all_rooms[i]);
    }

    // Print information on first room
    printf("Welcome to the haunted house. You are now in the first room.\n");
    print_room(all_rooms[0]);

    // Begin simulation of moving around the house
    Room* current_room = &all_rooms[0];
    while (true) {
        int choice;
        printf("Enter 1 to move to another room.\n");
        printf("Enter 2 to find the key.\n");
        printf("Enter 3 to quit.\n");
        scanf("%d", &choice);

        if (choice == 1) {
            move_to_room(current_room, all_rooms, num_rooms);
        } else if (choice == 2) {
            find_key(current_room);
        } else if (choice == 3) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}