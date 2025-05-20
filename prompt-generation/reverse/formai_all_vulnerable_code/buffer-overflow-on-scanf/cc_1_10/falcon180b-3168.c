//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void init_maze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
}

int is_valid_move(int x, int y, char maze[10][10]) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
        return 0;
    }
    if (maze[x][y] == '#') {
        return 0;
    }
    return 1;
}

void print_maze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[10][10];
    init_maze(maze);
    print_maze(maze);

    Point player = {0, 0};
    while (1) {
        system("clear");
        print_maze(maze);
        printf("You are at (%d, %d)\n", player.x, player.y);

        char move;
        scanf("%c", &move);
        switch (move) {
            case 'w':
                player.y--;
                break;
            case 'a':
                player.x--;
                break;
            case's':
                player.y++;
                break;
            case 'd':
                player.x++;
                break;
            default:
                printf("Invalid move\n");
        }

        if (!is_valid_move(player.x, player.y, maze)) {
            printf("You hit a wall!\n");
        } else {
            maze[player.y][player.x] = '@';
        }
    }

    return 0;
}