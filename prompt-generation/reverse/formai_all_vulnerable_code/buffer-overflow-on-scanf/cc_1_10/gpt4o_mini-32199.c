//GPT-4o-mini DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("****************************************\n");
    printf("*          Welcome to Number Guess     *\n");
    printf("*      Guess the number between 1 and 100!\n");
    printf("****************************************\n\n");
}

int get_random_number() {
    srand(time(NULL));  // Seed random number generator
    return rand() % 100 + 1;  // Return number between 1 and 100
}

void play_game() {
    int random_number = get_random_number();
    int user_guess = 0;
    int attempts = 0;

    while (user_guess != random_number) {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

        if (user_guess < 1 || user_guess > 100) {
            printf("Please guess a number between 1 and 100.\n");
        } else if (user_guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (user_guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n\n", random_number, attempts);
        }
    }
}

void play_again() {
    char response;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("\n");
        play_game();
        play_again();
    } else {
        printf("Thank you for playing! Goodbye.\n");
    }
}

int main() {
    print_welcome_message();
    play_game();
    play_again();
    return 0;
}