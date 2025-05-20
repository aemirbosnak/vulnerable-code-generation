//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6 (inclusive)
int rollDice() {
    return rand() % 6 + 1;
}

// Function to print dice image based on the value rolled
void printDice(int value) {
    switch(value) {
        case 1:
            printf("_____\n|     |\n|  _  |\n| | | |\n|_____|\n");
            break;
        case 2:
            printf("_____\n|   _|\n| | | |\n|___|\n");
            break;
        case 3:
            printf("_____\n|_|__|\n|   |\n|   |\n");
            break;
        case 4:
            printf("_____\n|   |\n|   |\n|___|\n");
            break;
        case 5:
            printf("_____\n|   |\n|   |\n|   |\n");
            break;
        case 6:
            printf("_____\n|   |\n|   |\n|   |\n|   |\n");
            break;
        default:
            printf("Invalid value!\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int player1Score = 0, player2Score = 0;
    char playAgain = 'y';

    // Main game loop
    while(playAgain == 'y') {
        printf("Player 1's turn:\n");
        player1Score += rollDice();
        printDice(player1Score);

        printf("\nPlayer 2's turn:\n");
        player2Score += rollDice();
        printDice(player2Score);

        if(player1Score > player2Score) {
            printf("\nPlayer 1 wins this round!\n");
        } else if(player2Score > player1Score) {
            printf("\nPlayer 2 wins this round!\n");
        } else {
            printf("\nIt's a tie!\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf("%c", &playAgain);
    }

    return 0;
}