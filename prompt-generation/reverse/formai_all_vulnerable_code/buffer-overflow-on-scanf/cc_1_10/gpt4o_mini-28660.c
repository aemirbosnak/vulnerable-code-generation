//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

typedef struct {
    char *description;
    int hasGhost;
    int hasTreasure;
} Room;

void initializeRooms(Room rooms[]) {
    rooms[0].description = "You are in a dusty library filled with old books.";
    rooms[0].hasGhost = 1;
    rooms[0].hasTreasure = 0;

    rooms[1].description = "A dark hallway with flickering lights.";
    rooms[1].hasGhost = 0;
    rooms[1].hasTreasure = 1;

    rooms[2].description = "An eerie bedroom with an unmade bed.";
    rooms[2].hasGhost = 1;
    rooms[2].hasTreasure = 0;

    rooms[3].description = "A creepy basement that smells of mildew.";
    rooms[3].hasGhost = 0;
    rooms[3].hasTreasure = 1;

    rooms[4].description = "An ancient attic filled with cobwebs.";
    rooms[4].hasGhost = 1;
    rooms[4].hasTreasure = 1;
}

void printRoomDescription(Room room) {
    printf("%s\n", room.description);
    if (room.hasGhost) {
        printf("Oh no! There's a ghost here!\n");
    }
    if (room.hasTreasure) {
        printf("You see a glimmering treasure chest!\n");
    }
}

int main() {
    srand(time(NULL));
    Room rooms[MAX_ROOMS];
    initializeRooms(rooms);
    int currentRoomIndex = rand() % MAX_ROOMS;
    int gameOver = 0;
    int foundTreasure = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Successfully navigate through rooms, but watch out for ghosts!\n");

    while (!gameOver) {
        printRoomDescription(rooms[currentRoomIndex]);

        char action;
        printf("What would you like to do? (e: explore, t: take treasure, q: quit): ");
        scanf(" %c", &action);

        switch (action) {
            case 'e':
                currentRoomIndex = rand() % MAX_ROOMS;
                printf("You move to another room...\n");
                break;
            case 't':
                if (rooms[currentRoomIndex].hasTreasure) {
                    foundTreasure = 1;
                    printf("You found a treasure! You are rich! 🎉\n");
                    rooms[currentRoomIndex].hasTreasure = 0; // You can't take it twice!
                } else {
                    printf("There's no treasure here!\n");
                }
                break;
            case 'q':
                gameOver = 1;
                printf("Thanks for playing! Escape the haunted house safely!\n");
                break;
            default:
                printf("Invalid action! Choose 'e', 't', or 'q'.\n");
                break;
        }

        if (rooms[currentRoomIndex].hasGhost && foundTreasure) {
            printf("But the ghost caught you! You must escape! 👻\n");
            gameOver = 1;
        }
    }

    return 0;
}