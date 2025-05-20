//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6

int roll_dice() {
    return rand() % SIDES + 1;
}

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int round_number = 0;
    char play_again;

    // Game loop
    do {
        printf("Round %d\n", ++round_number);
        player_score = 0;
        computer_score = 0;

        // Player turn
        while (player_score < 21) {
            printf("Your score: %d\n", player_score);
            printf("Do you want to roll the dice? (y/n): ");
            scanf(" %c", &play_again);

            if (play_again == 'y' || play_again == 'Y') {
                player_score += roll_dice();
                printf("You rolled a %d.\n", player_score);
            } else {
                break;
            }
        }

        // Computer turn
        while (computer_score < 21) {
            computer_score += roll_dice();
            printf("Computer rolled a %d.\n", computer_score);
        }

        if (player_score > 21) {
            printf("You bust! Computer wins.\n");
        } else if (computer_score > 21) {
            printf("Computer busts! You win.\n");
        } else if (player_score > computer_score) {
            printf("You win!\n");
        } else if (player_score < computer_score) {
            printf("You lose.\n");
        } else {
            printf("It's a tie.\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}