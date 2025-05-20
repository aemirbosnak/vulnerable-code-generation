//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice with the given number of sides
int roll_dice(int num_sides) {
    return rand_num(1, num_sides);
}

// Function to determine the result of a dice roll (win, lose, or draw)
int dice_result(int roll) {
    if (roll == 1) {
        return -1; // Lose
    } else if (roll == 6) {
        return 1; // Win
    } else {
        return 0; // Draw
    }
}

// Function to play a game of dice with the given number of rounds
void play_game(int num_rounds) {
    int player_score = 0;
    int computer_score = 0;
    int round_winner;

    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d:\n", i+1);

        player_score += roll_dice(6);
        computer_score += roll_dice(6);

        round_winner = dice_result(player_score);

        if (round_winner == 1) {
            printf("You win!\n");
        } else if (round_winner == -1) {
            printf("You lose.\n");
        } else {
            printf("It's a draw.\n");
        }
    }

    printf("Game over.\n");
    printf("Your score: %d\n", player_score);
    printf("Computer score: %d\n", computer_score);

    if (player_score > computer_score) {
        printf("You win the game!\n");
    } else if (player_score < computer_score) {
        printf("You lose the game.\n");
    } else {
        printf("It's a tie.\n");
    }
}

int main() {
    srand(time(NULL));

    int num_rounds;

    printf("How many rounds do you want to play? ");
    scanf("%d", &num_rounds);

    play_game(num_rounds);

    return 0;
}