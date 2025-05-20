//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing the player
    char name[50];
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("Welcome, %s! You are about to embark on a grand adventure!\n", name);
    printf("You find yourself standing at the edge of a dense forest, ready to explore.\n");
    printf("What do you do?\n");
    printf("1. Enter the forest\n");
    printf("2. Turn back\n");

    char choice;
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            printf("You take a deep breath and enter the forest. The trees are tall and dark, casting long shadows on the forest floor. As you walk deeper into the forest, you begin to hear strange noises in the distance. What do you do?\n");
            printf("1. Move towards the noise\n");
            printf("2. Stay where you are\n");
            break;
        case '2':
            printf("You decide to turn back. As you make your way out of the forest, you hear a rustling in the bushes. Suddenly, a creature jumps out at you! It's a goblin!\n");
            printf("What do you do?\n");
            printf("1. Fight the goblin\n");
            printf("2. Run away\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }

    switch (choice) {
        case '1':
            printf("You unsheathe your sword and prepare to fight the goblin. The goblin lunges at you with a dagger, but you manage to dodge and land a powerful blow. The goblin falls to the ground, defeated.\n");
            printf("You have won!\n");
            break;
        case '2':
            printf("You turn and run as fast as you can. You hear the goblin's laughter as it chases after you. Just as you think you've lost it, you see a clearing in the forest. You run towards it and hide behind a tree.\n");
            printf("The goblin catches up to you and tries to stab you with its dagger, but you manage to dodge and land a powerful blow. The goblin falls to the ground, defeated.\n");
            printf("You have won!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }

    return 0;
}