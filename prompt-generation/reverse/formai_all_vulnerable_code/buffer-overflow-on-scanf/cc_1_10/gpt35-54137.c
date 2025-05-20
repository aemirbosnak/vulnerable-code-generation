//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator
    srand(time(NULL));

    // display welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing outside a large, old house. It looks abandoned and quite spooky.\n");
    printf("Do you dare to enter?\n");

    // prompt user for input
    char response;
    printf("Enter 'y' to enter the house or 'n' to run away: ");
    scanf(" %c", &response);

    // if user chooses to enter the house
    if (response == 'y') {
        printf("You cautiously step inside the house. The door creaks heavily as you push it open.\n");

        // randomly generate a ghost encounter
        int ghost_chance = rand() % 101;
        if (ghost_chance <= 50) {
            printf("Suddenly, you feel a cold breeze and hear an eerie whisper in your ear. You turn around, but there's nothing there.\n");
        } else {
            printf("You hear a loud moan and turn to see a ghostly figure floating toward you. You try to run, but your feet feel heavy and you can't move.\n");
        }

        // prompt user for input
        char response2;
        printf("Do you try to fight the ghost or run away? Enter 'f' to fight or 'r' to run: ");
        scanf(" %c", &response2);

        // handle user response
        if (response2 == 'f') {
            printf("You try to punch the ghost, but your hand goes right through it. The ghost laughs and disappears.\n");
        } else {
            printf("You turn and run as fast as you can. You feel like something is chasing you, but you manage to make it outside and escape.\n");
        }
    } else {
        printf("You decide not to enter the house and run away as fast as you can.\n");
    }

    // display ending message
    printf("Thanks for playing the Haunted House Simulator!\n");

    return 0;
}