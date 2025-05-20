//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
void generate_maze(char maze[10][10]);
void print_maze(char maze[10][10]);
int move(char maze[10][10], int x, int y, char direction);
void play_game(char maze[10][10]);

int main() {
    srand(time(0));
    char maze[10][10];
    generate_maze(maze);
    play_game(maze);
    return 0;
}

void generate_maze(char maze[10][10]) {
    int x, y;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            maze[x][y] = rand() % 2? '.' : '#';
        }
    }
    // Set start and end points
    maze[0][0] = '.';
    maze[9][9] = 'E';
}

void print_maze(char maze[10][10]) {
    int x, y;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }
}

int move(char maze[10][10], int x, int y, char direction) {
    int nx, ny;
    switch (direction) {
        case 'w':
            ny = y - 1;
            break;
        case's':
            ny = y + 1;
            break;
        case 'a':
            nx = x - 1;
            break;
        case 'd':
            nx = x + 1;
            break;
        default:
            return 0;
    }
    if (maze[nx][ny] == '.') {
        maze[x][y] = '.';
        maze[nx][ny] = '@';
        return 1;
    }
    return 0;
}

void play_game(char maze[10][10]) {
    int x = 0, y = 0;
    maze[x][y] = '@';
    while (1) {
        system("clear");
        print_maze(maze);
        char input[2];
        scanf("%s", input);
        move(maze, x, y, input[0]);
        if (maze[x][y] == 'E') {
            printf("You win!\n");
            break;
        }
    }
}