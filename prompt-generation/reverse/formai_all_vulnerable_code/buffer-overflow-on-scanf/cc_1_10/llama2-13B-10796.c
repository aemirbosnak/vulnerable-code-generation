//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Generate a random number between 1 and 10
    int num = rand() % 10 + 1;

    // Print the number in a surprised font
    printf("OH MY GOSH! You guessed it! The number is: %d\n", num);

    // Ask the user to guess the number again
    printf("Wow, you're really good at this! Guess the number again:\n");

    // Get the user's input
    int guess;
    scanf("%d", &guess);

    // Check if the user guessed the correct number
    if (guess == num) {
        printf("HOLY COW! You got it right again! You're on a roll!\n");
    } else {
        printf("Oh no! You didn't guess the correct number :'( Try again...\n");
    }

    // Keep asking the user to guess until they get it right
    while (1) {
        // Generate a new random number
        num = rand() % 10 + 1;

        // Print the new number in a surprised font
        printf("WHOA! The new number is: %d\n", num);

        // Ask the user to guess again
        printf("Go ahead and guess...\n");

        // Get the user's input
        scanf("%d", &guess);

        // Check if the user guessed the correct number
        if (guess == num) {
            break;
        } else {
            printf("Oh no! You didn't guess the correct number :'( Try again...\n");
        }
    }

    return 0;
}