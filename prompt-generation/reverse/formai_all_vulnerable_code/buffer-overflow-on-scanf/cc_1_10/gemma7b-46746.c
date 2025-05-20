//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5

typedef struct Cell {
    int x;
    int y;
    char state;
} Cell;

Cell cells[WIDTH * HEIGHT];

void initialize() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        cells[i].x = -1;
        cells[i].y = -1;
        cells[i].state = 'N';
    }
}

void draw() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        switch (cells[i].state) {
            case 'O':
                printf("O ");
                break;
            case 'X':
                printf("X ");
                break;
            default:
                printf(". ");
                break;
        }
    }

    printf("\n");
}

void move(char direction) {
    switch (direction) {
        case 'w':
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                if (cells[i].state == 'O' && cells[i].y - 1 >= 0) {
                    cells[i].y--;
                }
            }
            break;
        case 'a':
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                if (cells[i].state == 'O' && cells[i].x - 1 >= 0) {
                    cells[i].x--;
                }
            }
            break;
        case 's':
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                if (cells[i].state == 'O' && cells[i].y + 1 < HEIGHT) {
                    cells[i].y++;
                }
            }
            break;
        case 'd':
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                if (cells[i].state == 'O' && cells[i].x + 1 < WIDTH) {
                    cells[i].x++;
                }
            }
            break;
    }
}

int main() {
    initialize();
    draw();

    char direction;

    printf("Enter direction (w, a, s, d): ");
    scanf("%c", &direction);

    move(direction);

    draw();

    return 0;
}