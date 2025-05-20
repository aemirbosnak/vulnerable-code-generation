//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void init_maze(char maze[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

int is_valid_move(int x, int y, int dx, int dy) {
    return (0 <= x + dx && x + dx < 10 && 0 <= y + dy && y + dy < 10);
}

void print_maze(const char maze[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char maze[10][10];
    init_maze(maze);

    int player_x = 0, player_y = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char key;
        scanf("%c", &key);

        int new_x = player_x, new_y = player_y;

        switch (key) {
            case 'w':
                new_y--;
                break;
            case's':
                new_y++;
                break;
            case 'a':
                new_x--;
                break;
            case 'd':
                new_x++;
                break;
            default:
                continue;
        }

        if (!is_valid_move(player_x, player_y, new_x - player_x, new_y - player_y)) {
            continue;
        }

        maze[player_y][player_x] = '.';
        maze[new_y][new_x] = '@';
        player_x = new_x;
        player_y = new_y;
    }

    return 0;
}