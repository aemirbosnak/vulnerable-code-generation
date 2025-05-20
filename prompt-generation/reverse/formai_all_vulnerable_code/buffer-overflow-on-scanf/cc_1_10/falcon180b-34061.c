//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int create_maze(char maze[ROWS][COLS]);
void print_maze(const char maze[ROWS][COLS]);
int move(int x, int y, int dx, int dy, char maze[ROWS][COLS]);

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    create_maze(maze);

    int playerx = 0;
    int playery = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char key;
        scanf("%c", &key);

        switch (key) {
            case 'w':
                if (move(playerx, playery, 0, -1, maze)) {
                    playery--;
                }
                break;
            case's':
                if (move(playerx, playery, 0, 1, maze)) {
                    playery++;
                }
                break;
            case 'a':
                if (move(playerx, playery, -1, 0, maze)) {
                    playerx--;
                }
                break;
            case 'd':
                if (move(playerx, playery, 1, 0, maze)) {
                    playerx++;
                }
                break;
            case 'q':
                exit(0);
            default:
                break;
        }
    }

    return 0;
}

int create_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    int startx = rand() % ROWS;
    int starty = rand() % COLS;

    while (maze[startx][starty]!= '.') {
        startx = rand() % ROWS;
        starty = rand() % COLS;
    }

    maze[startx][starty] = 'P';

    return 0;
}

void print_maze(const char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int move(int x, int y, int dx, int dy, char maze[ROWS][COLS]) {
    int nx = x + dx;
    int ny = y + dy;

    if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny]!= '#') {
        maze[x][y] = '.';
        maze[nx][ny] = 'P';
        return 1;
    }

    return 0;
}