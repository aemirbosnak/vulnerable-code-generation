//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int choice;
    char name[50];

    printf("Welcome to our Haunted House Simulator! Are you ready to enter?\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nGood luck, %s! You're now entering the Haunted House...\n\n", name);

    srand(time(NULL));

    while (1) {
        printf("\nYou enter a room, and you have two choices. What do you do?\n");
        printf("1. Open the door to your left.\n");
        printf("2. Open the door to your right.\n");

        scanf("%d", &choice);

        if (choice == 1) {
            int ghost_chance = rand() % 2;
            if (ghost_chance == 0) {
                printf("\nYou open the door and enter the room. You look around, but see nothing out of the ordinary.\n");
                printf("You take a step forward, and suddenly a ghost appears in front of you!\n");
                printf("You scream and run out of the room as fast as you can.\n");
                break;
            } else {
                printf("\nYou open the door and enter the room. It's quiet and empty.\n");
                printf("You look around and find nothing of interest. You continue on your journey.\n");
            }
        } else if (choice == 2) {
            int trap_chance = rand() % 2;
            if (trap_chance == 0) {
                printf("\nYou open the door and enter the room. You look around and see nothing.");
                printf("Suddenly, the floor beneath you gives way and you fall into a trap!");
                printf("You try to climb out, but it's too deep and you're stuck. You'll have to wait for help.\n");
                break;
            } else {
                printf("\nYou open the door and enter the room. You look around and find a key!");
                printf("You pick it up and continue on your journey.\n");
            }
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\nCongratulations! You made it out alive, %s!\n", name);

    return 0;
}