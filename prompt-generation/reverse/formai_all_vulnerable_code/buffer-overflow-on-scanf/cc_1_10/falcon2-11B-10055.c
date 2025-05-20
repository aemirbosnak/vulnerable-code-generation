//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

// Global variables
int rows, cols, alive_cells = 0;
int** board;

// Function to initialize the game of life board
void initBoard(int rows, int cols) {
    // Allocate memory for board
    board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        board[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // Initialize the board with random alive cells
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int rand_num = rand() % 2;
            board[i][j] = rand_num;
            alive_cells += rand_num;
        }
    }
}

// Function to display the game of life board
void displayBoard() {
    // Print the board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("Total alive cells: %d\n", alive_cells);
}

// Function to update the game of life board
void updateBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num_neighbors = 0;
            // Check the number of alive neighbors for each cell
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= rows || y < 0 || y >= cols) {
                        continue;
                    }
                    num_neighbors += board[x][y];
                }
            }
            // Update the cell state based on the rules of game of life
            if (board[i][j] == 1 && num_neighbors == 2 || num_neighbors == 3) {
                board[i][j] = 1;
                alive_cells++;
            } else if (board[i][j] == 1 && num_neighbors < 2 || num_neighbors > 3) {
                board[i][j] = 0;
                alive_cells--;
            }
        }
    }
}

int main() {
    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Initialize the game of life board
    initBoard(rows, cols);
    
    // Display the initial board
    displayBoard();
    
    // Play the game of life
    while (1) {
        updateBoard();
        printf("New generation: ");
        displayBoard();
    }
    
    return 0;
}