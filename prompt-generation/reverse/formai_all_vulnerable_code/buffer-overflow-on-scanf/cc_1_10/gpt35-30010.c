//FormAI DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;

    srand(time(NULL));
    printf("Welcome to the Table Game!\n");

    while (1) {
        int player_roll = 0;
        int computer_roll = rand() % 6 + 1;

        printf("Your turn:\n");
        printf("Enter 'roll' to roll the dice, or 'hold' to stop rolling.\n");

        char player_input[10];
        scanf("%s", player_input);

        if (strcmp(player_input, "roll") == 0) {
            player_roll = rand() % 6 + 1;
            printf("You rolled a %d\n", player_roll);

            if (player_roll == 1) {
                printf("Sorry, you lose your turn.\n");
                player_score = 0;
                computer_score = 0;
                continue;
            }

            player_score += player_roll;
            printf("Current score: You %d - Computer %d\n", player_score, computer_score);
        } else if (strcmp(player_input, "hold") == 0) {
            printf("You hold.\n");

            while (computer_score < player_score && computer_score < 20) {
                computer_roll = rand() % 6 + 1;
                computer_score += computer_roll;

                printf("The computer rolls a %d\n", computer_roll);
                printf("Current score: You %d - Computer %d\n", player_score, computer_score);
            }

            if (computer_score >= 100 || player_score >= 100) {
                break;
            }
        } else {
            printf("Invalid input. Please enter 'roll' or 'hold'.\n");
            continue;
        }
    }

    if (player_score >= 100) {
        printf("Congratulations! You win!\n");
    } else {
        printf("Sorry, the computer wins.\n");
    }

    return 0;
}