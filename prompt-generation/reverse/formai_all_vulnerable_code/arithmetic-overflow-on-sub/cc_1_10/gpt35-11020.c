//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 3

typedef enum {X = 'X', O = 'O', Empty = '_'} Mark;
typedef enum {Player1, Player2} Player;

void printInstructions();
void initGrid(Mark grid[GRID_SIZE][GRID_SIZE]);
void printGrid(Mark grid[GRID_SIZE][GRID_SIZE]);
Player getStartingPlayer();
void makeMove(Player player, Mark grid[GRID_SIZE][GRID_SIZE]);
int checkWin(Mark grid[GRID_SIZE][GRID_SIZE]);

int main() {
    Mark grid[GRID_SIZE][GRID_SIZE];
    Player currentPlayer;
    int winner;
    
    // Seed the random number generator
    srand((unsigned int) time(NULL));
    
    // Print instructions
    printInstructions();
    
    // Initialize grid
    initGrid(grid);
    
    // Determine starting player
    currentPlayer = getStartingPlayer();
    printf("\n\nStarting player: Player %d (%c)\n\n", currentPlayer + 1, currentPlayer == Player1 ? 'X' : 'O');
    
    // Game loop
    do {
        // Print grid
        printGrid(grid);
        
        // Make move for current player
        makeMove(currentPlayer, grid);
        
        // Switch player
        currentPlayer = currentPlayer == Player1 ? Player2 : Player1;
        
        // Check for winner
        winner = checkWin(grid);
    } while (winner == -1);
    
    // Print final grid and winner
    printGrid(grid);
    printf("\n\nPlayer %d (%c) wins!", winner + 1, winner == Player1 ? 'X' : 'O');
    
    return 0;
}

// Prints instructions for the game
void printInstructions() {
    printf("#################################\n");
    printf("# Welcome to Tic Tac Toe Console #\n");
    printf("#################################\n");
    printf("\n");
    printf("Instructions:\n");
    printf("  1. You will have to choose the symbol to play. X or O\n");
    printf("  2. The game begins and the player alternatively enters their symbol (X or O) at the respective available position. \n");
    printf("     Each move can be made by entering the position number of respective cell.\n");
    printf("  3. In order to win the game, a player must place three of their marks in a row (vertical, horizontal or diagonal).\n");
    printf("  4. If all the cells are filled with symbols and no player has won, the game is draw.\n");
    printf("\n");
}

// Initializes the grid with empty marks
void initGrid(Mark grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            grid[row][col] = Empty;
        }
    }
}

// Prints the grid to the console
void printGrid(Mark grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    printf("\n\n");
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// Randomly selects the starting player
Player getStartingPlayer() {
    int random = rand() % 2;
    return random == 0 ? Player1 : Player2;
}

// Makes a move for the current player
void makeMove(Player player, Mark grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    printf("Player %d (%c) make your move.\n", player + 1, player == Player1 ? 'X' : 'O');
    do {
        printf("Enter row (1-%d): ", GRID_SIZE);
        scanf("%d", &row);
        row--; // Adjust for 0-based indexing
        printf("Enter column (1-%d): ", GRID_SIZE);
        scanf("%d", &col);
        col--; // Adjust for 0-based indexing
    } while (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE || grid[row][col] != Empty);
    
    grid[row][col] = player == Player1 ? X : O;
}

// Checks if a player has won or if the game is a draw
int checkWin(Mark grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        // Check rows
        if (grid[row][0] != Empty && grid[row][0] == grid[row][1] && grid[row][0] == grid[row][2]) {
            return grid[row][0] == X ? Player1 : Player2;
        }
        
        // Check columns
        if (grid[0][col] != Empty && grid[0][col] == grid[1][col] && grid[0][col] == grid[2][col]) {
            return grid[0][col] == X ? Player1 : Player2;
        }
    }
    
    // Check diagonals
    if (grid[0][0] != Empty && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
        return grid[0][0] == X ? Player1 : Player2;
    }
    
    if (grid[0][2] != Empty && grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
        return grid[0][2] == X ? Player1 : Player2;
    }
    
    // Check if game is draw
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == Empty) {
                return -1; // Game is not over yet
            }
        }
    }
    
    return Empty; // Game is a draw
}