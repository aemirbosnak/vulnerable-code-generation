//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Generate random room number
    int roomNum = rand() % 10 + 1;

    // Initialize variables
    int foundKey = 0;
    int foundExit = 0;
    int ghostAppeared = 0;
    int health = 100;

    printf("Welcome to the Haunted House Simulator\n");
    printf("You find yourself in Room %d\n", roomNum);
    printf("Your health is at %d%%\n", health);

    // Loop until player finds the key and the exit or until health reaches 0
    while (!foundKey || !foundExit) {
        if (health <= 0) {
            printf("You died. Game over.\n");
            return 0;
        }

        // Generate random event
        int event = rand() % 3;

        switch (event) {
            case 0:
                printf("You hear strange noises nearby...\n");
                break;
            case 1:
                printf("The room suddenly becomes freezing cold...\n");
                break;
            case 2:
                if (!ghostAppeared) {
                    printf("A ghost suddenly appears in front of you! You lose 20 health...\n");
                    health -= 20;
                    ghostAppeared = 1;
                    break;
                }
                else {
                    printf("You see shadows out of the corner of your eye, but no ghost appears...\n");
                    break;
                }
        }

        // Ask player for action
        printf("\nWhat do you want to do?\n");
        printf("1. Look for the key\n");
        printf("2. Look for the exit\n");
        printf("3. Stay in the room\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rand() % 2 == 0) {
                    printf("You found the key!\n");
                    foundKey = 1;
                }
                else {
                    printf("You didn't find the key...\n");
                }
                break;
            case 2:
                if (foundKey) {
                    printf("Congratulations! You've escaped the haunted house!\n");
                    foundExit = 1;
                    return 0;
                }
                else {
                    printf("You need to find the key first...\n");
                }
                break;
            case 3:
                printf("You stay in the room for a while...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Decrease health by 10 for staying in the room too long
        health -= 10;
        printf("Your health is now at %d%%\n", health);
    }

    return 0;
}