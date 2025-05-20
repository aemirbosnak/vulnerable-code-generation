//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOUSE_SIZE 10

typedef struct {
    int health;
    int location[2];
    int inventory[3];
} Player;

int hauntedHouse[HOUSE_SIZE][HOUSE_SIZE];

void initializeHouse() {
    // code to initialize the haunted house layout
}

void printHouse(Player player) {
    // code to print the current layout of the haunted house
}

void movePlayer(Player *player, int direction) {
    // code to handle player movement based on direction input
}

void checkForEncounter(Player player) {
    // code to randomly trigger ghost encounters and combat
}

int main() {
    srand(time(0)); // seed the random number generator
    Player player = {100, {0, 0}, {0, 0, 0}}; // initialize player attributes
    
    initializeHouse();
    while(player.health > 0 && !(player.location[0] == HOUSE_SIZE - 1 && player.location[1] == HOUSE_SIZE - 1)) {
        printHouse(player);
        int direction;
        printf("Enter a direction to move (1 = up, 2 = down, 3 = left, 4 = right): ");
        scanf("%d", &direction);
        movePlayer(&player, direction);
        checkForEncounter(player);
    }
    
    if(player.health <= 0) {
        printf("Game over! You have been defeated by the ghosts.\n");
    } else {
        printf("Congratulations! You have escaped the haunted house!\n");
    }
    
    return 0;
}