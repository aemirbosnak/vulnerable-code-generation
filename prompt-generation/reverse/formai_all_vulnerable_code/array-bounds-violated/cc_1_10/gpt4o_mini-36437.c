//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Size of the grid
#define CARD_COUNT (SIZE * SIZE) / 2 // Number of pairs of cards

typedef struct {
    char value;
    int exposed;
} Card;

void initializeBoard(Card board[SIZE][SIZE]);
void shuffleCards(Card board[SIZE][SIZE]);
void printBoard(Card board[SIZE][SIZE]);
int checkMatch(Card board[SIZE][SIZE], int row1, int col1, int row2, int col2);
int allExposed(Card board[SIZE][SIZE]);
int getInput(int *row, int *col);
void playGame();

int main() {
    playGame();
    return 0;
}

void playGame() {
    Card board[SIZE][SIZE];
    initializeBoard(board);
    shuffleCards(board);

    int row1, col1, row2, col2;
    int attempts = 0, matches = 0;

    while (matches < CARD_COUNT) {
        printf("Current Board:\n");
        printBoard(board);
        printf("Pick first card (row and column): ");
        if (!getInput(&row1, &col1) || board[row1][col1].exposed) {
            printf("Invalid input or card already exposed. Try again.\n");
            continue;
        }
        
        board[row1][col1].exposed = 1;
        printf("First card: %c\n", board[row1][col1].value);
        printBoard(board);
        
        printf("Pick second card (row and column): ");
        if (!getInput(&row2, &col2) || board[row2][col2].exposed || (row1 == row2 && col1 == col2)) {
            printf("Invalid input. Try again.\n");
            board[row1][col1].exposed = 0;
            continue;
        }
        
        board[row2][col2].exposed = 1;
        printf("Second card: %c\n", board[row2][col2].value);
        printBoard(board);
        
        if (checkMatch(board, row1, col1, row2, col2)) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("Not a match. Try again.\n");
            attempts++;
            board[row1][col1].exposed = 0;
            board[row2][col2].exposed = 0;
        }
    }
    
    printf("Congratulations! You've matched all pairs in %d attempts.\n", attempts);
}

void initializeBoard(Card board[SIZE][SIZE]) {
    char cardValues[CARD_COUNT];
    for (int i = 0; i < CARD_COUNT; i++) {
        cardValues[i] = 'A' + i; // Fill with letters A, B, C, etc.
    }
    
    // Duplicate the letters for pairs
    for (int i = 0; i < CARD_COUNT; i++) {
        cardValues[CARD_COUNT + i] = cardValues[i];
    }

    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].exposed = 0;
        }
    }

    // Fill the board with card values
    for (int i = 0; i < CARD_COUNT * 2; i++) {
        int r, c;
        do {
            r = rand() % SIZE;
            c = rand() % SIZE;
        } while (board[r][c].value != 0); // Check if already filled
        board[r][c].value = cardValues[i];
    }
}

void shuffleCards(Card board[SIZE][SIZE]) {
    srand(time(NULL));
}

void printBoard(Card board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].exposed) {
                printf("[%c] ", board[i][j].value);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int checkMatch(Card board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    return board[row1][col1].value == board[row2][col2].value;
}

int allExposed(Card board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].exposed) {
                return 0;
            }
        }
    }
    return 1;
}

int getInput(int *row, int *col) {
    if (scanf("%d %d", row, col) != 2) {
        while(getchar() != '\n'); // clear invalid input
        return 0;
    }
    return 1;
}