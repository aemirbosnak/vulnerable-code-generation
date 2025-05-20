//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void generate_random_number(int *number);
void print_menu();
void player_turn(int *number, int tries_left, int player_number);

int main() {
    int number, player_number = 1, tries_left = MAX_TRIES, guess;

    srand(time(NULL));
    generate_random_number(&number);

    printf("Welcome to Number Guessing Game!\n");
    print_menu();

    while (tries_left > 0) {
        player_turn(&number, tries_left, player_number++);

        if (number == guess) {
            printf("Player %d has guessed the number %d correctly.\n", player_number - 1, number);
            break;
        }

        tries_left--;
        printf("Player %d's guess was incorrect. Tries left: %d\n", player_number - 1, tries_left);
    }

    if (tries_left == 0) {
        printf("Game Over! The number was %d.\n", number);
    }

    return 0;
}

void generate_random_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_menu() {
    printf("\nAvailable ranges:\n");
    printf("- Minimum number: %d\n", MIN_NUMBER);
    printf("- Maximum number: %d\n", MAX_NUMBER);
    printf("- Number of tries: %d\n", MAX_TRIES);
    printf("- Player %d will go first.\n", 1);
}

void player_turn(int *number, int tries_left, int player_number) {
    int guess;

    printf("\nPlayer %d, your turn to guess a number between %d and %d (inclusive).\n", player_number, MIN_NUMBER, MAX_NUMBER);
    scanf("%d", &guess);

    if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
        printf("Invalid input! Number should be between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
        player_turn(number, tries_left, player_number);
        return;
    }

    if (guess == *number) {
        printf("Congratulations, Player %d! You have guessed the number correctly.\n", player_number);
        return;
    }

    printf("Sorry, Player %d, your guess was incorrect.\n", player_number);
}