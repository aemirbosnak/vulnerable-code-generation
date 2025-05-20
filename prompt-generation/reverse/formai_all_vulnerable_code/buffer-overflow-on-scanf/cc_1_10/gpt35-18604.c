//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int visible[BOARD_SIZE][BOARD_SIZE]);
int checkWin(int visible[BOARD_SIZE][BOARD_SIZE]);

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Initialize board and visible arrays
    int board[BOARD_SIZE][BOARD_SIZE];
    int visible[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
            visible[i][j] = 0;
        }
    }
    
    // Print instructions
    printf("Welcome to the Memory Game!\n");
    printf("The goal of the game is to uncover all the numbers on the board.\n");
    printf("You will pick two coordinates on the board to reveal the numbers at those positions.\n");
    printf("If the numbers match, they will stay uncovered.\n");
    printf("If the numbers do not match, they will be covered again.\n");
    printf("Good luck!\n\n");
    
    // Keep playing until the player wins
    int numUncovered = 0;
    while (numUncovered < BOARD_SIZE*BOARD_SIZE) {
        // Print board
        printBoard(board, visible);
        
        // Get input from user
        int row1, col1, row2, col2;
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        
        // Check if coordinates are valid
        if (row1 < 0 || row1 > 3 || col1 < 0 || col1 > 3 || row2 < 0 || row2 > 3 || col2 < 0 || col2 > 3) {
            printf("Invalid coordinates. Please try again.\n");
            continue;
        }
        
        // Check if cards match
        if (board[row1][col1] == board[row2][col2]) {
            visible[row1][col1] = 1;
            visible[row2][col2] = 1;
            numUncovered += 2;
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }
    
    // Print winning message
    printf("Congratulations, you won!\n");
    
    return 0;
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int visible[BOARD_SIZE][BOARD_SIZE]) {
    printf("  0 1 2 3\n");
    printf(" +-+-+-+-+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (visible[i][j]) {
                printf("%d|", board[i][j]);
            } else {
                printf(" |");
            }
        }
        printf("\n");
        printf(" +-+-+-+-+\n");
    }
}

int checkWin(int visible[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!visible[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}