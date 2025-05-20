//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVELS 10
#define MAX_ATTEMPTS 3

int main() {
    int level, i, j, guess, correct;
    int sequence[MAX_LEVELS], user_sequence[MAX_LEVELS];

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to Memory Game!\n");

    for(level = 1; level <= MAX_LEVELS; level++) { // iterate over levels
        printf("\nLevel %d\n", level);

        // generate random sequence
        for(i = 0; i < level; i++) {
            sequence[i] = rand() % 10;
            printf("%d ", sequence[i]);
        }
        printf("\n");

        // prompt user to repeat sequence
        correct = 1;
        for(i = 0; i < MAX_ATTEMPTS; i++) { // iterate over attempts
            printf("Repeat the sequence: ");
            for(j = 0; j < level; j++) { // iterate over sequence
                scanf("%d", &guess);
                user_sequence[j] = guess;
            }

            // compare sequences
            for(j = 0; j < level; j++) {
                if(user_sequence[j] != sequence[j]) {
                    correct = 0;
                    break;
                }
            }
            if(correct) {
                printf("Correct!\n");
                break;
            } else {
                printf("Incorrect! You have %d attempts left.\n", MAX_ATTEMPTS - i - 1);
            }
        }
        if(!correct) {
            printf("Game over! You made it to level %d.\n", level);
            return 0;
        }
    }

    printf("Congratulations! You won Memory Game!\n");
    return 0;
}