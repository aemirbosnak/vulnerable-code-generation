//LLAMA2-13B DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000
#define MAX_VALUE 1000

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to check if a number is negative
int is_negative(int number) {
    return number < 0;
}

// Function to check if a number is positive
int is_positive(int number) {
    return number > 0;
}

// Function to check if a number is zero
int is_zero(int number) {
    return number == 0;
}

// Function to print a message to the console
void print_message(char *message) {
    printf("%s\n", message);
}

// Function to play a game of chance
void play_game() {
    int guess, correct = 0;
    char message[MAX_LENGTH];

    // Generate a random number between min and max
    int number = random_number(MIN_VALUE, MAX_VALUE);

    // Print the message to the console
    print_message("Guess a number between min and max");

    // Get the user's guess
    scanf("%d", &guess);

    // Check if the guess is negative
    if (is_negative(guess)) {
        print_message("Oops, your guess is negative!");
    } else if (is_positive(guess)) {
        // Check if the guess is equal to the number
        if (guess == number) {
            print_message("Correct! You guessed the number correctly!");
            correct++;
        } else {
            print_message("Too bad, your guess was not correct!");
        }
    } else if (is_zero(guess)) {
        print_message("Hmm, you guessed zero... that's not correct!");
    }

    // Print the result to the console
    printf("You guessed %d times correctly out of %d attempts\n", correct, MAX_VALUE);
}

int main() {
    srand(time(NULL));

    // Play the game multiple times
    for (int i = 0; i < 10; i++) {
        play_game();
    }

    return 0;
}