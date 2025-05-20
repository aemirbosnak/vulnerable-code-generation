//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print game instructions
void print_instructions() {
    printf("Welcome to the Guessing Game!\n");
    printf("You have 10 attempts to guess the randomly generated number between 1 and 100.\n");
    printf("After each guess, the program will tell you if the secret number is greater or smaller than your guess.\n");
    printf("Good luck!\n\n");
}

int main() {
    // print game instructions
    print_instructions();
    
    // initialize random number generator
    srand(time(NULL));
    
    // generate secret number
    int secret_number = rand() % 100 + 1;
    
    // initialize number of attempts and user's guess
    int attempts = 0;
    int guess = 0;
    
    while (attempts < 10) {
        // prompt user for guess
        printf("Guess #%d: ", attempts + 1);
        scanf("%d", &guess);
        
        // check if guess is correct
        if (guess == secret_number) {
            printf("Congratulations! You guessed the secret number in %d attempts.\n", attempts + 1);
            return 0;
        }
        
        // check if guess is too high or too low
        if (guess < secret_number) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }
        
        // increment number of attempts
        attempts++;
    }
    
    // if all attempts are used, print game over message
    printf("Game over! The secret number was %d.\n", secret_number);
    
    return 0;
}