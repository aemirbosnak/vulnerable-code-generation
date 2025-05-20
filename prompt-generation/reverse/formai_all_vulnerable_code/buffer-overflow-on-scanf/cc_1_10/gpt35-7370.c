//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define MIN_GHOST_CHARS 3
#define MAX_GHOST_CHARS 10

// Room struct
struct Room {
    char name[20];
    char description[50];
    char ghost[MAX_GHOST_CHARS];
};

// Randomly generates a ghost name
void generate_ghost_name(char *ghost) {
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";
    int len = rand() % (MAX_GHOST_CHARS - MIN_GHOST_CHARS + 1) + MIN_GHOST_CHARS;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            ghost[i] = consonants[rand() % 21];
        } else {
            ghost[i] = vowels[rand() % 5];
        }
    }
    ghost[len] = '\0';
}

// Generate random room based on room number
void generate_room(struct Room *room, int i) {
    char names[NUM_ROOMS][20] = {"Foyer", "Kitchen", "Dining Room", "Living Room", "Library", "Bedroom", "Bathroom", "Attic", "Basement", "Garage"};
    char descriptions[NUM_ROOMS][50] = {"The entryway to the house. It's dimly lit and the front door is locked.", "The kitchen is empty and cold.", "The dining room table is set for a fancy dinner, but no one is there to eat it.", "The living room has a dusty couch and a TV that doesn't work.", "The library is filled with old books, but something seems off about them.", "There's an unmade bed in the bedroom and a sense of unease.", "The bathroom is covered in cobwebs and the shower drips constantly.", "The attic is full of old toys and furniture, but it's too dark to see anything.", "The basement is damp and smells of mold.", "The garage is empty except for an old car covered in a tarp."};
    sprintf(room->name, "%s", names[i]);
    sprintf(room->description, "%s", descriptions[i]);
    generate_ghost_name(room->ghost);
}

// Prints room description and ghost name
void enter_room(struct Room *room) {
    printf("You enter the %s. %s There is a ghost named %s in the room.\n", room->name, room->description, room->ghost);
}

int main() {
    srand(time(NULL));                  // Seed random number generator
    struct Room rooms[NUM_ROOMS];        // Array of rooms
    int current_room = rand() % 10;      // Random starting room
    generate_room(&rooms[current_room], current_room);
    printf("Welcome to the Haunted House Simulator.\n");
    printf("You wake up in a dark room with no windows or doors. There's a piece of paper on the floor with a message written on it. It says 'Find your way out of this house and you might just survive.'\n");
    printf("You feel a chill run down your spine and realize you're not alone. You hear strange noises and realize that this house is haunted.\n");
    printf("You look around and see a door leading to the %s. You cautiously open it and enter the room.\n\n", rooms[current_room].name);
    enter_room(&rooms[current_room]);
    
    // Game loop
    int game_over = 0;
    while (!game_over) {
        int input;
        printf("What would you like to do?\n");
        printf("1. Move to another room.\n");
        printf("2. Stay in this room.\n");
        printf("3. Quit the game.\n");
        scanf("%d", &input);
        getchar(); // Consume newline character
        
        switch (input) {
            case 1: {
                int new_room = rand() % 10;                         // Choose new random room
                while (new_room == current_room) new_room = rand() % 10;  // Make sure it's not the same room
                current_room = new_room;                            // Update current room
                generate_room(&rooms[current_room], current_room);  // Generate new room description and ghost name
                printf("\nYou move to the %s.\n", rooms[current_room].name);
                enter_room(&rooms[current_room]);                   // Enter new room
                break;
            }
            case 2: {
                enter_room(&rooms[current_room]);                    // Stay in current room
                break;
            }
            case 3: {
                game_over = 1;                                       // Quit the game
                break;
            }
            default: {
                printf("Invalid input. Try again.\n\n");             // Invalid input
                break;
            }
        }
    }
    printf("Thanks for playing the Haunted House Simulator!\n");
    return 0;
}