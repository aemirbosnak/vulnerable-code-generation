//GPT-4o-mini DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

void display_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Can you guess the number I am thinking of between 1 and 100?\n");
    printf("You have %d attempts to get it right. Good luck!\n\n", MAX_TRIES);
}

int get_random_number() {
    srand(time(NULL)); 
    return rand() % 100 + 1; 
}

int main() {
    int random_number = get_random_number();
    int guess, attempts = 0;
    int game_over = 0;

    display_instructions();

    while (attempts < MAX_TRIES && !game_over) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", random_number, attempts);
            game_over = 1;
        }

        if (attempts == MAX_TRIES && !game_over) {
            printf("Sorry, you've used all your attempts. The number was %d.\n", random_number);
            game_over = 1;
        }

        // Display a playful hint every two tries
        if (attempts % 2 == 0 && !game_over) {
            if (random_number % 2 == 0) {
                printf("Hint: The number is even!\n");
            } else {
                printf("Hint: The number is odd!\n");
            }
        }
    }

    printf("Thank you for playing! Would you like to play again? (y/n): ");
    char play_again;
    scanf(" %c", &play_again);
    if (play_again == 'y' || play_again == 'Y') {
        main(); // Restart the game
    } else {
        printf("Goodbye! Have a great day!\n");
    }

    return 0;
}