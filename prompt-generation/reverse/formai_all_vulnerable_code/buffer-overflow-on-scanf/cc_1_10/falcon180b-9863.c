//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_NUM 6
#define DICE_SIDES 6

int rollDice(void) {
    int dice[DICE_NUM];
    int i, j;
    srand(time(NULL));

    for(i = 0; i < DICE_NUM; i++) {
        dice[i] = rand() % DICE_SIDES + 1;
    }

    for(i = 0; i < DICE_NUM - 1; i++) {
        for(j = i + 1; j < DICE_NUM; j++) {
            if(dice[i] > dice[j]) {
                int temp = dice[i];
                dice[i] = dice[j];
                dice[j] = temp;
            }
        }
    }

    return dice[0];
}

int main(void) {
    int i, j, playerWins = 0, computerWins = 0;

    printf("Welcome to the Dice Rolling Game!\n");

    while(1) {
        printf("Press 1 to roll the dice or 0 to quit: ");
        scanf("%d", &i);

        if(i == 0) {
            break;
        }

        printf("You rolled: %d\n", rollDice());

        if(i % 2 == 0) {
            printf("Computer's turn...\n");
            j = rollDice();
            printf("Computer rolled: %d\n", j);

            if(j > rollDice()) {
                printf("Computer wins!\n");
                computerWins++;
            } else if(j < rollDice()) {
                printf("You win!\n");
                playerWins++;
            } else {
                printf("It's a tie!\n");
            }
        } else {
            printf("Your turn...\n");
        }
    }

    printf("Thanks for playing!\n");
    printf("You won %d times.\n", playerWins);
    printf("Computer won %d times.\n", computerWins);

    return 0;
}