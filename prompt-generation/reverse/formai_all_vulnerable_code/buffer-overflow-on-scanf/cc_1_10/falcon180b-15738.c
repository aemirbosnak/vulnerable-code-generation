//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30
#define TRUE 1
#define FALSE 0

int board[SIZE][SIZE];

// Function to initialize the board with random values
void initBoard() {
    int i, j;
    srand(time(NULL));
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void printBoard() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if(board[i][j] == TRUE) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

// Function to count the number of alive neighbors
int countNeighbors(int x, int y) {
    int count = 0;
    int i, j;
    for(i=-1; i<=1; i++) {
        for(j=-1; j<=1; j++) {
            if((i!= 0 || j!= 0) && board[(x+i+SIZE)%SIZE][(y+j+SIZE)%SIZE] == TRUE) {
                count++;
            }
        }
    }
    return count;
}

// Function to update the board
void updateBoard() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            int neighbors = countNeighbors(i, j);
            if(board[i][j] == TRUE) {
                if(neighbors < 2) {
                    board[i][j] = FALSE;
                }
            } else {
                if(neighbors == 3) {
                    board[i][j] = TRUE;
                }
            }
        }
    }
}

// Function to run the game for a given number of generations
void runGame(int generations) {
    int i;
    initBoard();
    for(i=0; i<generations; i++) {
        printBoard();
        updateBoard();
    }
}

// Main function
int main() {
    int generations;
    printf("Enter the number of generations: ");
    scanf("%d", &generations);
    runGame(generations);
    return 0;
}