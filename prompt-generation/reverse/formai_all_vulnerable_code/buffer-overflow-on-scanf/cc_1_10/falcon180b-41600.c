//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice and return the result
int roll_dice(int num_sides) {
    return rand_int(1, num_sides);
}

// Function to simulate a dice rolling game between two players
void dice_game(int num_rounds, int num_dices, int num_sides) {
    int i, j, player1_score = 0, player2_score = 0;

    for (i = 0; i < num_rounds; i++) {
        printf("Round %d:\n", i + 1);

        for (j = 0; j < num_dices; j++) {
            int dice_result1 = roll_dice(num_sides);
            int dice_result2 = roll_dice(num_sides);

            printf("Player 1 rolled a %d and a %d, total score: %d\n", dice_result1, dice_result2, dice_result1 + dice_result2);
            printf("Player 2 rolled a %d and a %d, total score: %d\n", dice_result1, dice_result2, dice_result1 + dice_result2);

            if (dice_result1 + dice_result2 > 7) {
                player1_score++;
            } else if (dice_result1 + dice_result2 < 7) {
                player2_score++;
            } else {
                printf("It's a tie!\n");
            }
        }

        printf("\n");
    }

    printf("Final scores:\n");
    printf("Player 1: %d\n", player1_score);
    printf("Player 2: %d\n", player2_score);
}

int main() {
    int num_rounds, num_dices, num_sides;

    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    printf("Enter the number of dices: ");
    scanf("%d", &num_dices);

    printf("Enter the number of sides per dice: ");
    scanf("%d", &num_sides);

    srand(time(NULL)); // Seed the random number generator with the current time

    dice_game(num_rounds, num_dices, num_sides);

    return 0;
}