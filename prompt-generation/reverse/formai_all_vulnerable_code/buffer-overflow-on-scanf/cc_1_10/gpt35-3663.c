//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Function prototypes
void print_grid(int grid[ROW][COL]);
void move_north(int grid[ROW][COL], int x, int y);
void move_south(int grid[ROW][COL], int x, int y);
void move_east(int grid[ROW][COL], int x, int y);
void move_west(int grid[ROW][COL], int x, int y);

// Main function
int main() {
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    int x = 2, y = 2;

    print_grid(grid);

    char direction;
    while(1) {
        printf("\nEnter direction to move (n/s/e/w): ");
        scanf(" %c", &direction);
        
        switch(direction) {
            case 'n':
                move_north(grid, x, y);
                break;
            case 's':
                move_south(grid, x, y);
                break;
            case 'e':
                move_east(grid, x, y);
                break;
            case 'w':
                move_west(grid, x, y);
                break;
            default:
                printf("Invalid direction!\n");
                continue;
        }
        x = (x < 0) ? 0 : (x > ROW-1) ? ROW-1 : x;
        y = (y < 0) ? 0 : (y > COL-1) ? COL-1 : y;
        print_grid(grid);

        if(grid[x][y] == 0) {
            printf("\nYou have reached the goal!\n");
            break;
        }
    }
    return 0;
}

// Function to print the grid
void print_grid(int grid[ROW][COL]) {
    printf("\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(grid[i][j] == 1)
                printf("* ");
            else
                printf("O ");
        }
        printf("\n");
    }
}

// Function to move north
void move_north(int grid[ROW][COL], int x, int y) {
    if(x > 0 && grid[x-1][y] == 1) {
        grid[x][y] = 1;
        x--;
        grid[x][y] = 0;
    }
    else
        printf("Invalid move!\n");
}

// Function to move south
void move_south(int grid[ROW][COL], int x, int y) {
    if(x < ROW-1 && grid[x+1][y] == 1) {
        grid[x][y] = 1;
        x++;
        grid[x][y] = 0;
    }
    else
        printf("Invalid move!\n");
}

// Function to move east
void move_east(int grid[ROW][COL], int x, int y) {
    if(y < COL-1 && grid[x][y+1] == 1) {
        grid[x][y] = 1;
        y++;
        grid[x][y] = 0;
    }
    else
        printf("Invalid move!\n");
}

// Function to move west
void move_west(int grid[ROW][COL], int x, int y) {
    if(y > 0 && grid[x][y-1] == 1) {
        grid[x][y] = 1;
        y--;
        grid[x][y] = 0;
    }
    else
        printf("Invalid move!\n");
}