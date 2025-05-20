//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DESC_LEN 256

typedef struct {
    char* desc;
    int num_exits;
    int exits[MAX_ROOMS];
} Room;

Room rooms[MAX_ROOMS];
int current_room;

void init_game() {
    // Create the rooms.
    rooms[0].desc = "You are in a dark and dingy room. The only light comes from a small window high up on the wall. There is a door to the north.";
    rooms[0].num_exits = 1;
    rooms[0].exits[0] = 1;

    rooms[1].desc = "You are in a small, square room. There is a door to the south.";
    rooms[1].num_exits = 1;
    rooms[1].exits[0] = 0;

    // Set the current room.
    current_room = 0;
}

void print_room() {
    // Print the description of the current room.
    printf("%s\n", rooms[current_room].desc);

    // Print the exits from the current room.
    if (rooms[current_room].num_exits > 0) {
        printf("Exits:");
        for (int i = 0; i < rooms[current_room].num_exits; i++) {
            printf(" %d", rooms[current_room].exits[i]);
        }
        printf("\n");
    }
}

void move_room(int direction) {
    // Check if the direction is valid.
    if (direction < 0 || direction >= rooms[current_room].num_exits) {
        printf("Invalid direction.\n");
        return;
    }

    // Move to the new room.
    current_room = rooms[current_room].exits[direction];

    // Print the description of the new room.
    print_room();
}

int main() {
    // Initialize the game.
    init_game();

    // Play the game.
    while (1) {
        // Print the current room.
        print_room();

        // Get the player's input.
        int direction;
        printf("Which direction do you want to go? ");
        scanf("%d", &direction);

        // Move to the new room.
        move_room(direction);
    }

    return 0;
}