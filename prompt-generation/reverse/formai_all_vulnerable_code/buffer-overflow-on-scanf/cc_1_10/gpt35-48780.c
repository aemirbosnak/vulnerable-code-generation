//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ghosts = 0, doors = 0, rooms = 0;
    char player_name[50];

    printf("Welcome to the Haunted House Simulator\n");
    printf("-------------------------------------\n");

    printf("What is your name?\n");
    scanf("%s", player_name);

    printf("\n%s, you have arrived at an old and eerie mansion with no way back!\n", player_name);
    printf("You are standing in front of the mansion's door\n");
    printf("What will you do?\n");

    // Player chooses a door to enter
    printf("1. Enter the left door\n");
    printf("2. Enter the right door\n");
    scanf("%d", &doors);

    if (doors == 1) {
        printf("\nYou enter a room with a broken window and dusty furniture.\n");
        printf("Suddenly, you hear footsteps and see a ghostly figure in the corner of the room.\n");
        printf("What will you do?\n");

        // Player chooses a action to take
        printf("1. Run away!\n");
        printf("2. Confront the ghost!\n");
        scanf("%d", &ghosts);

        if (ghosts == 1) {
            printf("\nYou run away from the ghost and find yourself in another room.\n");
        } else {
            printf("\nThe ghost speaks to you in a language you cannot comprehend.\n");
            printf("You pass out and wake up in another room.\n");
        }

    } else {
        printf("\nYou enter a room with a creaky floor and dim lighting.\n");
        printf("The door shuts behind you and you are trapped!\n");
        printf("What will you do?\n");

        // Player chooses a action to take
        printf("1. Look for another way out!\n");
        printf("2. Yell for help!\n");
        scanf("%d", &rooms);

        if (rooms == 1) {
            printf("\nYou find a secret passage and escape the room safely.\n");
        } else {
            printf("\nYour screams attract the attention of a pack of hungry wolves.\n");
            printf("You have been eaten alive.\n");
            printf("GAME OVER\n");
            return 0;
        }
    }

    printf("\nYou walk into a new room and hear eerie whispers coming from a jar on the shelf.\n");
    printf("What will you do?\n");

    // Player chooses a action to take
    printf("1. Open the jar!\n");
    printf("2. Walk away!\n");
    scanf("%d", &ghosts);

    if (ghosts == 1) {
        printf("\nYou open the jar and a group of bats fly out.\n");
        printf("You have been bitten and turned into a vampire.\n");
        printf("You cannot leave the mansion and will haunt it forever.\n");
    } else {
        printf("\nYou walk away and find a key to escape the mansion.\n");
        printf("Congratulations! You have escaped the Haunted House!\n");
    }

    return 0;
}