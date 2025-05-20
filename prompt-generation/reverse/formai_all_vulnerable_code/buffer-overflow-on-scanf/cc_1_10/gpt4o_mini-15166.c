//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_MONSTERS 3

typedef struct {
    char *name;
    char *description;
    int dangerLevel;
} Room;

typedef struct {
    char *type;
    int scareFactor;
} Monster;

void displayRoom(Room room) {
    printf("You entered: %s\n", room.name);
    printf("%s\n", room.description);
    printf("Danger Level: %d\n", room.dangerLevel);
}

void displayMonster(Monster monster) {
    printf("A wild %s appears! Scare Factor: %d\n", monster.type, monster.scareFactor);
}

int randomEvent() {
    return rand() % 2; // 0 for safe, 1 for monster
}

Room rooms[MAX_ROOMS] = {
    {"Haunted Entrance", "You stand at the entrance of a dark, spooky house.", 1},
    {"Living Room", "The furniture is covered in dust, and an eerie silence surrounds you.", 2},
    {"Kitchen", "You smell something rotten, as if a ghost had made its last meal.", 3},
    {"Dungeon", "You hear chains rattling and a cold chill runs down your spine.", 4},
    {"Attic", "The rafters creak under an unseen weight, and old spirits seem to linger.", 3}
};

Monster monsters[MAX_MONSTERS] = {
    {"Ghost", 5},
    {"Zombie", 7},
    {"Vampire", 8}
};

int main() {
    srand(time(0)); // seeding random number generator
    int currentRoom = 0;
    char choice[10];
    int gameOver = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Survive and explore the haunted rooms.\n");

    while (!gameOver) {
        displayRoom(rooms[currentRoom]);

        if (randomEvent()) {
            int monsterIndex = rand() % MAX_MONSTERS;
            displayMonster(monsters[monsterIndex]);
            printf("What will you do? (run/fight): ");
            scanf("%s", choice);

            if (strcmp(choice, "run") == 0) {
                printf("You ran away safely!\n");
                currentRoom = (currentRoom + 1) % MAX_ROOMS; // move to next room
            } else if (strcmp(choice, "fight") == 0) {
                printf("You bravely faced the monster!\n");
                int chance = rand() % 10; // 0 to 9
                if (chance < monsters[monsterIndex].scareFactor) {
                    printf("You were defeated by the %s!\n", monsters[monsterIndex].type);
                    gameOver = 1; // end game
                } else {
                    printf("You defeated the %s!\n", monsters[monsterIndex].type);
                    currentRoom = (currentRoom + 1) % MAX_ROOMS; // move to next room
                }
            } else {
                printf("Invalid choice! Please try again.\n");
            }
        } else {
            printf("The room is safe. You can explore more.\n");
            currentRoom = (currentRoom + 1) % MAX_ROOMS; // move to next room
        }

        printf("Do you want to continue exploring? (yes/no): ");
        scanf("%s", choice);
        if (strcmp(choice, "no") == 0) {
            printf("You decided to leave the scary haunted house.\n");
            gameOver = 1; // end game
        }
    }

    printf("Game Over. Thank you for playing the Haunted House Simulator!\n");
    return 0;
}