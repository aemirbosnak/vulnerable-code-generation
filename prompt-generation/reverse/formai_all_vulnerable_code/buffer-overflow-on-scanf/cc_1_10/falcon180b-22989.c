//Falcon-180B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int random_number;
    char play_again;

    srand(time(0));

    do {
        printf("Welcome to the Number Guessing Game!\n");
        printf("Guess a number between 1 and 100.\n");
        scanf("%d", &choice);

        random_number = rand() % 100 + 1;

        if (choice == random_number) {
            printf("Congratulations! You guessed the correct number: %d.\n", random_number);
            player_score++;
        } else if (choice < random_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        computer_score = rand() % 100 + 1;
        printf("The computer guessed: %d\n", computer_score);

        if (computer_score == random_number) {
            printf("The computer wins this round.\n");
            computer_score++;
        } else if (computer_score < random_number) {
            printf("The computer guessed too low.\n");
        } else {
            printf("The computer guessed too high.\n");
        }

        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}