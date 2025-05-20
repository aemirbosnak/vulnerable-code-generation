//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms and doors
#define NUM_ROOMS 5
#define NUM_DOORS 4

// Define the room structure
typedef struct {
    char name[50];
    int num_doors;
    int connected_rooms[NUM_DOORS];
} Room;

// Initialize the rooms
Room rooms[NUM_ROOMS] = {
    {"Foyer", 1, {0}},
    {"Library", 2, {0, 1}},
    {"Dining Room", 2, {1, 2}},
    {"Kitchen", 1, {2}},
    {"Ballroom", 3, {1, 3, 4}}
};

// Define the door structure
typedef struct {
    char name[50];
    int connected_rooms[2];
} Door;

// Initialize the doors
Door doors[NUM_DOORS] = {
    {"Main Entrance", {0, -1}},
    {"Door to Library", {0, 1}},
    {"Door to Dining Room", {1, 2}},
    {"Door to Kitchen", {2, -1}}
};

// Function to print the current room
void print_room(int room_num) {
    printf("You are in the %s.\n", rooms[room_num].name);
}

// Function to move to a connected room
int move_to_room(int room_num, int door_num) {
    int connected_room = rooms[room_num].connected_rooms[door_num];
    
    if (connected_room == -1) {
        printf("The %s is locked.\n", doors[door_num * 2].name);
        return -1;
    } else {
        print_room(connected_room);
        return connected_room;
    }
}

// Main function
int main() {
    srand(time(NULL));
    
    // Start in the foyer
    int current_room = 0;
    print_room(current_room);
    
    // Main loop
    while (1) {
        printf("What do you want to do? ");
        char action[50];
        scanf("%s", action);
        
        // Move to a connected room
        if (strcmp(action, "move") == 0) {
            int door_num;
            printf("Which door do you want to use? ");
            scanf("%d", &door_num);
            
            int new_room = move_to_room(current_room, door_num);
            
            if (new_room!= -1) {
                current_room = new_room;
            }
        } else if (strcmp(action, "quit") == 0) {
            break;
        } else {
            printf("I don't understand.\n");
        }
    }
    
    return 0;
}