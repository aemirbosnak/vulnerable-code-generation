//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for game dimensions
#define ROWS 10
#define COLS 10

// Struct for holding coordinates
struct coordinates {
    int row;
    int col;
};

// Initialize global variables
char grid[ROWS][COLS]; // Grid for game board
struct coordinates player_pos; // Player's current position
struct coordinates exit_pos; // Exit's current position

// Function to print out game board
void print_board() {
    printf("\n\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == player_pos.row && j == player_pos.col) {
                printf("P");
            } else if(i == exit_pos.row && j == exit_pos.col) {
                printf("E");
            } else {
                printf("%c", grid[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move player
void move_player(char direction) {
    switch(direction) {
        case 'w':
            player_pos.row--;
            break;
        case 's':
            player_pos.row++;
            break;
        case 'a':
            player_pos.col--;
            break;
        case 'd':
            player_pos.col++;
            break;
        default:
            break;
    }
}

// Check if player reached the exit
int reached_exit() {
    if(player_pos.row == exit_pos.row && player_pos.col == exit_pos.col) {
        return 1;
    }
    return 0;
}

// Main function for running game
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize game board with obstacles
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int r = rand() % 10;
            if(r < 3) {
                grid[i][j] = '#';
            } else {
                grid[i][j] = ' ';
            }
        }
    }

    // Initialize player and exit positions
    player_pos.row = rand() % ROWS;
    player_pos.col = 0;
    exit_pos.row = rand() % ROWS;
    exit_pos.col = COLS - 1;

    // Print out game board
    print_board();

    // Game loop
    while(1) {
        // Get player input
        char input[100];
        printf("Enter direction (w,a,s,d): ");
        scanf("%s", input);
        char direction = input[0];

        // Move player
        move_player(direction);

        // If player reached the exit, end game
        if(reached_exit()) {
            printf("Congratulations, you reached the exit!\n");
            break;
        }

        // Print out game board
        print_board();
    }

    return 0;
}