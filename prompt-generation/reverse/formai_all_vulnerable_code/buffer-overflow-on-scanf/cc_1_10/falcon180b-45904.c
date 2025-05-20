//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_NUM 6
#define DICE_SIDES 6

int main() {
    int dice_values[DICE_NUM];
    int i, j, sum = 0;
    char play_again;

    // Initialize random seed
    srand(time(NULL));

    // Roll the dice
    for(i = 0; i < DICE_NUM; i++) {
        dice_values[i] = rand() % DICE_SIDES + 1;
        printf("Dice %d rolled %d\n", i+1, dice_values[i]);
    }

    // Calculate the sum
    for(i = 0; i < DICE_NUM; i++) {
        sum += dice_values[i];
    }

    printf("The sum of the dice rolls is %d\n", sum);

    // Ask if the player wants to play again
    printf("Do you want to roll the dice again? (y/n) ");
    scanf("%c", &play_again);

    while(play_again == 'y' || play_again == 'Y') {
        for(i = 0; i < DICE_NUM; i++) {
            dice_values[i] = rand() % DICE_SIDES + 1;
            printf("Dice %d rolled %d\n", i+1, dice_values[i]);
        }

        sum = 0;
        for(i = 0; i < DICE_NUM; i++) {
            sum += dice_values[i];
        }

        printf("The sum of the dice rolls is %d\n", sum);

        printf("Do you want to roll the dice again? (y/n) ");
        scanf("%c", &play_again);
    }

    return 0;
}