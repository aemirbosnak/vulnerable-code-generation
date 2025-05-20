//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIES 3
#define MAX_WARNINGS 2

void print_welcome();
void play_game();
int get_random_number();
void show_warning(int warnings);
void make_guess(int number_to_guess);
void see_result(int guess, int number_to_guess, int *warnings);

int main() {
    print_welcome();
    play_game();
    return 0;
}

void print_welcome() {
    printf("***** Welcome to the SHOCKING GUESSING GAME! *****\n");
    printf("Can you guess the right number between 1 and 100?\n");
}

void play_game() {
    int again = 1;

    while (again) {
        int number_to_guess = get_random_number();
        int tries = 0;
        int warnings = 0;

        printf("I've selected a number... Can you guess what it is?\n");

        while (tries < MAX_TRIES) {
            make_guess(number_to_guess);
            tries++;

            if (tries == MAX_TRIES) {
                printf("You have used all your tries! The number was %d.\n", number_to_guess);
                break;
            }
        }

        char response;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &response);
        again = (response == 'y' || response == 'Y') ? 1 : 0;

        if (again) {
            printf("Resetting the game... Prepare for the next shocking round!\n");
        } else {
            printf("Thanks for playing! See you next time!\n");
        }
    }
}

int get_random_number() {
    srand(time(NULL)); // Seed for random number generator
    return (rand() % 100) + 1; // Random number between 1 and 100
}

void make_guess(int number_to_guess) {
    int guess = 0;

    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
        printf("OUT OF BOUNDS! Please try between 1 and 100.\n");
    } else {
        int warnings = MAX_WARNINGS; // Reset warnings for each guess attempt
        see_result(guess, number_to_guess, &warnings);
    }
}

void see_result(int guess, int number_to_guess, int *warnings) {
    if (guess == number_to_guess) {
        printf("!!! SHOCKING VICTORY !!! You guessed it right!\n");
        exit(0); // Ends game on correct guess
    } else if (abs(guess - number_to_guess) <= 10) {
        printf("You're close! Just a bit off...\n");
    } else {
        printf("Far off! Shocking, isn't it?\n");
        (*warnings)--;
        show_warning(*warnings);
    }
}

void show_warning(int warnings) {
    if (warnings < 0) {
        printf("WARNING: You are out of warnings! Be careful!\n");
    } else {
        printf("You have %d warning(s) left.\n", warnings);
    }
}