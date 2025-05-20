//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    int dice;
    srand(time(NULL));
    dice = rand() % 6 + 1;
    return dice;
}

// Function to display the result of the roll
void displayResult(int dice) {
    switch(dice) {
        case 1:
            printf("You rolled a 1\n");
            break;
        case 2:
            printf("You rolled a 2\n");
            break;
        case 3:
            printf("You rolled a 3\n");
            break;
        case 4:
            printf("You rolled a 4\n");
            break;
        case 5:
            printf("You rolled a 5\n");
            break;
        case 6:
            printf("You rolled a 6\n");
            break;
        default:
            printf("Invalid roll\n");
            break;
    }
}

// Function to play the game
void playGame() {
    int choice;
    int dice;
    int count = 0;
    int winCount = 0;
    int loseCount = 0;

    do {
        printf("Enter your choice (1 to roll the dice, 0 to quit): ");
        scanf("%d", &choice);

        if(choice!= 0) {
            dice = rollDice();
            displayResult(dice);

            if(dice == 6) {
                winCount++;
            } else if(dice == 1) {
                loseCount++;
            }

            count++;
        }

    } while(choice!= 0);

    printf("You won %d times and lost %d times in %d rolls\n", winCount, loseCount, count);
}

int main() {
    playGame();
    return 0;
}