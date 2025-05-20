//Falcon-180B DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>

// Function to print a message with a given delay
void delay_print(char* message, int delay) {
    printf("%s", message);
    fflush(stdout);
    usleep(delay * 1000);
}

int main() {
    // Variables for the game
    int player_score = 0;
    int computer_score = 0;
    int round_number = 1;
    int choice;
    char play_again;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    while (1) {
        // Print the current round number
        printf("Round %d:\n", round_number);

        // Generate a random number between 1 and 6
        int dice_roll = rand() % 6 + 1;

        // Ask the player for their choice
        printf("You rolled a %d. What would you like to do?\n", dice_roll);
        printf("1. Roll again\n");
        printf("2. Keep score\n");
        scanf("%d", &choice);

        // Update the scores based on the player's choice
        if (choice == 1) {
            delay_print("Rolling again... ", 1000);
            if (dice_roll == 1) {
                printf("You rolled a 1! You lose a point.\n");
                player_score--;
            } else {
                printf("You rolled a %d.\n", dice_roll);
            }
        } else {
            delay_print("Keeping score... ", 1000);
            printf("Your score is now %d.\n", player_score);
        }

        // Check if the game is over
        if (player_score == 0) {
            printf("Game over! You lose.\n");
            break;
        } else if (computer_score == 0) {
            printf("Game over! You win!\n");
            break;
        }

        // Switch to the computer's turn
        printf("Computer's turn...\n");
        delay_print("Rolling... ", 1000);
        computer_score += rand() % 6 + 1;
        printf("The computer rolled a %d. Their score is now %d.\n", rand() % 6 + 1, computer_score);

        // Check if the game is over
        if (player_score == 0) {
            printf("Game over! You lose.\n");
            break;
        } else if (computer_score == 0) {
            printf("Game over! You win!\n");
            break;
        }

        // Ask the player if they want to play again
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &play_again);

        // Exit the loop if the player doesn't want to play again
        if (play_again == 'n') {
            break;
        }

        // Increment the round number
        round_number++;
    }

    return 0;
}