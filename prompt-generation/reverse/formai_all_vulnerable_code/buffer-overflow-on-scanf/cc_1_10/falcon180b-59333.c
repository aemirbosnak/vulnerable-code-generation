//Falcon-180B DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game
void init_game() {
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the game!\n");
}

// Function to play a round of the game
void play_round(int player_score, int computer_score) {
    int choice;
    int result;

    // Player's turn
    printf("Your turn! Enter 1 for rock, 2 for paper, or 3 for scissors:\n");
    scanf("%d", &choice);

    result = (rand() % 3) + 1; // Computer makes a choice

    if (choice == result) {
        printf("It's a tie!\n");
    } else if ((choice == 1 && result == 3) ||
               (choice == 2 && result == 1) ||
               (choice == 3 && result == 2)) {
        printf("You win this round!\n");
        player_score++;
    } else {
        printf("You lose this round.\n");
        computer_score++;
    }
}

// Function to determine the winner of the game
void determine_winner(int player_score, int computer_score) {
    if (player_score > computer_score) {
        printf("Congratulations! You win the game!\n");
    } else if (computer_score > player_score) {
        printf("Sorry, you lose the game.\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int player_score = 0;
    int computer_score = 0;

    init_game();

    while (player_score == computer_score) {
        play_round(player_score, computer_score);
    }

    determine_winner(player_score, computer_score);

    return 0;
}