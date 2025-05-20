//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int reveal[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    printf(" -----------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" | ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (reveal[i][j] == 0 || board[i][j] == 'X') {
                printf("* ");
            } else {
                printf("%c ", board[i][j]);
            }
            printf("| ");
        }
        printf("\n");
        printf(" -----------------------\n");
    }
    printf("\n");
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int reveal[BOARD_SIZE][BOARD_SIZE];
    srand(time(0));

    // initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 'X';
            reveal[i][j] = 0;
        }
    }

    // randomly place items
    int itemsPlaced = 0;
    while (itemsPlaced < (BOARD_SIZE * BOARD_SIZE / 2)) {
        int i = rand() % BOARD_SIZE;
        int j = rand() % BOARD_SIZE;
        if (board[i][j] == 'X') {
            board[i][j] = itemsPlaced + 65;
            itemsPlaced++;
        }
    }

    // play the game
    int selectedItem = -1;
    int selectedItemRow = -1;
    int selectedItemCol = -1;
    int moves = 0;
    do {
        printBoard(board, reveal);
        printf("Pick a row: ");
        scanf("%d", &selectedItemRow);
        printf("Pick a column: ");
        scanf("%d", &selectedItemCol);

        if (selectedItemRow >= 0 && selectedItemRow < BOARD_SIZE && selectedItemCol >= 0 && selectedItemCol < BOARD_SIZE && reveal[selectedItemRow][selectedItemCol] == 0) {
            reveal[selectedItemRow][selectedItemCol] = 1;

            if (selectedItem == -1) { // first item
                selectedItem = board[selectedItemRow][selectedItemCol];
            } else { // second item
                if (selectedItem == board[selectedItemRow][selectedItemCol]) {
                    printf("Match!\n");
                    selectedItem = -1;
                } else {
                    printf("No match\n");
                    reveal[selectedItemRow][selectedItemCol] = 0; // hide the second item
                    reveal[(selectedItemRow - 1) * (selectedItemRow >= 1)][(selectedItemCol - 1) * (selectedItemCol >= 1)] = 0; // hide the first item
                    selectedItem = -1;
                }
            }

            moves++;
        } else {
            printf("Invalid input, try again!\n");
        }

    } while (moves < BOARD_SIZE * BOARD_SIZE);

    printf("You've won in %d moves!\n", moves);
    
    return 0;
}