//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

typedef struct {
    int number;
    int attempts;
} Player;

void generate_random_number(int *number) {
    *number = rand() % 100 + 1;
}

int check_guess(int guess, int number) {
    return (guess == number) ? 1 : -1;
}

void print_game_over(int attempts) {
    if (attempts > 0) {
        printf("Game Over! You took %d attempts to guess the number.\n", attempts);
    } else {
        printf("Game Over! You couldn't guess the number within the given attempts.\n");
    }
}

int main() {
    srand(time(NULL));

    Player player = { 0 };
    int number, guess;

    generate_random_number(&number);

    printf("Welcome to Turing's Enigma! I've generated a random number between 1 and 100. Can you guess it?\n");

    for (player.attempts = 0; player.attempts < MAX_ATTEMPTS; player.attempts++) {
        printf("Attempt %d: ", player.attempts + 1);
        scanf("%d", &guess);

        int result = check_guess(guess, number);

        if (result > 0) {
            printf("Congratulations! You guessed the number correctly.\n");
            break;
        } else {
            printf("Incorrect guess. Try again.\n");
        }
    }

    print_game_over(player.attempts);

    return 0;
}