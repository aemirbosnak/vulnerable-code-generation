//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x, y;
} point;

char maze[HEIGHT][WIDTH];

void generate_maze(int x, int y) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;

    maze[y][x] = ' ';
    stack[top++] = (point){x, y};

    while (top > 0) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        point current = stack[--top];
        int dir = 0;

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx] == '#') {
                maze[current.y + dy[dir]][current.x + dx[dir]] = ' ';
                maze[ny][nx] = ' ';

                stack[top++] = current;
                stack[top++] = (point){nx, ny};
                dir = i;
                break;
            }
        }

        current.x += dx[dir];
        current.y += dy[dir];
        maze[current.y][current.x] = ' ';
        stack[top++] = current;
    }
}

void print_maze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    maze[0][0] = '#';
    maze[HEIGHT - 1][WIDTH - 1] = '#';

    int start_x = rand() % WIDTH;
    int start_y = rand() % HEIGHT;

    generate_maze(start_x, start_y);
    print_maze();

    return 0;
}