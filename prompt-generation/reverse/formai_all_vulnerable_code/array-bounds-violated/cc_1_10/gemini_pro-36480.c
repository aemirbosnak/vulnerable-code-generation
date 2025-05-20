//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

typedef struct {
    int x;
    int y;
} position;

int maze[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];

position stack[WIDTH * HEIGHT];
int top = 0;

void push(position pos) {
    stack[top++] = pos;
}

position pop() {
    return stack[--top];
}

int is_valid_position(position pos) {
    return pos.x >= 0 && pos.x < WIDTH &&
           pos.y >= 0 && pos.y < HEIGHT &&
           !visited[pos.y][pos.x];
}

void generate_maze() {
    srand(time(NULL));

    position start = { .x = 0, .y = 0 };
    push(start);

    while (top > 0) {
        position current = pop();
        visited[current.y][current.x] = 1;

        int directions[] = { 0, 1, 2, 3 };
        for (int i = 0; i < 4; i++) {
            int direction = directions[rand() % 4];
            switch (direction) {
                case 0:
                    if (is_valid_position((position) { .x = current.x + 1, .y = current.y })) {
                        push((position) { .x = current.x + 1, .y = current.y });
                        maze[current.y][current.x] |= 1 << direction;
                        maze[current.y][current.x + 1] |= 1 << (direction ^ 2);
                    }
                    break;
                case 1:
                    if (is_valid_position((position) { .x = current.x, .y = current.y + 1 })) {
                        push((position) { .x = current.x, .y = current.y + 1 });
                        maze[current.y][current.x] |= 1 << direction;
                        maze[current.y + 1][current.x] |= 1 << (direction ^ 2);
                    }
                    break;
                case 2:
                    if (is_valid_position((position) { .x = current.x - 1, .y = current.y })) {
                        push((position) { .x = current.x - 1, .y = current.y });
                        maze[current.y][current.x] |= 1 << direction;
                        maze[current.y][current.x - 1] |= 1 << (direction ^ 2);
                    }
                    break;
                case 3:
                    if (is_valid_position((position) { .x = current.x, .y = current.y - 1 })) {
                        push((position) { .x = current.x, .y = current.y - 1 });
                        maze[current.y][current.x] |= 1 << direction;
                        maze[current.y - 1][current.x] |= 1 << (direction ^ 2);
                    }
                    break;
            }
        }
    }
}

void print_maze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0) {
                printf("+");
            }
            if (maze[y][x] & 1) {
                printf(" ");
            } else {
                printf("+");
            }
            if (y == HEIGHT - 1) {
                printf("+");
            } else {
                printf(maze[y][x] & 2 ? " +" : "  ");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_maze();
    print_maze();
    return 0;
}