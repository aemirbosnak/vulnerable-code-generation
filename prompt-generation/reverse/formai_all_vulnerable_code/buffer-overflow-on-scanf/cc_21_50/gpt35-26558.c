//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6 // define the size of the board
#define BLANK_TILE 0 // define the value of the blank tile

int main() {
    int board[BOARD_SIZE][BOARD_SIZE]; // declare a 6x6 board
    int blank_row, blank_col; // keep track of the position of the blank tile
    int moves_count = 0; // keep track of the number of moves made by the player

    // seed random number generator
    srand(time(NULL));
    
    // initialize the board with random values from 1 to 36
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 36 + 1;
        }
    }

    // randomly choose a position for the blank tile
    blank_row = rand() % BOARD_SIZE;
    blank_col = rand() % BOARD_SIZE;
    board[blank_row][blank_col] = BLANK_TILE;

    // display the initial board to the player
    printf("Welcome to the Memory Game! Here is your board:\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == BLANK_TILE) {
                printf("__ "); // if the tile is blank, print a blank space
            } else {
                printf("%2d ", board[i][j]); // print the value of the tile
            }
        }
        printf("\n");
    }

    // get user input until all tiles are revealed
    while(1) {
        int row1, col1, row2, col2;
        printf("Enter the coordinates of two tiles to reveal (in the format row,col):\n");

        // get the coordinates of the first tile from the user
        scanf("%d,%d", &row1, &col1);
        while(row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE) {
            printf("Invalid coordinates. Please enter two numbers between 0 and %d (in the format row,col):\n", BOARD_SIZE-1);
            scanf("%d,%d", &row1, &col1);
        }

        // get the coordinates of the second tile from the user
        scanf("%d,%d", &row2, &col2);
        while(row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE || (row1 == row2 && col1 == col2)) {
            printf("Invalid coordinates. Please enter two different numbers between 0 and %d (in the format row,col):\n", BOARD_SIZE-1);
            scanf("%d,%d", &row2, &col2);
        }

        // swap the values of the two selected tiles
        int temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
        moves_count++; // increment the move counter
        
        // check if the game is over (all tiles except the blank tile are revealed)
        int game_over = 1;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] != BLANK_TILE) {
                    game_over = 0; // if any non-blank tiles are found, the game is not over
                }
            }
        }

        // display the updated board to the player
        printf("\nHere is the current board:\n");
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == BLANK_TILE) {
                    printf("__ ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("\n");
        }

        // end the game if all tiles are revealed
        if(game_over) {
            printf("\nCongratulations, you have won the game in %d moves!", moves_count);
            return 0;
        }
    }
}