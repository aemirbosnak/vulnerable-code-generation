//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a room
typedef struct room {
    char name[20];
    int x, y;
    struct room* north, *south, *east, *west;
} room;

// Function to generate a random room
room* generate_room() {
    room* new_room = malloc(sizeof(room));
    new_room->x = rand() % 10;
    new_room->y = rand() % 10;
    new_room->name[0] = 'A' + rand() % 26;
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    return new_room;
}

// Function to connect rooms
void connect_rooms(room* a, room* b) {
    a->east = b;
    b->west = a;
}

// Function to print a room
void print_room(room* r) {
    printf("You are in the %s room. (x: %d, y: %d)\n", r->name, r->x, r->y);
    if (r->north) {
        printf("You can go north to the %s room.\n", r->north->name);
    }
    if (r->south) {
        printf("You can go south to the %s room.\n", r->south->name);
    }
    if (r->east) {
        printf("You can go east to the %s room.\n", r->east->name);
    }
    if (r->west) {
        printf("You can go west to the %s room.\n", r->west->name);
    }
}

// Main game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the first room
    room* start = generate_room();

    // Connect rooms
    connect_rooms(start, generate_room());
    connect_rooms(start, generate_room());
    connect_rooms(start, generate_room());

    // Print the starting room
    print_room(start);

    // Get the player's input
    char direction;

    // Move the player around the room
    while (direction != 'q') {
        printf("Enter direction (n, s, e, w, q): ");
        scanf("%c", &direction);

        switch (direction) {
            case 'n':
                print_room(start->north);
                break;
            case 's':
                print_room(start->south);
                break;
            case 'e':
                print_room(start->east);
                break;
            case 'w':
                print_room(start->west);
                break;
            case 'q':
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }
    }

    return 0;
}