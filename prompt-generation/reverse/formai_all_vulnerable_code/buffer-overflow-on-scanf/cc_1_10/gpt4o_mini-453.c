//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE_COUNT 3

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void placeTreasure(char board[SIZE][SIZE]) {
    int count = 0;
    while (count < TREASURE_COUNT) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (board[row][col] != 'T') {
            board[row][col] = 'T';
            count++;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkTreasure(char board[SIZE][SIZE], int row, int col) {
    if (board[row][col] == 'T') {
        return 1; // found treasure
    }
    return 0; // no treasure
}

int main() {
    char board[SIZE][SIZE];
    int row, col, found = 0;

    srand(time(NULL));
    initializeBoard(board);
    placeTreasure(board);

    printf("Welcome to the Treasure Hunt Game!\n");
    printBoard(board);

    for (int turn = 1; turn <= 10; turn++) {
        printf("Turn %d: Choose your cell (row[0-%d] col[0-%d]): ", SIZE - 1, SIZE - 1);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid cell! Try again.\n");
            turn--; // do not count this turn
            continue;
        }

        if (board[row][col] == 'T') {
            found++;
            printf("Congratulations! You found a treasure at (%d, %d)!\n", row, col);
            board[row][col] = 'X'; // mark as found
        } else if (board[row][col] == '-') {
            printf("No treasure at (%d, %d). Keep searching!\n", row, col);
            board[row][col] = 'O'; // mark as searched
        } else {
            printf("You already searched this cell!\n");
            turn--; // do not count this turn
        }

        printBoard(board);

        if (found == TREASURE_COUNT) {
            printf("You found all treasures! You win!\n");
            break;
        }
    }

    if (found < TREASURE_COUNT) {
        printf("Game Over! You found %d treasures. Better luck next time!\n", found);
    }

    return 0;
}