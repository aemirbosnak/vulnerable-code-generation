//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0, dice_val, turn_score = 0;
    char choice;
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n\n");

    do {
        printf("Player, it's your turn!\n");
        printf("Rolling the dice...\n");
        dice_val = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_val);

        if (dice_val == 1) {
            printf("Oh no! You rolled a 1, you lose your turn and all turn points!\n");
            turn_score = 0;
            continue;
        }

        turn_score += dice_val;
        printf("Your current turn score is: %d\n", turn_score);

        printf("Do you want to roll again? (y/n)\n");
        scanf(" %c", &choice);

        while (choice == 'y') {
            printf("Rolling the dice again...\n");
            dice_val = rand() % 6 + 1;
            printf("You rolled a %d!\n", dice_val);

            if (dice_val == 1) {
                printf("Oh no! You rolled a 1, you lose your turn and all turn points!\n");
                turn_score = 0;
                break;
            }

            turn_score += dice_val;
            printf("Your current turn score is: %d\n", turn_score);

            if (player_score + turn_score >= 100) {
                break;
            }

            printf("Do you want to roll again? (y/n)\n");
            scanf(" %c", &choice);
        }

        player_score += turn_score;
        turn_score = 0;
        printf("Your total score is now: %d\n\n", player_score);

        if (player_score >= 100) {
            break;
        }

        printf("Computer's turn now!\n");
        turn_score = 0;

        do {
            dice_val = rand() % 6 + 1;
            printf("Computer rolled a %d!\n", dice_val);

            if (dice_val == 1) {
                printf("Uh-oh! Computer rolled a 1, it loses its turn and turn points!\n");
                turn_score = 0;
                break;
            }

            turn_score += dice_val;

            if (computer_score + turn_score >= 100 || turn_score >= 20) {
                break;
            }
        } while (turn_score < 15);

        computer_score += turn_score;
        turn_score = 0;
        printf("Computer's total score is now: %d\n\n", computer_score);

    } while (player_score < 100 && computer_score < 100);

    if (player_score >= 100) {
        printf("Congratulations! You won with a score of %d!", player_score);
    } else {
        printf("Sorry, computer won with a score of %d.", computer_score);
    }

    return 0;
}