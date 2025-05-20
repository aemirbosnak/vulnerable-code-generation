//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // initialize random number generator
    srand(time(NULL));

    // game introduction
    printf("Welcome to the Terminal Maze game!\n\n");
    printf("In this game, you will navigate through a maze and try to reach the end.\n");
    printf("However, the maze is full of obstacles and traps, so be careful!\n\n");

    // game setup
    const int maze_size = 10;
    char maze[maze_size][maze_size];
    int start_row = 0, start_col = 0;
    int end_row = maze_size - 1, end_col = maze_size - 1;

    // fill maze with empty spaces
    for (int row = 0; row < maze_size; row++) {
        for (int col = 0; col < maze_size; col++) {
            maze[row][col] = ' ';
        }
    }

    // add obstacles and traps to maze
    for (int i = 0; i < 5; i++) {
        int row = random_number(1, maze_size - 1);
        int col = random_number(1, maze_size - 1);
        maze[row][col] = '#'; // obstacle
    }
    for (int i = 0; i < 3; i++) {
        int row = random_number(1, maze_size - 1);
        int col = random_number(1, maze_size - 1);
        maze[row][col] = 'X'; // trap
    }

    // set starting and ending positions in maze
    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'E';

    // print starting maze
    printf("Here is the maze:\n\n");
    for (int row = 0; row < maze_size; row++) {
        for (int col = 0; col < maze_size; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }

    // game loop
    int current_row = start_row, current_col = start_col;
    while (current_row != end_row || current_col != end_col) {
        // get user input
        char direction;
        printf("\nEnter a direction (w = up, s = down, a = left, d = right): ");
        scanf(" %c", &direction);

        // move player in chosen direction
        switch (direction) {
            case 'w': // up
                if (current_row > 0 && maze[current_row-1][current_col] != '#') {
                    maze[current_row][current_col] = ' ';
                    current_row--;
                }
                break;
            case 's': // down
                if (current_row < maze_size - 1 && maze[current_row+1][current_col] != '#') {
                    maze[current_row][current_col] = ' ';
                    current_row++;
                }
                break;
            case 'a': // left
                if (current_col > 0 && maze[current_row][current_col-1] != '#') {
                    maze[current_row][current_col] = ' ';
                    current_col--;
                }
                break;
            case 'd': // right
                if (current_col < maze_size - 1 && maze[current_row][current_col+1] != '#') {
                    maze[current_row][current_col] = ' ';
                    current_col++;
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        // check for traps
        if (maze[current_row][current_col] == 'X') {
            printf("\nYou fell into a trap! Game over.\n");
            return 0;
        }

        // print updated maze
        printf("\n");
        for (int row = 0; row < maze_size; row++) {
            for (int col = 0; col < maze_size; col++) {
                printf("%c", maze[row][col]);
            }
            printf("\n");
        }
    }

    // player reached the end
    printf("\nCongratulations, you made it to the end of the maze!\n");

    return 0;
}