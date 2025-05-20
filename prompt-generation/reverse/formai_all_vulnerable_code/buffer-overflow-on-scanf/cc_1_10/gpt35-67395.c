//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 2
#define NUM_SIDES 6

int rollDice(void);
void drawDice(int diceValue);

int main(void)
{
    int diceValues[NUM_DICE];
    char userChoice = ' ';
    int i;

    srand(time(NULL));

    printf("Welcome to the C Dice Roller!\n");

    do {
        /* Roll the dice */
        for (i = 0; i < NUM_DICE; i++) {
            diceValues[i] = rollDice();
        }

        /* Draw the dice */
        for (i = 0; i < NUM_DICE; i++) {
            drawDice(diceValues[i]);
        }

        /* Ask the user if they want to roll again */
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &userChoice);
    } while (userChoice == 'y' || userChoice == 'Y');

    return 0;
}

int rollDice(void)
{
    return rand() % NUM_SIDES + 1;
}

void drawDice(int diceValue)
{
    switch (diceValue) {
        case 1:
            printf("-------\n");
            printf("|     |\n");
            printf("|  o  |\n");
            printf("|     |\n");
            printf("-------\n");
            break;
        case 2:
            printf("-------\n");
            printf("| o   |\n");
            printf("|     |\n");
            printf("|   o |\n");
            printf("-------\n");
            break;
        case 3:
            printf("-------\n");
            printf("| o   |\n");
            printf("|  o  |\n");
            printf("|   o |\n");
            printf("-------\n");
            break;
        case 4:
            printf("-------\n");
            printf("| o o |\n");
            printf("|     |\n");
            printf("| o o |\n");
            printf("-------\n");
            break;
        case 5:
            printf("-------\n");
            printf("| o o |\n");
            printf("|  o  |\n");
            printf("| o o |\n");
            printf("-------\n");
            break;
        case 6:
            printf("-------\n");
            printf("| o o |\n");
            printf("| o o |\n");
            printf("| o o |\n");
            printf("-------\n");
            break;
        default:
            printf("Invalid dice value!\n");
            break;
    }
}