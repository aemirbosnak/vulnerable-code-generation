//Falcon2-11B DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard() {
    printf("   |   |   \n");
    printf("  0 | 1 | 2 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
    printf("  3 | 4 | 5 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
    printf("  6 | 7 | 8 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
}

void playGame() {
    int playerChoice, computerChoice;
    char playerChar, computerChar;
    srand(time(NULL)); // Seed random number generator

    // Game loop
    while (1) {
        drawBoard();
        printf("Player, choose a number between 1 and 9: ");
        scanf("%d", &playerChoice);

        if (playerChoice < 1 || playerChoice > 9) {
            printf("Invalid input. Please choose a number between 1 and 9.\n");
            continue;
        }

        // Computer's turn
        computerChoice = rand() % 9 + 1;

        printf("Computer chose: %d\n", computerChoice);

        // Check if player wins
        if (playerChoice == computerChoice) {
            printf("You win!\n");
            break;
        } else if (playerChoice == (9 - computerChoice)) {
            printf("Computer wins!\n");
            break;
        } else {
            printf("Tie!\n");
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}