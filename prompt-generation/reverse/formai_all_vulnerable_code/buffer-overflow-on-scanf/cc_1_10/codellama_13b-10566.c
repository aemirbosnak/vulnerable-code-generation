//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: lively
/*
 * A simple terminal-based game in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5
#define MAX_GUESSES 10

struct player {
    char name[30];
    int score;
};

void display_instructions() {
    printf("Welcome to the terminal-based game! You will have to guess the number\n");
    printf("I will think of a number between 1 and 100, and you will have to guess\n");
    printf("it in as few attempts as possible. You will have 10 guesses per round,\n");
    printf("and the player with the lowest score at the end of the game wins.\n");
    printf("Let's get started!\n\n");
}

int get_input(int min, int max) {
    int input;
    while (1) {
        printf("Enter a number between %d and %d: ", min, max);
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

void play_round(int *number, int *guesses) {
    int guess = get_input(1, 100);
    if (guess == *number) {
        printf("You guessed it in %d attempts!\n", *guesses);
        *guesses = 0;
    } else if (guess < *number) {
        printf("Your guess is too low. Try again.\n");
        (*guesses)++;
    } else {
        printf("Your guess is too high. Try again.\n");
        (*guesses)++;
    }
}

void play_game() {
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guesses = 0;
    printf("The number is %d\n", number);
    for (int i = 0; i < MAX_ROUNDS; i++) {
        play_round(&number, &guesses);
        if (guesses == MAX_GUESSES) {
            printf("You have used all your guesses. The correct answer is %d\n", number);
            break;
        }
    }
}

int main() {
    display_instructions();
    play_game();
    return 0;
}