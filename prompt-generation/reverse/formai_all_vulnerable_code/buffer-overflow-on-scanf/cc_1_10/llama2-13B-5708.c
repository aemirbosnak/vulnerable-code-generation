//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int get_random_number() {
    return (rand() % 10) + 1;
}

// Function to print a happy message
void print_happy_message() {
    printf("Hooray! You've just been awarded a magical cookie!\n");
}

// Function to print a sad message
void print_sad_message() {
    printf("Oh no! It looks like you've been left out of the cookie party... 😔\n");
}

int main() {
    // Variables to store the user's guess and the correct answer
    int guess = 0;
    int correct_answer = 0;

    // Initialize the game loop
    printf("Welcome to the Magic Cookie Game! 🍪\n");

    // Generate a random number between 1 and 10
    int random_number = get_random_number();

    // Print the correct answer
    printf("The correct answer is: %d\n", random_number);

    // Start the game loop
    while (1) {
        // Ask the user for their guess
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);

        // Check if the user's guess is correct
        if (guess == random_number) {
            // Print a happy message and end the game
            print_happy_message();
            break;
        } else if (guess < random_number) {
            // Print a sad message and keep playing
            print_sad_message();
        } else {
            // Print a sad message and end the game
            print_sad_message();
            break;
        }
    }

    // Print a final message
    printf("Thanks for playing the Magic Cookie Game! 🎉\n");

    return 0;
}