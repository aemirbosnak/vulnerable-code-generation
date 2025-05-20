//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    char board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = '*';
        }
    }

    // Create the list of possible symbols
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // Place the symbols on the board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int symbolIndex = rand() % 8;
            board[i][j] = symbols[symbolIndex];
        }
    }

    // Print the game board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Get the player's guesses
    int guess1Row, guess1Col, guess2Row, guess2Col;
    printf("Enter the row and column of the first guess (e.g., 1 2): ");
    scanf("%d %d", &guess1Row, &guess1Col);
    printf("Enter the row and column of the second guess (e.g., 1 2): ");
    scanf("%d %d", &guess2Row, &guess2Col);

    // Check if the guesses match
    if (board[guess1Row][guess1Col] == board[guess2Row][guess2Col]) {
        printf("Match!\n");
    } else {
        printf("No match.\n");
    }

    return 0;
}