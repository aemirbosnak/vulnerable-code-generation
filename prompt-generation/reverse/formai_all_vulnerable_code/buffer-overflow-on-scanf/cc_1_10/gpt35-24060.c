//FormAI DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORE 100

int human_turn(int score);
int computer_turn(int score, int target_score);

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;

    printf("Welcome to the game of Pig!\n\n");
    printf("The objective of the game is to be the first player to reach %d points.\n", MAX_SCORE);
    printf("Each turn, the player rolls a six-sided die, and gets points equal to the rolled number, except for rolling a 1 which results in the turn ending.\n");
    printf("The player can keep rolling, but if a 1 is rolled, all the points for that turn are lost and the other player gets their turn.\n");
    printf("The first player to reach %d points wins!\n\n", MAX_SCORE);

    while (player_score < MAX_SCORE && computer_score < MAX_SCORE) {
        // human turn
        player_score += human_turn(player_score);
        if (player_score >= MAX_SCORE) {
            printf("Player wins!\n");
            break;
        }

        // computer turn
        computer_score += computer_turn(computer_score, MAX_SCORE - player_score);
        if (computer_score >= MAX_SCORE) {
            printf("Computer wins!\n");
            break;
        }

        printf("Current Score - Player: %d, Computer: %d\n\n", player_score, computer_score);
    }

    printf("Final Score - Player: %d, Computer: %d\n", player_score, computer_score);
    printf("Thank you for playing!\n");

    return 0;
}

int human_turn(int score) {
    int turn_score = 0, roll;
    char choice;

    do {
        roll = rand() % 6 + 1;
        printf("You rolled: %d\n", roll);

        if (roll == 1) {
            printf("You rolled a 1. Your turn is over.\n");
            return 0;
        }

        turn_score += roll;
        printf("Current turn score: %d\n", turn_score);

        if (score + turn_score >= MAX_SCORE) {
            printf("You won!\n");
            return turn_score;
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    return turn_score;
}

int computer_turn(int score, int target_score) {
    int turn_score = 0, roll;

    do {
        roll = rand() % 6 + 1;
        printf("Computer rolled: %d\n", roll);

        if (roll == 1) {
            printf("Computer rolled a 1. Player's turn.\n");
            return 0;
        }

        turn_score += roll;
        printf("Current turn score: %d\n", turn_score);

        if (score + turn_score >= MAX_SCORE || turn_score >= target_score) {
            printf("Computer ends turn.\n");
            return turn_score;
        }

    } while (turn_score < target_score);

    return turn_score;
}