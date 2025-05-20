//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    // Introduction
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You have entered a haunted house and you need to find a way out. Beware of the ghosts!\n\n");

    // Initializing variables
    int choice, i, ghost_pos;
    char name[20];
    int rooms[4] = {0, 0, 0, 0}; // 0 represents room is empty, 1 represents room has ghost

    // Getting user name
    printf("What is your name?\n");
    scanf("%s", name);

    // Adding ghosts to 3 random rooms
    srand(time(0));
    for(i=1; i<=3; i++) {
        ghost_pos = rand() % 4;
        rooms[ghost_pos] = 1;
    }

    // Starting the game
    printf("\n%s, you are now in the first room.\n", name);
    printf("There are 4 rooms in front of you, which one would you like to enter? (1-4)\n");
    scanf("%d", &choice);

    while(1) {

        // Checking if room has ghost
        if(rooms[choice-1] == 1) {
            printf("\nOh no! You have encountered a ghost.\n");
            printf("Unfortunately, there is no escape. You have been haunted forever.\n");
            break;
        }

        // Checking if user has reached exit room
        if(choice == 4) {
            printf("\nCongratulations %s, you have escaped the haunted house!\n", name);
            break;
        }

        // Moving to the next room
        printf("\nYou have entered room number %d.\n", choice+1);
        printf("There are 4 rooms in front of you, which one would you like to enter? (1-4)\n");
        scanf("%d", &choice);

    }

    return 0;
}