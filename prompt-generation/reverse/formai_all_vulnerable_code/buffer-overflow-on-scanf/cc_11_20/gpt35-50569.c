//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rock-Paper-Scissors game
int main() {

    srand(time(NULL)); // Initialize the random seed
    int player_score = 0;
    int computer_score = 0;
    char input[10];

    printf("Welcome to Rock-Paper-Scissors game!\n");
    printf("Instructions:\n");
    printf("You will play against the computer. You will enter 'rock', 'paper', or 'scissors'.\n");
    printf("The computer will choose a random move. Here are the rules:\n");
    printf("* Rock beats scissors\n");
    printf("* Scissors beats paper\n");
    printf("* Paper beats rock\n\n");

    while (1) {

        printf("Your move: ");
        scanf("%s", input);

        // Convert input to lowercase
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, "rock") == 0) {

            int computer_move = rand() % 3; // 0 - rock, 1 - paper, 2 - scissors

            if (computer_move == 0) {
                printf("Computer move: rock\n");
                printf("It's a tie!\n\n");
            } else if (computer_move == 1) {
                printf("Computer move: paper\n");
                printf("You lost this round.\n\n");
                computer_score++;
            } else if (computer_move == 2) {
                printf("Computer move: scissors\n");
                printf("You won this round!\n\n");
                player_score++;
            }

        } else if (strcmp(input, "paper") == 0) {
            
            int computer_move = rand() % 3; // 0 - rock, 1 - paper, 2 - scissors

            if (computer_move == 0) {
                printf("Computer move: rock\n");
                printf("You won this round!\n\n");
                player_score++;
            } else if (computer_move == 1) {
                printf("Computer move: paper\n");
                printf("It's a tie!\n\n");
            } else if (computer_move == 2) {
                printf("Computer move: scissors\n");
                printf("You lost this round.\n\n");
                computer_score++;
            }

        } else if (strcmp(input, "scissors") == 0) {

            int computer_move = rand() % 3; // 0 - rock, 1 - paper, 2 - scissors

            if (computer_move == 0) {
                printf("Computer move: rock\n");
                printf("You lost this round.\n\n");
                computer_score++;
            } else if (computer_move == 1) {
                printf("Computer move: paper\n");
                printf("You won this round!\n\n");
                player_score++;
            } else if (computer_move == 2) {
                printf("Computer move: scissors\n");
                printf("It's a tie!\n\n");
            }

        } else {
            printf("Invalid input. Please enter 'rock', 'paper', or 'scissors'.\n\n");
        }

        printf("Current score: You - %d, Computer - %d\n", player_score, computer_score);

        // Check if any player has won 3 rounds
        if (player_score == 3) {
            printf("Congratulations! You won the game.\n");
            break;
        } else if (computer_score == 3) {
            printf("Sorry, you lost the game.\n");
            break;
        }
    }

    return 0;
}