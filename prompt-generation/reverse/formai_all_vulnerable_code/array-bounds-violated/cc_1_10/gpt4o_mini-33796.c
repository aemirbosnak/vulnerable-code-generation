//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void printBoard(char board[SIZE][SIZE], char revealed[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 'T')
                printf(" %c ", board[i][j]);
            else
                printf(" * ");
        }
        printf("\n");
    }
}

void initializeBoard(char board[SIZE][SIZE]) {
    char symbols[8] = {'R', 'O', 'M', 'E', 'O', 'J', 'U', 'L'}; // The symbols for matching

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = symbols[index / 2]; // Two of each symbol
            if (index % 2 == 1) index++;
            else index += 2;
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    char revealed[SIZE][SIZE];
    int pairsFound = 0;
    int totalPairs = SIZE * SIZE / 2;

    // Initialize the revealed state
    memset(revealed, 'F', sizeof(revealed));
    
    // Shakespearean Opening
    printf("Gather around, for here we bring forth a memory game,\n");
    printf("Where lovers’ symbols hide, and only the brave shall reclaim.\n");

    initializeBoard(board);
    shuffleBoard(board);

    while (pairsFound < totalPairs) {
        printBoard(board, revealed);

        int x1, y1, x2, y2;
        printf("In the name of love, choose your first card (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Choose your second card (row col): ");
        scanf("%d %d", &x2, &y2);

        // Check bounds
        if (x1 >= SIZE || y1 >= SIZE || x2 >= SIZE || y2 >= SIZE || (x1 == x2 && y1 == y2)) {
            printf("Ah! You have chosen unwisely. Please choose again.\n");
            continue;
        }

        // Reveal chosen characters
        revealed[x1][y1] = 'T';
        revealed[x2][y2] = 'T';

        printBoard(board, revealed);

        // Check Match
        if (board[x1][y1] == board[x2][y2]) {
            printf("By love’s grace, you have found a match!\n");
            pairsFound++;
        } else {
            printf("Alas! No match found. The lovers remain apart.\n");
            revealed[x1][y1] = 'F';
            revealed[x2][y2] = 'F';
        }
    }

    printf("Hark! You have matched all pairs, love prevails in the end.\n");
    return 0;
}