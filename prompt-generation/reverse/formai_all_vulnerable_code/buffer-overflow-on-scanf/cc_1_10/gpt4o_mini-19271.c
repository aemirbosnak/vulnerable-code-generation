//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

typedef struct {
    char *name;
    char *description;
    int hasGhost;
    int visited;
} Room;

Room rooms[MAX_ROOMS];

void initRooms() {
    rooms[0].name = "The Dark Hallway";
    rooms[0].description = "A dimly lit hallway where shadows dance ominously.";
    rooms[0].hasGhost = rand() % 2;
    rooms[0].visited = 0;

    rooms[1].name = "The Laboratory";
    rooms[1].description = "A room filled with strange equipment and odd smells.";
    rooms[1].hasGhost = rand() % 2;
    rooms[1].visited = 0;

    rooms[2].name = "The Haunted Library";
    rooms[2].description = "Books whisper secrets of the past in this eerie space.";
    rooms[2].hasGhost = rand() % 2;
    rooms[2].visited = 0;

    rooms[3].name = "The Crypt";
    rooms[3].description = "A chilling space where the air is thick with silence.";
    rooms[3].hasGhost = rand() % 2;
    rooms[3].visited = 0;

    rooms[4].name = "The Attic";
    rooms[4].description = "An old dusty attic that holds forgotten memories.";
    rooms[4].hasGhost = rand() % 2;
    rooms[4].visited = 0;
}

void showRoom(Room room) {
    printf("You enter: %s\n", room.name);
    printf("%s\n", room.description);
    if (room.hasGhost) {
        printf("A ghost suddenly appears!\n");
    } else {
        printf("Nothing but silence greets you.\n");
    }
}

void playGame() {
    int choice;
    int gameRunning = 1;

    while (gameRunning) {
        printf("\nChoose a room to enter (0-%d) or -1 to exit:\n", MAX_ROOMS - 1);
        for (int i = 0; i < MAX_ROOMS; i++) {
            printf("%d: %s\n", i, rooms[i].name);
        }
        
        scanf("%d", &choice);
        
        if (choice == -1) {
            printf("Thanks for playing! Exiting...\n");
            gameRunning = 0;
        } else if (choice >= 0 && choice < MAX_ROOMS) {
            if (rooms[choice].visited == 0) {
                rooms[choice].visited = 1;
                showRoom(rooms[choice]);
            } else {
                printf("You've already visited this room. Choose another one!\n");
            }
        } else {
            printf("Invalid choice, please select again.\n");
        }
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    printf("Welcome to the Haunted House Simulator!\n");
    initRooms();
    playGame();
    return 0;
}