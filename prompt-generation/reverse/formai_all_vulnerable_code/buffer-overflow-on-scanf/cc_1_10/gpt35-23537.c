//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random color
char generateColor() {
    // create an array with possible colors
    char colors[] = {'R', 'G', 'B', 'Y'};
    // generate a random index between 0 and 3
    int index = rand() % 4;
    // return the color at the generated index
    return colors[index];
}

// function to check if the user's guess is correct
int checkGuess(char guess[], char sequence[], int length) {
    for (int i = 0; i < length; i++) {
        if (guess[i] != sequence[i]) {
            return 0;
        }
    }
    return 1;
}

// function to print the game instructions
void printInstructions() {
    printf("\n**********************************************\n");
    printf("***************** TABLE GAME ******************\n");
    printf("**********************************************\n\n");
    printf("The game generates a sequence of colors and you have to guess it.\n");
    printf("The sequence can have any combination of the following colors:\n");
    printf("  R - Red\n");
    printf("  G - Green\n");
    printf("  B - Blue\n");
    printf("  Y - Yellow\n");
    printf("The length of the sequence increases after each round.\n");
    printf("Good Luck!\n\n");
}

// main function
int main() {
    // seed the random number generator
    srand(time(NULL));
    // print game instructions
    printInstructions();
    // initialize game variables
    int length = 1;
    char sequence[length];
    char guess[length];
    int round = 1;
    int playAgain = 1;
    // loop to allow the player to keep playing
    while (playAgain) {
        // generate the sequence
        for (int i = 0; i < length; i++) {
            sequence[i] = generateColor();
        }
        // print the sequence for testing purposes
        printf("Sequence for round %d: %s\n", round, sequence);
        // reset the guess
        for (int i = 0; i < length; i++) {
            guess[i] = ' ';
        }
        // loop to allow the player to make a guess
        int done = 0;
        while (!done) {
            // prompt for the guess
            printf("Enter your guess (up to %d colors): ", length);
            scanf("%s", guess);
            // check the guess
            if (checkGuess(guess, sequence, length)) {
                printf("Correct!\n");
                done = 1;
            } else {
                printf("Incorrect. Try again.\n");
            }
        }
        // ask the player if they want to keep playing
        printf("Do you want to play again? (1 - Yes, 0 - No): ");
        scanf("%d", &playAgain);
        // increase the round and length for the next game
        round++;
        length++;
    }
    printf("Thanks for playing!\n");
    return 0;
}