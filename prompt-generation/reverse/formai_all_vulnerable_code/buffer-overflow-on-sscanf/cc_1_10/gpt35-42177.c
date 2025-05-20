//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define variables
int attempts = 0, wins = 0, losses = 0;

// function to generate a random number
int generate_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// function to prompt the user for a guess and validate input
int get_guess() {
    char input[5];
    int guess;
    while (1) {
        printf("Enter your guess (1-100): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &guess) != 1) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (guess < 1 || guess > 100) {
            printf("Invalid input. Must be between 1 and 100. Try again.\n");
            continue;
        }
        break;
    }
    return guess;
}

// game logic function
void play_game() {
    int random_number = generate_random_number(1, 100);
    int guess;
    printf("Guess a number between 1 and 100 in 10 attempts.\n");
    while (attempts < 10) {
        guess = get_guess();
        attempts++;
        if (guess == random_number) {
            printf("Correct! The number was %d. You guessed it in %d attempts.\n", random_number, attempts);
            wins++;
            return;
        }
        else if (guess < random_number) {
            printf("Your guess is too low. You have %d attempt(s) left.\n", 10 - attempts);
        }
        else {
            printf("Your guess is too high. You have %d attempt(s) left.\n", 10 - attempts);
        }
    }
    printf("You ran out of attempts. The number was %d.\n",random_number);
    losses++;
}

// function to print out game statistics
void print_statistics() {
    printf("**********STATISTICS**********\n");
    printf("Total games played: %d\n", wins + losses);
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
}


// main function
int main() {
    int play_again = 1;
    char input[5];
    while (play_again) {
        attempts = 0;
        play_game();
        printf("Play again? (y/n): ");
        fgets(input, sizeof(input), stdin);
        if (input[0] != 'y' && input[0] != 'Y') {
            play_again = 0;
        }
    }
    print_statistics();
    return 0;
}