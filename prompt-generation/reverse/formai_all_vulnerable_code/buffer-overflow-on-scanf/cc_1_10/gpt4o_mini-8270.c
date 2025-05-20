//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
void placeCards(char board[SIZE][SIZE]);
bool checkMatch(char card1, char card2);
bool isBoardComplete(bool revealed[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    int flips = 0;
    int pairsFound = 0;
    srand(time(0));

    initializeBoard(board);
    placeCards(board);

    printf("Welcome to the Memory Game!\n");
    printf("Find all the matching pairs of cards!\n\n");

    while (pairsFound < (SIZE * SIZE) / 2) {
        printBoard(board, revealed);
        int row1, col1, row2, col2;

        printf("Enter the coordinates of the first card (row and column): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card (row and column): ");
        scanf("%d %d", &row2, &col2);

        if (row1 < 0 || row1 >= SIZE || col1 < 0 || col1 >= SIZE || 
            row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE ||
            (row1 == row2 && col1 == col2) || revealed[row1][col1] || revealed[row2][col2]) {
            printf("Invalid input, try again!\n");
            continue;
        }

        revealed[row1][col1] = true;
        revealed[row2][col2] = true;
        flips++;

        printBoard(board, revealed);
        
        if (checkMatch(board[row1][col1], board[row2][col2])) {
            printf("It's a match!\n\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again!\n\n");
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
        }
    }

    printBoard(board, revealed);
    printf("Congratulations! You've found all pairs in %d flips!\n", flips);
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*'; // Initialize all positions with hidden cards
        }
    }
}

void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Current board:\n  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void placeCards(char board[SIZE][SIZE]) {
    char cards[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        cards[i] = 'A' + i; // Fill with letters A to D (for 8 cards)
    }

    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        board[i / SIZE][i % SIZE] = cards[i];
        board[(i + SIZE * SIZE / 2) / SIZE][(i + SIZE * SIZE / 2) % SIZE] = cards[i];
    }

    // Shuffle the board
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[j / SIZE][j % SIZE];
        board[j / SIZE][j % SIZE] = temp;
    }
}

bool checkMatch(char card1, char card2) {
    return card1 == card2;
}

bool isBoardComplete(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}