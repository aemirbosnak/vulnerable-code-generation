//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 5
#define MAX_ITEMS 3
#define MAX_NAME 30

typedef struct {
    char name[MAX_NAME];
    int canTransform;
} Character;

typedef struct {
    char description[200];
    char items[MAX_ITEMS][MAX_NAME];
    int numItems;
} Room;

void printRoomDescription(Room *room) {
    printf("\n%s\n", room->description);
    if (room->numItems > 0) {
        printf("You see the following items:\n");
        for (int i = 0; i < room->numItems; i++) {
            printf("- %s\n", room->items[i]);
        }
    }
}

void transformCharacter(Character *character) {
    if (character->canTransform) {
        printf("You shape-shift into a different form!\n");
        // Optionally, you can add different forms with different abilities
        strcpy(character->name, "Mystical Creature");
        character->canTransform = 0; // Can only transform once
    } else {
        printf("You cannot transform again!\n");
    }
}

void exploreRoom(Character *character, Room *room) {
    char action[20];
    printf("\nWhat would you like to do? (explore/transform/quit): ");
    scanf("%s", action);

    while (strcmp(action, "quit") != 0) {
        if (strcmp(action, "explore") == 0) {
            printRoomDescription(room);
        } else if (strcmp(action, "transform") == 0) {
            transformCharacter(character);
        } else {
            printf("Invalid action. Try again.\n");
        }
        printf("\nWhat would you like to do? (explore/transform/quit): ");
        scanf("%s", action);
    }
}

int main() {
    Character player = {"Adventurer", 1}; // Player starts as an Adventurer
    Room rooms[MAX_ROOM] = {
        {"You are in a dimly lit cave. There are strange markings on the wall.", {"Torch", "Map"}, 2},
        {"You find yourself in a mystical forest filled with glowing plants.", {"Glowing Flower", "Staff"}, 2},
        {"You are in a dark dungeon where echoes of your own footsteps frighten you.", {"Key", "", "", ""}, 1},
        {"You entered an ancient temple, the air is thick with history.", {"Artifact", "", "", ""}, 1},
        {"You made it to the summit of a mountain, where the sky meets the earth.", {"Crystal", "", "", ""}, 1}
    };

    printf("Welcome to the Shape-Shifting Adventure Game!\n");
    printf("You start your journey as an Adventurer. Can you discover all the secrets?\n");

    for (int i = 0; i < MAX_ROOM; i++) {
        printf("\nEntering room %d...\n", i + 1);
        exploreRoom(&player, &rooms[i]);
    }

    printf("Thank you for playing, %s! Your adventure ends here.\n", player.name);
    return 0;
}