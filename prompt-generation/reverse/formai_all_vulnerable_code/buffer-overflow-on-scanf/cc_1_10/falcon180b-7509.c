//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define BOARD_SIZE (WIDTH * HEIGHT)
#define TRUE 1
#define FALSE 0

// Define the board
int board[BOARD_SIZE];

// Function to initialize the board with random values
void initializeBoard() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = rand() % 2;
    }
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", board[i * WIDTH + j]);
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int countLiveNeighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && (row + i >= 0 && row + i < HEIGHT) && (col + j >= 0 && col + j < WIDTH)) {
                count += board[(row + i) * WIDTH + (col + j)];
            }
        }
    }
    return count;
}

// Function to update the board
void updateBoard() {
    int newBoard[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        int liveNeighbors = countLiveNeighbors(i / WIDTH, i % WIDTH);
        if (board[i] == TRUE && (liveNeighbors < 2 || liveNeighbors > 3)) {
            newBoard[i] = FALSE;
        } else if (board[i] == FALSE && liveNeighbors == 3) {
            newBoard[i] = TRUE;
        } else {
            newBoard[i] = board[i];
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = newBoard[i];
    }
}

// Function to run the game for a given number of generations
void runGame(int generations) {
    initializeBoard();
    printBoard();
    for (int i = 0; i < generations; i++) {
        updateBoard();
        printBoard();
        usleep(100000); // Sleep for 100ms between each generation
    }
}

int main() {
    int generations;
    printf("Enter the number of generations to run: ");
    scanf("%d", &generations);
    if (generations <= 0) {
        printf("Invalid number of generations.\n");
        return 1;
    }
    runGame(generations);
    return 0;
}