//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CARDS 16

int main() {
    int board[ROWS][COLS] = {0};

    // Initialize the board with card values
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand()%CARDS + 1;
        }
    }

    // Print the initial board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Shuffle the board
    for(int i=0; i<ROWS*COLS; i++) {
        int r = rand()%ROWS;
        int c = rand()%COLS;
        int temp = board[r][c];
        board[r][c] = board[i/COLS][i%COLS];
        board[i/COLS][i%COLS] = temp;
    }

    // Print the shuffled board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // User input for card selection
    int card1, card2, match = 0;
    printf("Enter the coordinates of the first card: ");
    scanf("%d %d", &card1, &card2);

    // Check if cards match
    if(board[card1-1][card2-1] == board[(card1-1)/2][(card2-1)/2]) {
        match = 1;
    }

    // Check if cards do not match
    if(match == 0) {
        printf("Cards do not match.\n");
    } else {
        printf("Cards match.\n");
    }

    return 0;
}