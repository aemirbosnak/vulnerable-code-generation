//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 10
#define MAX_SEQUENCE 10

int main()
{
    int round = 1;
    int score = 0;
    int sequence[MAX_SEQUENCE];
    int guess[MAX_SEQUENCE];

    srand(time(NULL)); // seed random number generator with current time

    printf("Welcome to the Memory Game!\n");
    printf("You will be presented with a sequence of numbers that you must repeat back correctly.\n");
    printf("You have 3 attempts per round to get it correct.\n\n");
    
    // game loop
    while (round <= MAX_ROUNDS) {
        printf("Round %d:\n", round);
        // generate random sequence of numbers
        for (int i = 0; i < MAX_SEQUENCE; i++) {
            sequence[i] = rand() % 10;
            printf("%d ", sequence[i]);
        }
        printf("\n");

        // player guesses
        for (int attempt = 0; attempt < 3; attempt++) {
            printf("Attempt %d - Enter the sequence: ", attempt + 1);
            for (int i = 0; i < MAX_SEQUENCE; i++) {
                scanf("%d", &guess[i]);
            }

            // check if correct
            int correct = 1;
            for (int i = 0; i < MAX_SEQUENCE; i++) {
                if (guess[i] != sequence[i]) {
                    correct = 0;
                    break;
                }
            }
            if (correct) {
                score++;
                printf("Correct!\n");
                break; // exit guesses loop
            } else {
                printf("Incorrect.\n");
            }
        }
        round++;
        printf("Current score: %d\n\n", score);
    }

    printf("Game over! Final score: %d\n", score);

    return 0;
}