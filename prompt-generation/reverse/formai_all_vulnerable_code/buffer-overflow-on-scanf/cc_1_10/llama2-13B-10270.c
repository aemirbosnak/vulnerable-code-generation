//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

// Function to print a happy face
void print_happy_face() {
    printf("   /_/\n  ( o.o )\n   > ^ <\n");
}

// Function to print a sad face
void print_sad_face() {
    printf("  ( T_T )\n   > ^ <\n");
}

// Function to print a confused face
void print_confused_face() {
    printf("  O_o)\n   > ^ <\n");
}

// Function to print a surprised face
void print_surprised_face() {
    printf("  O_O)\n   > ^ <\n");
}

// Function to print a game over message
void print_game_over() {
    printf("Game Over! Better luck next time! :(");
}

// Function to print a win message
void print_win() {
    printf("You won! Congratulations! :D");
}

// Function to print a lose message
void print_lose() {
    printf("You lost. Better luck next time! :(");
}

// Game loop
void game_loop() {
    int guess = 0;
    int correct = 0;
    int wrong = 0;

    print_happy_face();

    // Game starts
    printf("Welcome to the Happy Game! \n");
    printf("Your goal is to guess the correct number between 1 and 10. \n");

    // Generate a random number between 1 and 10
    int number = rand() % 10 + 1;

    // Print the correct number
    printf("The correct number is: %d \n", number);

    // Game loop
    while (1) {
        // Ask the user for their guess
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);

        // Check if the user guessed correctly
        if (guess == number) {
            correct++;
            print_win();
        } else if (guess < number) {
            wrong++;
            print_confused_face();
        } else {
            wrong++;
            print_sad_face();
        }

        // Print the game status
        printf("Correct: %d, Wrong: %d\n", correct, wrong);

        // Check if the game is over
        if (wrong >= 3) {
            print_game_over();
            break;
        }
    }
}

int main() {
    game_loop();
    return 0;
}