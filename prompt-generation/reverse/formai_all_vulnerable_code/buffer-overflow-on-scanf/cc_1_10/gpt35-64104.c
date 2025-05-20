//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("~~~~~~~~~~~ WELCOME TO THE CHEST HUNT ~~~~~~~~~~~\n");

    // Intializing the random seed
    srand(time(NULL));

    // Initializing the chest location and the player's guess
    int chest_loc = rand() % 10 + 1; // Chest location between 1 and 10
    int guess;

    // Number of attempts player have
    int attempts = 5;

    // Game Loop
    while (attempts > 0) {

        printf("You have %d attempts left.\n", attempts);

        // Getting player's guess
        printf("Enter the chest number you want to open (between 1 and 10): ");
        scanf("%d", &guess);

        // Checking if player guessed the chest location or not
        if (guess == chest_loc) {
            printf("\n ~~ CONGRATULATIONS! YOU FOUND THE CHEST ~~\n");
            printf("~~~~~~~~~~~~ GAME OVER ~~~~~~~~~~~~\n");
            return 0;
        } else {
            printf("Sorry, you did not find the chest.\n");

            // Hinting the player about the chest location
            if (guess < chest_loc) {
                printf("The chest is located to the right of %d.\n", guess);
            } else {
                printf("The chest is located to the left of %d.\n", guess);
            }
        }

        attempts--;
    }

    // Player ran out of attempts
    printf("\n~~~ GAME OVER ~~~\n");
    printf("You couldn't find the chest.\n");
    printf("The chest was located at %d.\n", chest_loc);

    return 0;
}