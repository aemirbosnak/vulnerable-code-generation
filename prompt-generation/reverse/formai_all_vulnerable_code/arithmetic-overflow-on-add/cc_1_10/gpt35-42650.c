//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int player1_score = 0, player2_score = 0;
    int player1_turn = 1, player2_turn = 0;
    int dice_value, roll_count, turn_score;
    char choice;

    srand(time(0));

    printf("Welcome to C Table Game!\n\n");

    do {
        printf("Rolling the dice for Player %d...\n", player1_turn);
        delay(2); // simulate rolling of dice
        dice_value = rand() % 6 + 1;
        printf("Player %d rolled a %d!\n", player1_turn, dice_value);
        if (dice_value == 1) {
            printf("Oops, Player %d lost their turn.\n", player1_turn);
            player1_turn = (player1_turn == 1 ? 2 : 1); // switch turns
            continue;
        }
        roll_count = 1;
        turn_score = dice_value;
        printf("Your current score for this turn is %d. Do you want to roll again (y/n)? ", turn_score);
        scanf(" %c", &choice);
        while (choice == 'y' || choice == 'Y') {
            printf("Rolling the dice again for Player %d...\n", player1_turn);
            delay(2); // simulate rolling of dice
            dice_value = rand() % 6 + 1;
            printf("Player %d rolled a %d!\n", player1_turn, dice_value);
            if (dice_value == 1) {
                printf("Oops, you lost your turn and score.\n");
                turn_score = 0;
                player1_turn = (player1_turn == 1 ? 2 : 1); // switch turns
                break;
            }
            roll_count++;
            turn_score += dice_value;
            printf("Your current score for this turn is %d. Do you want to roll again (y/n)? ", turn_score);
            scanf(" %c", &choice);
        }
        player1_score += turn_score;
        printf("Player %d's score is now %d.\n\n", player1_turn, player1_score);

        if (player1_score >= 50) {
            printf("Congratulations, Player %d wins!\n", player1_turn);
            return 0;
        }

        player1_turn = (player1_turn == 1 ? 2 : 1); // switch turns
    } while (1);

    return 0;
}