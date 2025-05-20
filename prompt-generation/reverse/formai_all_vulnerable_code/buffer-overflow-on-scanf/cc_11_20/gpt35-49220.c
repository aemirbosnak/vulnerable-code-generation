//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // initialize random seed
    srand(time(NULL));

    // initialize game variables
    int numPlayers = 2;
    int numPieces = numPlayers * 6;
    int boardSize = 24;
    int playerPositions[numPlayers][6];
    int currentPlayer = 0;
    int winner = -1;
    int roll;
    int piece;

    // initialize player positions
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 6; j++) {
            playerPositions[i][j] = -1; // indicate unused pieces
        }
    }

    printf("Welcome to the C Table Game!\n");

    // game loop
    while (winner == -1) {

        // print player info
        printf("\nPlayer %d:\n", currentPlayer+1);
        for (int i = 0; i < 6; i++) {
            if (playerPositions[currentPlayer][i] == -1) { // unused piece
                printf("  Piece %d: unused\n", i+1);
            } else { // used piece
                printf("  Piece %d: %d\n", i+1, playerPositions[currentPlayer][i]+1);
            }
        }

        // roll the die
        printf("\nPress enter to roll the die...\n");
        getchar();
        roll = rand() % 6 + 1; // generate random number between 1 and 6
        printf("You rolled a %d!\n", roll);

        // move a piece
        printf("Which piece would you like to move? (1-6)\n");
        scanf("%d", &piece);
        if (piece < 1 || piece > 6 || playerPositions[currentPlayer][piece-1] == boardSize-1) {
            printf("Invalid piece!\n");
            continue;
        }
        if (playerPositions[currentPlayer][piece-1] == -1) {
            playerPositions[currentPlayer][piece-1] = 0; // move from start
        } else {
            playerPositions[currentPlayer][piece-1] += roll; // move normally
        }

        // check for victory
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            if (playerPositions[currentPlayer][i] != -1) { // used piece
                sum += playerPositions[currentPlayer][i];
            }
            if (playerPositions[currentPlayer][i] == boardSize-1) {
                winner = currentPlayer;
                break;
            }
        }
        if (sum == 6 * (boardSize-1)) { // all pieces reached the end
            winner = currentPlayer;
        }

        // switch turns
        currentPlayer = (currentPlayer + 1) % numPlayers;

    }

    // print winner
    printf("\nPlayer %d wins!\n", winner+1);

    return 0;
}