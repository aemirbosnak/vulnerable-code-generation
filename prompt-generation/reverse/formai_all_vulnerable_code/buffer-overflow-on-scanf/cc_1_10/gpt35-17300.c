//FormAI DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GRID_SIZE 10

// Function to print the grid
void print_grid(char grid[][MAX_GRID_SIZE], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the robot can move in the given direction
bool can_move(char grid[][MAX_GRID_SIZE], int row, int col, char direction, int x, int y) {
    if(direction == 'N' && x - 1 >= 0) {
        if(grid[x-1][y] == '.') {
            return true;
        }
    }
    else if(direction == 'S' && x + 1 < row) {
        if(grid[x+1][y] == '.') {
            return true;
        }
    }
    else if(direction == 'E' && y + 1 < col) {
        if(grid[x][y+1] == '.') {
            return true;
        }
    }
    else if(direction == 'W' && y - 1 >= 0) {
        if(grid[x][y-1] == '.') {
            return true;
        }
    }
    return false;
}

int main() {
    int row, col, start_x, start_y, moves;
    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE];

    // Input grid size and start position
    printf("Enter grid size (row col): ");
    scanf("%d %d", &row, &col);
    printf("Enter start position (x y): ");
    scanf("%d %d", &start_x, &start_y);

    // Input grid
    printf("Enter grid:\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    printf("\n");

    // Input number of moves
    printf("Enter number of moves: ");
    scanf("%d", &moves);
    printf("\n");

    // Input moves
    char moves_list[moves];
    printf("Enter moves (NSEW): ");
    for(int i=0; i<moves; i++) {
        scanf(" %c", &moves_list[i]);
    }

    // Run the robot
    int x = start_x, y = start_y;
    char direction = 'N';
    grid[x][y] = 'R';
    for(int i=0; i<moves; i++) {
        if(moves_list[i] == 'N' && can_move(grid, row, col, 'N', x, y)) {
            grid[x][y] = '.';
            x--;
            direction = 'N';
            grid[x][y] = 'R';
        }
        else if(moves_list[i] == 'S' && can_move(grid, row, col, 'S', x, y)) {
            grid[x][y] = '.';
            x++;
            direction = 'S';
            grid[x][y] = 'R';
        }
        else if(moves_list[i] == 'E' && can_move(grid, row, col, 'E', x, y)) {
            grid[x][y] = '.';
            y++;
            direction = 'E';
            grid[x][y] = 'R';
        }
        else if(moves_list[i] == 'W' && can_move(grid, row, col, 'W', x, y)) {
            grid[x][y] = '.';
            y--;
            direction = 'W';
            grid[x][y] = 'R';
        }
        else {
            printf("Invalid move: %c\n", moves_list[i]);
            break;
        }
    }

    // Print final grid
    printf("Final grid:\n");
    print_grid(grid, row, col);

    // Print final position and direction of robot
    printf("Final position: (%d, %d)\n", x, y);
    printf("Final direction: %c\n", direction);

    return 0;
}