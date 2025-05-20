//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define GHOSTS 3
#define TREASURES 2
#define MAX_MOVES 10

typedef struct {
    int x, y;
} Point;

void init_maze(char maze[ROOMS][ROOMS]) {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            maze[i][j] = (i == j)? 'X' : '.';
        }
    }
}

void print_maze(const char maze[ROOMS][ROOMS]) {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int move(int dir, Point p) {
    switch (dir) {
        case 0: // up
            p.y--;
            break;
        case 1: // right
            p.x++;
            break;
        case 2: // down
            p.y++;
            break;
        case 3: // left
            p.x--;
            break;
        default:
            return -1;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    char maze[ROOMS][ROOMS];
    init_maze(maze);

    int player_x = 0, player_y = 0;
    int moves = 0;

    while (moves < MAX_MOVES) {
        print_maze(maze);

        int choice;
        printf("> ");
        scanf("%d", &choice);

        Point next_point = {player_x, player_y};
        int result = move(choice, next_point);

        if (result == -1) {
            printf("Invalid direction.\n");
        } else {
            player_x = next_point.x;
            player_y = next_point.y;

            if (maze[player_x][player_y] == 'T') {
                printf("You found a treasure!\n");
            } else if (maze[player_x][player_y] == 'G') {
                printf("You encountered a ghost!\n");
            }

            if (++moves == MAX_MOVES) {
                printf("You ran out of time. Game over.\n");
                break;
            }
        }
    }

    return 0;
}