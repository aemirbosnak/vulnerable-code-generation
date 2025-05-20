//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 4
#define COLS 4

void initializeBoard(char board[ROWS][COLS]);
void shuffleBoard(char board[ROWS][COLS]);
void displayBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]);
int selectCard(int *row, int *col);
int checkMatch(char board[ROWS][COLS], int row1, int col1, int row2, int col2);
int allMatched(int revealed[ROWS][COLS]);
void printTitle();
void waitForEnter();

int main() {
    char board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0}; // Keeps track of revealed cards
    int totalPairs = (ROWS * COLS) / 2;
    int pairsFound = 0;
    int row1, col1, row2, col2;

    srand(time(NULL));

    printTitle();
    initializeBoard(board);
    shuffleBoard(board);

    while (pairsFound < totalPairs) {
        displayBoard(board, revealed);

        printf("Select the first card:\n");
        selectCard(&row1, &col1);
        revealed[row1][col1] = 1; // Reveal the first card
        displayBoard(board, revealed);

        printf("Select the second card:\n");
        selectCard(&row2, &col2);
        revealed[row2][col2] = 1; // Reveal the second card
        displayBoard(board, revealed);

        if (checkMatch(board, row1, col1, row2, col2)) {
            printf("It's a match! 🎉\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again! 😢\n");
            revealed[row1][col1] = 0; // Hide the first card
            revealed[row2][col2] = 0; // Hide the second card
        }

        waitForEnter();
    }

    printf("Congratulations! You've found all pairs! 🥳\n");
    return 0;
}

void printTitle() {
    printf("==================================\n");
    printf("        MEMORY GAME! 🧠💖\n");
    printf("==================================\n");
}

void initializeBoard(char board[ROWS][COLS]) {
    char letters[ROWS * COLS / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < ROWS * COLS / 2; i++) {
        board[i / COLS][i % COLS] = letters[i];
        board[i / COLS + ROWS / 2][i % COLS] = letters[i]; // duplicate
    }
}

void shuffleBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;

            // Swap
            char temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

void displayBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("  0 1 2 3\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int selectCard(int *row, int *col) {
    while (1) {
        printf("Enter row and column (e.g., 0 1): ");
        scanf("%d %d", row, col);
        if (*row >= 0 && *row < ROWS && *col >= 0 && *col < COLS) {
            return 1;
        }
        printf("Invalid selection. Please try again! 😊\n");
    }
}

int checkMatch(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

int allMatched(int revealed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (!revealed[i][j]) return 0;
    return 1;
}

void waitForEnter() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n'); // Clear the buffer
    getchar(); // Wait for Enter
}