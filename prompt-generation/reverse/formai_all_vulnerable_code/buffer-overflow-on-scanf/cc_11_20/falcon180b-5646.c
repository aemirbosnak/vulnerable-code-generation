//Falcon-180B DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_score = 0, computer_score = 0;
    int choice;
    char play_again;

    // Game loop
    do {
        system("clear"); // Clear the console
        printf("Welcome to the Number Guessing Game!\n\n");
        printf("Guess a number between 1 and 100.\n");
        int secret_number = rand() % 100 + 1; // Generate a random number between 1 and 100
        printf("The secret number is: %d\n\n", secret_number);

        // Player's turn
        do {
            printf("Enter your guess: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > 100) {
                printf("Invalid input. Please enter a number between 1 and 100.\n");
            }
        } while (choice < 1 || choice > 100);

        if (choice == secret_number) {
            printf("Congratulations! You guessed the correct number in %d tries.\n\n", 1);
            player_score++;
        } else if (choice < secret_number) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        // Computer's turn
        int computer_guess;
        do {
            computer_guess = rand() % 100 + 1;
        } while (computer_guess == secret_number);

        if (computer_guess < secret_number) {
            printf("The computer guessed: %d\n", computer_guess);
        } else {
            printf("The computer guessed: %d\n", computer_guess);
        }

        if (computer_guess == secret_number) {
            printf("Sorry, you lose. The computer guessed the correct number in %d tries.\n\n", 1);
            computer_score++;
        } else if (computer_guess < secret_number) {
            printf("Too low. Your turn again.\n");
        } else {
            printf("Too high. Your turn again.\n");
        }

        // Check for winner
        if (player_score >= 5) {
            printf("Congratulations! You win the game.\n");
            break;
        } else if (computer_score >= 5) {
            printf("Sorry, you lose the game.\n");
            break;
        }

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}