//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define NUM_ROOMS 5

typedef struct {
    char* description;
    char* items[3];
    int itemCount;
} Room;

Room rooms[NUM_ROOMS];
int currentRoom = 0;
int hasKey = 0;

void initializeRooms() {
    rooms[0].description = "You are in a dimly lit hallway. Shadows dance along the walls.";
    rooms[0].items[0] = "a flickering lightbulb";
    rooms[0].items[1] = "scraps of paper";
    rooms[0].itemCount = 2;

    rooms[1].description = "You've entered a small room filled with old books. The air is musty.";
    rooms[1].items[0] = "a key";
    rooms[1].itemCount = 1;

    rooms[2].description = "This room has a single window, but the glass is cracked. It feels eerie.";
    rooms[2].items[0] = "a mysterious note";
    rooms[2].itemCount = 1;

    rooms[3].description = "You find yourself in a large empty space. The silence is deafening.";
    rooms[3].itemCount = 0;

    rooms[4].description = "A room with a locked door. You can feel eyes watching you.";
    rooms[4].itemCount = 0;
}

void describeCurrentRoom() {
    printf("\n%s\n", rooms[currentRoom].description);
    if (rooms[currentRoom].itemCount > 0) {
        printf("You see: ");
        for (int i = 0; i < rooms[currentRoom].itemCount; i++) {
            printf("%s", rooms[currentRoom].items[i]);
            if (i != rooms[currentRoom].itemCount - 1) printf(", ");
        }
        printf(".\n");
    }
}

void getInput(char* input) {
    printf("What do you want to do? ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline
}

void paranoidDecision() {
    char reaction;
    printf("You feel a chill. Do you investigate? (y/n): ");
    scanf(" %c", &reaction);
    getchar(); // Consume newline character
    if (reaction == 'y') {
        printf("You peered into the shadows...\n");
        if (rand() % 2 == 0) {
            printf("Nothing is there. Just your imagination.\n");
        } else {
            printf("You found something valuable amidst the shadows!\n");
        }
    } else {
        printf("You decide not to risk it. Better safe than sorry.\n");
    }
}

void navigateRooms(const char* command) {
    if (strcmp(command, "explore") == 0) {
        describeCurrentRoom();
        if (currentRoom == 1) {
            printf("You pick up the key!\n");
            hasKey = 1;
        }
    } else if (strcmp(command, "go") == 0) {
        if (currentRoom < NUM_ROOMS - 1) {
            currentRoom++;
            printf("You cautiously move to the next room.\n");
            paranoidDecision();
        } else {
            printf("You have reached the end of the building. Go back!\n");
        }
    } else if (strcmp(command, "check") == 0) {
        if (currentRoom == 4 && hasKey) {
            printf("You unlocked the door using the key!\n");
            currentRoom++;
        } else {
            printf("The door is locked. You need a key!\n");
        }
    } else {
        printf("I didn't understand that. Be careful what you say...\n");
    }
}

int main() {
    srand(time(0));
    char input[MAX_INPUT];

    initializeRooms();
    printf("Welcome to 'The Paranoia' Adventure Game.\n");

    while (currentRoom < NUM_ROOMS) {
        getInput(input);
        navigateRooms(input);
    }

    printf("You've escaped the building, or have you? The shadows might follow you...\n");
    return 0;
}