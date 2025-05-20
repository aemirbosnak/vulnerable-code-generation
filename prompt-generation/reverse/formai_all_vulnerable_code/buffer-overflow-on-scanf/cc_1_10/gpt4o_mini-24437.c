//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE]) {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = (num <= (SIZE*SIZE / 2)) ? num : 0;
            if (num < (SIZE*SIZE / 2)) num++;
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            int temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void displayBoard(int board[SIZE][SIZE], bool shown[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (shown[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" X ");
            }
        }
        printf("\n");
    }
}

bool isBoardFull(bool shown[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!shown[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void playMemoryGame() {
    int board[SIZE][SIZE];
    bool shown[SIZE][SIZE] = {false};
    int pairsFound = 0;

    initializeBoard(board);
    shuffleBoard(board);

    while (true) {
        displayBoard(board, shown);
        
        printf("\nSelect the first card (row and column): ");
        int row1, col1;
        scanf("%d %d", &row1, &col1);
        
        if (row1 < 0 || row1 >= SIZE || col1 < 0 || col1 >= SIZE || shown[row1][col1]) {
            printf("Invalid selection; please try again.\n");
            continue;
        }
        
        shown[row1][col1] = true;
        displayBoard(board, shown);

        printf("Select the second card (row and column): ");
        int row2, col2;
        scanf("%d %d", &row2, &col2);

        if (row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE || shown[row2][col2]) {
            printf("Invalid selection; please try again.\n");
            shown[row1][col1] = false; // revert the first selection
            continue;
        }

        shown[row2][col2] = true;
        displayBoard(board, shown);

        if (board[row1][col1] == board[row2][col2]) {
            printf("It's a match! You found a pair!\n");
            pairsFound++;
            if (pairsFound == SIZE * SIZE / 2) {
                printf("Congratulations! You've found all pairs!\n");
                break;
            }
        } else {
            printf("No match, try again next time!\n");
            printf("Press Enter to continue...");
            getchar(); // To capture the newline from previous input
            getchar(); // Wait for user to press Enter
            shown[row1][col1] = false;
            shown[row2][col2] = false;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Memory Game!\n");
    playMemoryGame();
    return 0;
}