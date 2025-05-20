//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LIFE_POINTS 10
#define NUM_ROOMS 5

typedef struct {
    char name[30];
    char description[100];
    int dangerLevel;
} Room;

Room rooms[NUM_ROOMS] = {
    {"The Entrance", "You stand at the entrance of the haunted house. A chilling wind makes you shiver.", 1},
    {"The Living Room", "The furniture is covered in dust. You hear whispers in the corner!", 2},
    {"The Kitchen", "There's a strange smell coming from the fridge. Are those eyes looking at you?", 3},
    {"The Basement", "It's dark and damp. You feel something brush against your leg.", 4},
    {"The Attic", "You see shadows moving. A ghost appears and points at you!", 5}
};

void displayRoom(Room room) {
    printf("\nYou have entered: %s\n", room.name);
    printf("%s\n", room.description);
}

int encounter(Room room) {
    printf("Danger Level: %d\n", room.dangerLevel);
    printf("You must face the danger!\n");

    int event = rand() % 3; // Random event
    switch (event) {
        case 0:
            printf("You found a hidden passage! You escape unscathed.\n");
            return 0; // No life lost
        case 1:
            printf("A ghost scared you! You lose 1 life point.\n");
            return 1; // Lose life
        case 2:
            printf("A creepy creature bites you! You lose 2 life points.\n");
            return 2; // Lose life
    }
    return 0; // Default to no loss
}

int main() {
    int lifePoints = MAX_LIFE_POINTS;
    int currentRoom = 0;
    char command[10];

    srand(time(NULL)); // Seed for randomness

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have %d life points.\n", lifePoints);

    while (lifePoints > 0 && currentRoom < NUM_ROOMS) {
        displayRoom(rooms[currentRoom]);
        
        lifePoints -= encounter(rooms[currentRoom]);
        if (lifePoints > MAX_LIFE_POINTS) {
            lifePoints = MAX_LIFE_POINTS; // Cap life points
        }

        printf("You have %d life points remaining.\n", lifePoints);

        if (currentRoom == NUM_ROOMS - 1) {
            printf("You are at the final room! Would you like to continue? (yes/no): ");
            scanf("%s", command);
            if (strcmp(command, "no") == 0) {
                break; // Exit the game
            }
        }

        currentRoom++;
    }

    if (lifePoints <= 0) {
        printf("You have lost all your life points! Game Over!\n");
    } else {
        printf("You have successfully navigated the haunted house! Congratulations!\n");
    }

    return 0;
}