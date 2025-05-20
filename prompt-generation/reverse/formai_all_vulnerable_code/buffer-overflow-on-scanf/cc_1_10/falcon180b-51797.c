//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];

    // Initialize maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Create a path through the maze
    int start_x = rand() % COLS;
    int start_y = rand() % ROWS;
    maze[start_y][start_x] = 'S';

    int end_x = rand() % COLS;
    int end_y = rand() % ROWS;
    maze[end_y][end_x] = 'E';

    // Print the maze
    print_maze(maze);

    // Play the game
    int player_x = start_x;
    int player_y = start_y;

    while (player_x!= end_x || player_y!= end_y) {
        printf("You are at (%d,%d). Enter your move (W/A/S/D): ", player_x, player_y);
        char move;
        scanf("%c", &move);

        switch (move) {
            case 'W':
                if (player_y > 0 && maze[player_y - 1][player_x]!= '#') {
                    player_y--;
                }
                break;
            case 'A':
                if (player_x > 0 && maze[player_y][player_x - 1]!= '#') {
                    player_x--;
                }
                break;
            case 'S':
                if (player_y < ROWS - 1 && maze[player_y + 1][player_x]!= '#') {
                    player_y++;
                }
                break;
            case 'D':
                if (player_x < COLS - 1 && maze[player_y][player_x + 1]!= '#') {
                    player_x++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        print_maze(maze);
    }

    printf("Congratulations! You reached the end.\n");

    return 0;
}