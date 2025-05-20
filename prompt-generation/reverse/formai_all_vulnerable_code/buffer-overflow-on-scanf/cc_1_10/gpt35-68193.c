//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;
}

void printDice(int num) {
    if(num == 1) {
        printf(" ----- \n|     |\n|  O  |\n|     |\n ----- \n");
    } else if(num == 2) {
        printf(" ----- \n|O    |\n|     |\n|    O|\n ----- \n");
    } else if(num == 3) {
        printf(" ----- \n|O    |\n|  O  |\n|    O|\n ----- \n");
    } else if(num == 4) {
        printf(" ----- \n|O   O|\n|     |\n|O   O|\n ----- \n");
    } else if(num == 5) {
        printf(" ----- \n|O   O|\n|  O  |\n|O   O|\n ----- \n");
    } else {
        printf(" ----- \n|O   O|\n|O   O|\n|O   O|\n ----- \n");
    }
}

int main() {
    srand(time(0));
    char playAgain = 'y';
    int dice1, dice2, total;
    printf("-------------------\n");
    printf(" WELCOME TO DICEY! \n");
    printf("-------------------\n");
    while(playAgain == 'y') {
        printf("Press enter to roll the dice!\n");
        getchar();
        printf("Rolling...\n");
        dice1 = rollDice();
        dice2 = rollDice();
        total = dice1 + dice2;
        printDice(dice1);
        printDice(dice2);
        printf("Total: %d\n", total);
        if(total == 7 || total == 11) {
            printf("You win!\n");
        } else if(total == 2 || total == 3 || total == 12) {
            printf("You lose!\n");
        } else {
            printf("Roll again. If you get %d, you win. If you get 7, you lose.\n", total);
            char pressEnter;
            do {
                pressEnter = getchar();
            } while(pressEnter != '\n');
            int point = total;
            while(1) {
                printf("Press enter to roll the dice!\n");
                getchar();
                printf("Rolling...\n");
                dice1 = rollDice();
                dice2 = rollDice();
                total = dice1 + dice2;
                printDice(dice1);
                printDice(dice2);
                printf("Total: %d\n", total);
                if(total == point) {
                    printf("You win!\n");
                    break;
                } else if(total == 7) {
                    printf("You lose!\n");
                    break;
                }
            }
        }
        printf("Play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }
    printf("Thanks for playing Dicey!\n");
    return 0;
}