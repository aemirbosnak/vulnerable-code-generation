//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

enum direction { RIGHT, LEFT, UP, DOWN };

void print_board(int board[][BOARD_SIZE]) {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize all cells to zero
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;
    board[row][col] = 'P'; // Place the player on a random cell
    print_board(board);
    
    int temp_row, temp_col;
    enum direction d;

    while(1) { // Game loop
        printf("\nEnter move direction (0=RIGHT, 1=LEFT, 2=UP, 3=DOWN): ");
        scanf("%d", &d);
        temp_row = row; 
        temp_col = col; // save current coordinates
        switch(d) {
            case RIGHT:
                col++;
                break;
            case LEFT:
                col--;
                break;
            case UP:
                row--;
                break;
            case DOWN:
                row++;
                break;
            default:
                printf("Invalid move direction!\n");
                continue;
        }
        
        if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) { // Player moved out of bounds
            printf("Out of bounds!\n");
            row = temp_row; // Restore previous coordinates
            col = temp_col;
        } else if(board[row][col] == '*') { // Player hit a mine
            printf("Game over!\n");
            break;
        } else { // Valid move
            board[temp_row][temp_col] = 0; // Clear previous cell
            board[row][col] = 'P'; // Place player on new cell
            print_board(board);
        }
    }

    return 0; 
}