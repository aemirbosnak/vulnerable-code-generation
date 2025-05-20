//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROOMS 5
#define ESCAPE_TIME 60

typedef struct {
    char *description;
    int haunted; // 0 for not haunted, 1 for haunted
} Room;

void initializeRooms(Room rooms[]) {
    rooms[0].description = "You are in a dark hallway.";
    rooms[0].haunted = rand() % 2;

    rooms[1].description = "You enter a room filled with dusty furniture.";
    rooms[1].haunted = rand() % 2;

    rooms[2].description = "There's an eerie silence here, only interrupted by creaking floorboards.";
    rooms[2].haunted = rand() % 2;

    rooms[3].description = "This room has cobwebs hanging from the ceiling.";
    rooms[3].haunted = rand() % 2;

    rooms[4].description = "You've found the exit, but it might be a trick!";
    rooms[4].haunted = 1; // last room always haunted for the effect
}

void printRoom(Room room) {
    printf("%s\n", room.description);
    if (room.haunted) {
        printf("A ghostly figure looms in the shadows. Beware!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Room rooms[ROOMS];
    initializeRooms(rooms);

    int currentRoom = 0;
    int timeSpent = 0;
    char command[10];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have %d seconds to escape.\n", ESCAPE_TIME);

    while (timeSpent < ESCAPE_TIME) {
        printRoom(rooms[currentRoom]);
        printf("What do you want to do? (move/exit) ");
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            if (currentRoom < ROOMS - 1) {
                currentRoom++;
                timeSpent += 10; // moving to the next room takes 10 seconds
            } else {
                printf("You've already reached the last room!\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            if (currentRoom == ROOMS - 1) {
                printf("You have escaped the haunted house! Congratulations!\n");
                break;
            } else {
                printf("You can't exit yet! You need to reach the last room.\n");
            }
        } else {
            printf("Invalid command. Please choose 'move' or 'exit'.\n");
        }

        if (currentRoom < ROOMS - 1) {
            printf("Time spent: %d seconds.\n", timeSpent);
        } else {
            printf("You're at the exit after %d seconds! Can you escape?\n", timeSpent);
        }

        sleep(1); // adding some delay to the loop
    }

    if (timeSpent >= ESCAPE_TIME) {
        printf("Time's up! You were trapped in the haunted house. Better luck next time!\n");
    }

    return 0;
}