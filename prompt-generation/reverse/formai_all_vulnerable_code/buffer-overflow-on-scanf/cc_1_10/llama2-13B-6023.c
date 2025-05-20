//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

// Function to print a happy face
void print_happy_face(void) {
    printf("😊");
}

// Function to print a sad face
void print_sad_face(void) {
    printf("😔");
}

// Function to print a question mark
void print_question_mark(void) {
    printf("?");
}

// Function to get a random number between 1 and 10
int get_random_number(void) {
    return (rand() % 10) + 1;
}

// Game loop
void game_loop(void) {
    int current_number, guess, correct;

    // Initialize game variables
    current_number = 1;
    guess = 0;
    correct = 0;

    // Print the game title and instructions
    printf("Welcome to the Happy Number Game!\n");
    printf("Your goal is to guess the current number, which is between 1 and 10.\n");
    printf("You have 10 chances to guess the correct number.\n");

    // Start the game loop
    while (guess < 10) {
        // Print the current number and a happy face
        printf("Current number: %d 😊\n", current_number);

        // Get the user's guess
        scanf("%d", &guess);

        // Check if the user's guess is correct
        if (guess == current_number) {
            // Print a happy face and increment the correct count
            print_happy_face();
            correct++;
        } else {
            // Print a sad face and increment the incorrect count
            print_sad_face();
            guess--;
        }

        // Update the current number
        current_number = get_random_number();
    }

    // Print the final result
    printf("You guessed %d out of 10 correct!\n", correct);
}

int main(void) {
    srand(time(NULL));

    // Start the game loop
    game_loop();

    return 0;
}