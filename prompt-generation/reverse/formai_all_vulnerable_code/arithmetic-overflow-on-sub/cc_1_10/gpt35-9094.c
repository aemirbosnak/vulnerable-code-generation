//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the terminal screen
void clearscreen() {
    system("clear");
}

// function to sleep for a certain number of seconds
void sleep(int seconds) {
    time_t start = time(NULL);
    while ((time(NULL) - start) < seconds) {}
}

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));

    // set the initial score to 0
    int score = 0;

    // welcome message
    printf("Welcome to the game!\n\n");

    // main game loop
    while (1) {
        // clear the screen
        clearscreen();

        // generate a random number between 1 and 10
        int guess_number = rand() % 10 + 1;

        // display the guess number
        printf("Guess the number between 1 and 10.\n");
        //printf("DEBUG: Guess number is %d.\n", guess_number);

        // ask the user to enter their guess
        int user_guess;
        printf("Enter your guess: ");
        scanf("%d", &user_guess);

        // check if the user's guess is correct
        if (user_guess == guess_number) {
            printf("Congratulations, you guessed the number!\n");
            score++;
        } else {
            printf("Sorry, the number was %d!\n", guess_number);
        }

        // display the score
        printf("Score: %d\n", score);

        // ask if the user wants to play again
        printf("Play again? (Y/N): ");
        char input;
        scanf(" %c", &input);
        if (input == 'N' || input == 'n') {
            break;
        }

        // pause for 3 seconds before starting a new round
        printf("Starting new round in 3 seconds...\n");
        sleep(3);
    }

    // display the final score
    printf("\n\nGame Over. Your final score is: %d\n", score);

    // exit the program
    return 0;
}