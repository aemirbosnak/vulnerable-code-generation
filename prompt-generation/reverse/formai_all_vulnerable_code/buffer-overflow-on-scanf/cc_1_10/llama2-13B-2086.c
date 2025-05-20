//LLAMA2-13B DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int curiosity = 0;
    int i, j, k;
    char magicWord[20];

    // Create a random magic word
    srand(time(NULL));
    for (i = 0; i < 20; i++) {
        magicWord[i] = 'a' + (rand() % 26);
    }

    // Print the magic word
    printf("The magic word is: %s\n", magicWord);

    // Ask the user to guess the magic word
    printf("Guess the magic word: ");
    scanf("%s", magicWord);

    // Check if the user guessed correctly
    for (i = 0; i < strlen(magicWord); i++) {
        if (magicWord[i] != magicWord[i]) {
            curiosity++;
        }
    }

    // If the user guessed correctly, print a curious message
    if (curiosity == 0) {
        printf("You guessed it! The magic word was: %s\n", magicWord);
    } else {
        printf("You were curious, but the magic word was: %s\n", magicWord);
    }

    // Calculate the number of times the user guessed incorrectly
    for (i = 0; i < strlen(magicWord); i++) {
        if (magicWord[i] != magicWord[i]) {
            curiosity++;
        }
    }

    // Print the number of incorrect guesses
    printf("You made %d incorrect guesses\n", curiosity);

    return 0;
}