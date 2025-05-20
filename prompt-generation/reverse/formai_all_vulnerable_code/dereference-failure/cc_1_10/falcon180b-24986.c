//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure for a room
typedef struct {
    char* name;
    int is_haunted;
    int has_ghost;
} Room;

// Function to initialize a room
void init_room(Room* room) {
    room->name = (char*)malloc(32*sizeof(char));
    room->is_haunted = rand() % 2;
    room->has_ghost = rand() % 2;
}

// Function to print a room
void print_room(Room* room) {
    printf("Room: %s\n", room->name);
    if(room->is_haunted) {
        printf("This room is haunted!\n");
    }
    if(room->has_ghost) {
        printf("There is a ghost in this room!\n");
    }
}

// Function to generate a random number of rooms
int generate_rooms(Room* rooms, int num_rooms) {
    int i;
    for(i = 0; i < num_rooms; i++) {
        init_room(&rooms[i]);
    }
    return 0;
}

// Function to simulate a haunted house
void haunted_house(Room* rooms, int num_rooms) {
    int i;
    srand(time(NULL));
    generate_rooms(rooms, num_rooms);
    printf("Welcome to the haunted house!\n");
    for(i = 0; i < num_rooms; i++) {
        print_room(&rooms[i]);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    haunted_house(rooms, MAX_ROOMS);
    return 0;
}