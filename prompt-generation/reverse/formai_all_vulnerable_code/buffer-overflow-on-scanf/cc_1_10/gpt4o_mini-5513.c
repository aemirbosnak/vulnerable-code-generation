//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 4
#define TOTAL_PAIRED (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE]);
void shuffleBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool isMatch(char board[SIZE][SIZE], int x1, int y1, int x2, int y2);
void playGame(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    shuffleBoard(board);
    playGame(board);
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    char symbols[] = "ABCDEFGH";
    for (int i = 0; i < TOTAL_PAIRED; i++) {
        board[i / SIZE][i % SIZE] = symbols[i / 2];
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[j / SIZE][j % SIZE];
        board[j / SIZE][j % SIZE] = temp;
    }
}

void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  ");
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* "); // hidden
            }
        }
        printf("\n");
    }
}

bool isMatch(char board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

void playGame(char board[SIZE][SIZE]) {
    bool revealed[SIZE][SIZE] = {false};
    int pairsFound = 0;

    while (pairsFound < TOTAL_PAIRED) {
        printBoard(board, revealed);
        int x1, y1, x2, y2;
        
        // Player selects first symbol
        printf("Select first card (row column): ");
        scanf("%d %d", &x1, &y1);
        revealed[x1][y1] = true;
        printBoard(board, revealed);

        // Player selects second symbol
        printf("Select second card (row column): ");
        scanf("%d %d", &x2, &y2);
        revealed[x2][y2] = true;
        printBoard(board, revealed);

        // Check for match
        if (isMatch(board, x1, y1, x2, y2)) {
            printf("It's a match! You found: %c\n", board[x1][y1]);
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            sleep(1); // Pause for a moment to allow the player to see
            revealed[x1][y1] = false;
            revealed[x2][y2] = false;
        }
    }
    
    printf("Congratulations! You've matched all pairs!\n");
}