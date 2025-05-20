//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int player_choice, computer_choice;
    printf("Let's play a game of rock-paper-scissors!\n\n");
    while (1) {
        printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
        scanf("%d", &player_choice);

        // Generate computer's choice randomly
        computer_choice = rand() % 3 + 1;

        // Print computer's choice
        if (computer_choice == 1) {
            printf("Computer chooses rock.\n");
        } else if (computer_choice == 2) {
            printf("Computer chooses paper.\n");
        } else {
            printf("Computer chooses scissors.\n");
        }

        // Compare player's choice with computer's choice
        if (player_choice == 1 && computer_choice == 3) {
            printf("You chose rock and computer chose scissors. You win!\n\n");
            player_score++;
        } else if (player_choice == 2 && computer_choice == 1) {
            printf("You chose paper and computer chose rock. You win!\n\n");
            player_score++;
        } else if (player_choice == 3 && computer_choice == 2) {
            printf("You chose scissors and computer chose paper. You win!\n\n");
            player_score++;
        } else if (player_choice == computer_choice) {
            printf("Both chose the same. It's a tie!\n\n");
        } else {
            printf("You lose!\n\n");
            computer_score++;
        }

        // Print scores
        printf("Current score:\nYou: %d\nComputer: %d\n\n", player_score, computer_score);

        // Ask to play again
        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &player_choice);
        if (player_choice == 0) {
            break;
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}