//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLUMNS 8

// Initializing haunted house grid
char grid[ROWS][COLUMNS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// Initializing player position
int player_row = 7;
int player_col = 0;

// Function to print the grid
void printGrid() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player either up, down, left or right
void movePlayer(char direction) {
    switch (direction) {
        case 'u':
            if(player_row > 0 && grid[player_row-1][player_col] != '*') {
                grid[player_row][player_col] = ' ';
                player_row--;
                grid[player_row][player_col] = 'P';
            }
            break;
        case 'd':
            if(player_row < ROWS-1 && grid[player_row+1][player_col] != '*') {
                grid[player_row][player_col] = ' ';
                player_row++;
                grid[player_row][player_col] = 'P';
            }
            break;
        case 'l':
            if(player_col > 0 && grid[player_row][player_col-1] != '*') {
                grid[player_row][player_col] = ' ';
                player_col--;
                grid[player_row][player_col] = 'P';
            }
            break;
        case 'r':
            if(player_col < COLUMNS-1 && grid[player_row][player_col+1] != '*') {
                grid[player_row][player_col] = ' ';
                player_col++;
                grid[player_row][player_col] = 'P';
            }
            break;
        default:
            printf("Invalid direction!\n");
    }
}

int main() {
    srand(time(NULL)); // Setting up randomization for populating rooms with ghosts
    
    // Initializing ghosts in random rooms
    int ghost1_row = rand() % (ROWS-1);
    int ghost1_col = rand() % (COLUMNS-1);
    int ghost2_row = rand() % (ROWS-1);
    int ghost2_col = rand() % (COLUMNS-1);
    
    // Ensuring ghosts are not in the same room as player
    while((ghost1_row == 7 && ghost1_col == 0) || (ghost2_row == 7 && ghost2_col == 0)) {
        ghost1_row = rand() % (ROWS-1);
        ghost1_col = rand() % (COLUMNS-1);
        ghost2_row = rand() % (ROWS-1);
        ghost2_col = rand() % (COLUMNS-1);
    }
    
    // Populating ghosts in haunted house
    grid[ghost1_row][ghost1_col] = 'G';
    grid[ghost2_row][ghost2_col] = 'G';
    grid[player_row][player_col] = 'P';
    
    // Initializing game variables
    bool gameOver = false;
    int moveCounter = 0;
    
    // Displaying haunted house grid and user instructions
    printGrid();
    printf("Instructions:\n");
    printf("- Move up: 'u'\n");
    printf("- Move down: 'd'\n");
    printf("- Move left: 'l'\n");
    printf("- Move right: 'r'\n");
    
    while(!gameOver) {
        char move;
        printf("\nEnter your move: ");
        scanf(" %c", &move);
        
        switch(move) {
            case 'u':
            case 'd':
            case 'l':
            case 'r':
                movePlayer(move);
                moveCounter++;
                printGrid();
                break;
            default:
                printf("Invalid move! Try again.\n");
        }
        
        // Checking if player wins or loses
        if(grid[player_row][player_col] == 'G') {
            printf("\nYou ran into a ghost! Game over.\n");
            gameOver = true;
        } else if(player_row == 0 && player_col == 7) {
            printf("\nCongratulations! You made it out of the haunted house in %d moves.\n", moveCounter);
            gameOver = true;
        }
    }
    
    return 0;
}