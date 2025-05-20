//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void print_menu() {
    printf("\n------------------------\n");
    printf("| Number Guessing Game  |\n");
    printf("------------------------\n");
    printf("| 1. Start Game         |\n");
    printf("| 2. Quit              |\n");
    printf("------------------------\n");
}

int generate_random_number() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

void game_round(int number, int attempts) {
    int guess;

    printf("\nPlayer 1, the number is %d. You have %d attempts left.\n", number, attempts);

    for (int i = 0; i < attempts; i++) {
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", i + 1);
            return;
        }
    }

    printf("Sorry, you couldn't guess the number within %d attempts. Player 2, it's your turn.\n", MAX_ATTEMPTS);
}

int main() {
    int number, player1_attempts, player2_attempts;

    print_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                number = generate_random_number();
                player1_attempts = MAX_ATTEMPTS;
                game_round(number, player1_attempts);

                if (player1_attempts == 0) {
                    printf("Sorry, the game is a tie.\n");
                    break;
                }

                player2_attempts = MAX_ATTEMPTS;
                number = generate_random_number();
                game_round(number, player2_attempts);

                if (player2_attempts == 0) {
                    printf("Player 1 wins!\n");
                } else {
                    printf("Player 2 wins!\n");
                }

                break;
            case 2:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose 1 or 2.\n");
        }

        print_menu();
    }

    return 0;
}