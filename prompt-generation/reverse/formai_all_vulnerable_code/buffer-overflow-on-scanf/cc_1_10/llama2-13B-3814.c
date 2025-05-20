//LLAMA2-13B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, z;
    char guess;

    srand(time(NULL));

    printf("Welcome to the Inquisitive C Program! \n");

    // First Question: Guess a Number
    printf("Think of a number between 1 and 100...\n");
    scanf("%d", &x);

    // Check if the guess is correct
    if (x == 42) {
        printf("Congratulations! You guessed the correct number! \n");
    } else {
        printf("Oops! Your guess was incorrect...\n");
    }

    // Second Question: Guess a Word
    printf("Now, think of a word that starts with the letter 'c'...\n");
    scanf(" %c", &guess);

    // Check if the guess is correct
    if (guess == 'c') {
        printf("Well done! You guessed the correct letter! \n");
    } else {
        printf("Oh no! Your guess was incorrect...\n");
    }

    // Third Question: Guess a Shape
    printf("Now, think of a shape...\n");
    scanf(" %d", &y);

    // Check if the guess is correct
    if (y == 5) {
        printf("Excellent! You guessed the correct shape! \n");
    } else {
        printf("Better luck next time...\n");
    }

    // Fourth Question: Guess a Color
    printf("Finally, think of a color...\n");
    scanf(" %c", &z);

    // Check if the guess is correct
    if (z == 'r') {
        printf("Wow! You guessed the correct color! \n");
    } else {
        printf("Oops! Your guess was incorrect...\n");
    }

    return 0;
}