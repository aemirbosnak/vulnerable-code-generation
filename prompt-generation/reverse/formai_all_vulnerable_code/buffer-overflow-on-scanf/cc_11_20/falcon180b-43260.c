//Falcon-180B DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int random_number;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Play the game
    while (player_score!= 5 && computer_score!= 5) {
        // Computer's turn
        random_number = rand() % 3;
        if (random_number == 0) {
            printf("Computer chooses rock.\n");
        } else if (random_number == 1) {
            printf("Computer chooses paper.\n");
        } else {
            printf("Computer chooses scissors.\n");
        }

        // Player's turn
        printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
        scanf("%d", &choice);

        if (choice == 0 && random_number == 2) {
            printf("You win this round!\n");
            player_score++;
        } else if (choice == 1 && random_number == 0) {
            printf("You win this round!\n");
            player_score++;
        } else if (choice == 2 && random_number == 1) {
            printf("You win this round!\n");
            player_score++;
        } else {
            printf("You lose this round.\n");
            computer_score++;
        }
    }

    // Determine the winner
    if (player_score == 5) {
        printf("Congratulations! You win the game!\n");
    } else {
        printf("Sorry, you lose the game.\n");
    }

    return 0;
}