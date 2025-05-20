//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player = 0, computer = 0, choice = 0;
    int round = 0, max_round = 5;
    int player_score = 0, computer_score = 0;

    printf("Welcome to the Rock-Paper-Scissors game!\n");

    srand(time(NULL));  // initialize random seed

    while (round < max_round) {
        printf("\nRound %d\n", round+1);
        printf("Please select your move: (1) Rock, (2) Paper, (3) Scissors\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {  // invalid input
            printf("Invalid move. Please try again.\n");
            continue;
        }

        player = choice;

        computer = rand() % 3 + 1;  // 1-3 inclusive

        printf("Player: %d\n", player);
        printf("Computer: %d\n", computer);

        if (player == computer) {  // draw
            printf("Draw!\n");
        } else if ((player == 1 && computer == 3) ||  // player wins
                   (player == 2 && computer == 1) ||
                   (player == 3 && computer == 2)) {
            printf("You win!\n");
            player_score++;
        } else {  // computer wins
            printf("Computer wins!\n");
            computer_score++;
        }

        round++;
    }

    printf("\nGame over. Your score: %d. Computer's score: %d.\n", player_score, computer_score);

    if (player_score > computer_score) {
        printf("Congratulations, you win!\n");
    } else if (player_score < computer_score) {
        printf("Sorry, you lose. Better luck next time!\n");
    } else {
        printf("The game is a tie.\n");
    }

    return 0;
}