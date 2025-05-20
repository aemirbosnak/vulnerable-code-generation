//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j, num_bombs;
    srand(time(0)); // Seed random number generator with current time
    
    printf("Welcome to the C Terminal Minesweeper!\n");
    printf("Enter the number of bombs you want to place (Maximum: %d): ", 
            BOARD_SIZE * BOARD_SIZE / 4);
    scanf("%d", &num_bombs);
    
    // Initialize board to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    
    // Randomly place bombs
    while (num_bombs > 0) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            num_bombs--;
        }
    }
    
    // Game loop
    int game_over = 0;
    while (!game_over) {
        // Display board
        printf("  ");
        for (i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
        }
        printf("\n");
        for (i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        
        // Get user input
        int x, y;
        printf("Enter the (x,y) coordinate of the cell you want to reveal: ");
        scanf("%d %d", &x, &y);
        
        // Process user input
        if (board[x][y] == '*') {
            printf("Game over. You hit a bomb.\n");
            game_over = 1;
        } else {
            // Count number of adjacent bombs
            int num_adj_bombs = 0;
            for (i = x-1; i <= x+1; i++) {
                for (j = y-1; j <= y+1; j++) {
                    if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                        if (board[i][j] == '*') {
                            num_adj_bombs++;
                        }
                    }
                }
            }
            board[x][y] = num_adj_bombs + '0'; // Convert count to char
            printf("You uncovered %c.\n", board[x][y]);
        }
        
        // Check if game is over
        int num_uncovered = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != '-' && board[i][j] != '*') {
                    num_uncovered++;
                }
            }
        }
        if (num_uncovered == BOARD_SIZE * BOARD_SIZE - num_bombs) {
            printf("Congratulations! You won the game!\n");
            game_over = 1;
        }
    }
    
    return 0;
}