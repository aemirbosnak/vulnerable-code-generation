//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char *description;
    int num_exits;
    int *exits;
} Room;

Room rooms[MAX_ROOMS];

int current_room;

void print_room() {
    printf("%s\n", rooms[current_room].description);
    for (int i = 0; i < rooms[current_room].num_exits; i++) {
        printf("Exit %d: %s\n", i + 1, rooms[rooms[current_room].exits[i]].description);
    }
}

void move_room(int exit) {
    if (exit <= 0 || exit > rooms[current_room].num_exits) {
        printf("Invalid exit.\n");
        return;
    }
    current_room = rooms[current_room].exits[exit - 1];
    print_room();
}

int main() {
    // Create the rooms
    rooms[0].description = "You are in a dark and gloomy forest. The trees are tall and thick, blocking out most of the sunlight. The air is heavy with the smell of damp earth and rotting leaves.";
    rooms[0].num_exits = 2;
    rooms[0].exits = malloc(sizeof(int) * rooms[0].num_exits);
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = 2;

    rooms[1].description = "You are in a small clearing. The sun is shining brightly, and the birds are singing. In the center of the clearing is a bubbling stream.";
    rooms[1].num_exits = 3;
    rooms[1].exits = malloc(sizeof(int) * rooms[1].num_exits);
    rooms[1].exits[0] = 0;
    rooms[1].exits[1] = 2;
    rooms[1].exits[2] = 3;

    rooms[2].description = "You are in a dense forest. The trees are so thick that you can barely see in front of you. The ground is covered in a thick layer of leaves.";
    rooms[2].num_exits = 2;
    rooms[2].exits = malloc(sizeof(int) * rooms[2].num_exits);
    rooms[2].exits[0] = 0;
    rooms[2].exits[1] = 1;

    rooms[3].description = "You are in a dark and spooky cave. The walls are covered in strange carvings, and the air is heavy with the smell of decay.";
    rooms[3].num_exits = 1;
    rooms[3].exits = malloc(sizeof(int) * rooms[3].num_exits);
    rooms[3].exits[0] = 1;

    // Start the game
    current_room = 0;
    print_room();

    // Get user input
    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        if (strcmp(input, "quit\n") == 0) {
            break;
        } else if (strcmp(input, "n\n") == 0) {
            move_room(1);
        } else if (strcmp(input, "s\n") == 0) {
            move_room(2);
        } else if (strcmp(input, "e\n") == 0) {
            move_room(3);
        } else if (strcmp(input, "w\n") == 0) {
            move_room(4);
        } else {
            printf("Invalid input.\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i].description);
        free(rooms[i].exits);
    }

    return 0;
}