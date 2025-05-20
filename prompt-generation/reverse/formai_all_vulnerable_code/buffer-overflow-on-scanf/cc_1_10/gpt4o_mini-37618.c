//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of the grid (4x4)
#define NUM_PAIRS (SIZE * SIZE / 2)

void initializeBoard(char board[SIZE][SIZE], char values[NUM_PAIRS]) {
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (index < NUM_PAIRS) {
                board[i][j] = values[index];
                board[i][j + 1] = values[index];
                j++; // Skip the next cell since we have a pair
                index++;
            }
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE * SIZE; ++i) {
        int r1 = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        int row1 = r1 / SIZE;
        int col1 = r1 % SIZE;
        int row2 = r2 / SIZE;
        int col2 = r2 % SIZE;
        
        char temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

void displayBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    char values[NUM_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    srand(time(NULL));
    initializeBoard(board, values);
    shuffleBoard(board);
    
    int revealed[SIZE][SIZE] = {0};
    int pairsFound = 0;
    int attempts = 0;
    
    while (pairsFound < NUM_PAIRS) {
        displayBoard(board, revealed);
        
        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &row2, &col2);
        
        if (row1 < 0 || row1 >= SIZE || col1 < 0 || col1 >= SIZE ||
            row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE ||
            (row1 == row2 && col1 == col2) || revealed[row1][col1] || revealed[row2][col2]) {
            printf("Invalid coordinates or already revealed cards. Try again.\n");
            continue;
        }

        revealed[row1][col1] = 1;
        revealed[row2][col2] = 1;
        displayBoard(board, revealed);
        attempts++;

        if (board[row1][col1] == board[row2][col2]) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
        
        printf("Attempts so far: %d\n", attempts);
    }
    
    printf("Congratulations! You've found all pairs in %d attempts!\n", attempts);
    return 0;
}