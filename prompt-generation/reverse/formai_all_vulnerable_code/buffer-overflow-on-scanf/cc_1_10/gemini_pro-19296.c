//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_TURNS 10

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char symbol;
    Position position;
    int revealed;
} Card;

Card board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    // Create a deck of cards
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int deck[BOARD_SIZE * BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        deck[i] = i % (BOARD_SIZE * BOARD_SIZE / 2);
    }

    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int j = rand() % (BOARD_SIZE * BOARD_SIZE);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Place the cards on the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = symbols[deck[index] / 2];
            board[i][j].position.row = i;
            board[i][j].position.col = j;
            board[i][j].revealed = 0;
            index++;
        }
    }
}

void printBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%c ", board[i][j].symbol);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

Position getMove() {
    Position move;
    int row, col;
    printf("Enter the row and column of the card you want to reveal (e.g. 1 2): ");
    scanf("%d %d", &row, &col);
    move.row = row - 1;
    move.col = col - 1;
    return move;
}

int checkMatch(Position move1, Position move2) {
    return board[move1.row][move1.col].symbol == board[move2.row][move2.col].symbol;
}

void revealCard(Position move) {
    board[move.row][move.col].revealed = 1;
}

int checkWin() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    initializeBoard();
    printBoard();

    Position move1, move2;
    int turns = 0;
    while (turns < MAX_TURNS && !checkWin()) {
        printf("Turn %d\n", turns + 1);
        printf("Enter the row and column of the first card you want to reveal (e.g. 1 2): ");
        scanf("%d %d", &move1.row, &move1.col);
        revealCard(move1);
        printBoard();

        printf("Enter the row and column of the second card you want to reveal (e.g. 1 2): ");
        scanf("%d %d", &move2.row, &move2.col);
        revealCard(move2);
        printBoard();

        if (checkMatch(move1, move2)) {
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }

        turns++;
    }

    if (checkWin()) {
        printf("Congratulations! You won in %d turns.\n", turns);
    } else {
        printf("Game over. You lost.\n");
    }

    return 0;
}