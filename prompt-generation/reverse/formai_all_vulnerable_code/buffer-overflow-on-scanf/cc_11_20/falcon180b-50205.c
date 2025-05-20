//Falcon-180B DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    int player_choice, computer_choice;
    char play_again;

    // Initialize random seed
    srand(time(NULL));

    // Game loop
    while (1) {
        // Player turn
        printf("Enter your choice (0-2): ");
        scanf("%d", &player_choice);
        if (player_choice < 0 || player_choice > 2) {
            printf("Invalid choice, defaulting to 0.\n");
            player_choice = 0;
        }

        // Computer turn
        computer_choice = rand() % 3;

        // Display choices
        printf("\n");
        if (player_choice == 0) {
            printf("You chose rock.\n");
        } else if (player_choice == 1) {
            printf("You chose paper.\n");
        } else {
            printf("You chose scissors.\n");
        }
        if (computer_choice == 0) {
            printf("Computer chose rock.\n");
        } else if (computer_choice == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        // Determine winner
        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((player_choice == 0 && computer_choice == 1) ||
                   (player_choice == 1 && computer_choice == 0) ||
                   (player_choice == 2 && computer_choice == 0)) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose.\n");
            computer_score++;
        }

        // Check for game over
        if (player_score == 5 || computer_score == 5) {
            printf("\nGame over! You win!\n");
            break;
        } else if (player_score + computer_score == 10) {
            printf("\nGame over! It's a tie!\n");
            break;
        }

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again == 'n') {
            break;
        }
    }

    return 0;
}