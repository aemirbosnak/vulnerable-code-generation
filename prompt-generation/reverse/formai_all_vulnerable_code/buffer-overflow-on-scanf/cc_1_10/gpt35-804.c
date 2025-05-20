//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int steps = 20;
    int position = 0;
    int ghosts = 3;

    printf("Welcome to the Haunted House Simulator\n");
    printf("You have %d steps to reach the exit\n", steps);
    printf("But beware, there are %d ghosts lurking around\n", ghosts);

    srand(time(NULL));

    while (steps > 0 && ghosts > 0) {

        printf("You are currently at position %d\n", position);
        printf("You have %d steps left\n", steps);
        printf("There are %d ghosts around\n", ghosts);
        printf("Enter a direction (0 for left, 1 for right): ");

        int direction;
        scanf("%d", &direction);

        // Move the player
        if (direction == 0) {
            position--;
        } else {
            position++;
        }

        steps--;    // Decrement the steps

        // Check for ghosts
        if (rand() % 4 == 0) {
            ghosts--;
            printf("You just encountered a ghost! %d more to go...\n", ghosts);
        }

        // Check for exit
        if (position >= 10) {
            printf("Congratulations! You made it out alive!\n");
            return 0;
        }
    }

    printf("Sorry, you did not make it out alive. Better luck next time!\n");
    return 0;
}