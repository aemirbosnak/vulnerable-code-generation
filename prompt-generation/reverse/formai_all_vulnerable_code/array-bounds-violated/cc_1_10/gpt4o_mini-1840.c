//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of the grid (4x4)
#define CARD_COUNT (SIZE * SIZE) / 2 // Number of unique cards

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void shuffleBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int flipCard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int checkMatch(char board[SIZE][SIZE], int card1[2], int card2[2]);
int gameFinished(int revealed[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 - face down, 1 - face up
    int pairsFound = 0;

    initializeBoard(board);
    shuffleBoard(board);

    while (pairsFound < CARD_COUNT) {
        displayBoard(board, revealed);
        int card1[2] = {flipCard(board, revealed)};
        displayBoard(board, revealed);
        int card2[2] = {flipCard(board, revealed)};

        if (checkMatch(board, card1, card2)) {
            printf("Match found!\n");
            revealed[card1[0]][card1[1]] = 1;
            revealed[card2[0]][card2[1]] = 1;
            pairsFound++;
        } else {
            printf("No match, try again!\n");
            revealed[card1[0]][card1[1]] = 0;
            revealed[card2[0]][card2[1]] = 0;
        }
        printf("\n");
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    char cards[CARD_COUNT] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 
                               'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = cards[index++];
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < CARD_COUNT * 10; i++) {
        int x1 = rand() % SIZE;
        int y1 = rand() % SIZE;
        int x2 = rand() % SIZE;
        int y2 = rand() % SIZE;
        char temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }
}

void displayBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int flipCard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    int x, y;
    while (1) {
        printf("Enter coordinates to flip (row and column): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && !revealed[x][y]) {
            revealed[x][y] = 1;
            return (x * SIZE) + y; // Convert coordinates to single index
        } else {
            printf("Invalid input or card already flipped. Try again.\n");
        }
    }
}

int checkMatch(char board[SIZE][SIZE], int card1[2], int card2[2]) {
    return board[card1[0]][card1[1]] == board[card2[0]][card2[1]];
}