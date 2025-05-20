//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
int x, y;

void init_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_maze();
    print_maze();

    while (1) {
        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
                if (y > 0 && maze[y - 1][x]!= '#') {
                    y--;
                }
                break;
            case's':
                if (y < ROWS - 1 && maze[y + 1][x]!= '#') {
                    y++;
                }
                break;
            case 'a':
                if (x > 0 && maze[y][x - 1]!= '#') {
                    x--;
                }
                break;
            case 'd':
                if (x < COLS - 1 && maze[y][x + 1]!= '#') {
                    x++;
                }
                break;
            default:
                continue;
        }

        print_maze();
    }

    return 0;
}