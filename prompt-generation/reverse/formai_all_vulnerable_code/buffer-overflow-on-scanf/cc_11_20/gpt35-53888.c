//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, computer_choice, user_score = 0, computer_score = 0;
    char play_again;

    do {
        // Get user's choice
        printf("Choose your weapon:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &user_choice);

        // Validate user's choice
        while (user_choice < 1 || user_choice > 3) {
            printf("Invalid choice! Enter your choice (1-3): ");
            scanf("%d", &user_choice);
        }

        // Generate computer's choice
        srand(time(0)); // Set seed for random number generator
        computer_choice = rand() % 3 + 1; // Generate a random number between 1 and 3

        // Determine winner
        if (user_choice == 1 && computer_choice == 2) {
            printf("Computer chose paper. You lose!\n");
            computer_score++;
        } else if (user_choice == 1 && computer_choice == 3) {
            printf("Computer chose scissors. You win!\n");
            user_score++;
        } else if (user_choice == 2 && computer_choice == 1) {
            printf("Computer chose rock. You win!\n");
            user_score++;
        } else if (user_choice == 2 && computer_choice == 3) {
            printf("Computer chose scissors. You lose!\n");
            computer_score++;
        } else if (user_choice == 3 && computer_choice == 1) {
            printf("Computer chose rock. You lose!\n");
            computer_score++;
        } else if (user_choice == 3 && computer_choice == 2) {
            printf("Computer chose paper. You win!\n");
            user_score++;
        } else {
            printf("It's a tie!\n");
        }

        // Display score
        printf("Your score: %d\n", user_score);
        printf("Computer's score: %d\n", computer_score);

        // Ask if user wants to play again
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &play_again); // Add a space before %c to consume the newline character

    } while (play_again == 'Y' || play_again == 'y');

    printf("Thanks for playing!\n");
    return 0;
}