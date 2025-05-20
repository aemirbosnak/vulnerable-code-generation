//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

typedef struct {
    char value;
    int revealed;
} Card;

void initBoard(Card board[SIZE][SIZE]) {
    char values[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        values[i] = 'A' + i;
    }

    // Shuffle pairs
    for (int i = TOTAL_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Fill the board with pairs
    int idx = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (idx < TOTAL_PAIRS) {
                board[i][j].value = values[idx / 2];
                board[i][j].revealed = 0;
                idx++;
            }
        }
    }
}

void printBoard(Card board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].revealed) {
                printf(" %c ", board[i][j].value);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

void clearScreen() {
    printf("\033[H\033[J");
}

int checkMatch(Card board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY) {
    return board[firstX][firstY].value == board[secondX][secondY].value;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Card board[SIZE][SIZE];
    initBoard(board);

    int firstX, firstY, secondX, secondY;
    int pairsFound = 0;
    char move;

    while (pairsFound < TOTAL_PAIRS) {
        clearScreen();
        printBoard(board);
        printf("Select first card (row, column) e.g., 1 2: ");
        scanf("%d %d", &firstX, &firstY);
        firstX -= 1; firstY -= 1; // Convert to zero-based index

        if (firstX < 0 || firstX >= SIZE || firstY < 0 || firstY >= SIZE || board[firstX][firstY].revealed) {
            printf("Invalid selection or already revealed. Try again.\n");
            continue;
        }

        board[firstX][firstY].revealed = 1;
        clearScreen();
        printBoard(board);

        printf("Select second card (row, column) e.g., 1 2: ");
        scanf("%d %d", &secondX, &secondY);
        secondX -= 1; secondY -= 1; // Convert to zero-based index

        if (secondX < 0 || secondX >= SIZE || secondY < 0 || secondY >= SIZE || board[secondX][secondY].revealed) {
            printf("Invalid selection or already revealed. Try again.\n");
            board[firstX][firstY].revealed = 0; // Hide the first card again
            continue;
        }

        board[secondX][secondY].revealed = 1;
        clearScreen();
        printBoard(board);

        if (checkMatch(board, firstX, firstY, secondX, secondY)) {
            printf("It's a match! You found: %c\n", board[firstX][firstY].value);
            pairsFound++;
        } else {
            printf("Not a match! Press any key to continue...\n");
            sleep(2);
            board[firstX][firstY].revealed = 0;
            board[secondX][secondY].revealed = 0;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}