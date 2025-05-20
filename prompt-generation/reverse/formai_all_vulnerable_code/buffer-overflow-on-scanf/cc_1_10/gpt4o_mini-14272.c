//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // A 4x4 board of cards
#define CARD_PAIRS (SIZE * SIZE) / 2

char* shapes[] = {"🔺", "🔲", "🔵", "⭐", "💚", "💖", "💛", "❓"};

void initializeBoard(char board[SIZE][SIZE], char shapes[CARD_PAIRS]) {
    int index = 0;
    for (int i = 0; i < CARD_PAIRS; i++) {
        board[index / SIZE][index % SIZE] = shapes[i];
        index++;
        board[index / SIZE][index % SIZE] = shapes[i];
        index++;
    }
    for (int i = 0; i < CARD_PAIRS; i++) {
        int randIndex1 = rand() % CARD_PAIRS;
        int randIndex2 = rand() % CARD_PAIRS;
        char temp = board[randIndex1 / SIZE][randIndex1 % SIZE];
        board[randIndex1 / SIZE][randIndex1 % SIZE] = board[randIndex2 / SIZE][randIndex2 % SIZE];
        board[randIndex2 / SIZE][randIndex2 % SIZE] = temp;
    }
}

void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("\n   0   1   2   3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %s ", board[i][j]);
            } else {
                printf(" ❓ ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(char board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

bool allRevealed(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!revealed[i][j]) return false;
    return true;
}

void playGame() {
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    char shapes[CARD_PAIRS] = {0};

    srand(time(NULL));
    initializeBoard(board, shapes);
    
    for (int i = 0; i < CARD_PAIRS; i++) {
        shapes[i] = shapes[i % (CARD_PAIRS / 2)];
    }

    int turns = 0;

    while (!allRevealed(revealed)) {
        printBoard(board, revealed);
        printf("Turn: %d\n", ++turns);

        int x1, y1, x2, y2;
        printf("Select first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        revealed[x1][y1] = true;

        printBoard(board, revealed);
        printf("Select second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        revealed[x2][y2] = true;

        if (checkMatch(board, x1, y1, x2, y2)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Hiding the cards again.\n");
            revealed[x1][y1] = false;
            revealed[x2][y2] = false;
        }
    }
    printf("Congratulations! You've matched all the shapes!\n");
}

int main() {
    printf("Welcome to the Shape Shifting Memory Game!\n");
    playGame();
    return 0;
}