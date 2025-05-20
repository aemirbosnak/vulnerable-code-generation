//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDices;
    int diceResult;
    int totalResult = 0;
    int player1Result = 0;
    int player2Result = 0;
    char playAgain;

    srand(time(0));

    printf("Enter number of dices: ");
    scanf("%d", &numDices);

    printf("\nPlayer 1 (Romeo): ");
    for (int i = 0; i < numDices; i++) {
        diceResult = rand() % 6 + 1;
        totalResult += diceResult;
        printf("%d ", diceResult);
    }
    printf("\nTotal: %d\n", totalResult);

    printf("\nPlayer 2 (Juliet): ");
    for (int i = 0; i < numDices; i++) {
        diceResult = rand() % 6 + 1;
        totalResult += diceResult;
        printf("%d ", diceResult);
    }
    printf("\nTotal: %d\n", totalResult);

    if (totalResult > player1Result) {
        printf("\nPlayer 2 wins!\n");
    } else if (totalResult < player2Result) {
        printf("\nPlayer 1 wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf("\nExiting...\n");
        return 0;
    }

    return 0;
}