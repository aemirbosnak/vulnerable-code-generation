//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int health;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Bartholomew", 1, 100},
    {"Miss Emily", 2, 80},
    {"The Disembodied", 3, 60},
    {"The Phantom", 4, 40},
    {"The Blood Countess", 5, 20}
};

void simulate_haunted_house() {
    int i, j, rand_room, ghost_num;
    srand(time(NULL));

    // Randomly choose a room.
    rand_room = rand() % MAX_GHOSTS;

    // Choose a ghost to interact with.
    ghost_num = rand() % MAX_GHOSTS;

    // Ghost interacts with the player.
    printf("You hear a noise in the hallway... ");

    if (ghosts[ghost_num].room == rand_room) {
        printf("The ghost of %s appears! ", ghosts[ghost_num].name);

        // Fight the ghost or flee.
        printf("What do you want to do? (fight/flee): ");

        char input;
        scanf("%c", &input);

        if (input == 'f') {
            printf("You flee the house. \n");
        } else if (input == 'f') {
            printf("You fight the ghost. \n");

            // Simulate battle and determine the outcome.
            if (ghosts[ghost_num].health > 0) {
                printf("You defeat the ghost of %s. \n", ghosts[ghost_num].name);
            } else {
                printf("The ghost of %s has defeated you. \n", ghosts[ghost_num].name);
            }
        } else {
            printf("Invalid input. \n");
        }
    } else {
        printf("There is no ghost in that room. \n");
    }
}

int main() {
    simulate_haunted_house();

    return 0;
}