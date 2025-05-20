//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 4; // change this to adjust the length of the sequence
    int sequence[size];
    int i;

    srand(time(NULL));

    // generate random sequence
    for (i = 0; i < size; i++) {
        sequence[i] = rand() % 10; // only use numbers 0-9
    }

    // print sequence for debugging purposes
    printf("Sequence: ");
    for (i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    // game loop
    int score = 0; // player's score
    int input[size]; // player's input
    while (1) {
        printf("Your turn: ");

        // get player input
        for (i = 0; i < size; i++) {
            scanf("%d", &input[i]);
        }

        // compare input to sequence
        for (i = 0; i < size; i++) {
            if (input[i] != sequence[i]) {
                printf("Game over. Score: %d\n", score);
                return 0; // end game
            }
        }

        // correct input
        score++;
        printf("Correct. Score: %d\n", score);

        // add new random number to sequence
        sequence[size-1] = rand() % 10;
        printf("New sequence: ");
        for (i = 0; i < size; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }

    return 0;
}